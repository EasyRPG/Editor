/*
 * This file is part of EasyRPG Editor.
 *
 * EasyRPG Editor is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * EasyRPG Editor is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with EasyRPG Editor. If not, see <http://www.gnu.org/licenses/>.
 */

#include "project.h"
#include "defines.h"
#include "common/filefinder.h"
#include "common/scope_guard.h"
#include "data.h"
#include "inireader.h"
#include "reader_util.h"
#include "ldb_reader.h"
#include "lmu_reader.h"
#include "lmt_reader.h"
#include <QDir>

Project::ProjectList Project::enumerate(const QDir& path) {
	ProjectList prj_list;

	const auto& list = path.entryList(QDir::Dirs);
	for (const QString& item: list) {
		auto res = Project::load(FileFinder::CombinePath(path.absolutePath(), item));
		if (res) {
			prj_list.push_back(res);
		}
	}

	return prj_list;
}

std::shared_ptr<Project> Project::load(const QString& path) {
	return load(QDir(path));
}

std::shared_ptr<Project> Project::load(const QDir& dir) {
	FileFinder::ProjectType project_type = FileFinder::GetProjectType(dir);

	if (project_type == FileFinder::ProjectType::None) {
		return nullptr;
	}

	auto p = std::make_shared<Project>();

	p->setProjectType(project_type);
	p->setProjectDir(dir);
	p->setEncoding("utf-8");

	QString cfg;
	if (project_type == FileFinder::ProjectType::EasyRpg) {
		cfg = FileFinder::Find(dir, EASY_CFG);
	} else {
		cfg = FileFinder::Find(dir, RM_INI);
	}

	if (!cfg.isNull()) {
		INIReader ini(cfg.toStdString());
		std::string title = ini.GetString("RPG_RT", GAMETITLE, "Untitled");

		if (project_type == FileFinder::ProjectType::Legacy) {
			// Check for game encoding
			std::string enc = ini.GetString("EasyRPG", "Encoding", "");
			if (enc.empty()) {
				enc = ReaderUtil::DetectEncoding(title);
			}

			p->setEncoding(QString::fromStdString(enc));
			title = ReaderUtil::Recode(title, enc);
		}

		p->setGameTitle(QString::fromStdString(title));
	}

	return p;
}



bool Project::loadDatabaseAndMapTree() {
	// FIXME: Should assign to private members when liblcf doesn't use global DB and Tree anymore
	// TODO: Error reporting
	ScopeGuard clear_on_return([]() {
		// wipe global variable, makes it easier to find
		// bugs by accidentally reading from Data::*
		Data::Clear();
	});

	if (projectType() == FileFinder::ProjectType::Legacy) {
		if (!LDB_Reader::Load(findFile(RM_DB).toStdString(), encoding().toStdString())) {
			return false;
		}
		if (!LMT_Reader::Load(findFile(RM_MT).toStdString(), encoding().toStdString())) {
			Data::Clear();
			return false;
		}
	} else {
		if (!LDB_Reader::LoadXml(findFile(EASY_DB).toStdString())) {
			return false;
		}
		if (!LMT_Reader::LoadXml(findFile(EASY_MT).toStdString())) {
			Data::Clear();
			return false;
		}
	}

	// Copy db and treemap
	m_db.reset(new RPG::Database(Data::data));
	m_treeMap.reset(new RPG::TreeMap(Data::treemap));

	return true;
}

std::unique_ptr<RPG::Map> Project::loadMap(int index) {
	QString ext = projectType() == FileFinder::ProjectType::EasyRpg ? "emu" : "lmu";

	QString file = QString("Map%1.%2")
			.arg(QString::number(index), 4, QLatin1Char('0')).arg(ext);
	QString mapFile = findFile(file);

	if (mapFile.isNull()) {
		return nullptr;
	}

	if (projectType() == FileFinder::ProjectType::EasyRpg) {
		return LMU_Reader::LoadXml(mapFile.toStdString());
	} else {
		return LMU_Reader::Load(mapFile.toStdString(), encoding().toStdString());
	}
}

bool Project::saveMap(RPG::Map& map, int index, bool incSavecount) {
	QString ext = projectType() == FileFinder::ProjectType::EasyRpg ? "emu" : "lmu";

	QString file = QString("Map%1.%2")
			.arg(QString::number(index), 4, QLatin1Char('0')).arg(ext);
	QString mapFile = findFileOrDefault(file);

	if (incSavecount) {
		LMU_Reader::PrepareSave(map);
	}

	if (projectType() == FileFinder::ProjectType::EasyRpg) {
		return LMU_Reader::SaveXml(mapFile.toStdString(), map);
	} else {
		return LMU_Reader::Save(mapFile.toStdString(), map, encoding().toStdString());
	}
}

void Project::relocate(const QDir& newDir, FileFinder::ProjectType newProjectType) {
	setProjectDir(newDir);
	setProjectType(newProjectType);
}

QString Project::findFile(const QString& filename, FileFinder::FileType type) const {
	return FileFinder::Find(projectDir().absolutePath(), filename, type);
}

QString Project::findFile(const QString& dir, const QString& filename, FileFinder::FileType type) const {
	return FileFinder::Find(projectDir().absolutePath(), dir, filename, type);
}

QString Project::findFileOrDefault(const QString& filename) {
	QString found = findFile(filename);
	return found.isEmpty() ? FileFinder::CombinePath(projectDir().absolutePath(), filename) : found;
}

QString Project::encoding() const {
	return m_encoding;
}

void Project::setEncoding(const QString& encoding) {
	m_encoding = encoding;
}

QDir Project::projectDir() const {
	return m_projectDir;
}

void Project::setProjectDir(const QDir& projectDir) {
	m_projectDir = projectDir;
}

QString Project::gameTitle() const {
	return m_gameTitle;
}

void Project::setGameTitle(const QString& gameTitle) {
	m_gameTitle = gameTitle;
}

FileFinder::ProjectType Project::projectType() const {
	return m_projectType;
}

void Project::setProjectType(FileFinder::ProjectType projectType) {
	m_projectType = projectType;
}

RPG::Database& Project::database() const {
	assert(m_db);
	return *m_db;
}

RPG::TreeMap& Project::treeMap() const {
	assert(m_treeMap);
	return *m_treeMap;
}

bool Project::saveDatabase(bool inc_savecount) {
	if (inc_savecount) {
		LDB_Reader::PrepareSave(*m_db);
	}

	Data::data = *m_db;
	ScopeGuard clear_on_return([]() {
		Data::Clear();
	});

	if (projectType() == FileFinder::ProjectType::Legacy) {
		if (!LDB_Reader::Save(findFileOrDefault(RM_DB).toStdString(), encoding().toStdString())) {
			return false;
		}
	} else {
		if (!LDB_Reader::SaveXml(findFileOrDefault(EASY_DB).toStdString())) {
			return false;
		}
	}

	return true;
}

bool Project::saveTreeMap() {
	Data::treemap = *m_treeMap;
	ScopeGuard clear_on_return([]() {
		Data::Clear();
	});

	if (projectType() == FileFinder::ProjectType::Legacy) {
		if (!LMT_Reader::Save(findFileOrDefault(RM_MT).toStdString(), encoding().toStdString())) {
			return false;
		}
	} else {
		if (!LMT_Reader::SaveXml(findFileOrDefault(EASY_MT).toStdString())) {
			return false;
		}
	}

	return true;
}

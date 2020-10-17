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
#include <lcf/inireader.h>
#include <lcf/reader_util.h>
#include <lcf/ldb/reader.h>
#include <lcf/lmu/reader.h>
#include <lcf/lmt/reader.h>
#include <lcf/encoder.h>
#include <QDir>
#include <memory>
#include <fstream>

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
		lcf::INIReader ini(cfg.toStdString());
		std::string title = ini.GetString("RPG_RT", GAMETITLE, "Untitled");

		if (project_type == FileFinder::ProjectType::Legacy) {
			// Check for game encoding
			std::string enc = ini.GetString("EasyRPG", "Encoding", "");
			if (enc.empty()) {
				// Only use the title for encoding detection
				// This is called for all games in the "Open Project" list
				// Upon project load a smarter detection is used
				enc = lcf::ReaderUtil::DetectEncoding(title);
			}

			p->setEncoding(QString::fromStdString(enc));
			title = lcf::ReaderUtil::Recode(title, enc);
		}

		p->setGameTitle(QString::fromStdString(title));
	}

	return p;
}

bool Project::loadDatabaseAndMapTree() {
	if (projectType() == FileFinder::ProjectType::Legacy) {
		detectEncoding();
		auto db = lcf::LDB_Reader::Load(findFile(RM_DB).toStdString(), encoding().toStdString());
		if (db == nullptr) {
			return false;
		}
		auto treemap = lcf::LMT_Reader::Load(findFile(RM_MT).toStdString(), encoding().toStdString());
		if (treemap == nullptr) {
			return false;
		}
		m_data = { *this, *db, *treemap };
	} else {
		auto db = lcf::LDB_Reader::LoadXml(findFile(EASY_DB).toStdString());
		if (db == nullptr) {
			return false;
		}
		auto treemap = lcf::LMT_Reader::LoadXml(findFile(EASY_MT).toStdString());
		if (treemap == nullptr) {
			return false;
		}
		m_data = { *this, *db, *treemap };
	}

	return true;
}

std::unique_ptr<lcf::rpg::Map> Project::loadMap(int index) const {
	QString ext = projectType() == FileFinder::ProjectType::EasyRpg ? "emu" : "lmu";

	QString file = QString("Map%1.%2")
			.arg(QString::number(index), 4, QLatin1Char('0')).arg(ext);
	QString mapFile = findFile(file);

	if (mapFile.isNull()) {
		return nullptr;
	}

	if (projectType() == FileFinder::ProjectType::EasyRpg) {
		return lcf::LMU_Reader::LoadXml(mapFile.toStdString());
	} else {
		return lcf::LMU_Reader::Load(mapFile.toStdString(), encoding().toStdString());
	}
}

bool Project::saveMap(lcf::rpg::Map& map, int index, bool incSavecount) {
	const bool is2k3 = m_data.database().system.ldb_id == 2003;
	QString ext = projectType() == FileFinder::ProjectType::EasyRpg ? "emu" : "lmu";

	QString file = QString("Map%1.%2")
			.arg(QString::number(index), 4, QLatin1Char('0')).arg(ext);
	QString mapFile = findFileOrDefault(file);

	if (incSavecount) {
		lcf::LMU_Reader::PrepareSave(map);
	}

	if (projectType() == FileFinder::ProjectType::EasyRpg) {
		return lcf::LMU_Reader::SaveXml(mapFile.toStdString(), map, is2k3);
	} else {
		return lcf::LMU_Reader::Save(mapFile.toStdString(), map, is2k3, encoding().toStdString());
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

QString Project::detectEncoding() {
	if (projectType() == FileFinder::ProjectType::EasyRpg) {
		setEncoding("utf-8");
		return encoding();
	}

	auto cfg = findFile(RM_INI);
	std::string enc;
	std::string title;
	if (!cfg.isNull()) {
		lcf::INIReader ini(cfg.toStdString());
		title = ini.GetString("RPG_RT", GAMETITLE, "Untitled");
		enc = ini.GetString("EasyRPG", "Encoding", "");
	}

	if (enc.empty()) {
		std::ifstream i(findFile(RM_DB).toStdString(), std::ios::binary);
		if (i) {
			std::string dbenc = lcf::ReaderUtil::DetectEncoding(i);
			lcf::Encoder encoder(dbenc);
			if (encoder.IsOk()) {
				enc = dbenc;
			}
		}
	}

	setEncoding(QString::fromStdString(enc));
	setGameTitle(QString::fromStdString(lcf::ReaderUtil::Recode(title, enc)));

	return encoding();
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

ProjectData &Project::projectData() {
	return m_data;
}

const ProjectData &Project::projectData() const {
	return m_data;
}

lcf::rpg::Database& Project::database() {
	return m_data.database();
}

const lcf::rpg::Database& Project::database() const {
	return m_data.database();
}

lcf::rpg::TreeMap& Project::treeMap() {
	return m_data.treeMap();
}

const lcf::rpg::TreeMap& Project::treeMap() const {
	return m_data.treeMap();
}

bool Project::saveDatabase(bool inc_savecount) {
	if (inc_savecount) {
		lcf::LDB_Reader::PrepareSave(m_data.database());
	}

	if (projectType() == FileFinder::ProjectType::Legacy) {
		if (!lcf::LDB_Reader::Save(findFileOrDefault(RM_DB).toStdString(), m_data.database(), encoding().toStdString())) {
			return false;
		}
	} else {
		if (!lcf::LDB_Reader::SaveXml(findFileOrDefault(EASY_DB).toStdString(), m_data.database())) {
			return false;
		}
	}

	return true;
}

bool Project::saveTreeMap() {
	const bool is2k3 = m_data.database().system.ldb_id == 2003;
	if (projectType() == FileFinder::ProjectType::Legacy) {
		if (!lcf::LMT_Reader::Save(findFileOrDefault(RM_MT).toStdString(), m_data.treeMap(), is2k3, encoding().toStdString())) {
			return false;
		}
	} else {
		if (!lcf::LMT_Reader::SaveXml(findFileOrDefault(EASY_MT).toStdString(), m_data.treeMap(), is2k3)) {
			return false;
		}
	}

	return true;
}

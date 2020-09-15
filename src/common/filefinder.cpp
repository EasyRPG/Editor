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

#include "common/dbstring.h"
#include "defines.h"
#include "filefinder.h"

QString FileFinder::Find(const QDir& dir, const QString& filename, FileType type) {
	auto fn = [&](std::initializer_list<std::string> exts) -> QString {
		for (const std::string& ext: exts) {
			QString file_to_find = filename + ToQString(ext);
			const auto& list = dir.entryList(QDir::Files);
			for (const QString& item: list) {
				if (item.compare(file_to_find, Qt::CaseInsensitive) == 0) {
					return CombinePath(dir.absolutePath(), item);
				}
			}
		}
		return nullptr;
	};

	switch (type) {
		case FileType::Default:
			return fn({""});
		case FileType::Image:
			return fn({ ".bmp", ".png", ".xyz"});
		case FileType::Sound:
			return fn({".opus", ".oga", ".ogg", ".wav", ".mp3"});
		case FileType::Music:
			return fn({".opus", ".oga", ".ogg", ".wav", ".mid", ".midi", ".mp3"});
		case FileType::Video:
			return fn({".webm", ".mp4", ".avi"});
		case FileType::Font:
			return fn({".ttf", ".ttc", ".otf", ".fon"});
	}

	assert(false);
	return nullptr;
}

QString FileFinder::Find(const QDir& baseDir, const QString& subDir, const QString& filename, FileType type) {
	QString dir = CombinePath(baseDir.absolutePath(), subDir);
	return Find(dir, filename, type);
}

FileFinder::ProjectType FileFinder::GetProjectType(const QDir& directory) {
	if (IsRPG2kProject(directory)) {
		return ProjectType::Legacy;
	} else if (IsEasyRpgProject(directory)) {
		return ProjectType::EasyRpg;
	}
	return ProjectType::None;
}

bool FileFinder::IsRPG2kProject(const QDir& directory) {
	return Find(directory, RM_DB).length() > 0 && Find(directory, RM_MT).length() > 0;
}

bool FileFinder::IsEasyRpgProject(const QDir& directory) {
	return Find(directory, EASY_DB).length() > 0 && Find(directory, EASY_MT).length() > 0;
}

QString FileFinder::CombinePath(const QString& path1, const QString& path2) {
	return path1 + QDir::separator() + path2;
}

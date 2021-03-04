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

#pragma once

#include <QDir>

namespace FileFinder {
	enum class FileType {
		Default,
		Image,
		Sound,
		Music,
		Video,
		Font
	};

	enum class ProjectType {
		None,
		/** EasyRPG project */
		EasyRpg,
		/** Legacy (RPG Maker 2k/2k3) project */
		Legacy
	};

	QString Find(const QDir& directory, const QString& filename, FileType type = FileType::Default, QDir::Filter filter = QDir::Files);
	QString Find(const QDir& baseDir, const QString& subDir, const QString& filename, FileType type = FileType::Default, QDir::Filter filter = QDir::Files);

	ProjectType GetProjectType(const QDir& directory);

	bool IsRPG2kProject(const QDir& directory);

	bool IsEasyRpgProject(const QDir& directory);

	QString CombinePath(const QString& path1, const QString& path2);
};


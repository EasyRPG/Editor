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

#include "directory_model.h"
#include "common/filefinder.h"

DirectoryModel::DirectoryModel(QObject* parent) : QAbstractListModel(parent) {}

int DirectoryModel::rowCount(const QModelIndex& parent) const {
	Q_UNUSED(parent)
	return m_fileList.count();
}

QVariant DirectoryModel::data(const QModelIndex& index, int role) const {
	if (!index.isValid() || index.row() < 0 ||
		index.row() >= m_fileList.count())
		return QVariant();

	const QString& filename = m_fileList.at(index.row());

	switch (role) {
	case FileNameRole:
		return filename;
	case FullPathRole:
		return QString("%1/%2").arg(m_path).arg(filename);
	case BaseNameRole:
		return filename.left(filename.lastIndexOf("."));
	case Qt::DisplayRole:
		return filename;
	default:
		return QVariant();
	}
}

QHash<int, QByteArray> DirectoryModel::roleNames() const {
	QHash<int, QByteArray> roles;
	roles[FileNameRole] = "fileName";
	roles[FullPathRole] = "fullPath";
	roles[BaseNameRole] = "baseName";
	return roles;
}

QString DirectoryModel::path() const { return m_path; }

void DirectoryModel::setPath(const QString& path) {
	if (m_path == path)
		return;

	m_path = path;
	refreshModel();
	emit pathChanged();
}

FileFinder::FileType DirectoryModel::fileType() const { return m_fileType; }

void DirectoryModel::setFileType(FileFinder::FileType fileType) {
	if (m_fileType == fileType)
		return;

	m_fileType = fileType;
	refreshModel();
	emit fileTypeChanged();
}

void DirectoryModel::refreshModel() {
	beginResetModel();

	m_fileList.clear();

	if (!m_path.isEmpty()) {
		QDir dir(m_path);
		if (dir.exists()) {
			auto entries = dir.entryList(QDir::Files | QDir::NoDotAndDotDot, QDir::Name);

			// Apply filters based on file type
			QStringList filters = FileFinder::GetFiltersForType(m_fileType);

			for (const QString& entry : entries) {
				if (matchesFilter(entry, filters)) {
					m_fileList.append(entry);
				}
			}
		}
	}

	endResetModel();
	emit countChanged();
}

bool DirectoryModel::matchesFilter(const QString& fileName,
								   const QStringList& filters) const {
	if (filters.isEmpty() || filters.contains(""))
		return true;

	QString fileLower = fileName.toLower();

	for (const QString& filter : filters) {
		if (fileLower.endsWith(filter.toLower())) {
			return true;
		}
	}

	return false;
}

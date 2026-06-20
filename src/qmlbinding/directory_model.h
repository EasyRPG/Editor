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

#include "common/filefinder.h"
#include <QAbstractListModel>
#include <QDir>
#include <QFileInfo>
#include <QStringList>
#include <QtQmlIntegration>

class DirectoryModel : public QAbstractListModel {
	Q_OBJECT
	QML_ELEMENT
	Q_PROPERTY(QString path READ path WRITE setPath NOTIFY pathChanged)
	Q_PROPERTY(int count READ rowCount NOTIFY countChanged)
	Q_PROPERTY(FileFinder::FileType fileType READ fileType WRITE setFileType NOTIFY
				   fileTypeChanged)

public:
	enum Roles {
		FileNameRole = Qt::UserRole + 1,
		FullPathRole,
		BaseNameRole
	};

	explicit DirectoryModel(QObject* parent = nullptr);

	// QAbstractItemModel interface
	int rowCount(const QModelIndex& parent = QModelIndex()) const override;
	QVariant data(const QModelIndex& index,
				  int role = Qt::DisplayRole) const override;
	Q_INVOKABLE QHash<int, QByteArray> roleNames() const override;

	// Property accessors
	QString path() const;
	void setPath(const QString& path);

	FileFinder::FileType fileType() const;
	void setFileType(FileFinder::FileType fileType);

signals:
	void pathChanged();
	void countChanged();
	void fileTypeChanged();

private:
	void refreshModel();
	bool matchesFilter(const QString& fileName,
					   const QStringList& filters) const;

	QString m_path;
	FileFinder::FileType m_fileType = FileFinder::FileType::Default;
	QList<QString> m_fileList;
};

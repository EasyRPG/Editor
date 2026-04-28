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

#include <QPixmap>
#include <QQuickPaintedItem>
#include "project_data_gadget.h"

class SpritePaintedItem : public QQuickPaintedItem {
	Q_OBJECT
	QML_ELEMENT
	Q_PROPERTY(QString filename READ filename WRITE setFilename NOTIFY filenameChanged)
	Q_PROPERTY(QString directory READ directory WRITE setDirectory NOTIFY directoryChanged)
	Q_PROPERTY(ProjectDataGadget* projectData READ projectData WRITE setProjectData NOTIFY projectDataChanged)

public:
	explicit SpritePaintedItem(QQuickItem* parent = nullptr);

	QString filename() const;
	void setFilename(const QString& filename);

	QString directory() const;
	void setDirectory(const QString& directory);

	ProjectDataGadget* projectData() const;
	void setProjectData(ProjectDataGadget* projectData);

	void paint(QPainter* painter) override;

signals:
	void filenameChanged();
	void directoryChanged();
	void projectDataChanged();

private:
	void reload();

	QString m_filename;
	QString m_directory;
	ProjectDataGadget* m_projectData = nullptr;
	QPixmap m_image;
};


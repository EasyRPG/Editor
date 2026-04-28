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
#include "json_t.h"
#include "model/project_data.h"
#include <lcf/rpg/fwd.h>
#include <QObject>
#include <QPixmap>

class ActorModel;
class JsonView;

/**
 * Wrapper around ProjectData class for usage in QML
 */
class ProjectDataGadget : public QObject
{
	Q_OBJECT
	QML_NAMED_ELEMENT(ProjectData)
	QML_SINGLETON
	Q_PROPERTY(QString projectPath READ projectPath)

public:
    explicit ProjectDataGadget(QObject* parent = nullptr);

    void setProjectData(ProjectData* data);

    Q_INVOKABLE JsonView* database();
    Q_INVOKABLE JsonView* treeMap();

    Q_INVOKABLE QString findFile(const QString& filename, FileFinder::FileType type = FileFinder::FileType::Default) const;
    Q_INVOKABLE QString findFile(const QString& dir, const QString& filename, FileFinder::FileType type = FileFinder::FileType::Default) const;
    Q_INVOKABLE QString findFileOrDefault(const QString& filename);
    Q_INVOKABLE QString findDirectory(const QString& dir) const;
    Q_INVOKABLE QString findDirectory(const QString& baseDir, const QString& dir) const;

    Q_INVOKABLE QPixmap loadImage(const QString& dir, const QString& filename) const;

	Q_INVOKABLE ActorModel actorModel(int actor_index);

	QString projectPath() const;

signals:
    void projectDataChanged();

private:
	ProjectData* m_data = nullptr;
	JsonT<lcf::rpg::Database> m_database_json;
	JsonT<lcf::rpg::TreeMap> m_treemap_json;
};

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

#include "project_data_gadget.h"
#include "common/image_loader.h"
#include "model/actor.h"
#include "model/project.h"
#include "json_view.h"

ProjectDataGadget::ProjectDataGadget(QObject* parent) : QObject(parent) {

}

void ProjectDataGadget::setProjectData(ProjectData* data) {
    if (m_data == data) return;

    m_data = data;

    if (m_data) {
        m_database_json.setData(&m_data->database());
        m_treemap_json.setData(&m_data->treeMap());
    }

    emit projectDataChanged();
}

JsonView* ProjectDataGadget::database() {
    return m_data ? qvariant_cast<JsonView*>(m_database_json.subtree("/")) : nullptr;
}

JsonView* ProjectDataGadget::treeMap() {
    return m_data ? qvariant_cast<JsonView*>(m_treemap_json.subtree("/")) : nullptr;
}

QString ProjectDataGadget::findFile(const QString& filename, FileFinder::FileType type) const {
	return m_data->project().findFile(filename, type);
}

QString ProjectDataGadget::findFile(const QString& dir, const QString& filename, FileFinder::FileType type) const {
	return m_data->project().findFile(dir, filename, type);
}

QString ProjectDataGadget::findFileOrDefault(const QString& filename) {
	return m_data->project().findFileOrDefault(filename);
}

QString ProjectDataGadget::findDirectory(const QString& dir) const {
	return m_data->project().findDirectory(dir);
}

QString ProjectDataGadget::findDirectory(const QString& baseDir, const QString& dir) const {
	return m_data->project().findDirectory(baseDir, dir);
}

QPixmap ProjectDataGadget::loadImage(const QString& dir, const QString& filename) const {
	QString file = findFile(dir, filename, FileFinder::FileType::Image);
	if (file.isEmpty()) {
		return {};
	}

	return ImageLoader::Load(file);
}

ActorModel ProjectDataGadget::actorModel(int actor_index) {
	return ActorModel(*m_data, m_data->database().actors[actor_index]);
}

QString ProjectDataGadget::projectPath() const {
	return m_data->project().projectDir().absolutePath();
}

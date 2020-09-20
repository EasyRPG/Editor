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

#include <QAbstractListModel>
#include <QPixmap>
#include <QMessageBox>

#include <lcf/rpg/database.h>
#include "core.h"
#include "common/dbstring.h"
#include "common/filefinder.h"
#include "common/image_loader.h"
#include "model/rpg_factory.h"
#include "ui/common/widget_as_dialog_wrapper.h"
#include "ui/common/faceset_item.h"
#include "ui/database/actor_widget.h"
#include "ui/database/item_widget.h"

template<typename T>
class RpgModel : public QAbstractListModel {
public:
	RpgModel(ProjectData& project, std::vector<T>& data, QObject *parent = nullptr) :
			QAbstractListModel(parent), m_project(project), m_data(data) {}
	int rowCount(const QModelIndex& = QModelIndex()) const override { return m_data.size(); }
	QVariant data(const QModelIndex &index, int role) const override;

private:
	ProjectData& m_project;
	std::vector<T>& m_data;
};

enum ModelData {
	ModelDataId = Qt::UserRole,
	ModelDataObject
};

template<class T>
QVariant RpgModel<T>::data(const QModelIndex &index, int role) const {
	if (!index.isValid()) {
		return QVariant();
	} else if (role == Qt::DisplayRole || role == Qt::EditRole) {
		auto data = m_data[index.row()];
		return QString("%1: %2").arg(data.ID, 4, 10, QChar('0')).arg(ToQString(data.name));
	} else if (role == Qt::DecorationRole) {
		return RpgFactory::Create(m_project, m_data[index.row()]).preview();
	} else if (role == Qt::UserRole) {
		return m_data[index.row()].ID;
	} else if (role == ModelDataObject) {
		return QVariant::fromValue(&m_data[index.row()]);
	}

	return QVariant();
}

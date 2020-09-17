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
#include "ui/common/widget_as_dialog_wrapper.h"
#include "ui/common/faceset_item.h"
#include "ui/database/actor_widget.h"
#include "ui/database/item_widget.h"

template <class T>
QPixmap previewModel(const T& item) {
	if constexpr (std::is_same_v<T,lcf::rpg::Actor>) {
		QPixmap faceSet = ImageLoader::Load(core().project()->findFile("FaceSet", ToQString(item.face_name), FileFinder::FileType::Image));

		int x = (item.face_index % 4) * 48;
		int y = (item.face_index / 4) * 48;

		return faceSet.copy(x, y, 48, 48);
	} else if constexpr (std::is_same_v<T,lcf::rpg::Enemy>) {
		QPixmap monster = ImageLoader::Load(core().project()->findFile("Monster", ToQString(item.battler_name), FileFinder::FileType::Image));
		if (!monster) {
			return QPixmap(48, 48);
		}
		monster.scaled(48, 48, Qt::AspectRatioMode::KeepAspectRatio);
	}

	return QPixmap();
}

template <class T>
void editModel(lcf::rpg::Database& db, T& obj, QWidget* parent) {
	if constexpr (std::is_same_v<lcf::rpg::Actor, T>) {
		auto* w = new WidgetAsDialogWrapper<ActorWidget, T>(db, obj, parent);
		w->show();
	} else if constexpr (std::is_same_v<lcf::rpg::Item, T>) {
		auto* w = new WidgetAsDialogWrapper<ItemWidget, T>(db, obj, parent);
		w->show();
	} else {
		QMessageBox::warning(parent, "Edit not supported", "Editing not supported (yet)");
	}
}

template <class T>
class RpgModel : public QAbstractListModel
{
public:
	RpgModel(std::vector<T>& data, QObject *parent = nullptr) :
			QAbstractListModel(parent), m_data(data) {}
	int rowCount(const QModelIndex& = QModelIndex()) const override { return m_data.size(); }
	QVariant data(const QModelIndex &index, int role) const override;

private:
	std::vector<T>& m_data;
};

template <class T>
QVariant RpgModel<T>::data(const QModelIndex &index, int role) const
{
	if (!index.isValid()) {
		return QVariant();
	} else if (role == Qt::DisplayRole || role == Qt::EditRole) {
		auto data = m_data[index.row()];
		return QString("%1: %2").arg(data.ID, 4, 10, QChar('0')).arg(ToQString(data.name));
	} else if (role == Qt::DecorationRole) {
		return previewModel<T>(m_data[index.row()]);
	} else if (role == Qt::UserRole) {
		return m_data[index.row()].ID;
	}

	return QVariant();
}

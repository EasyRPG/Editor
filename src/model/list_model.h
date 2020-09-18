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

#include <QAbstractListModel>
#include <QPixmap>

#include "core.h"
#include "common/dbstring.h"
#include "common/filefinder.h"
#include "common/image_loader.h"
#include <lcf/rpg/database.h>
#include "ui/common/faceset_item.h"

template <class T>
QPixmap preview(const T& item) {
	if constexpr (std::is_same<T,lcf::rpg::Actor>::value) {
		QPixmap faceSet = ImageLoader::Load(core().project()->findFile("FaceSet", ToQString(item.face_name), FileFinder::FileType::Image));

		int x = (item.face_index % 4) * 48;
		int y = (item.face_index / 4) * 48;

		return faceSet.copy(x, y, 48, 48);
	} else if constexpr (std::is_same<T,lcf::rpg::Enemy>::value) {
		QPixmap monster = ImageLoader::Load(core().project()->findFile("Monster", ToQString(item.battler_name), FileFinder::FileType::Image));
		if (!monster) {
			return QPixmap(48, 48);
		}
		monster.scaled(48, 48, Qt::AspectRatioMode::KeepAspectRatio);
	}

	return QPixmap();
}

template <class T>
class ListModel : public QAbstractListModel
{
public:
	ListModel(std::vector<T>& data, QObject *parent = nullptr) :
		QAbstractListModel(parent), m_data(data) {}
	virtual ~ListModel() {}
	virtual int rowCount(const QModelIndex& = QModelIndex()) const override { return m_data.size(); }
	virtual QVariant data(const QModelIndex &index, int role) const override;

private:
	std::vector<T>& m_data;
};

template <class T>
QVariant ListModel<T>::data(const QModelIndex &index, int role) const
{
	if (!index.isValid()) {
		return QVariant();
	} else if (role == Qt::DisplayRole || role == Qt::EditRole) {
		auto data = m_data[index.row()];
		return QString("%1: %2").arg(data.ID, 4, 10, QChar('0')).arg(ToQString(data.name));
	} else if (role == Qt::DecorationRole) {
		return preview<T>(m_data[index.row()]);
	} else if (role == Qt::UserRole) {
		if (index.row() > 0) {
			return m_data[index.row()].ID;
		}
	}

	return QVariant();
}

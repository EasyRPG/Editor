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

#include <QObject>
#include <QAbstractItemModel>
#include "core.h"
#include "data.h"

template <class DATA>
class RpgModel : public QAbstractListModel
{
public:
	RpgModel(QObject *parent = nullptr) : QAbstractListModel(parent), _data(DATA()()) {}
	virtual ~RpgModel() {}
	virtual int rowCount(const QModelIndex & = QModelIndex()) const override { return _data.size(); }
	virtual QVariant data(const QModelIndex &index, int role) const override;

	typedef decltype(DATA()()) type;
	typedef DATA typestruct;

private:
	decltype(DATA()()) _data;
};

template <class DATA>
QVariant RpgModel<DATA>::data(const QModelIndex &index, int role) const
{
	if (!index.isValid())
		return QVariant();
	else if (role == Qt::DisplayRole || role == Qt::EditRole)
	{
		if (index.row() == 0)
		{
			return QString("=== EDIT ===");
		}
		else
		{
			auto data = _data[index.row()-1];
			return QString("%1: %2").arg(data.ID).arg(QString::fromStdString(data.name));
		}
	}
	else if (role == Qt::UserRole)
		if (index.row() > 0)
			return _data[index.row()-1].ID;

	return QVariant();
}




#define VARSTRUCT(STRUCTNAME, VARNAME) \
	namespace detail { struct STRUCTNAME { decltype(mCore->project()->database().VARNAME) operator()() const { return mCore->project()->database().VARNAME; } }; } \
	using  STRUCTNAME##RpgModel = RpgModel<detail::STRUCTNAME>;

VARSTRUCT(Actor, actors)
VARSTRUCT(Skill, skills)
VARSTRUCT(Item, items)
VARSTRUCT(Enemy, enemies)
VARSTRUCT(Troop, troops)
VARSTRUCT(Terrain, terrains)
VARSTRUCT(Attribute, attributes)
VARSTRUCT(State, states)
VARSTRUCT(Animation, animations)
VARSTRUCT(Chipset, chipsets)
VARSTRUCT(CommonEvent, commonevents)
//BattleCommands ?!
VARSTRUCT(Class, classes)
VARSTRUCT(BattlerAnimation, battleranimations)
VARSTRUCT(Switch, switches)
VARSTRUCT(Variable, variables)

#undef VARSTRUCT


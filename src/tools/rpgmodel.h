#ifndef RPGMODEL_H
#define RPGMODEL_H

#include <QObject>
#include <QAbstractItemModel>
#include <data.h>

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
	namespace detail { struct STRUCTNAME { decltype(Data::VARNAME) operator()() const { return Data::VARNAME; } }; } \
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

#endif // RPGMODEL_H

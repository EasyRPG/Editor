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

#include "actor_delegate.h"
#include "core.h"
#include "common/dbstring.h"

ActorDelegate::ActorDelegate(QObject *parent) :
	QItemDelegate(parent)
{
}

QWidget *ActorDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
	Q_UNUSED(index)
	Q_UNUSED(option)
	QComboBox *editor = new QComboBox(parent);
	editor->addItem(tr("<None>"), 0);
	for (size_t i = 0; i < core().project()->database().actors.size(); i++)
		editor->addItem(ToQString(core().project()->database().actors[i].name), core().project()->database().actors[i].ID);
	return editor;
}

void ActorDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
	int id = index.model()->data(index, Qt::UserRole).toInt();
	static_cast<QComboBox*>(editor)->setCurrentIndex(id);
}

void ActorDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
	int id = static_cast<QComboBox*>(editor)->currentIndex() + 1;
	model->setData(index, id, Qt::UserRole);
	model->setData(index, ToQString(core().project()->database().actors[static_cast<size_t>(id)-1].name));
}

void ActorDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
	Q_UNUSED(index)
	editor->setGeometry(option.rect);
}

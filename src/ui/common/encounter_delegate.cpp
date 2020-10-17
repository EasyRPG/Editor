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

#include "core.h"
#include "common/dbstring.h"
#include "encounter_delegate.h"

QEncounterDelegate::QEncounterDelegate(QObject *parent) :
	QItemDelegate(parent)
{

}

QWidget *QEncounterDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
	Q_UNUSED(index)
	Q_UNUSED(option)
	QComboBox *editor = new QComboBox(parent);
	for (size_t i = 0; i < core().project()->database().troops.size(); i++)
		editor->addItem(ToQString(core().project()->database().troops[i].name));
	return editor;
}

void QEncounterDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
	int id = index.model()->data(index, Qt::UserRole).toInt();
	static_cast<QComboBox*>(editor)->setCurrentIndex(id-1);
}

void QEncounterDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
	int id = static_cast<QComboBox*>(editor)->currentIndex() + 1;
	model->setData(index, id, Qt::UserRole);
	model->setData(index, ToQString(core().project()->database().troops[static_cast<size_t>(id)-1].name));
}

void QEncounterDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
	Q_UNUSED(index)
	editor->setGeometry(option.rect);
}

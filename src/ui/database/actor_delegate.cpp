#include "actor_delegate.h"
#include <data.h>

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
	for (size_t i = 0; i < Data::actors.size(); i++)
		editor->addItem(QString::fromStdString(Data::actors[i].name), Data::actors[i].ID);
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
	model->setData(index, QString::fromStdString(Data::actors[static_cast<size_t>(id)-1].name));
}

void ActorDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
	Q_UNUSED(index)
	editor->setGeometry(option.rect);
}

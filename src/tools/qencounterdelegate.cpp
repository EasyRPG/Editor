#include "qencounterdelegate.h"
#include <data.h>

QEncounterDelegate::QEncounterDelegate(QObject *parent) :
    QItemDelegate(parent)
{

}

QWidget *QEncounterDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(index)
    Q_UNUSED(option)
    QComboBox *editor = new QComboBox(parent);
    for (size_t i = 0; i < Data::troops.size(); i++)
        editor->addItem(QString::fromStdString(Data::troops[i].name));
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
    model->setData(index, QString::fromStdString(Data::troops[static_cast<size_t>(id)-1].name));
}

void QEncounterDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(index)
    editor->setGeometry(option.rect);
}

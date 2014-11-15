#ifndef QCOMBODELEGATE_H
#define QCOMBODELEGATE_H

#include <QItemDelegate>
#include <QComboBox>
#include <QVariant>

class QEncounterDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    explicit QEncounterDelegate(QObject *parent = 0);

    QWidget *createEditor(QWidget *parent,
                          const QStyleOptionViewItem &option,
                          const QModelIndex &index) const;

    void setEditorData(QWidget *editor, const QModelIndex &index) const;

    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;

    void updateEditorGeometry(QWidget *editor,
                              const QStyleOptionViewItem &option,
                              const QModelIndex &index) const;

signals:

public slots:

};

#endif // QCOMBODELEGATE_H

#ifndef QACTORDELEGATE_H
#define QACTORDELEGATE_H

#include <QItemDelegate>
#include <QComboBox>

class ActorDelegate : public QItemDelegate
{
	Q_OBJECT
public:
	explicit ActorDelegate(QObject *parent = nullptr);

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

#endif // QACTORDELEGATE_H

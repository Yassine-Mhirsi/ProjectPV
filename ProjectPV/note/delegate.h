#ifndef DELEGATE_H
#define DELEGATE_H

#include <QItemDelegate>
#include <QObject>
#include <QSpinBox>

class delegate : public QItemDelegate
{
    Q_OBJECT
public:
    delegate(QObject *parent = nullptr);


    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;

    // Override setEditorData to set data to the spinbox
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;

    // Override setModelData to get data from the spinbox
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;

};

#endif // DELEGATE_H

#include "delegate.h"

delegate::delegate(QObject *parent) :
    QItemDelegate(parent)
{}

QWidget *delegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    if (index.column() == 0) { // Assuming the additional column is at index 0
        QSpinBox *spinBox = new QSpinBox(parent);
        spinBox->setMinimum(0); // Set minimum value for the spinbox
        spinBox->setMaximum(100); // Set maximum value for the spinbox
        return spinBox;
    }
    return QItemDelegate::createEditor(parent, option, index); // For other columns, use default editor
}

void delegate::setEditorData(QWidget *editor, const QModelIndex &index) const {
    if (QSpinBox *spinBox = qobject_cast<QSpinBox*>(editor)) { // Check if the editor is a spinbox
        int value = index.model()->data(index, Qt::EditRole).toInt(); // Get data from model
        spinBox->setValue(value); // Set value to the spinbox
    } else {
        QItemDelegate::setEditorData(editor, index); // For other editors, use default editor data
    }
}

void delegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const {
    if (QSpinBox *spinBox = qobject_cast<QSpinBox*>(editor)) { // Check if the editor is a spinbox
        int value = spinBox->value(); // Get value from the spinbox
        model->setData(index, value, Qt::EditRole); // Set data to the model
    } else {
        QItemDelegate::setModelData(editor, model, index); // For other editors, use default model data
    }
}

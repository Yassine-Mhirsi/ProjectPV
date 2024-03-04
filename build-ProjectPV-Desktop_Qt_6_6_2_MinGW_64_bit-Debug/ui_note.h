/********************************************************************************
** Form generated from reading UI file 'note.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTE_H
#define UI_NOTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_note
{
public:
    QTableView *gm_tableView;
    QPushButton *add_pushButton;
    QComboBox *grp_comboBox;

    void setupUi(QDialog *note)
    {
        if (note->objectName().isEmpty())
            note->setObjectName("note");
        note->resize(961, 584);
        gm_tableView = new QTableView(note);
        gm_tableView->setObjectName("gm_tableView");
        gm_tableView->setGeometry(QRect(70, 140, 761, 391));
        gm_tableView->verticalHeader()->setVisible(false);
        add_pushButton = new QPushButton(note);
        add_pushButton->setObjectName("add_pushButton");
        add_pushButton->setGeometry(QRect(470, 60, 83, 29));
        grp_comboBox = new QComboBox(note);
        grp_comboBox->setObjectName("grp_comboBox");
        grp_comboBox->setGeometry(QRect(280, 60, 141, 28));

        retranslateUi(note);

        QMetaObject::connectSlotsByName(note);
    } // setupUi

    void retranslateUi(QDialog *note)
    {
        note->setWindowTitle(QCoreApplication::translate("note", "Dialog", nullptr));
        add_pushButton->setText(QCoreApplication::translate("note", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class note: public Ui_note {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTE_H

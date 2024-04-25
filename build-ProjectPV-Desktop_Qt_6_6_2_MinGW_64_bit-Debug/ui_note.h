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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_note
{
public:
    QTableView *gm_tableView;
    QComboBox *grp_comboBox;
    QTableView *note_tableView;
    QDoubleSpinBox *doubleSpinBox;
    QPushButton *modify_pushButton;
    QLineEdit *idmat_lineEdit;
    QLineEdit *idetu_lineEdit;
    QLineEdit *type_lineEdit;
    QTableView *moymat_tableView;
    QTableView *moygm_tableView;
    QTableView *moy_tableView;
    QTableView *pv_tableView;

    void setupUi(QDialog *note)
    {
        if (note->objectName().isEmpty())
            note->setObjectName("note");
        note->resize(961, 947);
        gm_tableView = new QTableView(note);
        gm_tableView->setObjectName("gm_tableView");
        gm_tableView->setGeometry(QRect(0, 80, 361, 391));
        gm_tableView->verticalHeader()->setVisible(false);
        grp_comboBox = new QComboBox(note);
        grp_comboBox->setObjectName("grp_comboBox");
        grp_comboBox->setGeometry(QRect(40, 50, 141, 28));
        note_tableView = new QTableView(note);
        note_tableView->setObjectName("note_tableView");
        note_tableView->setGeometry(QRect(480, 40, 481, 192));
        note_tableView->verticalHeader()->setVisible(false);
        doubleSpinBox = new QDoubleSpinBox(note);
        doubleSpinBox->setObjectName("doubleSpinBox");
        doubleSpinBox->setGeometry(QRect(810, 240, 62, 25));
        modify_pushButton = new QPushButton(note);
        modify_pushButton->setObjectName("modify_pushButton");
        modify_pushButton->setGeometry(QRect(880, 240, 80, 24));
        idmat_lineEdit = new QLineEdit(note);
        idmat_lineEdit->setObjectName("idmat_lineEdit");
        idmat_lineEdit->setGeometry(QRect(480, 240, 113, 24));
        idetu_lineEdit = new QLineEdit(note);
        idetu_lineEdit->setObjectName("idetu_lineEdit");
        idetu_lineEdit->setGeometry(QRect(600, 240, 71, 24));
        type_lineEdit = new QLineEdit(note);
        type_lineEdit->setObjectName("type_lineEdit");
        type_lineEdit->setGeometry(QRect(680, 240, 113, 28));
        moymat_tableView = new QTableView(note);
        moymat_tableView->setObjectName("moymat_tableView");
        moymat_tableView->setGeometry(QRect(370, 280, 281, 192));
        moymat_tableView->verticalHeader()->setVisible(false);
        moygm_tableView = new QTableView(note);
        moygm_tableView->setObjectName("moygm_tableView");
        moygm_tableView->setGeometry(QRect(660, 280, 291, 192));
        moygm_tableView->verticalHeader()->setVisible(false);
        moy_tableView = new QTableView(note);
        moy_tableView->setObjectName("moy_tableView");
        moy_tableView->setGeometry(QRect(190, 520, 571, 192));
        moy_tableView->verticalHeader()->setVisible(false);
        pv_tableView = new QTableView(note);
        pv_tableView->setObjectName("pv_tableView");
        pv_tableView->setGeometry(QRect(300, 720, 391, 192));
        pv_tableView->verticalHeader()->setVisible(false);

        retranslateUi(note);

        QMetaObject::connectSlotsByName(note);
    } // setupUi

    void retranslateUi(QDialog *note)
    {
        note->setWindowTitle(QCoreApplication::translate("note", "Dialog", nullptr));
        modify_pushButton->setText(QCoreApplication::translate("note", "Update", nullptr));
    } // retranslateUi

};

namespace Ui {
    class note: public Ui_note {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTE_H

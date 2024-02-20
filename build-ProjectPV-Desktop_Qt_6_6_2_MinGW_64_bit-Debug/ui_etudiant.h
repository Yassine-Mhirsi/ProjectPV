/********************************************************************************
** Form generated from reading UI file 'etudiant.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ETUDIANT_H
#define UI_ETUDIANT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_etudiant
{
public:
    QLineEdit *mail_lineEdit;
    QLabel *label_5;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label_6;
    QLineEdit *numinsc_lineEdit;
    QLineEdit *name_lineEdit;
    QLineEdit *lastname_lineEdit;
    QListView *etudiant_listView;
    QPushButton *add_pushButton;

    void setupUi(QDialog *etudiant)
    {
        if (etudiant->objectName().isEmpty())
            etudiant->setObjectName("etudiant");
        etudiant->resize(835, 514);
        mail_lineEdit = new QLineEdit(etudiant);
        mail_lineEdit->setObjectName("mail_lineEdit");
        mail_lineEdit->setGeometry(QRect(510, 220, 161, 28));
        label_5 = new QLabel(etudiant);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(470, 220, 63, 20));
        label_4 = new QLabel(etudiant);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(470, 180, 91, 20));
        label_3 = new QLabel(etudiant);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(470, 140, 63, 20));
        label_6 = new QLabel(etudiant);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(470, 260, 91, 20));
        numinsc_lineEdit = new QLineEdit(etudiant);
        numinsc_lineEdit->setObjectName("numinsc_lineEdit");
        numinsc_lineEdit->setGeometry(QRect(550, 260, 121, 28));
        name_lineEdit = new QLineEdit(etudiant);
        name_lineEdit->setObjectName("name_lineEdit");
        name_lineEdit->setGeometry(QRect(530, 140, 141, 28));
        lastname_lineEdit = new QLineEdit(etudiant);
        lastname_lineEdit->setObjectName("lastname_lineEdit");
        lastname_lineEdit->setGeometry(QRect(550, 180, 121, 28));
        etudiant_listView = new QListView(etudiant);
        etudiant_listView->setObjectName("etudiant_listView");
        etudiant_listView->setGeometry(QRect(0, -10, 301, 531));
        add_pushButton = new QPushButton(etudiant);
        add_pushButton->setObjectName("add_pushButton");
        add_pushButton->setGeometry(QRect(460, 340, 83, 29));

        retranslateUi(etudiant);

        QMetaObject::connectSlotsByName(etudiant);
    } // setupUi

    void retranslateUi(QDialog *etudiant)
    {
        etudiant->setWindowTitle(QCoreApplication::translate("etudiant", "Dialog", nullptr));
        label_5->setText(QCoreApplication::translate("etudiant", "Mail : ", nullptr));
        label_4->setText(QCoreApplication::translate("etudiant", "Last Name : ", nullptr));
        label_3->setText(QCoreApplication::translate("etudiant", "Name : ", nullptr));
        label_6->setText(QCoreApplication::translate("etudiant", "Num_Insc : ", nullptr));
        add_pushButton->setText(QCoreApplication::translate("etudiant", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class etudiant: public Ui_etudiant {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ETUDIANT_H

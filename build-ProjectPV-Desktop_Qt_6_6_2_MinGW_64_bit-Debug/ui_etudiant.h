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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_etudiant
{
public:
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QLineEdit *name_lineEdit;
    QLabel *label_4;
    QLineEdit *lastname_lineEdit;
    QLabel *label_5;
    QLineEdit *mail_lineEdit;
    QLabel *label_6;
    QLineEdit *numinsc_lineEdit;
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QLineEdit *searchbar;
    QHBoxLayout *horizontalLayout;
    QPushButton *add_pushButton;
    QPushButton *clear_pushButton;
    QPushButton *modify_pushButton;
    QPushButton *delete_pushButton;

    void setupUi(QDialog *etudiant)
    {
        if (etudiant->objectName().isEmpty())
            etudiant->setObjectName("etudiant");
        etudiant->resize(435, 672);
        verticalLayout_4 = new QVBoxLayout(etudiant);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_3 = new QLabel(etudiant);
        label_3->setObjectName("label_3");

        verticalLayout_2->addWidget(label_3);

        name_lineEdit = new QLineEdit(etudiant);
        name_lineEdit->setObjectName("name_lineEdit");

        verticalLayout_2->addWidget(name_lineEdit);

        label_4 = new QLabel(etudiant);
        label_4->setObjectName("label_4");

        verticalLayout_2->addWidget(label_4);

        lastname_lineEdit = new QLineEdit(etudiant);
        lastname_lineEdit->setObjectName("lastname_lineEdit");

        verticalLayout_2->addWidget(lastname_lineEdit);

        label_5 = new QLabel(etudiant);
        label_5->setObjectName("label_5");

        verticalLayout_2->addWidget(label_5);

        mail_lineEdit = new QLineEdit(etudiant);
        mail_lineEdit->setObjectName("mail_lineEdit");

        verticalLayout_2->addWidget(mail_lineEdit);

        label_6 = new QLabel(etudiant);
        label_6->setObjectName("label_6");

        verticalLayout_2->addWidget(label_6);

        numinsc_lineEdit = new QLineEdit(etudiant);
        numinsc_lineEdit->setObjectName("numinsc_lineEdit");

        verticalLayout_2->addWidget(numinsc_lineEdit);


        verticalLayout_3->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");

        verticalLayout_3->addLayout(verticalLayout);

        tableView = new QTableView(etudiant);
        tableView->setObjectName("tableView");
        tableView->setStyleSheet(QString::fromUtf8(""));
        tableView->horizontalHeader()->setDefaultSectionSize(140);
        tableView->verticalHeader()->setVisible(false);

        verticalLayout_3->addWidget(tableView);

        searchbar = new QLineEdit(etudiant);
        searchbar->setObjectName("searchbar");

        verticalLayout_3->addWidget(searchbar);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        add_pushButton = new QPushButton(etudiant);
        add_pushButton->setObjectName("add_pushButton");

        horizontalLayout->addWidget(add_pushButton);

        clear_pushButton = new QPushButton(etudiant);
        clear_pushButton->setObjectName("clear_pushButton");

        horizontalLayout->addWidget(clear_pushButton);

        modify_pushButton = new QPushButton(etudiant);
        modify_pushButton->setObjectName("modify_pushButton");

        horizontalLayout->addWidget(modify_pushButton);

        delete_pushButton = new QPushButton(etudiant);
        delete_pushButton->setObjectName("delete_pushButton");

        horizontalLayout->addWidget(delete_pushButton);


        verticalLayout_3->addLayout(horizontalLayout);


        verticalLayout_4->addLayout(verticalLayout_3);

        QWidget::setTabOrder(name_lineEdit, lastname_lineEdit);
        QWidget::setTabOrder(lastname_lineEdit, mail_lineEdit);
        QWidget::setTabOrder(mail_lineEdit, numinsc_lineEdit);
        QWidget::setTabOrder(numinsc_lineEdit, tableView);
        QWidget::setTabOrder(tableView, add_pushButton);
        QWidget::setTabOrder(add_pushButton, clear_pushButton);
        QWidget::setTabOrder(clear_pushButton, modify_pushButton);
        QWidget::setTabOrder(modify_pushButton, delete_pushButton);

        retranslateUi(etudiant);

        QMetaObject::connectSlotsByName(etudiant);
    } // setupUi

    void retranslateUi(QDialog *etudiant)
    {
        etudiant->setWindowTitle(QCoreApplication::translate("etudiant", "Dialog", nullptr));
        label_3->setText(QCoreApplication::translate("etudiant", "Name : ", nullptr));
        label_4->setText(QCoreApplication::translate("etudiant", "Last Name : ", nullptr));
        label_5->setText(QCoreApplication::translate("etudiant", "Mail : ", nullptr));
        label_6->setText(QCoreApplication::translate("etudiant", "Num_Insc : ", nullptr));
        add_pushButton->setText(QCoreApplication::translate("etudiant", "Save", nullptr));
        clear_pushButton->setText(QCoreApplication::translate("etudiant", "Clear", nullptr));
        modify_pushButton->setText(QCoreApplication::translate("etudiant", "Modify", nullptr));
        delete_pushButton->setText(QCoreApplication::translate("etudiant", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class etudiant: public Ui_etudiant {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ETUDIANT_H

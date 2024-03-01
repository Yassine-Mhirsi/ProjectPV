/********************************************************************************
** Form generated from reading UI file 'ListeMat.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTEMAT_H
#define UI_LISTEMAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ListeMat
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *mat_tableView;
    QHBoxLayout *horizontalLayout;
    QPushButton *delete_pushButton;
    QLineEdit *delete_lineEdit;

    void setupUi(QDialog *ListeMat)
    {
        if (ListeMat->objectName().isEmpty())
            ListeMat->setObjectName("ListeMat");
        ListeMat->resize(430, 417);
        verticalLayout = new QVBoxLayout(ListeMat);
        verticalLayout->setObjectName("verticalLayout");
        mat_tableView = new QTableView(ListeMat);
        mat_tableView->setObjectName("mat_tableView");
        mat_tableView->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(mat_tableView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        delete_pushButton = new QPushButton(ListeMat);
        delete_pushButton->setObjectName("delete_pushButton");

        horizontalLayout->addWidget(delete_pushButton);

        delete_lineEdit = new QLineEdit(ListeMat);
        delete_lineEdit->setObjectName("delete_lineEdit");
        delete_lineEdit->setMaximumSize(QSize(10, 16777215));

        horizontalLayout->addWidget(delete_lineEdit);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ListeMat);

        QMetaObject::connectSlotsByName(ListeMat);
    } // setupUi

    void retranslateUi(QDialog *ListeMat)
    {
        ListeMat->setWindowTitle(QCoreApplication::translate("ListeMat", "Dialog", nullptr));
        delete_pushButton->setText(QCoreApplication::translate("ListeMat", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ListeMat: public Ui_ListeMat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTEMAT_H

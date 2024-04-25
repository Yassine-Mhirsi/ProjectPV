/********************************************************************************
** Form generated from reading UI file 'groupemodule.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPEMODULE_H
#define UI_GROUPEMODULE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_groupemodule
{
public:
    QLineEdit *idMat_lineEdit;
    QTableView *LM_tableView;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *IdGM_label;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *IdGM_lineEdit;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *name_lineEdit;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QDoubleSpinBox *coef_doubleSpinBox;
    QPushButton *hide_pushButton;
    QPushButton *matiere_pushButton;
    QVBoxLayout *verticalLayout_3;
    QTableView *matiere_tableView;
    QPushButton *add_pushButton;
    QTableView *gm_tableView;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *delete_pushButton;
    QPushButton *modify_pushButton;
    QPushButton *clear_pushButton;

    void setupUi(QDialog *groupemodule)
    {
        if (groupemodule->objectName().isEmpty())
            groupemodule->setObjectName("groupemodule");
        groupemodule->resize(435, 741);
        idMat_lineEdit = new QLineEdit(groupemodule);
        idMat_lineEdit->setObjectName("idMat_lineEdit");
        idMat_lineEdit->setGeometry(QRect(400, 300, 41, 24));
        LM_tableView = new QTableView(groupemodule);
        LM_tableView->setObjectName("LM_tableView");
        LM_tableView->setGeometry(QRect(420, 190, 71, 81));
        LM_tableView->verticalHeader()->setVisible(false);
        layoutWidget = new QWidget(groupemodule);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 10, 411, 721));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        IdGM_label = new QLabel(layoutWidget);
        IdGM_label->setObjectName("IdGM_label");

        verticalLayout->addWidget(IdGM_label);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        IdGM_lineEdit = new QLineEdit(layoutWidget);
        IdGM_lineEdit->setObjectName("IdGM_lineEdit");
        IdGM_lineEdit->setStyleSheet(QString::fromUtf8("    border-radius: 10px; /* Adjust the value to change the roundness */\n"
"    padding: 5px; /* Adjust the padding as needed */\n"
"    border: 1px solid #555555; /* Optional: add a border */"));

        horizontalLayout_3->addWidget(IdGM_lineEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        name_lineEdit = new QLineEdit(layoutWidget);
        name_lineEdit->setObjectName("name_lineEdit");
        name_lineEdit->setStyleSheet(QString::fromUtf8("    border-radius: 10px; /* Adjust the value to change the roundness */\n"
"    padding: 5px; /* Adjust the padding as needed */\n"
"    border: 1px solid #555555; /* Optional: add a border */"));

        horizontalLayout_2->addWidget(name_lineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        coef_doubleSpinBox = new QDoubleSpinBox(layoutWidget);
        coef_doubleSpinBox->setObjectName("coef_doubleSpinBox");

        horizontalLayout->addWidget(coef_doubleSpinBox);


        verticalLayout->addLayout(horizontalLayout);

        hide_pushButton = new QPushButton(layoutWidget);
        hide_pushButton->setObjectName("hide_pushButton");

        verticalLayout->addWidget(hide_pushButton);

        matiere_pushButton = new QPushButton(layoutWidget);
        matiere_pushButton->setObjectName("matiere_pushButton");

        verticalLayout->addWidget(matiere_pushButton);


        verticalLayout_2->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        matiere_tableView = new QTableView(layoutWidget);
        matiere_tableView->setObjectName("matiere_tableView");
        matiere_tableView->verticalHeader()->setVisible(false);

        verticalLayout_3->addWidget(matiere_tableView);

        add_pushButton = new QPushButton(layoutWidget);
        add_pushButton->setObjectName("add_pushButton");

        verticalLayout_3->addWidget(add_pushButton);


        verticalLayout_2->addLayout(verticalLayout_3);

        gm_tableView = new QTableView(layoutWidget);
        gm_tableView->setObjectName("gm_tableView");
        gm_tableView->verticalHeader()->setVisible(false);

        verticalLayout_2->addWidget(gm_tableView);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        delete_pushButton = new QPushButton(layoutWidget);
        delete_pushButton->setObjectName("delete_pushButton");

        horizontalLayout_4->addWidget(delete_pushButton);

        modify_pushButton = new QPushButton(layoutWidget);
        modify_pushButton->setObjectName("modify_pushButton");

        horizontalLayout_4->addWidget(modify_pushButton);

        clear_pushButton = new QPushButton(layoutWidget);
        clear_pushButton->setObjectName("clear_pushButton");

        horizontalLayout_4->addWidget(clear_pushButton);


        verticalLayout_2->addLayout(horizontalLayout_4);

        QWidget::setTabOrder(IdGM_lineEdit, name_lineEdit);
        QWidget::setTabOrder(name_lineEdit, coef_doubleSpinBox);
        QWidget::setTabOrder(coef_doubleSpinBox, matiere_pushButton);
        QWidget::setTabOrder(matiere_pushButton, hide_pushButton);
        QWidget::setTabOrder(hide_pushButton, gm_tableView);
        QWidget::setTabOrder(gm_tableView, matiere_tableView);
        QWidget::setTabOrder(matiere_tableView, add_pushButton);
        QWidget::setTabOrder(add_pushButton, delete_pushButton);
        QWidget::setTabOrder(delete_pushButton, modify_pushButton);
        QWidget::setTabOrder(modify_pushButton, clear_pushButton);
        QWidget::setTabOrder(clear_pushButton, LM_tableView);
        QWidget::setTabOrder(LM_tableView, idMat_lineEdit);

        retranslateUi(groupemodule);

        QMetaObject::connectSlotsByName(groupemodule);
    } // setupUi

    void retranslateUi(QDialog *groupemodule)
    {
        groupemodule->setWindowTitle(QCoreApplication::translate("groupemodule", "Dialog", nullptr));
        IdGM_label->setText(QCoreApplication::translate("groupemodule", "IdGM", nullptr));
        label->setText(QCoreApplication::translate("groupemodule", "NomGM", nullptr));
        label_2->setText(QCoreApplication::translate("groupemodule", "CoefGM", nullptr));
        hide_pushButton->setText(QCoreApplication::translate("groupemodule", "Hide Matiere", nullptr));
        matiere_pushButton->setText(QCoreApplication::translate("groupemodule", "Show Matiere", nullptr));
        add_pushButton->setText(QCoreApplication::translate("groupemodule", "Add Selected Matiere", nullptr));
        delete_pushButton->setText(QCoreApplication::translate("groupemodule", "Delete", nullptr));
        modify_pushButton->setText(QCoreApplication::translate("groupemodule", "Update", nullptr));
        clear_pushButton->setText(QCoreApplication::translate("groupemodule", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class groupemodule: public Ui_groupemodule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPEMODULE_H

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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_groupemodule
{
public:
    QTableView *matiere_tableView;
    QTableView *gm_tableView;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QDoubleSpinBox *coef_doubleSpinBox;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *name_lineEdit;
    QPushButton *add_pushButton;
    QPushButton *matiere_pushButton;
    QLineEdit *idMat_lineEdit;
    QTableView *LM_tableView;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *IdGM_label;
    QLineEdit *IdGM_lineEdit;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *delete_pushButton;
    QPushButton *modify_pushButton;
    QPushButton *clear_pushButton;

    void setupUi(QDialog *groupemodule)
    {
        if (groupemodule->objectName().isEmpty())
            groupemodule->setObjectName("groupemodule");
        groupemodule->resize(752, 486);
        matiere_tableView = new QTableView(groupemodule);
        matiere_tableView->setObjectName("matiere_tableView");
        matiere_tableView->setGeometry(QRect(395, 10, 341, 221));
        matiere_tableView->verticalHeader()->setVisible(false);
        gm_tableView = new QTableView(groupemodule);
        gm_tableView->setObjectName("gm_tableView");
        gm_tableView->setGeometry(QRect(20, 240, 371, 201));
        gm_tableView->verticalHeader()->setVisible(false);
        layoutWidget = new QWidget(groupemodule);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(140, 140, 106, 27));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        coef_doubleSpinBox = new QDoubleSpinBox(layoutWidget);
        coef_doubleSpinBox->setObjectName("coef_doubleSpinBox");

        horizontalLayout->addWidget(coef_doubleSpinBox);

        layoutWidget1 = new QWidget(groupemodule);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(140, 90, 162, 26));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName("label");

        horizontalLayout_2->addWidget(label);

        name_lineEdit = new QLineEdit(layoutWidget1);
        name_lineEdit->setObjectName("name_lineEdit");

        horizontalLayout_2->addWidget(name_lineEdit);

        add_pushButton = new QPushButton(groupemodule);
        add_pushButton->setObjectName("add_pushButton");
        add_pushButton->setGeometry(QRect(680, 240, 51, 24));
        matiere_pushButton = new QPushButton(groupemodule);
        matiere_pushButton->setObjectName("matiere_pushButton");
        matiere_pushButton->setGeometry(QRect(150, 190, 80, 24));
        idMat_lineEdit = new QLineEdit(groupemodule);
        idMat_lineEdit->setObjectName("idMat_lineEdit");
        idMat_lineEdit->setGeometry(QRect(510, 240, 113, 24));
        LM_tableView = new QTableView(groupemodule);
        LM_tableView->setObjectName("LM_tableView");
        LM_tableView->setGeometry(QRect(450, 270, 256, 201));
        LM_tableView->verticalHeader()->setVisible(false);
        layoutWidget2 = new QWidget(groupemodule);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(140, 50, 165, 26));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        IdGM_label = new QLabel(layoutWidget2);
        IdGM_label->setObjectName("IdGM_label");

        horizontalLayout_3->addWidget(IdGM_label);

        IdGM_lineEdit = new QLineEdit(layoutWidget2);
        IdGM_lineEdit->setObjectName("IdGM_lineEdit");

        horizontalLayout_3->addWidget(IdGM_lineEdit);

        layoutWidget3 = new QWidget(groupemodule);
        layoutWidget3->setObjectName("layoutWidget3");
        layoutWidget3->setGeometry(QRect(70, 450, 254, 26));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        delete_pushButton = new QPushButton(layoutWidget3);
        delete_pushButton->setObjectName("delete_pushButton");

        horizontalLayout_4->addWidget(delete_pushButton);

        modify_pushButton = new QPushButton(layoutWidget3);
        modify_pushButton->setObjectName("modify_pushButton");

        horizontalLayout_4->addWidget(modify_pushButton);

        clear_pushButton = new QPushButton(layoutWidget3);
        clear_pushButton->setObjectName("clear_pushButton");

        horizontalLayout_4->addWidget(clear_pushButton);


        retranslateUi(groupemodule);

        QMetaObject::connectSlotsByName(groupemodule);
    } // setupUi

    void retranslateUi(QDialog *groupemodule)
    {
        groupemodule->setWindowTitle(QCoreApplication::translate("groupemodule", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("groupemodule", "CoefGM", nullptr));
        label->setText(QCoreApplication::translate("groupemodule", "NomGM", nullptr));
        add_pushButton->setText(QCoreApplication::translate("groupemodule", "Add", nullptr));
        matiere_pushButton->setText(QCoreApplication::translate("groupemodule", "Show Matiere", nullptr));
        IdGM_label->setText(QCoreApplication::translate("groupemodule", "IdGM", nullptr));
        delete_pushButton->setText(QCoreApplication::translate("groupemodule", "delete", nullptr));
        modify_pushButton->setText(QCoreApplication::translate("groupemodule", "update", nullptr));
        clear_pushButton->setText(QCoreApplication::translate("groupemodule", "clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class groupemodule: public Ui_groupemodule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPEMODULE_H

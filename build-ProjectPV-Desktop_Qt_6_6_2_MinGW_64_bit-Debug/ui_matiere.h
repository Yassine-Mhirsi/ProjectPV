/********************************************************************************
** Form generated from reading UI file 'matiere.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATIERE_H
#define UI_MATIERE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_matiere
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_4;
    QLineEdit *searchbar;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *id_label;
    QLineEdit *id_lineEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *name_lineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label_3;
    QComboBox *comboBox;
    QPushButton *add_teacher;
    QHBoxLayout *horizontalLayout_3;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *add_pushButton;
    QPushButton *delete_pushButton;
    QPushButton *modify_pushButton;
    QPushButton *clear_pushButton;

    void setupUi(QDialog *matiere)
    {
        if (matiere->objectName().isEmpty())
            matiere->setObjectName("matiere");
        matiere->resize(663, 449);
        verticalLayout_2 = new QVBoxLayout(matiere);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_4 = new QLabel(matiere);
        label_4->setObjectName("label_4");
        label_4->setMinimumSize(QSize(450, 0));

        horizontalLayout_7->addWidget(label_4);

        searchbar = new QLineEdit(matiere);
        searchbar->setObjectName("searchbar");
        searchbar->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border-radius: 10px; /* Adjust the value to change the roundness */\n"
"    padding: 5px; /* Adjust the padding as needed */\n"
"    border: 1px solid #555555; /* Optional: add a border */\n"
"}\n"
""));

        horizontalLayout_7->addWidget(searchbar);


        verticalLayout_2->addLayout(horizontalLayout_7);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        id_label = new QLabel(matiere);
        id_label->setObjectName("id_label");

        horizontalLayout_2->addWidget(id_label);

        id_lineEdit = new QLineEdit(matiere);
        id_lineEdit->setObjectName("id_lineEdit");
        id_lineEdit->setEnabled(false);
        id_lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border-radius: 10px; /* Adjust the value to change the roundness */\n"
"    padding: 5px; /* Adjust the padding as needed */\n"
"    border: 1px solid #555555; /* Optional: add a border */\n"
"}\n"
""));

        horizontalLayout_2->addWidget(id_lineEdit);


        horizontalLayout_5->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(matiere);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        name_lineEdit = new QLineEdit(matiere);
        name_lineEdit->setObjectName("name_lineEdit");
        name_lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border-radius: 10px; /* Adjust the value to change the roundness */\n"
"    padding: 5px; /* Adjust the padding as needed */\n"
"    border: 1px solid #555555; /* Optional: add a border */\n"
"}\n"
""));

        horizontalLayout->addWidget(name_lineEdit);


        horizontalLayout_5->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_2 = new QLabel(matiere);
        label_2->setObjectName("label_2");

        horizontalLayout_4->addWidget(label_2);

        doubleSpinBox = new QDoubleSpinBox(matiere);
        doubleSpinBox->setObjectName("doubleSpinBox");
        doubleSpinBox->setMinimum(1.000000000000000);
        doubleSpinBox->setMaximum(10.000000000000000);
        doubleSpinBox->setSingleStep(0.500000000000000);

        horizontalLayout_4->addWidget(doubleSpinBox);

        label_3 = new QLabel(matiere);
        label_3->setObjectName("label_3");

        horizontalLayout_4->addWidget(label_3);

        comboBox = new QComboBox(matiere);
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border-radius: 10px; /* Adjust the value to change the roundness */\n"
"    padding: 5px; /* Adjust the padding as needed */\n"
"    border: 1px solid #555555; /* Optional: add a border */\n"
"    min-width: 6em;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 20px;\n"
"\n"
"\n"
"    border-left-width: 1px;\n"
"    border-left-color: darkgray;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 10px;\n"
"    border-bottom-right-radius: 10px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(E:/documents/cpp/QtProjectPV/p/ProjectPV/assets/arrow-down.svg);\n"
"    width: 16px;\n"
"    height: 16px;\n"
"	border-right-radius: 10px\n"
"}\n"
"\n"
"\n"
""));

        horizontalLayout_4->addWidget(comboBox);

        add_teacher = new QPushButton(matiere);
        add_teacher->setObjectName("add_teacher");
        add_teacher->setMaximumSize(QSize(27, 27));
        add_teacher->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border-radius: 10px; /* Adjust the value to change the roundness */\n"
"    padding: 5px; /* Adjust the padding as needed */\n"
"    border: 1px solid #555555; /* Optional: add a border */\n"
"}\n"
"\n"
"QPushButton:hover { color: white; background-color: lightgray; }\n"
""));

        horizontalLayout_4->addWidget(add_teacher);


        horizontalLayout_5->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");

        horizontalLayout_5->addLayout(horizontalLayout_3);


        verticalLayout->addLayout(horizontalLayout_5);

        tableView = new QTableView(matiere);
        tableView->setObjectName("tableView");
        tableView->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(tableView);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        add_pushButton = new QPushButton(matiere);
        add_pushButton->setObjectName("add_pushButton");

        horizontalLayout_6->addWidget(add_pushButton);

        delete_pushButton = new QPushButton(matiere);
        delete_pushButton->setObjectName("delete_pushButton");

        horizontalLayout_6->addWidget(delete_pushButton);

        modify_pushButton = new QPushButton(matiere);
        modify_pushButton->setObjectName("modify_pushButton");

        horizontalLayout_6->addWidget(modify_pushButton);

        clear_pushButton = new QPushButton(matiere);
        clear_pushButton->setObjectName("clear_pushButton");

        horizontalLayout_6->addWidget(clear_pushButton);


        verticalLayout->addLayout(horizontalLayout_6);


        verticalLayout_2->addLayout(verticalLayout);

        QWidget::setTabOrder(searchbar, id_lineEdit);
        QWidget::setTabOrder(id_lineEdit, name_lineEdit);
        QWidget::setTabOrder(name_lineEdit, doubleSpinBox);
        QWidget::setTabOrder(doubleSpinBox, comboBox);
        QWidget::setTabOrder(comboBox, tableView);
        QWidget::setTabOrder(tableView, add_pushButton);
        QWidget::setTabOrder(add_pushButton, delete_pushButton);
        QWidget::setTabOrder(delete_pushButton, modify_pushButton);
        QWidget::setTabOrder(modify_pushButton, clear_pushButton);

        retranslateUi(matiere);

        QMetaObject::connectSlotsByName(matiere);
    } // setupUi

    void retranslateUi(QDialog *matiere)
    {
        matiere->setWindowTitle(QCoreApplication::translate("matiere", "Dialog", nullptr));
        label_4->setText(QString());
        id_label->setText(QCoreApplication::translate("matiere", "IdMat :", nullptr));
        label->setText(QCoreApplication::translate("matiere", "Name :", nullptr));
        label_2->setText(QCoreApplication::translate("matiere", "Coef :", nullptr));
        label_3->setText(QCoreApplication::translate("matiere", "Teacher :", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("matiere", "Select Teacher", nullptr));

        add_teacher->setText(QString());
        add_pushButton->setText(QCoreApplication::translate("matiere", "Add", nullptr));
        delete_pushButton->setText(QCoreApplication::translate("matiere", "Delete", nullptr));
        modify_pushButton->setText(QCoreApplication::translate("matiere", "Update", nullptr));
        clear_pushButton->setText(QCoreApplication::translate("matiere", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class matiere: public Ui_matiere {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATIERE_H

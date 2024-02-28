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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_matiere
{
public:
    QLineEdit *name_lineEdit;
    QComboBox *comboBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox;

    void setupUi(QDialog *matiere)
    {
        if (matiere->objectName().isEmpty())
            matiere->setObjectName("matiere");
        matiere->resize(649, 449);
        name_lineEdit = new QLineEdit(matiere);
        name_lineEdit->setObjectName("name_lineEdit");
        name_lineEdit->setGeometry(QRect(170, 90, 113, 24));
        comboBox = new QComboBox(matiere);
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(170, 170, 111, 24));
        label = new QLabel(matiere);
        label->setObjectName("label");
        label->setGeometry(QRect(100, 90, 49, 16));
        label_2 = new QLabel(matiere);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(100, 130, 49, 16));
        label_3 = new QLabel(matiere);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(100, 170, 49, 16));
        doubleSpinBox = new QDoubleSpinBox(matiere);
        doubleSpinBox->setObjectName("doubleSpinBox");
        doubleSpinBox->setGeometry(QRect(170, 130, 62, 25));
        doubleSpinBox->setMinimum(1.000000000000000);

        retranslateUi(matiere);

        QMetaObject::connectSlotsByName(matiere);
    } // setupUi

    void retranslateUi(QDialog *matiere)
    {
        matiere->setWindowTitle(QCoreApplication::translate("matiere", "Dialog", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("matiere", "Select Teacher", nullptr));

        label->setText(QCoreApplication::translate("matiere", "Name", nullptr));
        label_2->setText(QCoreApplication::translate("matiere", "Coef", nullptr));
        label_3->setText(QCoreApplication::translate("matiere", "Teacher", nullptr));
    } // retranslateUi

};

namespace Ui {
    class matiere: public Ui_matiere {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATIERE_H

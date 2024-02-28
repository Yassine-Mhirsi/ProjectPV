/********************************************************************************
** Form generated from reading UI file 'groupe.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPE_H
#define UI_GROUPE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_groupe
{
public:

    void setupUi(QDialog *groupe)
    {
        if (groupe->objectName().isEmpty())
            groupe->setObjectName("groupe");
        groupe->resize(400, 300);

        retranslateUi(groupe);

        QMetaObject::connectSlotsByName(groupe);
    } // setupUi

    void retranslateUi(QDialog *groupe)
    {
        groupe->setWindowTitle(QCoreApplication::translate("groupe", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class groupe: public Ui_groupe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPE_H

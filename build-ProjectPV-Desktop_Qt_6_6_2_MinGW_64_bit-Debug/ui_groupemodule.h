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

QT_BEGIN_NAMESPACE

class Ui_groupemodule
{
public:

    void setupUi(QDialog *groupemodule)
    {
        if (groupemodule->objectName().isEmpty())
            groupemodule->setObjectName("groupemodule");
        groupemodule->resize(400, 300);

        retranslateUi(groupemodule);

        QMetaObject::connectSlotsByName(groupemodule);
    } // setupUi

    void retranslateUi(QDialog *groupemodule)
    {
        groupemodule->setWindowTitle(QCoreApplication::translate("groupemodule", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class groupemodule: public Ui_groupemodule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPEMODULE_H

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
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_note
{
public:

    void setupUi(QDialog *note)
    {
        if (note->objectName().isEmpty())
            note->setObjectName("note");
        note->resize(400, 300);

        retranslateUi(note);

        QMetaObject::connectSlotsByName(note);
    } // setupUi

    void retranslateUi(QDialog *note)
    {
        note->setWindowTitle(QCoreApplication::translate("note", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class note: public Ui_note {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTE_H

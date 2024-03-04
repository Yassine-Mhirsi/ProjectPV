/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *etudiant_pushButton;
    QPushButton *pushButton;
    QPushButton *matiere_pushButton;
    QPushButton *gm_pushButton;
    QPushButton *grp_pushButton;
    QPushButton *note_pushButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(835, 514);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        etudiant_pushButton = new QPushButton(centralwidget);
        etudiant_pushButton->setObjectName("etudiant_pushButton");
        etudiant_pushButton->setGeometry(QRect(100, 110, 83, 29));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(220, 270, 80, 24));
        matiere_pushButton = new QPushButton(centralwidget);
        matiere_pushButton->setObjectName("matiere_pushButton");
        matiere_pushButton->setGeometry(QRect(400, 210, 80, 24));
        gm_pushButton = new QPushButton(centralwidget);
        gm_pushButton->setObjectName("gm_pushButton");
        gm_pushButton->setGeometry(QRect(430, 90, 101, 24));
        grp_pushButton = new QPushButton(centralwidget);
        grp_pushButton->setObjectName("grp_pushButton");
        grp_pushButton->setGeometry(QRect(430, 330, 83, 29));
        note_pushButton = new QPushButton(centralwidget);
        note_pushButton->setObjectName("note_pushButton");
        note_pushButton->setGeometry(QRect(550, 260, 83, 29));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        etudiant_pushButton->setText(QCoreApplication::translate("MainWindow", "Students", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Prof", nullptr));
        matiere_pushButton->setText(QCoreApplication::translate("MainWindow", "Matiere", nullptr));
        gm_pushButton->setText(QCoreApplication::translate("MainWindow", "groupemodule", nullptr));
        grp_pushButton->setText(QCoreApplication::translate("MainWindow", "Groupe", nullptr));
        note_pushButton->setText(QCoreApplication::translate("MainWindow", "Note", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *grp_pushButton;
    QPushButton *matiere_pushButton;
    QPushButton *etudiant_pushButton;
    QPushButton *note_pushButton;
    QPushButton *gm_pushButton;
    QPushButton *ens_pushButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1023, 646);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(10, 20, 1001, 611));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setHorizontalSpacing(7);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        grp_pushButton = new QPushButton(gridLayoutWidget);
        grp_pushButton->setObjectName("grp_pushButton");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(grp_pushButton->sizePolicy().hasHeightForWidth());
        grp_pushButton->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(18);
        grp_pushButton->setFont(font);

        gridLayout->addWidget(grp_pushButton, 2, 1, 1, 1);

        matiere_pushButton = new QPushButton(gridLayoutWidget);
        matiere_pushButton->setObjectName("matiere_pushButton");
        sizePolicy.setHeightForWidth(matiere_pushButton->sizePolicy().hasHeightForWidth());
        matiere_pushButton->setSizePolicy(sizePolicy);
        matiere_pushButton->setFont(font);

        gridLayout->addWidget(matiere_pushButton, 1, 1, 1, 1);

        etudiant_pushButton = new QPushButton(gridLayoutWidget);
        etudiant_pushButton->setObjectName("etudiant_pushButton");
        sizePolicy.setHeightForWidth(etudiant_pushButton->sizePolicy().hasHeightForWidth());
        etudiant_pushButton->setSizePolicy(sizePolicy);
        etudiant_pushButton->setFont(font);
        etudiant_pushButton->setAutoDefault(false);

        gridLayout->addWidget(etudiant_pushButton, 0, 1, 1, 1);

        note_pushButton = new QPushButton(gridLayoutWidget);
        note_pushButton->setObjectName("note_pushButton");
        sizePolicy.setHeightForWidth(note_pushButton->sizePolicy().hasHeightForWidth());
        note_pushButton->setSizePolicy(sizePolicy);
        note_pushButton->setFont(font);

        gridLayout->addWidget(note_pushButton, 2, 2, 1, 1);

        gm_pushButton = new QPushButton(gridLayoutWidget);
        gm_pushButton->setObjectName("gm_pushButton");
        sizePolicy.setHeightForWidth(gm_pushButton->sizePolicy().hasHeightForWidth());
        gm_pushButton->setSizePolicy(sizePolicy);
        gm_pushButton->setFont(font);

        gridLayout->addWidget(gm_pushButton, 1, 2, 1, 1);

        ens_pushButton = new QPushButton(gridLayoutWidget);
        ens_pushButton->setObjectName("ens_pushButton");
        sizePolicy.setHeightForWidth(ens_pushButton->sizePolicy().hasHeightForWidth());
        ens_pushButton->setSizePolicy(sizePolicy);
        ens_pushButton->setFont(font);

        gridLayout->addWidget(ens_pushButton, 0, 2, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        grp_pushButton->setText(QCoreApplication::translate("MainWindow", "Groupe", nullptr));
        matiere_pushButton->setText(QCoreApplication::translate("MainWindow", "Matiere", nullptr));
        etudiant_pushButton->setText(QCoreApplication::translate("MainWindow", "Students", nullptr));
        note_pushButton->setText(QCoreApplication::translate("MainWindow", "Note", nullptr));
        gm_pushButton->setText(QCoreApplication::translate("MainWindow", "groupemodule", nullptr));
        ens_pushButton->setText(QCoreApplication::translate("MainWindow", "Prof", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

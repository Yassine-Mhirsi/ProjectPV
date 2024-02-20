/********************************************************************************
** Form generated from reading UI file 'welcome.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOME_H
#define UI_WELCOME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Welcome
{
public:
    QLabel *title;
    QLabel *Pi;
    QPushButton *welcome;
    QLabel *status;

    void setupUi(QWidget *Welcome)
    {
        if (Welcome->objectName().isEmpty())
            Welcome->setObjectName("Welcome");
        Welcome->resize(835, 514);
        title = new QLabel(Welcome);
        title->setObjectName("title");
        title->setGeometry(QRect(170, 240, 481, 41));
        title->setLayoutDirection(Qt::LeftToRight);
        title->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	font-size:30px;\n"
"}"));
        Pi = new QLabel(Welcome);
        Pi->setObjectName("Pi");
        Pi->setGeometry(QRect(230, 110, 351, 131));
        Pi->setLayoutDirection(Qt::LeftToRight);
        Pi->setFrameShape(QFrame::NoFrame);
        Pi->setTextFormat(Qt::AutoText);
        Pi->setPixmap(QPixmap(QString::fromUtf8("../assets/logopi.png")));
        Pi->setScaledContents(true);
        Pi->setAlignment(Qt::AlignCenter);
        welcome = new QPushButton(Welcome);
        welcome->setObjectName("welcome");
        welcome->setGeometry(QRect(340, 310, 131, 61));
        welcome->setLayoutDirection(Qt::LeftToRight);
        welcome->setAutoFillBackground(false);
        welcome->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font: 14pt \"Segoe UI\";\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"	border-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"}"));
        welcome->setCheckable(false);
        welcome->setChecked(false);
        welcome->setAutoDefault(false);
        welcome->setFlat(false);
        status = new QLabel(Welcome);
        status->setObjectName("status");
        status->setGeometry(QRect(20, 480, 81, 20));

        retranslateUi(Welcome);

        welcome->setDefault(false);


        QMetaObject::connectSlotsByName(Welcome);
    } // setupUi

    void retranslateUi(QWidget *Welcome)
    {
        Welcome->setWindowTitle(QCoreApplication::translate("Welcome", "Form", nullptr));
        title->setText(QCoreApplication::translate("Welcome", "Student Grades Mangement System", nullptr));
        Pi->setText(QString());
        welcome->setText(QCoreApplication::translate("Welcome", "Welcome", nullptr));
        status->setText(QCoreApplication::translate("Welcome", "[+]Status", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Welcome: public Ui_Welcome {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOME_H

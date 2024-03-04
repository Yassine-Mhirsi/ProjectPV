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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_groupe
{
public:
    QTableView *gm_tableView;
    QTableView *etu_tableView;
    QTableView *grp_tableView;
    QPushButton *addgm_pushButton;
    QPushButton *addetu_pushButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *idGRP_lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QComboBox *niv_comboBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QComboBox *dip_comboBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QComboBox *spec_comboBox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QComboBox *numg_comboBox;
    QTableView *LG_tableView;
    QLineEdit *idgm_lineEdit;
    QLineEdit *idetu_lineEdit;
    QPushButton *modify_pushButton;
    QPushButton *delete_pushButton;

    void setupUi(QDialog *groupe)
    {
        if (groupe->objectName().isEmpty())
            groupe->setObjectName("groupe");
        groupe->resize(896, 576);
        gm_tableView = new QTableView(groupe);
        gm_tableView->setObjectName("gm_tableView");
        gm_tableView->setGeometry(QRect(585, 40, 291, 192));
        gm_tableView->verticalHeader()->setVisible(false);
        etu_tableView = new QTableView(groupe);
        etu_tableView->setObjectName("etu_tableView");
        etu_tableView->setGeometry(QRect(585, 310, 291, 192));
        etu_tableView->verticalHeader()->setVisible(false);
        grp_tableView = new QTableView(groupe);
        grp_tableView->setObjectName("grp_tableView");
        grp_tableView->setGeometry(QRect(20, 330, 511, 192));
        grp_tableView->verticalHeader()->setVisible(false);
        addgm_pushButton = new QPushButton(groupe);
        addgm_pushButton->setObjectName("addgm_pushButton");
        addgm_pushButton->setGeometry(QRect(790, 240, 80, 24));
        addetu_pushButton = new QPushButton(groupe);
        addetu_pushButton->setObjectName("addetu_pushButton");
        addetu_pushButton->setGeometry(QRect(790, 510, 80, 24));
        layoutWidget = new QWidget(groupe);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(110, 80, 221, 180));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        idGRP_lineEdit = new QLineEdit(layoutWidget);
        idGRP_lineEdit->setObjectName("idGRP_lineEdit");

        horizontalLayout->addWidget(idGRP_lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName("label_5");

        horizontalLayout_2->addWidget(label_5);

        niv_comboBox = new QComboBox(layoutWidget);
        niv_comboBox->addItem(QString());
        niv_comboBox->addItem(QString());
        niv_comboBox->addItem(QString());
        niv_comboBox->addItem(QString());
        niv_comboBox->addItem(QString());
        niv_comboBox->addItem(QString());
        niv_comboBox->setObjectName("niv_comboBox");

        horizontalLayout_2->addWidget(niv_comboBox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");

        horizontalLayout_3->addWidget(label_4);

        dip_comboBox = new QComboBox(layoutWidget);
        dip_comboBox->addItem(QString());
        dip_comboBox->addItem(QString());
        dip_comboBox->addItem(QString());
        dip_comboBox->addItem(QString());
        dip_comboBox->setObjectName("dip_comboBox");

        horizontalLayout_3->addWidget(dip_comboBox);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        horizontalLayout_4->addWidget(label_3);

        spec_comboBox = new QComboBox(layoutWidget);
        spec_comboBox->addItem(QString());
        spec_comboBox->addItem(QString());
        spec_comboBox->addItem(QString());
        spec_comboBox->addItem(QString());
        spec_comboBox->setObjectName("spec_comboBox");

        horizontalLayout_4->addWidget(spec_comboBox);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        horizontalLayout_5->addWidget(label_2);

        numg_comboBox = new QComboBox(layoutWidget);
        numg_comboBox->addItem(QString());
        numg_comboBox->addItem(QString());
        numg_comboBox->addItem(QString());
        numg_comboBox->addItem(QString());
        numg_comboBox->setObjectName("numg_comboBox");

        horizontalLayout_5->addWidget(numg_comboBox);


        verticalLayout->addLayout(horizontalLayout_5);

        LG_tableView = new QTableView(groupe);
        LG_tableView->setObjectName("LG_tableView");
        LG_tableView->setGeometry(QRect(425, 70, 121, 192));
        LG_tableView->verticalHeader()->setVisible(false);
        idgm_lineEdit = new QLineEdit(groupe);
        idgm_lineEdit->setObjectName("idgm_lineEdit");
        idgm_lineEdit->setGeometry(QRect(660, 240, 113, 28));
        idetu_lineEdit = new QLineEdit(groupe);
        idetu_lineEdit->setObjectName("idetu_lineEdit");
        idetu_lineEdit->setGeometry(QRect(650, 510, 113, 28));
        modify_pushButton = new QPushButton(groupe);
        modify_pushButton->setObjectName("modify_pushButton");
        modify_pushButton->setGeometry(QRect(50, 530, 83, 29));
        delete_pushButton = new QPushButton(groupe);
        delete_pushButton->setObjectName("delete_pushButton");
        delete_pushButton->setGeometry(QRect(150, 530, 83, 29));

        retranslateUi(groupe);

        QMetaObject::connectSlotsByName(groupe);
    } // setupUi

    void retranslateUi(QDialog *groupe)
    {
        groupe->setWindowTitle(QCoreApplication::translate("groupe", "Dialog", nullptr));
        addgm_pushButton->setText(QCoreApplication::translate("groupe", "add", nullptr));
        addetu_pushButton->setText(QCoreApplication::translate("groupe", "add", nullptr));
        label->setText(QCoreApplication::translate("groupe", "IdGRP", nullptr));
        label_5->setText(QCoreApplication::translate("groupe", "Niveau", nullptr));
        niv_comboBox->setItemText(0, QCoreApplication::translate("groupe", "Select...", nullptr));
        niv_comboBox->setItemText(1, QCoreApplication::translate("groupe", "1ere", nullptr));
        niv_comboBox->setItemText(2, QCoreApplication::translate("groupe", "2eme", nullptr));
        niv_comboBox->setItemText(3, QCoreApplication::translate("groupe", "3eme", nullptr));
        niv_comboBox->setItemText(4, QCoreApplication::translate("groupe", "4eme", nullptr));
        niv_comboBox->setItemText(5, QCoreApplication::translate("groupe", "5eme", nullptr));

        label_4->setText(QCoreApplication::translate("groupe", "Dipl\303\264me", nullptr));
        dip_comboBox->setItemText(0, QCoreApplication::translate("groupe", "Select...", nullptr));
        dip_comboBox->setItemText(1, QCoreApplication::translate("groupe", "ING", nullptr));
        dip_comboBox->setItemText(2, QCoreApplication::translate("groupe", "Master", nullptr));
        dip_comboBox->setItemText(3, QCoreApplication::translate("groupe", "LMD", nullptr));

        label_3->setText(QCoreApplication::translate("groupe", "Sp\303\251cialit\303\251", nullptr));
        spec_comboBox->setItemText(0, QCoreApplication::translate("groupe", "Select...", nullptr));
        spec_comboBox->setItemText(1, QCoreApplication::translate("groupe", "INF", nullptr));
        spec_comboBox->setItemText(2, QCoreApplication::translate("groupe", "INDUS", nullptr));
        spec_comboBox->setItemText(3, QCoreApplication::translate("groupe", "MATH", nullptr));

        label_2->setText(QCoreApplication::translate("groupe", "Num_G", nullptr));
        numg_comboBox->setItemText(0, QCoreApplication::translate("groupe", "Select...", nullptr));
        numg_comboBox->setItemText(1, QCoreApplication::translate("groupe", "1", nullptr));
        numg_comboBox->setItemText(2, QCoreApplication::translate("groupe", "2", nullptr));
        numg_comboBox->setItemText(3, QCoreApplication::translate("groupe", "3", nullptr));

        modify_pushButton->setText(QCoreApplication::translate("groupe", "Modify", nullptr));
        delete_pushButton->setText(QCoreApplication::translate("groupe", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class groupe: public Ui_groupe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPE_H

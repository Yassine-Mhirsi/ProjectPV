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
    QTableView *LG_tableView;
    QLineEdit *idgm_lineEdit;
    QLineEdit *idetu_lineEdit;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
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
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *showgm_pushButton;
    QPushButton *showetu_pushButton;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *hidegm_pushButton;
    QPushButton *hideetu_pushButton;
    QLabel *gm_label;
    QTableView *gm_tableView;
    QPushButton *addgm_pushButton;
    QVBoxLayout *verticalLayout_4;
    QLabel *etu_label;
    QTableView *etu_tableView;
    QPushButton *addetu_pushButton;
    QLabel *label_8;
    QTableView *grp_tableView;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *modify_pushButton;
    QPushButton *delete_pushButton;

    void setupUi(QDialog *groupe)
    {
        if (groupe->objectName().isEmpty())
            groupe->setObjectName("groupe");
        groupe->resize(435, 903);
        LG_tableView = new QTableView(groupe);
        LG_tableView->setObjectName("LG_tableView");
        LG_tableView->setGeometry(QRect(430, 50, 121, 192));
        LG_tableView->verticalHeader()->setVisible(false);
        idgm_lineEdit = new QLineEdit(groupe);
        idgm_lineEdit->setObjectName("idgm_lineEdit");
        idgm_lineEdit->setGeometry(QRect(440, 250, 113, 28));
        idetu_lineEdit = new QLineEdit(groupe);
        idetu_lineEdit->setObjectName("idetu_lineEdit");
        idetu_lineEdit->setGeometry(QRect(440, 290, 113, 28));
        layoutWidget = new QWidget(groupe);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(7, 12, 421, 881));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
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


        verticalLayout_2->addLayout(verticalLayout);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        showgm_pushButton = new QPushButton(layoutWidget);
        showgm_pushButton->setObjectName("showgm_pushButton");

        horizontalLayout_7->addWidget(showgm_pushButton);

        showetu_pushButton = new QPushButton(layoutWidget);
        showetu_pushButton->setObjectName("showetu_pushButton");

        horizontalLayout_7->addWidget(showetu_pushButton);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        hidegm_pushButton = new QPushButton(layoutWidget);
        hidegm_pushButton->setObjectName("hidegm_pushButton");

        horizontalLayout_8->addWidget(hidegm_pushButton);

        hideetu_pushButton = new QPushButton(layoutWidget);
        hideetu_pushButton->setObjectName("hideetu_pushButton");

        horizontalLayout_8->addWidget(hideetu_pushButton);


        verticalLayout_3->addLayout(horizontalLayout_8);

        gm_label = new QLabel(layoutWidget);
        gm_label->setObjectName("gm_label");

        verticalLayout_3->addWidget(gm_label);

        gm_tableView = new QTableView(layoutWidget);
        gm_tableView->setObjectName("gm_tableView");
        gm_tableView->verticalHeader()->setVisible(false);

        verticalLayout_3->addWidget(gm_tableView);

        addgm_pushButton = new QPushButton(layoutWidget);
        addgm_pushButton->setObjectName("addgm_pushButton");

        verticalLayout_3->addWidget(addgm_pushButton);


        verticalLayout_5->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        etu_label = new QLabel(layoutWidget);
        etu_label->setObjectName("etu_label");

        verticalLayout_4->addWidget(etu_label);

        etu_tableView = new QTableView(layoutWidget);
        etu_tableView->setObjectName("etu_tableView");
        etu_tableView->verticalHeader()->setVisible(false);

        verticalLayout_4->addWidget(etu_tableView);

        addetu_pushButton = new QPushButton(layoutWidget);
        addetu_pushButton->setObjectName("addetu_pushButton");

        verticalLayout_4->addWidget(addetu_pushButton);


        verticalLayout_5->addLayout(verticalLayout_4);


        verticalLayout_2->addLayout(verticalLayout_5);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName("label_8");

        verticalLayout_2->addWidget(label_8);

        grp_tableView = new QTableView(layoutWidget);
        grp_tableView->setObjectName("grp_tableView");
        grp_tableView->verticalHeader()->setVisible(false);

        verticalLayout_2->addWidget(grp_tableView);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        modify_pushButton = new QPushButton(layoutWidget);
        modify_pushButton->setObjectName("modify_pushButton");

        horizontalLayout_6->addWidget(modify_pushButton);

        delete_pushButton = new QPushButton(layoutWidget);
        delete_pushButton->setObjectName("delete_pushButton");

        horizontalLayout_6->addWidget(delete_pushButton);


        verticalLayout_2->addLayout(horizontalLayout_6);


        retranslateUi(groupe);

        QMetaObject::connectSlotsByName(groupe);
    } // setupUi

    void retranslateUi(QDialog *groupe)
    {
        groupe->setWindowTitle(QCoreApplication::translate("groupe", "Dialog", nullptr));
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

        showgm_pushButton->setText(QCoreApplication::translate("groupe", "Show GroupeModule", nullptr));
        showetu_pushButton->setText(QCoreApplication::translate("groupe", "Show Etudiant", nullptr));
        hidegm_pushButton->setText(QCoreApplication::translate("groupe", "Hide GroupeModule", nullptr));
        hideetu_pushButton->setText(QCoreApplication::translate("groupe", "Hide Etudiant", nullptr));
        gm_label->setText(QCoreApplication::translate("groupe", "GroupeModule : ", nullptr));
        addgm_pushButton->setText(QCoreApplication::translate("groupe", "Add Selected GM", nullptr));
        etu_label->setText(QCoreApplication::translate("groupe", "Etudiant : ", nullptr));
        addetu_pushButton->setText(QCoreApplication::translate("groupe", "Add Selected Etudiant", nullptr));
        label_8->setText(QCoreApplication::translate("groupe", "Groupe :", nullptr));
        modify_pushButton->setText(QCoreApplication::translate("groupe", "Modify", nullptr));
        delete_pushButton->setText(QCoreApplication::translate("groupe", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class groupe: public Ui_groupe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPE_H

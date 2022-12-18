/********************************************************************************
** Form generated from reading UI file 'searhparams.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARHPARAMS_H
#define UI_SEARHPARAMS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SearhParams
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *plainTextEdit;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton;

    void setupUi(QDialog *SearhParams)
    {
        if (SearhParams->objectName().isEmpty())
            SearhParams->setObjectName("SearhParams");
        SearhParams->resize(429, 315);
        verticalLayoutWidget = new QWidget(SearhParams);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(10, 10, 401, 141));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        plainTextEdit = new QPlainTextEdit(verticalLayoutWidget);
        plainTextEdit->setObjectName("plainTextEdit");

        verticalLayout->addWidget(plainTextEdit);

        verticalLayoutWidget_2 = new QWidget(SearhParams);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(10, 150, 229, 151));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        radioButton = new QRadioButton(verticalLayoutWidget_2);
        radioButton->setObjectName("radioButton");

        verticalLayout_2->addWidget(radioButton);

        radioButton_2 = new QRadioButton(verticalLayoutWidget_2);
        radioButton_2->setObjectName("radioButton_2");

        verticalLayout_2->addWidget(radioButton_2);

        radioButton_3 = new QRadioButton(verticalLayoutWidget_2);
        radioButton_3->setObjectName("radioButton_3");

        verticalLayout_2->addWidget(radioButton_3);

        radioButton_4 = new QRadioButton(verticalLayoutWidget_2);
        radioButton_4->setObjectName("radioButton_4");

        verticalLayout_2->addWidget(radioButton_4);

        verticalLayoutWidget_3 = new QWidget(SearhParams);
        verticalLayoutWidget_3->setObjectName("verticalLayoutWidget_3");
        verticalLayoutWidget_3->setGeometry(QRect(240, 260, 171, 41));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(verticalLayoutWidget_3);
        pushButton->setObjectName("pushButton");

        verticalLayout_3->addWidget(pushButton);


        retranslateUi(SearhParams);

        QMetaObject::connectSlotsByName(SearhParams);
    } // setupUi

    void retranslateUi(QDialog *SearhParams)
    {
        SearhParams->setWindowTitle(QCoreApplication::translate("SearhParams", "Dialog", nullptr));
        radioButton->setText(QCoreApplication::translate("SearhParams", "find by author", nullptr));
        radioButton_2->setText(QCoreApplication::translate("SearhParams", "find by tag", nullptr));
        radioButton_3->setText(QCoreApplication::translate("SearhParams", "created less than 3 days ago", nullptr));
        radioButton_4->setText(QCoreApplication::translate("SearhParams", "modified less than 3 days ago", nullptr));
        pushButton->setText(QCoreApplication::translate("SearhParams", "Find", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SearhParams: public Ui_SearhParams {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARHPARAMS_H

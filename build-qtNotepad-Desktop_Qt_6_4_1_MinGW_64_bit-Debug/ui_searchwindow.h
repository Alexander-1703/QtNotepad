/********************************************************************************
** Form generated from reading UI file 'searchwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHWINDOW_H
#define UI_SEARCHWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SearchWindow
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPlainTextEdit *plainTextEdit;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QListWidget *listWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QTextEdit *textEdit;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QTextEdit *textEdit_2;

    void setupUi(QDialog *SearchWindow)
    {
        if (SearchWindow->objectName().isEmpty())
            SearchWindow->setObjectName("SearchWindow");
        SearchWindow->resize(550, 500);
        SearchWindow->setMinimumSize(QSize(550, 500));
        SearchWindow->setMaximumSize(QSize(550, 500));
        verticalLayoutWidget = new QWidget(SearchWindow);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(10, 10, 531, 206));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        plainTextEdit = new QPlainTextEdit(verticalLayoutWidget);
        plainTextEdit->setObjectName("plainTextEdit");

        verticalLayout->addWidget(plainTextEdit);

        verticalLayoutWidget_3 = new QWidget(SearchWindow);
        verticalLayoutWidget_3->setObjectName("verticalLayoutWidget_3");
        verticalLayoutWidget_3->setGeometry(QRect(10, 220, 239, 131));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        radioButton = new QRadioButton(verticalLayoutWidget_3);
        radioButton->setObjectName("radioButton");

        verticalLayout_3->addWidget(radioButton);

        radioButton_2 = new QRadioButton(verticalLayoutWidget_3);
        radioButton_2->setObjectName("radioButton_2");

        verticalLayout_3->addWidget(radioButton_2);

        radioButton_3 = new QRadioButton(verticalLayoutWidget_3);
        radioButton_3->setObjectName("radioButton_3");

        verticalLayout_3->addWidget(radioButton_3);

        radioButton_4 = new QRadioButton(verticalLayoutWidget_3);
        radioButton_4->setObjectName("radioButton_4");

        verticalLayout_3->addWidget(radioButton_4);

        listWidget = new QListWidget(SearchWindow);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(240, 220, 301, 161));
        horizontalLayoutWidget = new QWidget(SearchWindow);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(10, 350, 108, 21));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName("label_2");

        horizontalLayout_3->addWidget(label_2);

        textEdit = new QTextEdit(horizontalLayoutWidget);
        textEdit->setObjectName("textEdit");

        horizontalLayout_3->addWidget(textEdit);

        horizontalLayoutWidget_2 = new QWidget(SearchWindow);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(10, 380, 531, 61));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(horizontalLayoutWidget_2);
        pushButton->setObjectName("pushButton");

        horizontalLayout_5->addWidget(pushButton);

        pushButton_4 = new QPushButton(horizontalLayoutWidget_2);
        pushButton_4->setObjectName("pushButton_4");

        horizontalLayout_5->addWidget(pushButton_4);

        pushButton_2 = new QPushButton(horizontalLayoutWidget_2);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout_5->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(SearchWindow);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(10, 440, 531, 29));
        textEdit_2 = new QTextEdit(SearchWindow);
        textEdit_2->setObjectName("textEdit_2");
        textEdit_2->setGeometry(QRect(170, 350, 71, 21));

        retranslateUi(SearchWindow);

        QMetaObject::connectSlotsByName(SearchWindow);
    } // setupUi

    void retranslateUi(QDialog *SearchWindow)
    {
        SearchWindow->setWindowTitle(QCoreApplication::translate("SearchWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("SearchWindow", "to search by author or tags:", nullptr));
        radioButton->setText(QCoreApplication::translate("SearchWindow", "search by author", nullptr));
        radioButton_2->setText(QCoreApplication::translate("SearchWindow", "search by tag (through a space)", nullptr));
        radioButton_3->setText(QCoreApplication::translate("SearchWindow", "recently created (<= N days)", nullptr));
        radioButton_4->setText(QCoreApplication::translate("SearchWindow", "recently modified (<= N days)", nullptr));
        label_2->setText(QCoreApplication::translate("SearchWindow", "N:", nullptr));
        pushButton->setText(QCoreApplication::translate("SearchWindow", "find", nullptr));
        pushButton_4->setText(QCoreApplication::translate("SearchWindow", "delete", nullptr));
        pushButton_2->setText(QCoreApplication::translate("SearchWindow", "select", nullptr));
        pushButton_3->setText(QCoreApplication::translate("SearchWindow", "show all", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SearchWindow: public Ui_SearchWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHWINDOW_H

/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *mainLayout;
    QLabel *titleLabel;
    QLabel *subTitleLabel;
    QHBoxLayout *bodyLayout;
    QFrame *leftCard;
    QVBoxLayout *leftLayout;
    QLabel *accountLabel;
    QListWidget *listWidget;
    QFrame *centerCard;
    QVBoxLayout *centerLayout;
    QLabel *addLabel;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton;
    QFrame *rightCard;
    QVBoxLayout *rightLayout;
    QLabel *detailLabel;
    QListWidget *listWidget_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1000, 700);
        MainWindow->setStyleSheet(QString::fromUtf8("\n"
"QMainWindow {\n"
"    background-color: #f3f6fb;\n"
"}\n"
"\n"
"QWidget#centralwidget {\n"
"    background-color: #f3f6fb;\n"
"}\n"
"\n"
"QLabel#titleLabel {\n"
"    color: #1f2937;\n"
"    font-size: 28px;\n"
"    font-weight: 700;\n"
"    padding: 10px 0px 0px 0px;\n"
"}\n"
"\n"
"QLabel#subTitleLabel {\n"
"    color: #6b7280;\n"
"    font-size: 13px;\n"
"    padding-bottom: 8px;\n"
"}\n"
"\n"
"QFrame#leftCard,\n"
"QFrame#centerCard,\n"
"QFrame#rightCard {\n"
"    background-color: #ffffff;\n"
"    border: 1px solid #e5e7eb;\n"
"    border-radius: 16px;\n"
"}\n"
"\n"
"QLabel#accountLabel,\n"
"QLabel#addLabel,\n"
"QLabel#detailLabel {\n"
"    color: #111827;\n"
"    font-size: 16px;\n"
"    font-weight: 600;\n"
"    padding: 4px 2px 8px 2px;\n"
"}\n"
"\n"
"QListWidget {\n"
"    background-color: transparent;\n"
"    border: none;\n"
"    outline: none;\n"
"    color: #1f2937;\n"
"    font-size: 14px;\n"
"    padding: 4px;\n"
"}\n"
"\n"
"QListWidget::item {\n"
"    min-height: 38px;\n"
"    padding-left: 1"
                        "2px;\n"
"    padding-right: 10px;\n"
"    margin: 2px 0px;\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"QListWidget::item:hover {\n"
"    background-color: #eef4ff;\n"
"}\n"
"\n"
"QListWidget::item:selected {\n"
"    background-color: #dbeafe;\n"
"    color: #0f4c81;\n"
"    font-weight: 600;\n"
"}\n"
"\n"
"QLineEdit {\n"
"    min-height: 38px;\n"
"    background-color: #f9fafb;\n"
"    color: #111827;\n"
"    border: 1px solid #d1d5db;\n"
"    border-radius: 10px;\n"
"    padding-left: 12px;\n"
"    padding-right: 12px;\n"
"    selection-background-color: #bfdbfe;\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"    border: 1px solid #9ca3af;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    background-color: #ffffff;\n"
"    border: 2px solid #60a5fa;\n"
"}\n"
"\n"
"QPushButton {\n"
"    min-height: 40px;\n"
"    background-color: #2563eb;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    font-weight: 600;\n"
"    padding: 0px 18px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    "
                        "background-color: #1d4ed8;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #1e40af;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #cbd5e1;\n"
"    color: #64748b;\n"
"}\n"
"\n"
"QMenuBar {\n"
"    background-color: #f3f6fb;\n"
"    color: #374151;\n"
"    border: none;\n"
"}\n"
"\n"
"QMenuBar::item:selected {\n"
"    background-color: #e5e7eb;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QStatusBar {\n"
"    background-color: #f3f6fb;\n"
"    color: #6b7280;\n"
"    border: none;\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    background: transparent;\n"
"    width: 10px;\n"
"    margin: 2px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background: #cbd5e1;\n"
"    min-height: 28px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical:hover {\n"
"    background: #94a3b8;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical,\n"
"QScrollBar::sub-line:vertical {\n"
"    height: 0px;\n"
"}\n"
"\n"
"QScrollBar:horizontal {\n"
"    background: transparent;\n"
"    height"
                        ": 10px;\n"
"    margin: 2px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal {\n"
"    background: #cbd5e1;\n"
"    min-width: 28px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal,\n"
"QScrollBar::sub-line:horizontal {\n"
"    width: 0px;\n"
"}\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        mainLayout = new QVBoxLayout(centralwidget);
        mainLayout->setSpacing(12);
        mainLayout->setObjectName("mainLayout");
        mainLayout->setContentsMargins(24, 20, 24, 20);
        titleLabel = new QLabel(centralwidget);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setAlignment(Qt::AlignCenter);

        mainLayout->addWidget(titleLabel);

        subTitleLabel = new QLabel(centralwidget);
        subTitleLabel->setObjectName("subTitleLabel");
        subTitleLabel->setAlignment(Qt::AlignCenter);

        mainLayout->addWidget(subTitleLabel);

        bodyLayout = new QHBoxLayout();
        bodyLayout->setSpacing(14);
        bodyLayout->setObjectName("bodyLayout");
        leftCard = new QFrame(centralwidget);
        leftCard->setObjectName("leftCard");
        leftLayout = new QVBoxLayout(leftCard);
        leftLayout->setSpacing(8);
        leftLayout->setObjectName("leftLayout");
        leftLayout->setContentsMargins(14, 14, 14, 14);
        accountLabel = new QLabel(leftCard);
        accountLabel->setObjectName("accountLabel");

        leftLayout->addWidget(accountLabel);

        listWidget = new QListWidget(leftCard);
        listWidget->setObjectName("listWidget");

        leftLayout->addWidget(listWidget);


        bodyLayout->addWidget(leftCard);

        centerCard = new QFrame(centralwidget);
        centerCard->setObjectName("centerCard");
        centerLayout = new QVBoxLayout(centerCard);
        centerLayout->setSpacing(12);
        centerLayout->setObjectName("centerLayout");
        centerLayout->setContentsMargins(18, 18, 18, 18);
        addLabel = new QLabel(centerCard);
        addLabel->setObjectName("addLabel");

        centerLayout->addWidget(addLabel);

        lineEdit = new QLineEdit(centerCard);
        lineEdit->setObjectName("lineEdit");

        centerLayout->addWidget(lineEdit);

        lineEdit_2 = new QLineEdit(centerCard);
        lineEdit_2->setObjectName("lineEdit_2");

        centerLayout->addWidget(lineEdit_2);

        lineEdit_3 = new QLineEdit(centerCard);
        lineEdit_3->setObjectName("lineEdit_3");

        centerLayout->addWidget(lineEdit_3);

        pushButton = new QPushButton(centerCard);
        pushButton->setObjectName("pushButton");

        centerLayout->addWidget(pushButton);


        bodyLayout->addWidget(centerCard);

        rightCard = new QFrame(centralwidget);
        rightCard->setObjectName("rightCard");
        rightLayout = new QVBoxLayout(rightCard);
        rightLayout->setSpacing(8);
        rightLayout->setObjectName("rightLayout");
        rightLayout->setContentsMargins(14, 14, 14, 14);
        detailLabel = new QLabel(rightCard);
        detailLabel->setObjectName("detailLabel");

        rightLayout->addWidget(detailLabel);

        listWidget_2 = new QListWidget(rightCard);
        listWidget_2->setObjectName("listWidget_2");

        rightLayout->addWidget(listWidget_2);


        bodyLayout->addWidget(rightCard);


        mainLayout->addLayout(bodyLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "SafeBox - JSON Password Manager", nullptr));
        titleLabel->setText(QCoreApplication::translate("MainWindow", "\360\237\224\220 SafeBox", nullptr));
        subTitleLabel->setText(QCoreApplication::translate("MainWindow", "Local JSON Password Manager", nullptr));
        accountLabel->setText(QCoreApplication::translate("MainWindow", "\350\264\246\345\217\267\345\210\227\350\241\250", nullptr));
        addLabel->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\345\257\206\347\240\201", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\345\220\215\347\247\260", nullptr));
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\264\246\345\217\267", nullptr));
        lineEdit_3->setPlaceholderText(QCoreApplication::translate("MainWindow", "\345\257\206\347\240\201", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
        detailLabel->setText(QCoreApplication::translate("MainWindow", "\350\257\246\347\273\206\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

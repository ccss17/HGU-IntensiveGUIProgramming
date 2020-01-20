/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page_4;
    QLabel *label_9;
    QPushButton *pushButton_5;
    QPushButton *pushButton_7;
    QWidget *page;
    QLabel *label;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QWidget *page_3;
    QLabel *label_8;
    QPushButton *pushButton_4;
    QLineEdit *lineEdit_3;
    QWidget *page_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QLabel *label_4;
    QToolButton *toolButton_7;
    QToolButton *toolButton_8;
    QToolButton *toolButton_9;
    QToolButton *toolButton_6;
    QToolButton *toolButton_5;
    QToolButton *toolButton_4;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QLabel *label_7;
    QLabel *label_6;
    QLabel *label_5;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 518);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 801, 471));
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        label_9 = new QLabel(page_4);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(250, 100, 311, 61));
        QFont font;
        font.setPointSize(34);
        label_9->setFont(font);
        pushButton_5 = new QPushButton(page_4);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(430, 220, 141, 61));
        pushButton_7 = new QPushButton(page_4);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(170, 220, 141, 61));
        stackedWidget->addWidget(page_4);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        label = new QLabel(page);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(250, 100, 311, 61));
        label->setFont(font);
        label_3 = new QLabel(page);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(320, 300, 141, 51));
        QFont font1;
        font1.setPointSize(50);
        label_3->setFont(font1);
        lineEdit = new QLineEdit(page);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(180, 310, 141, 51));
        QFont font2;
        font2.setPointSize(30);
        lineEdit->setFont(font2);
        lineEdit_2 = new QLineEdit(page);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(460, 310, 141, 51));
        lineEdit_2->setFont(font2);
        pushButton = new QPushButton(page);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(320, 220, 141, 61));
        stackedWidget->addWidget(page);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        label_8 = new QLabel(page_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(250, 100, 311, 61));
        label_8->setFont(font);
        pushButton_4 = new QPushButton(page_3);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(320, 220, 141, 61));
        lineEdit_3 = new QLineEdit(page_3);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(320, 320, 141, 51));
        lineEdit_3->setFont(font2);
        stackedWidget->addWidget(page_3);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        pushButton_3 = new QPushButton(page_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(520, 350, 151, 51));
        pushButton_2 = new QPushButton(page_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(520, 280, 151, 51));
        label_4 = new QLabel(page_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 410, 281, 41));
        label_4->setFont(font2);
        toolButton_7 = new QToolButton(page_2);
        toolButton_7->setObjectName(QString::fromUtf8("toolButton_7"));
        toolButton_7->setGeometry(QRect(20, 280, 121, 121));
        QFont font3;
        font3.setPointSize(80);
        toolButton_7->setFont(font3);
        toolButton_8 = new QToolButton(page_2);
        toolButton_8->setObjectName(QString::fromUtf8("toolButton_8"));
        toolButton_8->setGeometry(QRect(140, 280, 121, 121));
        toolButton_8->setFont(font3);
        toolButton_9 = new QToolButton(page_2);
        toolButton_9->setObjectName(QString::fromUtf8("toolButton_9"));
        toolButton_9->setGeometry(QRect(260, 280, 121, 121));
        toolButton_9->setFont(font3);
        toolButton_6 = new QToolButton(page_2);
        toolButton_6->setObjectName(QString::fromUtf8("toolButton_6"));
        toolButton_6->setGeometry(QRect(260, 160, 121, 121));
        toolButton_6->setFont(font3);
        toolButton_5 = new QToolButton(page_2);
        toolButton_5->setObjectName(QString::fromUtf8("toolButton_5"));
        toolButton_5->setGeometry(QRect(140, 160, 121, 121));
        toolButton_5->setFont(font3);
        toolButton_4 = new QToolButton(page_2);
        toolButton_4->setObjectName(QString::fromUtf8("toolButton_4"));
        toolButton_4->setGeometry(QRect(20, 160, 121, 121));
        toolButton_4->setFont(font3);
        toolButton = new QToolButton(page_2);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(20, 40, 121, 121));
        toolButton->setFont(font3);
        toolButton_2 = new QToolButton(page_2);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setGeometry(QRect(140, 40, 121, 121));
        toolButton_2->setFont(font3);
        toolButton_3 = new QToolButton(page_2);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        toolButton_3->setGeometry(QRect(260, 40, 121, 121));
        toolButton_3->setFont(font3);
        label_7 = new QLabel(page_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(470, 190, 231, 51));
        QFont font4;
        font4.setPointSize(25);
        label_7->setFont(font4);
        label_6 = new QLabel(page_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(470, 130, 231, 51));
        label_6->setFont(font4);
        label_5 = new QLabel(page_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(470, 60, 231, 51));
        label_5->setFont(font4);
        label_2 = new QLabel(page_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 0, 731, 41));
        QFont font5;
        font5.setPointSize(26);
        label_2->setFont(font5);
        stackedWidget->addWidget(page_2);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\354\246\220\352\261\260\354\232\264 \355\213\261\355\203\235\355\206\241\352\262\214\354\236\204!", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "\353\251\200\355\213\260 \355\224\214\353\240\210\354\235\264", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "\354\213\261\352\270\200 \355\224\214\353\240\210\354\235\264", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\354\246\220\352\261\260\354\232\264 \355\213\261\355\203\235\355\206\241\352\262\214\354\236\204!", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">vs</p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\354\213\234\354\236\221", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\354\246\220\352\261\260\354\232\264 \355\213\261\355\203\235\355\206\241\352\262\214\354\236\204!", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "\354\213\234\354\236\221", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\354\262\230\354\235\214\354\234\274\353\241\234", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\353\213\244\354\235\214 \353\247\244\354\271\230", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Next Turn", nullptr));
        toolButton_7->setText(QString());
        toolButton_8->setText(QString());
        toolButton_9->setText(QString());
        toolButton_6->setText(QString());
        toolButton_5->setText(QString());
        toolButton_4->setText(QString());
        toolButton->setText(QString());
        toolButton_2->setText(QString());
        toolButton_3->setText(QString());
        label_7->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">vs</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

/********************************************************************************
** Form generated from reading UI file 'gamewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWINDOW_H
#define UI_GAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_title;
    QPushButton *btn_reset;
    QLabel *label_turn;
    QPushButton *btn_2;
    QPushButton *btn_3;
    QPushButton *btn_1;
    QPushButton *btn_9;
    QPushButton *btn_8;
    QPushButton *btn_7;
    QPushButton *btn_5;
    QPushButton *btn_4;
    QPushButton *btn_6;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(386, 342);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label_title = new QLabel(centralwidget);
        label_title->setObjectName(QString::fromUtf8("label_title"));
        label_title->setGeometry(QRect(10, 0, 361, 41));
        QFont font;
        font.setPointSize(25);
        label_title->setFont(font);
        label_title->setAlignment(Qt::AlignCenter);
        btn_reset = new QPushButton(centralwidget);
        btn_reset->setObjectName(QString::fromUtf8("btn_reset"));
        btn_reset->setGeometry(QRect(260, 90, 111, 24));
        label_turn = new QLabel(centralwidget);
        label_turn->setObjectName(QString::fromUtf8("label_turn"));
        label_turn->setGeometry(QRect(270, 50, 91, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8(".SF Compact Rounded"));
        font1.setPointSize(18);
        label_turn->setFont(font1);
        label_turn->setAlignment(Qt::AlignCenter);
        btn_2 = new QPushButton(centralwidget);
        btn_2->setObjectName(QString::fromUtf8("btn_2"));
        btn_2->setGeometry(QRect(87, 42, 80, 80));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btn_2->sizePolicy().hasHeightForWidth());
        btn_2->setSizePolicy(sizePolicy1);
        btn_2->setMinimumSize(QSize(80, 80));
        QFont font2;
        font2.setPointSize(50);
        btn_2->setFont(font2);
        btn_3 = new QPushButton(centralwidget);
        btn_3->setObjectName(QString::fromUtf8("btn_3"));
        btn_3->setGeometry(QRect(172, 42, 80, 80));
        sizePolicy1.setHeightForWidth(btn_3->sizePolicy().hasHeightForWidth());
        btn_3->setSizePolicy(sizePolicy1);
        btn_3->setMinimumSize(QSize(80, 80));
        btn_3->setFont(font2);
        btn_1 = new QPushButton(centralwidget);
        btn_1->setObjectName(QString::fromUtf8("btn_1"));
        btn_1->setEnabled(true);
        btn_1->setGeometry(QRect(2, 42, 80, 80));
        sizePolicy1.setHeightForWidth(btn_1->sizePolicy().hasHeightForWidth());
        btn_1->setSizePolicy(sizePolicy1);
        btn_1->setMinimumSize(QSize(80, 80));
        btn_1->setFont(font2);
        btn_9 = new QPushButton(centralwidget);
        btn_9->setObjectName(QString::fromUtf8("btn_9"));
        btn_9->setGeometry(QRect(172, 210, 80, 80));
        sizePolicy1.setHeightForWidth(btn_9->sizePolicy().hasHeightForWidth());
        btn_9->setSizePolicy(sizePolicy1);
        btn_9->setMinimumSize(QSize(80, 80));
        btn_9->setFont(font2);
        btn_8 = new QPushButton(centralwidget);
        btn_8->setObjectName(QString::fromUtf8("btn_8"));
        btn_8->setGeometry(QRect(87, 210, 80, 80));
        sizePolicy1.setHeightForWidth(btn_8->sizePolicy().hasHeightForWidth());
        btn_8->setSizePolicy(sizePolicy1);
        btn_8->setMinimumSize(QSize(80, 80));
        btn_8->setFont(font2);
        btn_7 = new QPushButton(centralwidget);
        btn_7->setObjectName(QString::fromUtf8("btn_7"));
        btn_7->setGeometry(QRect(2, 210, 80, 80));
        sizePolicy1.setHeightForWidth(btn_7->sizePolicy().hasHeightForWidth());
        btn_7->setSizePolicy(sizePolicy1);
        btn_7->setMinimumSize(QSize(80, 80));
        btn_7->setFont(font2);
        btn_5 = new QPushButton(centralwidget);
        btn_5->setObjectName(QString::fromUtf8("btn_5"));
        btn_5->setGeometry(QRect(87, 126, 80, 80));
        sizePolicy1.setHeightForWidth(btn_5->sizePolicy().hasHeightForWidth());
        btn_5->setSizePolicy(sizePolicy1);
        btn_5->setMinimumSize(QSize(80, 80));
        btn_5->setFont(font2);
        btn_4 = new QPushButton(centralwidget);
        btn_4->setObjectName(QString::fromUtf8("btn_4"));
        btn_4->setGeometry(QRect(2, 126, 80, 80));
        sizePolicy1.setHeightForWidth(btn_4->sizePolicy().hasHeightForWidth());
        btn_4->setSizePolicy(sizePolicy1);
        btn_4->setMinimumSize(QSize(80, 80));
        btn_4->setFont(font2);
        btn_6 = new QPushButton(centralwidget);
        btn_6->setObjectName(QString::fromUtf8("btn_6"));
        btn_6->setGeometry(QRect(172, 126, 80, 80));
        sizePolicy1.setHeightForWidth(btn_6->sizePolicy().hasHeightForWidth());
        btn_6->setSizePolicy(sizePolicy1);
        btn_6->setMinimumSize(QSize(80, 80));
        btn_6->setFont(font2);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 386, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_title->setText(QCoreApplication::translate("MainWindow", "Tic Tac Toe", nullptr));
        btn_reset->setText(QCoreApplication::translate("MainWindow", "reset", nullptr));
        label_turn->setText(QCoreApplication::translate("MainWindow", "X's turn!", nullptr));
        btn_2->setText(QString());
        btn_3->setText(QString());
        btn_1->setText(QString());
        btn_9->setText(QString());
        btn_8->setText(QString());
        btn_7->setText(QString());
        btn_5->setText(QString());
        btn_4->setText(QString());
        btn_6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWINDOW_H

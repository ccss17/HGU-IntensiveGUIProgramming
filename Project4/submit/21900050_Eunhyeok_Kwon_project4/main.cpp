#include "mainwindow.h"
#include "test/testwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

//    TestWindow w2;
//    w2.show();

    return a.exec();
}

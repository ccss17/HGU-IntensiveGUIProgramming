#include "gamewindow.h" // get mainwindow header ready

#include <QApplication> // The QApplication class manages the GUI application's control flow and main settings.

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); // create QApplication Object
    MainWindow w;   // create MainWindow Object
    w.show();
    return a.exec();    // begin QApplicatoin loop
}

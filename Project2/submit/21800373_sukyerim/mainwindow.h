#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void Mouse_Pressed();
    void Mouse_current_pos();

    void on_pushButton_2_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_2_textChanged(const QString &arg1);

    void who_clicked();
    void who_clicked_2();
    void who_clicked_3();
    void who_clicked_4();
    void who_clicked_5();
    void who_clicked_6();
    void who_clicked_7();
    void who_clicked_8();
    void who_clicked_9();

    void on_toolButton_clicked();

    void on_toolButton_2_clicked();

    void on_toolButton_3_clicked();

    void on_toolButton_4_clicked();

    void on_toolButton_5_clicked();

    void on_toolButton_6_clicked();

    void on_toolButton_7_clicked();

    void on_toolButton_8_clicked();

    void on_toolButton_9_clicked();



    void end();

    void who_win();

    void on_pushButton_3_clicked();


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

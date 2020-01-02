#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "my_qlabel.h"

#include <qtoolbutton.h>
#include <QWidget>
#include <QLabel>
#include <QDebug>

QString A;
QString B;
QString Turn;
int count =0;
QToolButton *button[3][3];
QWidget * parent;



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    button[0][0] = ui->toolButton;
    button[0][1] = ui->toolButton_2;
    button[0][2] = ui->toolButton_3;
    button[1][0] = ui->toolButton_4;
    button[1][1] = ui->toolButton_5;
    button[1][2] = ui->toolButton_6;
    button[2][0] = ui->toolButton_7;
    button[2][1] = ui->toolButton_8;
    button[2][2] = ui->toolButton_9;

    connect(ui->lblMouse, SIGNAL(Mouse_Pressed()), this, SLOT(Mouse_Pressed()) );
    connect(ui->lblMouse, SIGNAL(Mouse_Pos()), this, SLOT(Mouse_current_pos()) );
}

MainWindow::~MainWindow()
{
    delete ui;
}

//assign player
void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    A = arg1;
}

void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    B = arg1;
}

//notice who are the players
void MainWindow::on_pushButton_2_clicked()
{
    QString strTotal;

    strTotal = QString("<b>%1</b> VS <b>%2</b>")
                          .arg(A)
                          .arg(B);
    ui->label->setText(strTotal);
    ui->lblMouse_Current_Event->setText(QString("<b>%1's</b> turn").arg(A)); //initialize who is the first turn

}

//Detect Mouse
void MainWindow::Mouse_Pressed()
{
    count++;
    if(count==10) end();
    if(count %2 ==0){
        ui->lblMouse_Current_Event->setText(QString("<b>%1's</b> turn").arg(A));
    }
    else{
        ui->lblMouse_Current_Event->setText(QString("<b>%1's</b> turn").arg(B));
    }
    who_win();

}

void MainWindow::Mouse_current_pos()
{
    //ui-> label_4 -> setText(QString("X = %1, Y = %2").arg(ui->lblMouse->x).arg(ui->lblMouse->y));
    //ui->lblMouse_Current_Event->setText("Mouse Moving!");
}

void MainWindow::who_clicked()
{
    if(ui->lblMouse_Current_Event->text() == QString("<b>%1's</b> turn").arg(A)){
        ui->toolButton->setText("X");
    }
    if(ui->lblMouse_Current_Event->text() == QString("<b>%1's</b> turn").arg(B)){
        ui->toolButton->setText("O");
    }

}

void MainWindow::who_clicked_2()
{
    if(ui->lblMouse_Current_Event->text() == QString("<b>%1's</b> turn").arg(A)){
        ui->toolButton_2->setText("X");
    }
    if(ui->lblMouse_Current_Event->text() == QString("<b>%1's</b> turn").arg(B)){
        ui->toolButton_2->setText("O");
    }

}

void MainWindow::who_clicked_3()
{
    if(ui->lblMouse_Current_Event->text() == QString("<b>%1's</b> turn").arg(A)){
        ui->toolButton_3->setText("X");
    }
    if(ui->lblMouse_Current_Event->text() == QString("<b>%1's</b> turn").arg(B)){
        ui->toolButton_3->setText("O");
    }

}

void MainWindow::who_clicked_4()
{
    if(ui->lblMouse_Current_Event->text() == QString("<b>%1's</b> turn").arg(A)){
        ui->toolButton_4->setText("X");
    }
    if(ui->lblMouse_Current_Event->text() == QString("<b>%1's</b> turn").arg(B)){
        ui->toolButton_4->setText("O");
    }

}
void MainWindow::who_clicked_5()
{
    if(ui->lblMouse_Current_Event->text() == QString("<b>%1's</b> turn").arg(A)){
        ui->toolButton_5->setText("X");
    }
    if(ui->lblMouse_Current_Event->text() == QString("<b>%1's</b> turn").arg(B)){
        ui->toolButton_5->setText("O");
    }

}

void MainWindow::who_clicked_6()
{
    if(ui->lblMouse_Current_Event->text() == QString("<b>%1's</b> turn").arg(A)){
        ui->toolButton_6->setText("X");
    }
    if(ui->lblMouse_Current_Event->text() == QString("<b>%1's</b> turn").arg(B)){
        ui->toolButton_6->setText("O");
    }

}

void MainWindow::who_clicked_7()
{
    if(ui->lblMouse_Current_Event->text() == QString("<b>%1's</b> turn").arg(A)){
        ui->toolButton_7->setText("X");
    }
    if(ui->lblMouse_Current_Event->text() == QString("<b>%1's</b> turn").arg(B)){
        ui->toolButton_7->setText("O");
    }

}

void MainWindow::who_clicked_8()
{
    if(ui->lblMouse_Current_Event->text() == QString("<b>%1's</b> turn").arg(A)){
        ui->toolButton_8->setText("X");
    }
    if(ui->lblMouse_Current_Event->text() == QString("<b>%1's</b> turn").arg(B)){
        ui->toolButton_8->setText("O");
    }

}

void MainWindow::who_clicked_9()
{
    if(ui->lblMouse_Current_Event->text() == QString("<b>%1's</b> turn").arg(A)){
        ui->toolButton_9->setText("X");
    }
    if(ui->lblMouse_Current_Event->text() == QString("<b>%1's</b> turn").arg(B)){
        ui->toolButton_9->setText("O");
    }

}

void MainWindow::on_toolButton_clicked()
{
   who_clicked();
   Mouse_Pressed();

}

void MainWindow::on_toolButton_2_clicked()
{
    who_clicked_2();
    Mouse_Pressed();
}

void MainWindow::on_toolButton_3_clicked()
{
    who_clicked_3();
    Mouse_Pressed();
}

void MainWindow::on_toolButton_4_clicked()
{
    who_clicked_4();
    Mouse_Pressed();
}

void MainWindow::on_toolButton_5_clicked()
{
    who_clicked_5();
    Mouse_Pressed();
}

void MainWindow::on_toolButton_6_clicked()
{
    who_clicked_6();
    Mouse_Pressed();
}

void MainWindow::on_toolButton_7_clicked()
{
    who_clicked_7();
    Mouse_Pressed();
}

void MainWindow::on_toolButton_8_clicked()
{
    who_clicked_8();
    Mouse_Pressed();
}

void MainWindow::on_toolButton_9_clicked()
{
    who_clicked_9();
    Mouse_Pressed();
}

void MainWindow::end()
{
    ui->lblMouse_Current_Event->setText(QString("Finish!"));
}

void MainWindow::who_win()
{
    int i=0;
    button[0][0] = ui->toolButton;
    button[0][1] = ui->toolButton_2;
    button[0][2] = ui->toolButton_3;
    button[1][0] = ui->toolButton_4;
    button[1][1] = ui->toolButton_5;
    button[1][2] = ui->toolButton_6;
    button[2][0] = ui->toolButton_7;
    button[2][1] = ui->toolButton_8;
    button[2][2] = ui->toolButton_9;


    for(i=0; i<3; i++){

        //player1 win 가로
        if(button[i][0]->text() == 'X' && button[i][1]->text() =='X' && button[i][2]->text() == 'X'){
            if(ui->lblMouse_Current_Event->text() == QString("<b>%1's</b> turn").arg(B)){
                ui->lblMouse_Current_Event->setText(QString("<b>%1</b> WIN!").arg(A));
            }

        }

        //player1 win 세로
        if(button[0][i]->text() == 'X' && button[1][i]->text() =='X' && button[2][i]->text() == 'X'){
            if(ui->lblMouse_Current_Event->text() == QString("<b>%1's</b> turn").arg(B)){
                ui->lblMouse_Current_Event->setText(QString("<b>%1</b> WIN!").arg(A));
            }

        }
    }
    for(i=0; i<3; i++){
        //player2 win 세로
        if(button[0][i]->text() == 'O' && button[1][i]->text() == 'O' && button[2][i]->text() == 'O'){
            if(ui->lblMouse_Current_Event->text() == QString("<b>%1's</b> turn").arg(A)){
                ui->lblMouse_Current_Event->setText(QString("<b>%1</b> WIN!").arg(B));
            }

        }

        //player2 win 가로
        if(button[i][0]->text() == 'O' && button[i][1]->text() == 'O' && button[i][2]->text() == 'O'){
            if(ui->lblMouse_Current_Event->text() == QString("<b>%1's</b> turn").arg(A)){
                ui->lblMouse_Current_Event->setText(QString("<b>%1</b> WIN!").arg(B));
            }

        }
    }

    //대각선
    if(button[0][0]->text() == 'X' && button[1][1]->text() == 'X' && button[2][2]->text() == 'X'){
        if(ui->lblMouse_Current_Event->text() == QString("<b>%1's</b> turn").arg(B)){
            ui->lblMouse_Current_Event->setText(QString("<b>%1</b> WIN!").arg(A));
        }
    }

    if(button[0][2]->text() == 'X' && button[1][1]->text() == 'X' && button[2][0]->text() == 'X'){
        if(ui->lblMouse_Current_Event->text() == QString("<b>%1's</b> turn").arg(B)){
            ui->lblMouse_Current_Event->setText(QString("<b>%1</b> WIN!").arg(A));
        }
    }

    //대각선
    if((button[0][0]->text() == 'O' && button[1][1]->text() == 'O' && button[2][2]->text() == 'O') || (button[0][2]->text() == 'O' && button[1][1]->text() == 'O' && button[2][0]->text() == 'O')){
        if(ui->lblMouse_Current_Event->text() == QString("<b>%1's</b> turn").arg(A)){
            ui->lblMouse_Current_Event->setText(QString("<b>%1</b> WIN!").arg(B));
        }
    }
}


void MainWindow::on_pushButton_3_clicked()
{
   count =0;
   ui->lblMouse_Current_Event->setText(QString("Whose turn?"));
   ui->label->setText(" ");

   ui->lineEdit->setText(" ");
   ui->lineEdit_2->setText(" ");

   for(int i=0; i<3; i++){
       for(int j=0; j<3; j++){
           button[i][j]->setText(" ");
       }
   }

}


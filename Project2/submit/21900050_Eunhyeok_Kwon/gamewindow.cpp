#include "gamewindow.h"
#include "ui_gamewindow.h"  // gets the ui header file

// class constructor
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , C(3,3,3)  // definition of tic tac toe in terms of Connect game
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);  // setup ui with 'this'
    reset_board();  // initialize board empty
}

// class destructor
MainWindow::~MainWindow()
{
    delete ui;
}

// game flow function
void MainWindow::game_flow(int x, int y, QPushButton &ref)
{
    if(!game_over)
    {
        C.canvas_coor_to_array(x,y);   // this translation is required
        int i = x;
        int j = y;
        if(C.empty_place(i,j))
        {
            C.place_stone(i,j);
            if(C.firstPlayerTurn())
                ref.setText(first_player_stone);
            else
                ref.setText(second_player_stone);

            if(C.k_in_a_row(i,j))
            {
                game_over = true;
                if(C.firstPlayerTurn())
                    ui->label_turn->setText(first_player_stone+" WON!");
                else
                    ui->label_turn->setText(second_player_stone+" WON!");
            }
            else if(C.full_board())
            {
                game_over = true;
                ui->label_turn->setText("DRAW...");
            }
            else if(C.turn_over())
            {
                C.switch_turn();
                if(C.firstPlayerTurn())
                    ui->label_turn->setText(first_player_stone+"'s turn!");
                else
                    ui->label_turn->setText(second_player_stone+"'s turn!");
            }
        }
    }
}

// reset board
void MainWindow::reset_board()
{
    ui->btn_1->setText("");
    ui->btn_2->setText("");
    ui->btn_3->setText("");
    ui->btn_4->setText("");
    ui->btn_5->setText("");
    ui->btn_6->setText("");
    ui->btn_7->setText("");
    ui->btn_8->setText("");
    ui->btn_9->setText("");
    ui->label_turn->setText(first_player_stone+"'s turn!");
}

// other class functions
void MainWindow::on_btn_1_clicked()
{
    int x=0, y=0;
    QPushButton &ref = *(ui->btn_1);
    game_flow(x,y,ref);
}
void MainWindow::on_btn_2_clicked()
{
    int x=1, y=0;
    QPushButton &ref = *(ui->btn_2);
    game_flow(x,y,ref);
}
void MainWindow::on_btn_3_clicked()
{
    int x=2, y=0;
    QPushButton &ref = *(ui->btn_3);
    game_flow(x,y,ref);
}


void MainWindow::on_btn_4_clicked()
{
    int x=0, y=1;
    QPushButton &ref = *(ui->btn_4);
    game_flow(x,y,ref);
}
void MainWindow::on_btn_5_clicked()
{
    int x=1, y=1;
    QPushButton &ref = *(ui->btn_5);
    game_flow(x,y,ref);
}
void MainWindow::on_btn_6_clicked()
{
    int x=2, y=1;
    QPushButton &ref = *(ui->btn_6);
    game_flow(x,y,ref);
}


void MainWindow::on_btn_7_clicked()
{
    int x=0, y=2;
    QPushButton &ref = *(ui->btn_7);
    game_flow(x,y,ref);
}
void MainWindow::on_btn_8_clicked()
{
    int x=1, y=2;
    QPushButton &ref = *(ui->btn_8);
    game_flow(x,y,ref);
}
void MainWindow::on_btn_9_clicked()
{
    int x=2, y=2;
    QPushButton &ref = *(ui->btn_9);
    game_flow(x,y,ref);
}

void MainWindow::on_btn_reset_clicked()
{
    C.reset_board();
    reset_board();
    game_over = false;
}

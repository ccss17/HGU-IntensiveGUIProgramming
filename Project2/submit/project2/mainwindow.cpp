#include "mainwindow.h"
#include "ui_mainwindow.h"

int player;
QString players[2];
int match = 1;
QString a;
char tic[3][3];
int A = 0, B = 0, C = 0;
int k;
int mode = 0;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Project2 틱택톡");
    ui->pushButton_2->setVisible(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int checkwin()
{
    int check = 0;
    int r = 0, l = 0;
    if (player == 1){
        for (int i = 0 ; i < 3 ; i++){
            for (int j = 0 ; j < 3 ; j++){
                if (tic[i][j] != 'O') break;
                else if (j == 2) check = 1;
            }
            for (int j = 0 ; j < 3 ; j++){
                if (tic[j][i] != 'O') break;
                else if (j == 2) check = 1;
            }
            if (tic[i][i] == 'O'){
                r++;
                if (r == 3) check = 1;
            }
            if (tic[i][2-i] == 'O'){
                l++;
                if (l == 3) check = 1;
            }
        }
    }
    if (player == 2){
        for (int i = 0 ; i < 3 ; i++){
            for (int j = 0 ; j < 3 ; j++){
                if (tic[i][j] != 'X') break;
                else if (j == 2) check = 1;
            }
            for (int j = 0 ; j < 3 ; j++){
                if (tic[j][i] != 'X') break;
                else if (j == 2) check = 1;
            }
            if (tic[i][i] == 'X'){
                r++;
                if (r == 3) check = 1;
            }
            if (tic[i][2-i] == 'X'){
                l++;
                if (l == 3) check = 1;
            }
        }
    }
    if (check == 1) return 1;
    for (int i = 0 ; i < 3 ; i++){
        for (int j = 0 ; j < 3 ; j++){
            if (tic[i][j] != 'O' && tic[i][j] != 'X') return 0;
        }
    }
    return 2;
}

int chplay(char check)
{
    if (check == 'O'){
        return 2;
    }
    else{
        return 1;
    }
}

int rule(){
    srand(time(0));
    int i, j;
    int a, b;
    int a_1, b_1, a_2, b_2;
    int O, X;
    int k, k_1 = 0, k_2 = 0;
    int r = 0, l = 0;
    for (i = 0 ; i < 3 ; i++){
        X = 0;
        k = 0;
        for (j = 0 ; j < 3 ; j++){
            if (tic[i][j] == 'X') X++;
            else if (tic[i][j] == '\0'){
                k++;
                a = i;
                b = j;
            }
            if (X == 2 && k == 1) return a*3+b;
        }
        X = 0;
        k = 0;
        for (j = 0 ; j < 3 ; j++){
            if (tic[j][i] == 'X') X++;
            else if (tic[j][i] == '\0'){
                k++;
                a = j;
                b = i;
            }
            if (X == 2 && k == 1) return a*3+b;
        }
        if (tic[i][i] == 'X'){
            r++;
        }
        else if (tic[i][i] == '\0'){
            k_1++;
            a_1 = i;
            b_1 = i;
        }
        if (r == 2 && k_1 == 1) return a_1*3+b_1;
        if (tic[i][2-i] == 'X'){
            l++;
        }
        else if (tic[i][2-i] == '\0'){
            k_2++;
            a_2 = i;
            b_2 = 2-i;
        }
        if (l == 2 && k_2 == 1) return a_2*3+b_2;
    }
    k_1 = 0;
    k_2 = 0;
    r = 0;
    l = 0;
    for (i = 0 ; i < 3 ; i++){
        O = 0;
        k = 0;
        for (j = 0 ; j < 3 ; j++){
            if (tic[i][j] == 'O') O++;
            else if (tic[i][j] == '\0'){
                k++;
                a = i;
                b = j;
            }
            if (O == 2 && k == 1) return a*3+b;
        }
        O = 0;
        k = 0;
        for (j = 0 ; j < 3 ; j++){
            if (tic[j][i] == 'O') O++;
            else if (tic[j][i] == '\0'){
                k++;
                a = j;
                b = i;
            }
            if (O == 2 && k == 1) return a*3+b;
        }
        if (tic[i][i] == 'O'){
            r++;
        }
        else if (tic[i][i] == '\0'){
            k_1++;
            a_1 = i;
            b_1 = i;
        }
        if (r == 2 && k_1 == 1) return a_1*3+b_1;
        if (tic[i][2-i] == 'O'){
            l++;
        }
        else if (tic[i][2-i] == '\0'){
            k_2++;
            a_2 = i;
            b_2 = 2-i;
        }
        if (l == 2 && k_2 == 1) return a_2*3+b_2;
    }
    while(true){
        a = rand()%3;
        b = rand()%3;
        if (tic[a][b] == '\0'){
            return a*3+b;
        }
    }
}


void MainWindow::win(){
    if (player == 1) A++;
    else B++;
    ui->label_4->setText(players[player-1] + " win!");
    ui->toolButton->setEnabled(false);
    ui->toolButton_2->setEnabled(false);
    ui->toolButton_3->setEnabled(false);
    ui->toolButton_4->setEnabled(false);
    ui->toolButton_5->setEnabled(false);
    ui->toolButton_6->setEnabled(false);
    ui->toolButton_7->setEnabled(false);
    ui->toolButton_8->setEnabled(false);
    ui->toolButton_9->setEnabled(false);
    ui->pushButton_2->setVisible(1);
}

void MainWindow::draw(){
    C++;
    ui->label_4->setText("Draw!");
    ui->toolButton->setEnabled(false);
    ui->toolButton_2->setEnabled(false);
    ui->toolButton_3->setEnabled(false);
    ui->toolButton_4->setEnabled(false);
    ui->toolButton_5->setEnabled(false);
    ui->toolButton_6->setEnabled(false);
    ui->toolButton_7->setEnabled(false);
    ui->toolButton_8->setEnabled(false);
    ui->toolButton_9->setEnabled(false);
    ui->pushButton_2->setVisible(1);
}

void MainWindow::restart(){
    ui->toolButton->setEnabled(true);
    ui->toolButton_2->setEnabled(true);
    ui->toolButton_3->setEnabled(true);
    ui->toolButton_4->setEnabled(true);
    ui->toolButton_5->setEnabled(true);
    ui->toolButton_6->setEnabled(true);
    ui->toolButton_7->setEnabled(true);
    ui->toolButton_8->setEnabled(true);
    ui->toolButton_9->setEnabled(true);
    ui->toolButton->setText("");
    ui->toolButton_2->setText("");
    ui->toolButton_3->setText("");
    ui->toolButton_4->setText("");
    ui->toolButton_5->setText("");
    ui->toolButton_6->setText("");
    ui->toolButton_7->setText("");
    ui->toolButton_8->setText("");
    ui->toolButton_9->setText("");
    for (int i = 0 ; i < 3 ; i++)
        for (int j = 0 ; j < 3 ; j++)
            tic[i][j] = '\0';
    ui->pushButton_2->setVisible(0);

    srand(time(0));
    player = rand()%2+1;
    ui->label_2->setText(a.setNum(match) + " 라운드  " + players[0] + "  vs  " + players[1]);
    ui->label_4->setText(players[player-1] + "'s Turn");
    vs();
    if (mode == 1){
        if (player == 2){
            Computer();
        }
    }
}

void MainWindow::vs(){
    ui->label_5->setText(a.setNum(A) + " vs " + a.setNum(B));
    ui->label_6->setText(players[0] + "  " + a.setNum(A) + "승 " + a.setNum(C) + "무 " + a.setNum(B) + "패");
    ui->label_7->setText(players[1] + "  " + a.setNum(B) + "승 " + a.setNum(C) + "무 " + a.setNum(A) + "패");
}

void MainWindow::Computer(){
    int sum;
    sum = rule();
    if (sum == 0){
        on_toolButton_clicked();
    }
    else if (sum == 1){
        on_toolButton_2_clicked();
    }
    else if (sum == 2){
        on_toolButton_3_clicked();
    }
    else if (sum == 3){
        on_toolButton_4_clicked();
    }
    else if (sum == 4){
        on_toolButton_5_clicked();
    }
    else if (sum == 5){
        on_toolButton_6_clicked();
    }
    else if (sum == 6){
        on_toolButton_7_clicked();
    }
    else if (sum == 7){
        on_toolButton_8_clicked();
    }
    else{
        on_toolButton_9_clicked();
    }
}

void MainWindow::on_toolButton_clicked()
{
    if (tic[0][0] == '\0'){
        if (player == 1){
            ui->toolButton->setText("O");
            tic[0][0] = 'O';
        }
        else if (player == 2){
            ui->toolButton->setText("X");
            tic[0][0] = 'X';
        }
        k = checkwin();
        if (k == 1){
            win();
        }
        else if (k == 2){
            draw();
        }
        else{
            player = chplay(tic[0][0]);
            ui->label_4->setText(players[player-1] + "'s Turn");
            if (mode == 1){
                if (player == 2){
                    Computer();
                }
            }
        }
    }
}

void MainWindow::on_toolButton_2_clicked()
{
    if (tic[0][1] == '\0'){
        if (player == 1){
            ui->toolButton_2->setText("O");
            tic[0][1] = 'O';
        }
        else if (player == 2){
            ui->toolButton_2->setText("X");
            tic[0][1] = 'X';
        }
        k = checkwin();
        if (k == 1){
            win();
        }
        else if (k == 2){
            draw();
        }
        else{
            player = chplay(tic[0][1]);
            ui->label_4->setText(players[player-1] + "'s Turn");
            if (mode == 1){
                if (player == 2){
                    Computer();
                }
            }
        }
    }
}

void MainWindow::on_toolButton_3_clicked()
{
    if (tic[0][2] == '\0'){
        if (player == 1){
            ui->toolButton_3->setText("O");
            tic[0][2] = 'O';
        }
        else if (player == 2){
            ui->toolButton_3->setText("X");
            tic[0][2] = 'X';
        }
        k = checkwin();
        if (k == 1){
            win();
        }
        else if (k == 2){
            draw();
        }
        else{
            player = chplay(tic[0][2]);
            ui->label_4->setText(players[player-1] + "'s Turn");
            if (mode == 1){
                if (player == 2){
                    Computer();
                }
            }
        }
    }
}

void MainWindow::on_toolButton_4_clicked()
{
    if (tic[1][0] == '\0'){
        if (player == 1){
            ui->toolButton_4->setText("O");
            tic[1][0] = 'O';
        }
        else if (player == 2){
            ui->toolButton_4->setText("X");
            tic[1][0] = 'X';
        }
        k = checkwin();
        if (k == 1){
            win();
        }
        else if (k == 2){
            draw();
        }
        else{
            player = chplay(tic[1][0]);
            ui->label_4->setText(players[player-1] + "'s Turn");
            if (mode == 1){
                if (player == 2){
                    Computer();
                }
            }
        }
    }
}

void MainWindow::on_toolButton_5_clicked()
{
    if (tic[1][1] == '\0'){
        if (player == 1){
            ui->toolButton_5->setText("O");
            tic[1][1] = 'O';
        }
        else if (player == 2){
            ui->toolButton_5->setText("X");
            tic[1][1] = 'X';
        }
        k = checkwin();
        if (k == 1){
            win();
        }
        else if (k == 2){
            draw();
        }
        else{
            player = chplay(tic[1][1]);
            ui->label_4->setText(players[player-1] + "'s Turn");
            if (mode == 1){
                if (player == 2){
                    Computer();
                }
            }
        }
    }
}

void MainWindow::on_toolButton_6_clicked()
{
    if (tic[1][2] == '\0'){
        if (player == 1){
            ui->toolButton_6->setText("O");
            tic[1][2] = 'O';
        }
        else if (player == 2){
            ui->toolButton_6->setText("X");
            tic[1][2] = 'X';
        }
        k = checkwin();
        if (k == 1){
            win();
        }
        else if (k == 2){
            draw();
        }
        else{
            player = chplay(tic[1][2]);
            ui->label_4->setText(players[player-1] + "'s Turn");
            if (mode == 1){
                if (player == 2){
                    Computer();
                }
            }
        }
    }
}

void MainWindow::on_toolButton_7_clicked()
{
    if (tic[2][0] == '\0'){
        if (player == 1){
            ui->toolButton_7->setText("O");
            tic[2][0] = 'O';
        }
        else if (player == 2){
            ui->toolButton_7->setText("X");
            tic[2][0] = 'X';
        }
        k = checkwin();
        if (k == 1){
            win();
        }
        else if (k == 2){
            draw();
        }
        else{
            player = chplay(tic[2][0]);
            ui->label_4->setText(players[player-1] + "'s Turn");
            if (mode == 1){
                if (player == 2){
                    Computer();
                }
            }
        }
    }
}

void MainWindow::on_toolButton_8_clicked()
{
    if (tic[2][1] == '\0'){
        if (player == 1){
            ui->toolButton_8->setText("O");
            tic[2][1] = 'O';
        }
        else if (player == 2){
            ui->toolButton_8->setText("X");
            tic[2][1] = 'X';
        }
        k = checkwin();
        if (k == 1){
            win();
        }
        else if (k == 2){
            draw();
        }
        else{
            player = chplay(tic[2][1]);
            ui->label_4->setText(players[player-1] + "'s Turn");
            if (mode == 1){
                if (player == 2){
                    Computer();
                }
            }
        }
    }
}

void MainWindow::on_toolButton_9_clicked()
{
    if (tic[2][2] == '\0'){
        if (player == 1){
            ui->toolButton_9->setText("O");
            tic[2][2] = 'O';
        }
        else if (player == 2){
            ui->toolButton_9->setText("X");
            tic[2][2] = 'X';
        }
        k = checkwin();
        if (k == 1){
            win();
        }
        else if (k == 2){
            draw();
        }
        else{
            player = chplay(tic[2][2]);
            ui->label_4->setText(players[player-1] + "'s Turn");
            if (mode == 1){
                if (player == 2){
                    Computer();
                }
            }
        }
    }
}


void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    players[0] = ui->lineEdit->text();
    players[1] = ui->lineEdit_2->text();

    restart();
}

void MainWindow::on_pushButton_2_clicked()
{
    match++;
    restart();
}

void MainWindow::on_pushButton_3_clicked()
{
    match = 1;
    A = 0;
    B = 0;
    C = 0;

    ui->stackedWidget->setCurrentIndex(0);

    restart();
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    players[0] = ui->lineEdit_3->text();
    players[1] = "Computer";

    restart();
}

void MainWindow::on_pushButton_5_clicked()
{
    mode = 0;
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_7_clicked()
{
    mode = 1;
    ui->stackedWidget->setCurrentIndex(2);
}

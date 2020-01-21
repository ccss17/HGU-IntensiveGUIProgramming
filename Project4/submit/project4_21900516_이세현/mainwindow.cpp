#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ingame.h"
#include "computer.h"

int player; //현재 플레이어
int mode = 0; // 싱글, 멀티, 토너먼트등 게임 기능
QString players[2]; // 플레에어들
QString a;
int A_win = 0, B_win = 0; //승, 패
int win = 0;
int com_num;
ingame game;
computer com;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Project4 즐거운 오목 한판!");

    ui->frame->setStyleSheet("background:rgb(204,153,51)");

    ui->Level->setVisible(0);
    ui->Chatting->setVisible(0);
    ui->Chat->setVisible(0);
    ui->Send->setVisible(0);
    ui->stackedWidget->setCurrentIndex(0);

    QToolButton * button;
    QString om;

    for (int i = 0 ; i < 15 ; i++){
        for (int j = 0 ; j < 15 ; j++){
            om = "om_" + om.setNum(15*i+j+1);
            button = MainWindow::findChild<QToolButton*>(om);
            omook[i][j] = button;
        }
    }

    for (int i = 0 ; i < 15 ; i++){
        for (int j = 0 ; j < 15 ; j++){
            omook[i][j]->setStyleSheet("background:hsla(120,100%,100%, 1)");
            connect(omook[i][j], SIGNAL(clicked()), this, SLOT(click()));
        }
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

int chplay(int k);


void MainWindow::on_Multi_clicked()
{
    mode = 0;
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_Single_clicked()
{
    mode = 1;
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_IPGame_clicked()
{
    mode = 2;
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_GoTitle_clicked()
{
    Go_Title();
}

void MainWindow::on_GoTitle_2_clicked()
{
    Go_Title();
}

void MainWindow::on_GoTitle_3_clicked()
{
    Go_Title();
}

void MainWindow::on_GoTitle_4_clicked()
{
    Go_Title();
}

void MainWindow::Go_Title(){
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::setting(){

    for (int i = 0 ; i < 15 ; i++){
        for (int j = 0 ; j < 15 ; j++){
            omook[i][j]->setText("");
            omook[i][j]->setEnabled(1);
        }
    }
    ui->widget->setVisible(0);
    ui->Reset->setEnabled(1);
    ui->GoTitle_4->setEnabled(1);

    srand(time(0));
    player = rand()%2+1;
    ui->Playervs->setText(players[0] + "  vs  " + players[1]);
    ui->Turn->setText(players[player-1] + "'s Turn");
    vs();
    game.setting();
    if (mode == 1){
        if (player == 2){
            com_num = com.com_rule(game);
//            com_num = com_rule();
            computer_click(com_num);
        }
    }
}

void MainWindow::vs(){
    ui->label_vs->setText(a.setNum(A_win) + " vs " + a.setNum(B_win));
}

void MainWindow::on_GameStart_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    players[0] = ui->Player1Multi->text();
    players[1] = ui->Player2Multi->text();
    setting();
    ui->Level->setVisible(0);
    ui->Chatting->setVisible(0);
    ui->Chat->setVisible(0);
    ui->Send->setVisible(0);
}

void MainWindow::on_GameStart_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    players[0] = ui->SinglePlayer->text();
    players[1] = "Computer";
    setting();
    ui->Level->setVisible(1);
    ui->Chatting->setVisible(0);
    ui->Chat->setVisible(0);
    ui->Send->setVisible(0);
}

void MainWindow::on_GameStart_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    players[0] = ui->IpPlayer->text();
    setting();
    ui->Level->setVisible(0);
    ui->Chatting->setVisible(1);
    ui->Chat->setVisible(1);
    ui->Send->setVisible(1);
}


void MainWindow::click()
{
    int x, y;
    QToolButton *button = (QToolButton*)sender();

    for (int i = 0 ; i < 15 ; i++){
        for (int j = 0 ; j < 15 ; j++){
            if (omook[i][j] == button){
                x = i;
                y = j;
                break;
            }
        }
    }


    if (button->text() == ""){
        if(player == 1) {
            button->setText("⚫");
            win = game.on_click(x, y, 'O');
        }
        else {
            button->setText("⚪");
            win = game.on_click(x, y, 'X');
        }
        if (win == 1){
            game_win();
        }
        else {
            player = chplay(player);
            ui->Turn->setText(players[player-1] + "'s Turn");
            if (mode == 1){
                if (player == 2){
                    com_num = com.com_rule(game);
                    computer_click(com_num);
                }
            }
        }
    }
}

void MainWindow::computer_click(int k){
    omook[k/15][k%15]->clicked();
}
//int MainWindow::check_win(QString c){
//    int cnt = 0;

//    for (int i = 0 ; i < 15 ; i++){
//        for (int j = 0 ; j < 15 ; j++){
//            if (omook[i][j]->text() == c){
//                cnt++;
//            }
//            else {
//                cnt = 0;
//            }
//            if (cnt == 5){
//                return 1;
//            }
//        }
//    }
//    for (int i = 0 ; i < 15 ; i++){
//        for (int j = 0 ; j < 15 ; j++){
//            if (omook[j][i]->text() == c){
//                cnt++;
//            }
//            else {
//                cnt = 0;
//            }
//            if (cnt == 5){
//                return 1;
//            }
//        }
//    }
//    for (int i = 0 ; i < 11 ; i++){
//        for (int j = 0 ; j < 11 ; j++){
//            for (int k = 0 ; k < 5 ; k++){
//                if (omook[i+k][j+k]->text() == c){
//                    cnt++;
//                }
//                else {
//                    break;
//                }
//            }
//            if (cnt == 5){
//                return 1;
//            }
//            cnt = 0;
//        }
//    }
//    for (int i = 0 ; i < 11 ; i++){
//        for (int j = 4 ; j < 15 ; j++){
//            for (int k = 0 ; k < 5 ; k++){
//                if (omook[i+k][j-k]->text() == c){
//                    cnt++;
//                }
//                else {
//                    break;
//                }
//            }
//            if (cnt == 5){
//                return 1;
//            }
//            cnt = 0;
//        }
//    }
//    return 0;
//}

void MainWindow::game_win(){
    for (int i = 0 ; i < 15 ; i++){
        for (int j = 0 ; j < 15 ; j++){
            omook[i][j]->setEnabled(0);
        }
    }
    ui->Turn->setText(players[player-1] + "'Win!");
    ui->widget->setVisible(1);
    ui->GameWin->setText(players[player-1] + "'Win!");
    ui->Reset->setEnabled(0);
    ui->GoTitle_4->setEnabled(0);
}

int chplay(int k)
{
    if (k == 1){
        return 2;
    }
    else{
        return 1;
    }
}

void MainWindow::on_Reset_clicked()
{
    setting();
}

void MainWindow::on_Yes_clicked()
{
    setting();
}

void MainWindow::on_No_clicked()
{
    Go_Title();
}

//int MainWindow::com_rule(){
//    srand(time(0));
//    int white_cnt = 0;
//    int black_cnt = 0;
//    int space_cnt = 0;
//    int a, b;
//    int a_num[2], b_num[2];
//    QString check;

//    // 우선순위 1
//    for (int i = 0 ; i < 15 ; i++){
//        for (int j = 0 ; j < 15 ; j++){
//            for (int k = 0 ; k < 5 ; k++){
//                if (j+k < 15){
//                    check = omook[i][j+k]->text();
//                    if (check == "⚪") white_cnt++;
//                    else if (check == "⚫") {break;}
//                    else {
//                        space_cnt++;
//                        a = i;
//                        b = j+k;
//                    }
//                    if (white_cnt == 4 && space_cnt == 1) return 15*a+b;
//                }
//                else {break;}
//            }
//            white_cnt = 0;
//            black_cnt = 0;
//            space_cnt = 0;
//            for (int k = 0 ; k < 5 ; k++){
//                if (i+k < 15){
//                    check = omook[i+k][j]->text();
//                    if (check == "⚪") white_cnt++;
//                    else if (check == "⚫") {break;}
//                    else {
//                        space_cnt++;
//                        a = i+k;
//                        b = j;
//                    }
//                    if (white_cnt == 4 && space_cnt == 1) return 15*a+b;
//                }
//                else {break;}
//            }
//            white_cnt = 0;
//            black_cnt = 0;
//            space_cnt = 0;
//            for (int k = 0 ; k < 5 ; k++){
//                if (i+k < 15 && j+k < 15){
//                    check = omook[i+k][j+k]->text();
//                    if (check == "⚪") white_cnt++;
//                    else if (check == "⚫") {break;}
//                    else {
//                        space_cnt++;
//                        a = i+k;
//                        b = j+k;
//                    }
//                    if (white_cnt == 4 && space_cnt == 1) return 15*a+b;
//                }
//                else {break;}
//            }
//            white_cnt = 0;
//            black_cnt = 0;
//            space_cnt = 0;
//            for (int k = 0 ; k < 5 ; k++){
//                if (i+k < 15 && j-k > -1){
//                    check = omook[i+k][j-k]->text();
//                    if (check == "⚪") white_cnt++;
//                    else if (check == "⚫") {break;}
//                    else {
//                        space_cnt++;
//                        a = i+k;
//                        b = j+k;
//                    }
//                    if (white_cnt == 4 && space_cnt == 1) return 15*a+b;
//                }
//                else {break;}
//            }
//            white_cnt = 0;
//            black_cnt = 0;
//            space_cnt = 0;
//        }
//    }

//    // 우선순위 2
//    for (int i = 0 ; i < 15 ; i++){
//        for (int j = 0 ; j < 15 ; j++){
//            for (int k = 0 ; k < 5 ; k++){
//                if (j+k < 15){
//                    check = omook[i][j+k]->text();
//                    if (check == "⚫") black_cnt++;
//                    else if (check == "⚪") {break;}
//                    else {
//                        space_cnt++;
//                        a = i;
//                        b = j+k;
//                    }
//                    if (black_cnt == 4 && space_cnt == 1) return 15*a+b;
//                }
//                else {break;}
//            }
//            white_cnt = 0;
//            black_cnt = 0;
//            space_cnt = 0;
//            for (int k = 0 ; k < 5 ; k++){
//                if (i+k < 15){
//                    check = omook[i+k][j]->text();
//                    if (check == "⚫") black_cnt++;
//                    else if (check == "⚪") {break;}
//                    else {
//                        space_cnt++;
//                        a = i+k;
//                        b = j;
//                    }
//                    if (black_cnt == 4 && space_cnt == 1) return 15*a+b;
//                }
//                else {break;}
//            }
//            white_cnt = 0;
//            black_cnt = 0;
//            space_cnt = 0;
//            for (int k = 0 ; k < 5 ; k++){
//                if (i+k < 15 && j+k < 15){
//                    check = omook[i+k][j+k]->text();
//                    if (check == "⚫") black_cnt++;
//                    else if (check == "⚪") {break;}
//                    else {
//                        space_cnt++;
//                        a = i+k;
//                        b = j+k;
//                    }
//                    if (black_cnt == 4 && space_cnt == 1) return 15*a+b;
//                }
//                else {break;}
//            }
//            white_cnt = 0;
//            black_cnt = 0;
//            space_cnt = 0;
//            for (int k = 0 ; k < 5 ; k++){
//                if (i+k < 15 && j-k > -1){
//                    check = omook[i+k][j-k]->text();
//                    if (check == "⚫") black_cnt++;
//                    else if (check == "⚪") {break;}
//                    else {
//                        space_cnt++;
//                        a = i+k;
//                        b = j+k;
//                    }
//                    if (black_cnt == 4 && space_cnt == 1) return 15*a+b;
//                }
//                else {break;}
//            }
//            white_cnt = 0;
//            black_cnt = 0;
//            space_cnt = 0;
//        }
//    }

//    // 우선순위 3
//    a = 0;
//    b = 0;
//    for (int i = 0 ; i < 15 ; i++){
//        for (int j = 0 ; j < 15 ; j++){
//            for (int k = 0 ; k < 5 ; k++){
//                if (j+k < 15){
//                    check = omook[i][j+k]->text();
//                    if (k == 0 && check == ""){
//                        a_num[a] = i;
//                        b_num[a] = j+k;
//                        a++;
//                        continue;
//                    }
//                    else if (k < 4 && check == "⚪") continue;
//                    else if (k == 4 && check == ""){
//                        a_num[a] = i;
//                        b_num[a] = j+k;
//                        a = rand()%2;
//                        return 15*a_num[a]+b_num[a];
//                    }
//                    else break;
//                }
//                else {
//                    break;
//                }
//            }
//            a = 0;
//            for (int k = 0 ; k < 5 ; k++){
//                if (i+k < 15){
//                    check = omook[i+k][j]->text();
//                    if (k == 0 && check == ""){
//                        a_num[a] = i+k;
//                        b_num[a] = j;
//                        a++;
//                        continue;
//                    }
//                    else if (k < 4 && check == "⚪") continue;
//                    else if (k == 4 && check == ""){
//                        a_num[a] = i+k;
//                        b_num[a] = j;
//                        a = rand()%2;
//                        return 15*a_num[a]+b_num[a];
//                    }
//                    else break;
//                }
//                else {
//                    break;
//                }
//            }
//            a = 0;
//            for (int k = 0 ; k < 5 ; k++){
//                if (i+k < 15 && j+k < 15){
//                    check = omook[i+k][j+k]->text();
//                    if (k == 0 && check == ""){
//                        a_num[a] = i+k;
//                        b_num[a] = j+k;
//                        a++;
//                        continue;
//                    }
//                    else if (k < 4 && check == "⚪") continue;
//                    else if (k == 4 && check == ""){
//                        a_num[a] = i+k;
//                        b_num[a] = j+k;
//                        a = rand()%2;
//                        return 15*a_num[a]+b_num[a];
//                    }
//                    else break;
//                }
//                else {
//                    break;
//                }
//            }
//            a = 0;
//            for (int k = 0 ; k < 5 ; k++){
//                if (i+k < 15 && j-k > -1){
//                    check = omook[i+k][j-k]->text();
//                    if (k == 0 && check == ""){
//                        a_num[a] = i+k;
//                        b_num[a] = j-k;
//                        a++;
//                        continue;
//                    }
//                    else if (k < 4 && check == "⚪") continue;
//                    else if (k == 4 && check == ""){
//                        a_num[a] = i+k;
//                        b_num[a] = j-k;
//                        a = rand()%2;
//                        return 15*a_num[a]+b_num[a];
//                    }
//                    else break;
//                }
//                else {
//                    break;
//                }
//            }
//            a = 0;
//        }
//    }

//    // 우선순위 5
//    for (int i = 0 ; i < 15 ; i++){
//        for (int j = 0 ; j < 15 ; j++){
//            for (int k = 0 ; k < 5 ; k++){
//                if (j+k < 15){
//                    check = omook[i][j+k]->text();
//                    if (k == 0 && check == ""){
//                        a_num[a] = i;
//                        b_num[a] = j+k;
//                        a++;
//                        continue;
//                    }
//                    else if (k < 4 && check == "⚫") continue;
//                    else if (k == 4 && check == ""){
//                        a_num[a] = i;
//                        b_num[a] = j+k;
//                        a = rand()%2;
//                        return 15*a_num[a]+b_num[a];
//                    }
//                    else break;
//                }
//                else {
//                    break;
//                }
//            }
//            a = 0;
//            for (int k = 0 ; k < 5 ; k++){
//                if (i+k < 15){
//                    check = omook[i+k][j]->text();
//                    if (k == 0 && check == ""){
//                        a_num[a] = i+k;
//                        b_num[a] = j;
//                        a++;
//                        continue;
//                    }
//                    else if (k < 4 && check == "⚫") continue;
//                    else if (k == 4 && check == ""){
//                        a_num[a] = i+k;
//                        b_num[a] = j;
//                        a = rand()%2;
//                        return 15*a_num[a]+b_num[a];
//                    }
//                    else break;
//                }
//                else {
//                    break;
//                }
//            }
//            a = 0;
//            for (int k = 0 ; k < 5 ; k++){
//                if (i+k < 15 && j+k < 15){
//                    check = omook[i+k][j+k]->text();
//                    if (k == 0 && check == ""){
//                        a_num[a] = i+k;
//                        b_num[a] = j+k;
//                        a++;
//                        continue;
//                    }
//                    else if (k < 4 && check == "⚫") continue;
//                    else if (k == 4 && check == ""){
//                        a_num[a] = i+k;
//                        b_num[a] = j+k;
//                        a = rand()%2;
//                        return 15*a_num[a]+b_num[a];
//                    }
//                    else break;
//                }
//                else {
//                    break;
//                }
//            }
//            a = 0;
//            for (int k = 0 ; k < 5 ; k++){
//                if (i+k < 15 && j-k > -1){
//                    check = omook[i+k][j-k]->text();
//                    if (k == 0 && check == ""){
//                        a_num[a] = i+k;
//                        b_num[a] = j-k;
//                        a++;
//                        continue;
//                    }
//                    else if (k < 4 && check == "⚫") continue;
//                    else if (k == 4 && check == ""){
//                        a_num[a] = i+k;
//                        b_num[a] = j-k;
//                        a = rand()%2;
//                        return 15*a_num[a]+b_num[a];
//                    }
//                    else break;
//                }
//                else {
//                    break;
//                }
//            }
//            a = 0;
//        }
//    }


//    while(true){
//        a = rand()%15;
//        b = rand()%15;
//        if (omook[a][b]->text() == ""){
//            return 15*a+b;
//        }
//    }
//}

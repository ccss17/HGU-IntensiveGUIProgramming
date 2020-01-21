#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(page_menu);      // begin program with menu page

    connectGame = new ConnectGame(19,19,5);
    connectBoard = new ConnectBoard();                  // board is initialized at creation
    connectServer = new ConnectServer();
    connectClient = new ConnectClient();
    ai1 = new AI1();
    cleanTransparentLayer = new QImage(600, 600, QImage::Format_ARGB32);
    cleanTransparentLayer->fill(QColor(0,0,0,0));

    playing = false;
    gameChoise = gameType_none;

    server_color = BLACK;
    client_color = WHITE;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete connectGame;
    delete connectBoard;
    delete connectServer;
    delete connectClient;
    delete ai1;
    delete cleanTransparentLayer;
}


/**** game flow functions for game choice ****/
void MainWindow::gameflow_mousePress_singleplay(QPoint pos)
{
    if(playing)
    {
        /* 플레이어가 클릭한 자리에 돌을 그린다 */
        QPoint logicCoor = connectBoard->coorToArrayIndex(pos);
        /* 보드 위를 클릭 해야지만 게임이 진행 된다 */
        if(logicCoor != QPoint(-1, -1) && connectGame->empty_place(logicCoor.x(), logicCoor.y()))
        {
            if(connectGame->empty_place(logicCoor.x(),logicCoor.y()))
            {
                connectGame->place_stone(logicCoor.x(),logicCoor.y());
                connectBoard->drawStone(connectBoard->getPointInStoneQPointArray(logicCoor), connectGame->firstPlayerTurn());
                update();

            }
            /** check for player victory **/
            if(connectGame->k_in_a_row(logicCoor.x(),logicCoor.y()))
            {
                playing = false;
            }
            else if(connectGame->full_board())
            {
                playing = false;
            }
            else
            {
                /* 컴퓨터는 플레이어가 돌은 놓은 자리에서 돌을 한번 더 놀수 있다고 가정할 때 가장 이득이 되는 장소를 찾아 그 장소를 막는다 */
                double opponent_best = 0;
                double temp_move = 0;
                QPoint opponent_best_move;
                int count_33536 = 0;    // considerable defensive position min value
                int count_4480 = 0;

                int player_current_threat =0;

                /// only before switching tunrs
                State_type opponent_turn = connectGame->getCurrent_turn();
                State_type computer_turn;
                if(opponent_turn==BLACK)
                    computer_turn = WHITE;
                else computer_turn = BLACK;

                for(int i=0; i<19; i++)
                {
                    for(int j=0; j<19; j++)
                    {
                        if(connectGame->empty_place(j, i))
                        {
                            temp_move = ai1->moveEval(*connectGame, j, i, connectGame->getCurrent_turn());
                            if(temp_move >= opponent_best)
                            {
                                if(temp_move >= 33536)
                                    count_33536++;
                                if(temp_move >= 4480)
                                    count_4480++;

                                opponent_best = temp_move;
                                opponent_best_move = QPoint(j,i);
                            }
                            if(ai1->searchThreats(*connectGame, logicCoor.y(), logicCoor.x(), opponent_turn) > player_current_threat)
                                player_current_threat = ai1->searchThreats(*connectGame, logicCoor.y(), logicCoor.x(), opponent_turn);
                        }
                    }
                }
                if(player_current_threat<2)
                {
                    int temp_my_threat = 0;
                    int this_pos_threat = 0;
                    for(int i=0; i<19; i++)
                    {
                        for(int j=0; j<19; j++)
                        {
                            if(connectGame->empty_place(j, i))
                            {
                                this_pos_threat = ai1->searchThreats(*connectGame, j, i, computer_turn);
                                if(this_pos_threat>3 && this_pos_threat>temp_my_threat)
                                {
                                    opponent_best_move = QPoint(j,i);
                                    temp_my_threat = this_pos_threat;
                                }
                            }
                        }
                    }
                }

                /** change turn **/
                if(connectGame->turn_over())
                {
                    connectGame->switch_turn();
                }
                /* 컴퓨터가 위에서 계산한 결과에 따라 자신의 돌을 놓는다 */
                connectGame->place_stone(opponent_best_move.x(),opponent_best_move.y());
                connectBoard->drawStone(connectBoard->getPointInStoneQPointArray(opponent_best_move), connectGame->firstPlayerTurn());
                update();

                /** check for computer victory **/
                if(connectGame->k_in_a_row(opponent_best_move.x(),opponent_best_move.y()))
                {
                    playing = false;
                }
                else if(connectGame->full_board())
                {
                    playing = false;
                }
                /** change turn **/
                else if(connectGame->turn_over())
                {
                    connectGame->switch_turn();
                }
            }
        }
    }
}

void MainWindow::gameflow_mouseMove_singleplay(QPoint pos)
{
    /* just did same as multiplyer... if computer needs more time, then it should be edited I think*/
    if(playing)
    {
        connectBoard->clearShadowLayer();
        update();
        QPoint logicCoor = connectBoard->coorToArrayIndex(pos);
        if(logicCoor != QPoint(-1, -1))
        {
            if(connectGame->empty_place(logicCoor.x(),logicCoor.y()))
            {
                connectBoard->drawShadowStone(connectBoard->getPointInStoneQPointArray(logicCoor), connectGame->firstPlayerTurn());
//                qDebug()<<"projecting shadow...";
                update();
            }
        }
    }
}

void MainWindow::gameflow_mousePress_multiplay(QPoint pos)         // for mouse press event
{
    if(playing)
    {
        QPoint logicCoor = connectBoard->coorToArrayIndex(pos);
        if(logicCoor != QPoint(-1, -1))
        {
            if(connectGame->empty_place(logicCoor.x(),logicCoor.y()))
            {
//                qDebug() << "calculated logicCoor is " << logicCoor;
                connectGame->place_stone(logicCoor.x(),logicCoor.y());
//                qDebug() << "drawing!" << test++;
                connectBoard->drawStone(connectBoard->getPointInStoneQPointArray(logicCoor), connectGame->firstPlayerTurn());
                update();

                if(connectGame->k_in_a_row(logicCoor.x(),logicCoor.y()))
                {
                    playing = false;
                }
                else if(connectGame->full_board())
                {
                    playing = false;
                }
                else if(connectGame->turn_over())
                {
                    connectGame->switch_turn();
                }
            }
        }
    }
}

void MainWindow::gameflow_mouseMove_multiplay(QPoint pos)
{
    if(playing)
    {
        connectBoard->clearShadowLayer();
        update();
        QPoint logicCoor = connectBoard->coorToArrayIndex(pos);
        if(logicCoor != QPoint(-1, -1))
        {
            if(connectGame->empty_place(logicCoor.x(),logicCoor.y()))
            {
                connectBoard->drawShadowStone(connectBoard->getPointInStoneQPointArray(logicCoor), connectGame->firstPlayerTurn());
//                qDebug()<<"projecting shadow...";
                update();
            }
        }
    }
}

void MainWindow::gameflow_mousePress_host(QPoint pos)
{
//    connectServer->checkBytesAvailable();
//    connectServer->onReadyRead();
    if(playing && connectGame->getCurrent_turn() == server_color)
    {
        QPoint logicCoor = connectBoard->coorToArrayIndex(pos);
        if(logicCoor != QPoint(-1, -1))
        {
            if(connectGame->empty_place(logicCoor.x(),logicCoor.y()))
            {
                connectServer->sendDataType("stone_move");
                connectServer->sendStoneMoveData(logicCoor);
            }
            connectGame->place_stone(logicCoor.x(),logicCoor.y());
    //                qDebug() << "drawing!" << test++;
            connectBoard->drawStone(connectBoard->getPointInStoneQPointArray(logicCoor), connectGame->firstPlayerTurn());
            update();
            if(connectGame->k_in_a_row(logicCoor.x(),logicCoor.y()))
            {
                playing = false;
            }
            else if(connectGame->full_board())
            {
                playing = false;
            }
            else if(connectGame->turn_over())
            {
                connectGame->switch_turn();
            }
        }
    }
}

void MainWindow::gameflow_mouseMove_host(QPoint pos)
{

}

void MainWindow::gameflow_mousePress_join(QPoint pos)
{
    if(playing && connectGame->getCurrent_turn() == client_color)
    {
        QPoint logicCoor = connectBoard->coorToArrayIndex(pos);
        if(logicCoor != QPoint(-1, -1))
        {
            if(connectGame->empty_place(logicCoor.x(),logicCoor.y()))
            {
                connectClient->sendDataType("stone_move");
                connectClient->sendStoneMoveData(logicCoor);
            }
            connectGame->place_stone(logicCoor.x(),logicCoor.y());
            connectBoard->drawStone(connectBoard->getPointInStoneQPointArray(logicCoor), connectGame->firstPlayerTurn());
            update();
            if(connectGame->k_in_a_row(logicCoor.x(),logicCoor.y()))
            {
                playing = false;
            }
            else if(connectGame->full_board())
            {
                playing = false;
            }
            else if(connectGame->turn_over())
            {
                connectGame->switch_turn();
            }
        }
    }
}

void MainWindow::gameflow_mouseMove_join(QPoint pos)
{

}


void MainWindow::onOpponentMadeMove(QPoint pos)
{
    qInfo() << "opponent made move!";
    if(playing && connectGame->getCurrent_turn() == client_color)
    {
        QPoint logicCoor = connectBoard->coorToArrayIndex(pos);
        if(logicCoor != QPoint(-1, -1))
        {
            if(connectGame->empty_place(logicCoor.x(),logicCoor.y()))
            {
                connectClient->sendDataType("stone_move");
                connectClient->sendStoneMoveData(logicCoor);
            }
            connectGame->place_stone(logicCoor.x(),logicCoor.y());
            connectBoard->drawStone(connectBoard->getPointInStoneQPointArray(logicCoor), connectGame->firstPlayerTurn());
            update();
            if(connectGame->k_in_a_row(logicCoor.x(),logicCoor.y()))
            {
                playing = false;
            }
            else if(connectGame->full_board())
            {
                playing = false;
            }
            else if(connectGame->turn_over())
            {
                connectGame->switch_turn();
            }
        }
    }

}

/************ page_menu ************/
void MainWindow::on_pushButton_single_clicked()
{
    gameChoise = gameType_single;
    ui->stackedWidget->setCurrentIndex(page_game);
}
void MainWindow::on_pushButton_multi_clicked()
{
    gameChoise = gameType_multi;
    ui->stackedWidget->setCurrentIndex(page_game);
}

void MainWindow::on_pushButton_host_clicked()
{
     gameChoise = gameType_host;
     ui->stackedWidget->setCurrentIndex(page_game);
     connectServer->openServer();

}
void MainWindow::on_pushButton_join_clicked()
{
     gameChoise = gameType_join;
     ui->stackedWidget->setCurrentIndex(page_join);
}


void MainWindow::on_pushButton_joinServer_clicked()
{
    gameChoise = gameType_join;
    connectClient->makeConnectionTo(ui->lineEdit_serverAddress->text());
    connect(connectClient->getSocket(), SIGNAL(connected()), this, SLOT(onClientConnectedToServer()));
}

void MainWindow::onClientConnectedToServer()
{
    ui->stackedWidget->setCurrentIndex(page_game);
    connect(connectClient, SIGNAL(opponentMadeMove(QPoint)), this, SLOT(onOpponentMadeMove(QPoint)));
    connect(connectServer, SIGNAL(opponentMadeMove(QPoint)), this, SLOT(onOpponentMadeMove(QPoint)));
}


// NOT USED ...
/************ page_name ************/
 void MainWindow::on_lineEdit_userName_textChanged(const QString &arg1)
{

}

void MainWindow::on_lineEdit_userName_returnPressed()
{
    on_pushButton_submitName_clicked();
}

void MainWindow::on_pushButton_submitName_clicked()
{

}


/************ stack view ************/
/* page_game INITIALIZATION for each game type */
void MainWindow::on_stackedWidget_currentChanged(int currentPageIdx)
{
    qInfo() << currentPageIdx;
    switch (currentPageIdx) {
    case page_game:
        qInfo() << "starting game page";
        playing = true;
        this->setMouseTracking(true);
        ui->centralwidget->setMouseTracking(true);
        ui->stackedWidget->setMouseTracking(true);
        ui->page_game->setMouseTracking(true);
        /** all the widgets in the heirarchy must have setMouseTracking true **/

        if(gameChoise == gameType_host)
        {
            connectServer->openServer();
        }
        else if(gameChoise == gameType_join)
        {
        }
        break;
    case page_join:
        break;
    case page_menu:
        qInfo() << "returning to menu";
        playing = false;
        this->setMouseTracking(false);
        ui->centralwidget->setMouseTracking(false);
        ui->stackedWidget->setMouseTracking(false);
        ui->page_game->setMouseTracking(false);

        if(gameChoise != gameType_none)
        {
            delete connectBoard;
            connectBoard = new ConnectBoard();
            delete connectGame;
            connectGame = new ConnectGame(19,19,5);
        }

        if(gameChoise == gameType_host)
        {
            connectServer->closeServer();
            gameChoise = gameType_none;
        }
        else if(gameChoise == gameType_join)
        {
            connectClient->closeConnection();
            gameChoise = gameType_none;
        }
    }
}


/************ events ************/
void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QRect dirtyRect = event->rect();
    /** the layers must be painted in the right order; bottom layers are painted first**/
    painter.drawImage(dirtyRect, *connectBoard->getBoardLayer(), dirtyRect);
    painter.drawImage(dirtyRect, *connectBoard->getShadowLayer(), dirtyRect);
    painter.drawImage(dirtyRect, *connectBoard->getStoneLayer(), dirtyRect);
}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    switch (gameChoise) {
    case gameType_single:
        gameflow_mousePress_singleplay(event->pos());
        break;
    case gameType_multi:
        gameflow_mousePress_multiplay(event->pos());
        break;
    case gameType_host:
        gameflow_mousePress_host(event->pos());
        break;
    case gameType_join:
        gameflow_mousePress_join(event->pos());
        break;
    default:
        event->ignore();
    }
}
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    switch (gameChoise) {
    case gameType_single:
        gameflow_mouseMove_singleplay(event->pos());
        break;
    case gameType_multi:
        gameflow_mouseMove_multiplay(event->pos());
        break;
    case gameType_host:
        gameflow_mouseMove_host(event->pos());
        break;
    case gameType_join:
        gameflow_mouseMove_join(event->pos());
        break;
    default:
        event->ignore();
    }
}


// grey, green (other background color)
//background-color: rgb(40, 40, 45);
//background-color: rgb(170, 200, 165);

void MainWindow::on_pushButton_exit_clicked()
{
    ui->stackedWidget->setCurrentIndex(page_menu);
}

/*
 * 버그 목록
 * 2. client에서 나갔다가 다시 들어가면 서버가 시작했을 때 왼쪽 위 코너에 추가로 돌이 놓이면서 게임 불가
 *
 *
 */


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


//    connect(connectClient, SIGNAL(opponentMadeMove(QPoint)), this, SLOT(onOpponentMadeMove(QPoint)));
    connect(connectServer, SIGNAL(opponentMadeMove(QPoint)), this, SLOT(onOpponentMadeMove(QPoint)));


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
                /** draw stone on the clicked position **/
                connectGame->place_stone(logicCoor.x(),logicCoor.y());
                connectBoard->drawStone(connectBoard->getPointInStoneQPointArray(logicCoor), connectGame->firstPlayerTurn());
                update();
                /** check for gameover situation **/
                if(connectGame->k_in_a_row(logicCoor.x(),logicCoor.y()))
                {
                    playing = false;
                }
                else if(connectGame->full_board())
                {
                    playing = false;
                }
                /** 순서 변경은 정보를 받을 때 한다 **/
                else if(connectGame->turn_over())
                {
                    connectGame->switch_turn();
                }
                /** send movement data at the end of the function -- after switching turn!**/
                connectServer->sendDataType("stone_move");
                connectServer->sendStoneMoveData(logicCoor);
            }
        }
    }
}

void MainWindow::gameflow_mouseMove_host(QPoint pos)
{

}

void MainWindow::gameflow_mousePress_join(QPoint pos)
{
    /* 마우스를 클릭해도 자신의 차례가 오지 않았거나 자리가 이미 차있는 곳에서는 아무 작업도 수행하지 않도록 해야한다 */
    if(playing && connectGame->getCurrent_turn() == client_color)
    {
        /* 클릭한 x,y coordinate좌표를 i,j 2d array의 index 값으로 각각 대응시킬 수 있도록 변환한다 */
        QPoint logicCoor = connectBoard->coorToArrayIndex(pos);
        /* 클릭한 좌표가 -1,-1 즉 돌을 놓을 수 없는 자리라면 아무일도 실행하지 않는다 */
        if(logicCoor != QPoint(-1, -1))
        {
            /* 현재 마우스로 클릭한 곳에 돌이 이미 들어가 있는지 확인한다 */
            /* 현재 비어있는 공간임을 확인하면 아래 if문을 실행한다 */
            if(connectGame->empty_place(logicCoor.x(),logicCoor.y()))
            {
                /* 서버에게 클릭한 곳의 위치 정보를 전송한다 */
                connectClient->sendDataType("stone_move");
                connectClient->sendStoneMoveData(logicCoor);

                connectGame->place_stone(logicCoor.x(),logicCoor.y());
                connectBoard->drawStone(connectBoard->getPointInStoneQPointArray(logicCoor), connectGame->firstPlayerTurn());
                update();
                /* 방금 내가 둔 돌이 gameover 조건을 총족시키는지 확인해 보아라 */
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

void MainWindow::gameflow_mouseMove_join(QPoint pos)
{

}

/* 네트워크 연결을 통해 상대가 돌과 관련된 정보를 전송했을 시 이것이 실행된다 */
void MainWindow::onOpponentMadeMove(QPoint pos)
{

    /* 클라이언트는 이 slot이 발생하면 먼저 받은 수를 보드에 update 해야 한다. 2번째로 자신의 차례로 인지하고 수를 하나 둘 수 있어야 한다 */
    if(gameChoise == gameType_join)
    {
//        qInfo() << "opponent(server) made move!";
//        qInfo() << connectGame->getCurrent_turn() << "==?==" << client_color;
        /* connectGame의 current_turn은 기본적으로 흑 시작이다. 하지만 클라이언트는 서버로부터 흑의 위치를 입력받고 백돌을 두는 것으로 시작한다. */
        /* 돌을 두는 것이 규칙에 적합한지는 각 서버나 클라이언트에서 먼저 확인하기 때문에 계산이 맞다고 가정하고 그냥 바로 돌을 놓는다. */
        /* 이 slot함수가 불렸다는 것은 상대 프로그램에서는 최소한 이 수까지는 게임이 진행되고 있다는 것이기 때문에 따로 gameover인지 확인할 필요는 없다 */
        /* 이 구조는 서버와 클라이언트가 각각 서로에게 보낸 정보는 전적으로 신뢰하는 구조이다 */
        /* 만약 직접 입력을 통해 좌표를 입력하게 된다면, 입력에 대해 확인하는 절차를 추가해야 할 것이다 */
        connectGame->place_stone(pos.x(), pos.y());             // 이건 시스템 클래스인데..? 아 돌을 놓을 수 없는 자리는 클라인언트 자체에서 계산하도록 하자
        connectBoard->drawStone(connectBoard->getPointInStoneQPointArray(pos), connectGame->firstPlayerTurn());    // 차례는 자기 차례이지만 여기에서 그리는 돌은 상대 돌이다
        update();
        /* 여기까지 클라이언트는 서버에서 입력받은 위치에 흑돌을 놓았고, 이것을 자신의 connectGame의 stone_array에 저장하였다. */
        /* 여기까지 상대가 둔 돌을 그리는 작업을 마치고 자신의 차례로 넘어가기 전에 먼저 이 수가 gameover의 조건을 만족시키는지 확인한다 */
        /* 돌의 좌표만 넘어오고 이겼는지 졌는지는 따로 계산하지 않기 때문에, 클라이언트에서 직접 확인하고 그에 적절한 대응을 해야한다. */
        if(connectGame->k_in_a_row(pos.x(), pos.y()))
            playing = false;
        else if(connectGame->full_board())
            playing = false;
        else
            connectGame->switch_turn();                     // 마지막으로 gameover의 조건이 맞지 않을시 자신의 차례로 넘긴다
    }

    /* 아직까지 설계한 바로는 서버가 흑이고 먼저 수를 둔다 */
    else if(gameChoise == gameType_host)
    {
        qInfo() << "opponent(client) made move!";
        qInfo() << connectGame->getCurrent_turn() << "==?==" << client_color;
        if(playing && connectGame->getCurrent_turn() == client_color)
        {
            connectGame->place_stone(pos.x(),pos.y());      // 이건 시스템 클래스인데..? 아 돌을 놓을 수 없는 자리는 클라인언트 자체에서 계산하도록 하자
            connectBoard->drawStone(connectBoard->getPointInStoneQPointArray(pos), connectGame->firstPlayerTurn());
            update();
        }
        if(connectGame->k_in_a_row(pos.x(),pos.y()))
        {
            playing = false;
        }
        else if(connectGame->full_board())
        {
            playing = false;
        }
        connectGame->switch_turn();
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


//     connect(connectClient, SIGNAL(opponentMadeMove(QPoint)), this, SLOT(onOpponentMadeMove(QPoint)));
     connect(connectServer, SIGNAL(opponentMadeMove(QPoint)), this, SLOT(onOpponentMadeMove(QPoint)));


}


void MainWindow::on_pushButton_joinServer_clicked()
{
    gameChoise = gameType_join;
    connectClient->makeConnectionTo(ui->lineEdit_serverAddress->text());
    connect(connectClient->getSocket(), SIGNAL(connected()), this, SLOT(onClientConnectedToServer()));


//    connect(connectClient, SIGNAL(opponentMadeMove(QPoint)), this, SLOT(onOpponentMadeMove(QPoint)));
    connect(connectServer, SIGNAL(opponentMadeMove(QPoint)), this, SLOT(onOpponentMadeMove(QPoint)));


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

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(page_menu);
}

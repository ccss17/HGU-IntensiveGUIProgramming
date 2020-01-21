#include "testwindow.h"
#include "ui_testwindow.h"

TestWindow::TestWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestWindow)
{
    ui->setupUi(this);
    connectGame = new ConnectGame(19,19,5);
    connectBoard = new ConnectBoard();
    ai1 = new AI1;
}

TestWindow::~TestWindow()
{
    delete ai1;
    delete connectBoard;
    delete connectGame;
    delete ui;
}

void TestWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QRect dirtyRect = event->rect();
    /** the layers must be painted in the right order; bottom layers are painted first**/
    painter.drawImage(dirtyRect, *connectBoard->getBoardLayer(), dirtyRect);
    painter.drawImage(dirtyRect, *connectBoard->getShadowLayer(), dirtyRect);
    painter.drawImage(dirtyRect, *connectBoard->getStoneLayer(), dirtyRect);
}


/* 돌을 놓기 위해 마우스를 클릭!! */
void TestWindow::mousePressEvent(QMouseEvent *event)
{

    /* 플레이어가 클릭한 자리에 돌을 그린다 */
    QPoint logicCoor = connectBoard->coorToArrayIndex(event->pos());

    /* 보드 위를 클릭 해야지만 게임이 진행 된다 */
    if(logicCoor != QPoint(-1, -1) && connectGame->empty_place(logicCoor.x(), logicCoor.y()))
    {
        if(connectGame->empty_place(logicCoor.x(),logicCoor.y()))
        {
//                qDebug() << "calculated logicCoor is " << logicCoor;
            connectGame->place_stone(logicCoor.x(),logicCoor.y());
//                qDebug() << "drawing!" << test++;
            connectBoard->drawStone(connectBoard->getPointInStoneQPointArray(logicCoor), connectGame->firstPlayerTurn());
            update();
//            if(connectGame->turn_over())
//            {
//                connectGame->switch_turn();
//            }
        }


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
    //                qInfo() << temp_move;

                    if(temp_move >= opponent_best)
                    {
    //                    qInfo() << "[" << j << ", " << i << "]: " << temp_move<<">"<< "     [" << opponent_best_move.x() << ", " << opponent_best_move.y() << "]: " <<opponent_best;
                        if(temp_move >= 33536)
                            count_33536++;
                        if(temp_move >= 4480)
                            count_4480++;

                        opponent_best = temp_move;
                        opponent_best_move = QPoint(j,i);

                         /* 위에서 컴퓨터가 찾은 플레이어에게 가장 좋은 장소를 막은 것이 정말 좋은 수 였는지 다시한번 판단한다 */
                        if(ai1->searchThreats(*connectGame, logicCoor.y(), logicCoor.x(), opponent_turn)<3)
                        {
                            // 미완성...
                        }
                    }
                    if(ai1->searchThreats(*connectGame, logicCoor.y(), logicCoor.x(), opponent_turn) > player_current_threat)
                        player_current_threat = ai1->searchThreats(*connectGame, logicCoor.y(), logicCoor.x(), opponent_turn);
                }
            }
        }

//        qInfo() << ai1->searchThreats(*connectGame, logicCoor.y(), logicCoor.x(), opponent_turn);
//        qInfo() << ai1->searchThreats(*connectGame, logicCoor.y(), logicCoor.x(), computer_turn);

        /* 플레이어에게 3이상의 threat이 없을 때, 컴퓨터가 자신이 확실하게 이길 수 있는 수가 있는지 확인한다 */
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
    //                    qInfo() << "[" << j << ", " << i << "]: " <<  this_pos_threat;
                        if(this_pos_threat>3 && this_pos_threat>temp_my_threat)
                        {
                            qInfo()<<"hello:: "<<this_pos_threat;
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

        /** change turn **/
        if(connectGame->turn_over())
        {
            connectGame->switch_turn();
        }

    }
}

void TestWindow::mouseMoveEvent(QMouseEvent *event)
{

}

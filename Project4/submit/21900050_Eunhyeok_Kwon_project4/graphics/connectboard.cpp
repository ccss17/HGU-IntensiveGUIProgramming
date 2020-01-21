#include "connectboard.h"

ConnectBoard::ConnectBoard()
{
    /** initialize layer images **/
    boardLayer = new QImage(600, 600, QImage::Format_RGB32);
    shadowLayer = new QImage(600, 600, QImage::Format_ARGB32);      // alpha channel available for transparent background
    stoneLayer = new QImage(600, 600, QImage::Format_ARGB32);       // alpha channel available for transparent background

    boardLayer->fill(QColor(190, 145, 75));
    shadowLayer->fill(QColor(0,0,0,0));                             // transparent background
    stoneLayer->fill(QColor(0,0,0,0));                              // transparent background

    /** set up variables for drawing board and other drawing calculations that uses coordinates **/
    frame_size = 600;                                               // frame size; the container
    size = 19;                                                      // number of lines in a row (number of squares in a row +1)
    bm = 10;                                                        // board margin             10
    ss = round((frame_size - bm*2) / (size+0.5));                   // size of each square      30
    bp = (frame_size - bm*2 - ss*(size - 1))/2;                     // board padding            20
    shadowRad = ss*0.25;
    stoneRad = ss*0.46;

    stoneQPointArray = new QPoint* [size];
    for(int i=0; i<size; i++)
    {
        stoneQPointArray[i] = new QPoint [size];
    }

    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            stoneQPointArray[i][j] = QPoint((bm+bp)+ss*j, (bm+bp)+ss*i);
        }
    }

    drawBoardLayer();                                               // most basic initialization of board

}

ConnectBoard::~ConnectBoard()
{
    delete boardLayer;
    delete shadowLayer;
    delete stoneLayer;

    for(int i=0; i<size; i++)
    {
        delete []stoneQPointArray[i];
    }
    delete []stoneQPointArray;
}


/*** layer getter function ***/
QImage *ConnectBoard::getBoardLayer() const
{
    return boardLayer;
}

QImage *ConnectBoard::getShadowLayer() const
{
    return shadowLayer;
}

QImage *ConnectBoard::getStoneLayer() const
{
    return stoneLayer;
}


/*** drawing functions for layers ***/
void ConnectBoard::drawBoardLayer()
{
    QPainter painter(boardLayer);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.fillRect(bm, bm, frame_size-bm*2, frame_size-bm*2, QColor(230, 180, 100));
    painter.setPen(QColor(100,70,30));
    for(int i=0; i<size; i++)
    {
        painter.drawLine(0+(bm+bp), i*ss+(bm+bp), frame_size-(bm+bp), i*ss+(bm+bp));
        painter.drawLine(i*ss+(bm+bp), 0+(bm+bp), i*ss+(bm+bp), frame_size-(bm+bp));
    }

    /** draws the little dots; temporary function only for 19x19 board **/
    if(size == 19)
    {
        painter.setBrush(QColor(110,80,40));
        int rad = ss*0.2/2;
        for(int i=0; i<size; i+=3)
            for(int j=0; j<size; j+=3)
                if((i-3)%2==0 && (j-3)%2==0)
                    painter.drawEllipse(QPoint(0+(bm+bp)+i*ss, j*ss+(bm+bp)), rad, rad);
    }
}

void ConnectBoard::drawOnBoardForTesting()
{
    QPainter painter(boardLayer);
    painter.setBrush(QColor(255, 255, 255));
    painter.drawEllipse(100, 100, 50, 50);
}

void ConnectBoard::drawShadowStone(QPoint center, bool firstPlayerTurn)
{
    QPainter painter(shadowLayer);
    painter.setRenderHint(QPainter::Antialiasing);
    if(firstPlayerTurn)
    {
        painter.setPen(Qt::NoPen);
        painter.setBrush(QColor(50, 50, 50, 180));
    }
    else
    {
        painter.setPen(Qt::NoPen);
        painter.setBrush(QColor(255, 255, 255, 180));
    }
    painter.drawEllipse(center, shadowRad, shadowRad);
}

void ConnectBoard::clearShadowLayer()
{
    shadowLayer->fill(QColor(0,0,0,0));
}

void ConnectBoard::drawStone(QPoint center, bool firstPlayerTurn)
{
    QPainter painter(stoneLayer);
    painter.setRenderHint(QPainter::Antialiasing);
    if(firstPlayerTurn)
    {
        // draw black stone
        painter.setPen(Qt::black);
        painter.setBrush(QColor(10, 10, 10, 255));
    }
    else{
        // draw white stone
        painter.setPen(Qt::gray);
        painter.setBrush(QColor(255, 255, 255, 255));
    }
    painter.drawEllipse(center, stoneRad, stoneRad);
}


/*** support functions ***/
QPoint ConnectBoard::coorToArrayIndex(QPoint pos)
{
    if(bm + bp - ss/2 <= pos.x() && pos.x() <= size*ss + ss/2 &&
            bm + bp - ss/2 <= pos.y() && pos.y() <= size*ss + ss/2)
    {
        int x = round((pos.x() - bm - bp + ss/2) / ss);
        int y = round((pos.y() - bm - bp + ss/2) / ss);

        if(0 <= x && x <= size-1 && 0 <= y && y <= size-1)
        {
            return QPoint(x,y);
        }
    }
    return QPoint(-1,-1);
}

QPoint ConnectBoard::getPointInStoneQPointArray(QPoint logicCoor) const
{
    return stoneQPointArray[logicCoor.y()][logicCoor.x()];
}


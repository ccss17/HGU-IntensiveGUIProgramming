#ifndef CONNECTBOARD_H
#define CONNECTBOARD_H

#include <QPainter>
#include <QDebug>

#include <cmath>                    // used for rounding numbers

class ConnectBoard
{
public:
    ConnectBoard();
    ~ConnectBoard();

    /*** layer getter function ***/
    QImage *getBoardLayer() const;
    QImage *getShadowLayer() const;
    QImage *getStoneLayer() const;

    /*** drawing functions for each layers ***/
    void drawBoardLayer();              // draws game board on boardLayer
    void drawOnBoardForTesting();
    void drawShadowStone(QPoint center, bool firstPlayerTurn);       // draws shadow stone on shadowLayer; color 0 = black, 1 = white
    void clearShadowLayer();
    void drawStone(QPoint center, bool firstPlayerTurn);    // draws black stone if first player's turn

    /*** support functions ***/
    QPoint coorToArrayIndex(QPoint p);  // translates actual coordinate to logical coordinate
                                        // this function is quite special, becuase it also checks if the mouse position is inside the board and only returns the correct logical coordinate if the check was satisfied


    QPoint getPointInStoneQPointArray(QPoint logicCoor) const;

private:
    QImage *boardLayer;
    QImage *shadowLayer;
    QImage *stoneLayer;

    int frame_size;                     // frame size (must be square)
    int size;                           // size of the board -- optimized for 19x19 board, seems to not work above 70x70 board
    int bm;                             // board margin
    int ss;                             // square size -- size of each square
    int bp;                             // board padding
    int shadowRad;                      // radius of stone shadow
    int stoneRad;                       // radius of stone

    QPoint **stoneQPointArray;          // 2d array for storing x,y coordinate of point where stones will be placed
};

#endif // CONNECTBOARD_H

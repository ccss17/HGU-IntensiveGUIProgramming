#ifndef AI1_H
#define AI1_H

#include "mechanism/State_type.h"
#include "mechanism/Stone_array.h"
#include "mechanism/connectgame.h"

#include <algorithm>
#include <cstdlib>
#include <cmath>

#include <QDebug>

class AI1
{
public:
    AI1();
    ~AI1();

    double moveEval(ConnectGame &game, int x, int y, State_type turn);
    int searchThreats(ConnectGame &game, int x, int y, State_type turn);
private:
//    int array[19][19] = {{0}};
};

#endif // AI1_H

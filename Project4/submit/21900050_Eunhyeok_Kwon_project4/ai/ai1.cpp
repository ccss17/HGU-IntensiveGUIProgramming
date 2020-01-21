#include "ai1.h"

AI1::AI1()
{
}

AI1::~AI1()
{
}

double AI1::moveEval(ConnectGame &game, int x, int y, State_type turn)
{
    int opponent;
    if(turn == BLACK)
        opponent = WHITE;
    else
        opponent = BLACK;

    int count = 0;      // for qInfo()

    int weights[5] = {int(std::pow(2,10)), int(std::pow(2,9)), int(std::pow(2,8)), int(std::pow(2,7)), int(std::pow(2,6))};
    int empty_weight = 2;

    int i = y;
    int j = x;
    int di;
    int dj;
    double evalPoint = 0;
    double subEval;

    int pointValue;
    for(int q=0; q<4; q++)
    {
        subEval = 1;
        for(int l=0; l<2; l++)
        {
            for(int k=0; k<4; k++)
            {
                di = i + (k+1) * (std::min(std::abs(q-2), 1)) * (l*2 - 1);
                dj = j + (k+1) * std::min(q, 1) * (-2*l + 1) * (1 - (int)(q/3)*2);
//                qInfo() << "(" << di << " ," << dj << ")";
                if(di<0 || di>=19 || dj<0 || dj>=19)
                    break;
                pointValue = game.get_value(di, dj);
                if(pointValue == opponent)
                    break;
                else if(pointValue == EMPTY)
                    subEval *= empty_weight;
                else if(pointValue == turn)
                    subEval *= weights[k];
//                qInfo() << count++ << ": " << pointValue;
            }
        }
        evalPoint += subEval;
    }

    return evalPoint;
}

int AI1::searchThreats(ConnectGame &game, int x, int y, State_type turn)
{
    Stone_array copy = game.stone_array;

    int opponent;
    if(turn == BLACK)
        opponent = WHITE;
    else
        opponent = BLACK;

    int i = y;
    int j = x;
    int di;
    int dj;
    int wri;
    int wrj;
    double threats = 0;
    int pointValue;
    int count =0;
    int myStone_inRow=0;
    bool flag_noThreat = false;

    copy.set_value(x, y, turn);

    for(int q=0; q<4; q++)
    {
        for(int p=0; p<4; p++)
        {
            di = i + std::min(-std::min(((q+1)%3), 1), 0) * p;
            dj = j + std::min(5- q*2, 1) * std::min(q, 1) * p;
//            qInfo() << "[" <<di<<", "<<dj<<"]";
            if(di<0 || di>=19 || dj<0 || dj>=19)
                break;
            pointValue = copy.get_value(di, dj);
            if(pointValue == opponent)
                break;
//            qInfo() <<  "[" <<di<<", "<<dj<<"]"<<count++ <<": " << pointValue;
            myStone_inRow=0;
            for(int r=0; r<4; r++)
            {
                /// 4 크기의 window중에 3개가 my stone이면 threat ++
                wri = di + std::min(-std::min(((q+1)%3), 1), 0) * -r;
                wrj = dj + std::min(5- q*2, 1) * std::min(q, 1) * -r;

                if(wri<0 || wri>=19 || wrj<0 || wrj>=19)
                    break;
                pointValue = copy.get_value(wrj, wri);
//                qInfo() <<  "     [" <<wrj<<", "<<wri<<"]"<<count++ <<": " << pointValue;
//                qInfo() << "    "<<pointValue;
                if(pointValue == opponent)
                {
                    break;
                    flag_noThreat = true;
                }
                else if(pointValue == turn)
                    myStone_inRow++;
            }
            if(!flag_noThreat && myStone_inRow >=3)
            {
                flag_noThreat = false;
//                qInfo() << "    counted as threat";
                threats++;
                if(myStone_inRow == 4){
                    threats = 99;
                    break;
                }
            }
//            qInfo()<<" ----- ";
        }
//        qInfo() << " ";
    }
//    qInfo() << threats;
    return threats;
}

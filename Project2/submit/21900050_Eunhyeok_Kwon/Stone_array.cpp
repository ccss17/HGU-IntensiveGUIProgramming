#include "Stone_array.h"

#include <QDebug>

// constructor
Stone_array::Stone_array(int y_len, int x_len): M(y_len), N(x_len)
{
    p = new Point*[M];  // M 개의 Point pointer list를 만든다
    for(int i=0; i<M; i++)
    {
        p[i] = new Point[N];    // x 개의 Point list를 만든다
    }
}

// destructor (free memory)
Stone_array::~Stone_array()
{
    for(int i=0; i<M; i++)
    {
        delete []p[i];
    }
    delete []p;
}


// other functions
void Stone_array::init()
{
    int i,j;
    for(i=0; i<M; i++)
    {
        for(j=0; j<N; j++)
        {
            p[i][j].set_value(EMPTY);
        }
    }
}


void Stone_array::print_all()
{
    // testing if stone array is created right
    int i, j;
    for(i=0; i<M; i++)
    {
        for(j=0; j<N; j++)
        {
            qInfo()<<p[i][j].get_value()<<" ";
        }
        qInfo()<<endl;
    }
}

State_type Stone_array::get_value(int i, int j)
{
    return p[i][j].get_value();
}

void Stone_array::set_value(int i, int j, State_type s)
{
    p[i][j].set_value(s);
}

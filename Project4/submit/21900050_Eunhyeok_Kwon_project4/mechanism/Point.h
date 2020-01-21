#ifndef POINT_H
#define POINT_H

#include "State_type.h"

class Point
{
    State_type state;   // enum type variable

    public:
        Point(State_type s=EMPTY): state(s)
        {}

        State_type get_value();

        void set_value(State_type s);
};

#endif // POINT_H

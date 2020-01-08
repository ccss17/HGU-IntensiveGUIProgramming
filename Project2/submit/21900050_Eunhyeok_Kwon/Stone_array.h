#ifndef STONE_ARRAY_H
#define STONE_ARRAY_H

#include "Point.h"
#include "State_type.h"

class Stone_array
{
    Point **p;
    int M, N;   // Y = 세로길이, X = 가로 길이
public:
    // constructor (동적 할당 할 것임)
    Stone_array(int y_len, int x_len);
    // destructor
    ~Stone_array();

    // other functions
    void init();
    void print_all();   // console output for debugging

    State_type get_value(int i, int j);
    void set_value(int i, int j, State_type s);
};

#endif // STONE_ARRAY_H

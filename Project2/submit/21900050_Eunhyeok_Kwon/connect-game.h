#ifndef CONNECT_H
#define CONNECT_H

#include "Stone_array.h"
#include "State_type.h"

#include <QDebug>

class Connect
{
    // State Connect(m, n, k, p, q)
    // Connect is a two player game
    // m = board height
    // n = board width, like a matrice
    // k = number of consecutive stones for win
    // p = number of stone placed in each turn
    // q = number of stone placed for the first move

    // this game is assumed to be played on square board

    // black stone allways makes the first move
    int M, N, K, P, Q;
    Stone_array stone_array;
    State_type current_turn;
    int total_stones = 0;
    // connect gameboard numbering begins at bottom left corner
public:
    // 생성자
    // construct stone at the same time
    Connect(int m, int n, int k, int p=1, int q=1): M(m), N(n), K(k), P(p), Q(q), stone_array(m, n)
    {
        stone_array.init();   // initialize stone places as EMPTY (0)
        current_turn = BLACK; // game always begin with black (??)

//        stone_array.print_all();  // testing if stone object was created and initialized right
        // it seems to be right
    }

    bool firstPlayerTurn();   // if first player's turn, returns true

    bool empty_place(int i, int j); // checks if space is valid for stone placement

    void place_stone(int i, int j);

    bool turn_over();   // checks if current players turn is over

    void switch_turn(); // this function is currently built for Connect p, q value of 1.

    void reset_board();

    bool full_board();

    bool in_bound(int i, int j);    // not sure if this is going to be used
    // this name should be out_bound and the return value should be changed

    // goal is to represent the array (index) memory values visually match the coordinate values of the actual board
    // to avoid confusion, array index values will be represented with i and j
    // coordinate values will be represented with x and y
    void canvas_coor_to_array(int &x, int &y);
    // canvas coordinate are 0,0 at top left corner

    int consecutive_vertical(int i, int j);
    int consecutive_horizontal(int i, int j);
    int consecutive_pos_diagonal(int i, int j);
    int consecutive_neg_diagnoal(int i, int j);

    bool k_in_a_row(int i, int j); // checks for victory (k-in-a-row)
    // checks from the lastest stone placement
        // therefore, this function must be used before the turn is over and current_turn changes
    // need to check horizontal, diagonal, and vertical
};

#endif // CONNECT_H

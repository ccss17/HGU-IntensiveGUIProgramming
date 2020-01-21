#include "connectgame.h"

State_type ConnectGame::get_value(int i, int j)
{
    return stone_array.get_value(j, i);
}

State_type ConnectGame::getCurrent_turn() const
{
    return current_turn;
}


bool ConnectGame::firstPlayerTurn()
{
    if(current_turn == BLACK) return true;
    return false;
}

bool ConnectGame::empty_place(int i, int j)
{
    if(stone_array.get_value(i,j)==EMPTY) return true;
    return false;
}

void ConnectGame::place_stone(int i, int j)
{
    stone_array.set_value(i, j, current_turn);
    total_stones++;
}

bool ConnectGame::turn_over()
{
    if((total_stones-Q)%P == 0) return true;
    return false;
}

void ConnectGame::switch_turn()
{
    if(current_turn==BLACK) current_turn = WHITE;
    else current_turn = BLACK;
}

void ConnectGame::reset_board()
{
    stone_array.init();
    current_turn = BLACK;
    total_stones = 0;
}

bool ConnectGame::full_board()
{
    if(total_stones >= M*N) return true;
    return false;
}

bool ConnectGame::in_bound(int i, int j)
{
    if(i < 0 || N < i || j < 0 || M < j) return false;
    return true;
}


//void ConnectGame::canvas_coor_to_array(int &x, int &y)
//{
//    int temp = x;
//    x = y;
//    y = temp;
//}

int ConnectGame::consecutive_vertical(int i, int j)
{
    int k;
    int consecutive = 1;
    // checking downwards
    for(k=i+1; k<M; k++)
    {
        if(stone_array.get_value(k,j) == current_turn)
            consecutive++;
        else break;
    }
    // checking upwards
    for(k=i-1; k>=0; k--)
    {
        if(stone_array.get_value(k,j) == current_turn)
            consecutive++;
        else break;
    }
//    stone_array.print_all();
//    qInfo() << consecutive;
//    qInfo() << "-----";
    return consecutive;
}

int ConnectGame::consecutive_horizontal(int i, int j)
{
    int k;
    int consecutive = 1;
    // checking through right side
    for(k=j+1; k<N; k++)
    {
        if(stone_array.get_value(i,k) == current_turn)
            consecutive++;
        else break;
    }
    // checking through left side
    for(k=j-1; k>=0; k--)
    {
        if(stone_array.get_value(i,k) == current_turn)
            consecutive++;
        else break;
    }
    return consecutive;
}


int ConnectGame::consecutive_pos_diagonal(int i, int j)
{
    int k,l;    // used in place of i and j
    int consecutive = 1;

    // if the stone cannot create K consecutive stones at that point, return 0 ...
    // doing this might be more time consuming and memory consuming than just calculating, so going to skip this thought

    // checking coor ++ area
    // i need to decrease, j needs to increase
    for(k=i-1,l=j+1; k>=0 && l<M; k--,l++)
    {
        if(stone_array.get_value(k,l) == current_turn)
            consecutive++;
        else break;
    }
    //checking coor -- area
    for(k=i+1,l=j-1; k<M && l>=0; k++,l--)
    {
        if(stone_array.get_value(k,l) == current_turn)
            consecutive++;
        else break;
    }
    return consecutive;
    // seems to be working
}

int ConnectGame::consecutive_neg_diagnoal(int i, int j)
{
    int k,l;
    int consecutive = 1;

    // checking coor -+ area
    for(k=i-1,l=j-1; k>=0 && l>=0; k--,l--)
    {
        if(stone_array.get_value(k,l) == current_turn)
            consecutive++;
        else break;
    }
    // checking coor +- area
    for(k=i+1,l=j+1; k<M && l<N; k++,l++)
    {
        if(stone_array.get_value(k,l) == current_turn)
            consecutive++;
        else break;
    }
    return consecutive;
}

bool ConnectGame::k_in_a_row(int i, int j)
{
    if(consecutive_vertical(i,j) >= K) return true;
    if(consecutive_horizontal(i,j) >= K) return true;
    if(consecutive_pos_diagonal(i,j) >= K) return true;
    if(consecutive_neg_diagnoal(i,j) >= K) return true;
    return false;
}

#include "ingame.h"

ingame::ingame()
{

}


int ingame::on_click(int a, int b, char c){
    om[a][b] = c;
    if (check_win(a, b, c) == 1){
        return 1;
    }
    return 0;
}

int ingame::check_win(int a, int b, char c){
    int cnt = 0;

    for (int i = -4 ; i < 5 ; i++){
        if (a+i > -1 && a+i < 15){
            if (om[a+i][b] == c){
                cnt++;
            }
            else {
                cnt = 0;
            }
            if (cnt == 5){
                return 1;
            }
        }
    }
    cnt = 0;
    for (int i = -4 ; i < 5 ; i++){
        if (b+i > -1 && b+i < 15){
            if (om[a][b+i] == c){
                cnt++;
            }
            else {
                cnt = 0;
            }
            if (cnt == 5){
                return 1;
            }
        }
    }
    cnt = 0;
    for (int i = -4 ; i < 5 ; i++){
        if (a+i > -1 && a+i < 15 && b+i > -1 && b+i < 15){
            if (om[a+i][b+i] == c){
                cnt++;
            }
            else {
                cnt = 0;
            }
            if (cnt == 5){
                return 1;
            }
        }
    }
    cnt = 0;
    for (int i = -4 ; i < 5 ; i++){
        if (a+i > -1 && a+i < 15 && b-i > -1 && b-i < 15){
            if (om[a+i][b-i] == c){
                cnt++;
            }
            else {
                cnt = 0;
            }
            if (cnt == 5){
                return 1;
            }
        }
    }


//    for (int i = a-4 ; i < a+4 ; i++){
//        for (int j = b-4 ; j < b+4 ; j++){
//            if (om[i][j] == c){
//                cnt++;
//            }
//            else {
//                cnt = 0;
//            }
//            if (cnt == 5){
//                return 1;
//            }
//        }
//        cnt = 0;
//        for (int j = 0 ; j < 15 ; j++){
//            if (om[j][i] == c){
//                cnt++;
//            }
//            else {
//                cnt = 0;
//            }
//            if (cnt == 5){
//                return 1;
//            }
//        }
//        cnt = 0;
//    }
//    for (int i = 0 ; i < 11 ; i++){
//        for (int j = 0 ; j < 11 ; j++){
//            for (int k = 0 ; k < 5 ; k++){
//                if (om[i+k][j+k] == c){
//                    cnt++;
//                }
//                else {
//                    break;
//                }
//            }
//            if (cnt == 5){
//                return 1;
//            }
//            cnt = 0;
//        }
//        cnt = 0;
//    }
//    for (int i = 0 ; i < 11 ; i++){
//        for (int j = 4 ; j < 15 ; j++){
//            for (int k = 0 ; k < 5 ; k++){
//                if (om[i+k][j-k] == c){
//                    cnt++;
//                }
//                else {
//                    break;
//                }
//            }
//            if (cnt == 5){
//                return 1;
//            }
//            cnt = 0;
//        }
//        cnt = 0;
//    }
    return 0;
}

void ingame::setting(){
    for (int i = 0 ; i < 15 ; i++){
        for (int j = 0 ; j < 15 ; j++){
            om[i][j] = '\0';
        }
    }
}

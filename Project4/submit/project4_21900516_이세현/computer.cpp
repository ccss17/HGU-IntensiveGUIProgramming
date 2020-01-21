#include "computer.h"
#include "ingame.h"
#include <random>

computer::computer()
{

}

int computer::com_rule(ingame game){
    srand(time(0));
    int white_cnt = 0;
    int black_cnt = 0;
    int space_cnt = 0;
    int a, b;
    int a_num[3], b_num[3];
    char check;

    // 우선순위 1
    for (int i = 0 ; i < 15 ; i++){
        for (int j = 0 ; j < 15 ; j++){
            for (int k = 0 ; k < 5 ; k++){
                if (j+k < 15){
                    check = game.om[i][j+k];
                    if (check == 'X') white_cnt++;
                    else if (check == 'O') {break;}
                    else {
                        space_cnt++;
                        a = i;
                        b = j+k;
                    }
                    if (white_cnt == 4 && space_cnt == 1) return 15*a+b;
                }
                else {break;}
            }
            white_cnt = 0;
            black_cnt = 0;
            space_cnt = 0;
            for (int k = 0 ; k < 5 ; k++){
                if (i+k < 15){
                    check = game.om[i+k][j];
                    if (check == 'X') white_cnt++;
                    else if (check == 'O') {break;}
                    else {
                        space_cnt++;
                        a = i+k;
                        b = j;
                    }
                    if (white_cnt == 4 && space_cnt == 1) return 15*a+b;
                }
                else {break;}
            }
            white_cnt = 0;
            black_cnt = 0;
            space_cnt = 0;
            for (int k = 0 ; k < 5 ; k++){
                if (i+k < 15 && j+k < 15){
                    check = game.om[i+k][j+k];
                    if (check == 'X') white_cnt++;
                    else if (check == 'O') {break;}
                    else {
                        space_cnt++;
                        a = i+k;
                        b = j+k;
                    }
                    if (white_cnt == 4 && space_cnt == 1) return 15*a+b;
                }
                else {break;}
            }
            white_cnt = 0;
            black_cnt = 0;
            space_cnt = 0;
            for (int k = 0 ; k < 5 ; k++){
                if (i+k < 15 && j-k > -1){
                    check = game.om[i+k][j-k];
                    if (check == 'X') white_cnt++;
                    else if (check == 'O') {break;}
                    else {
                        space_cnt++;
                        a = i+k;
                        b = j-k;
                    }
                    if (white_cnt == 4 && space_cnt == 1) return 15*a+b;
                }
                else {break;}
            }
            white_cnt = 0;
            black_cnt = 0;
            space_cnt = 0;
        }
    }

    // 우선순위 2
    for (int i = 0 ; i < 15 ; i++){
        for (int j = 0 ; j < 15 ; j++){
            for (int k = 0 ; k < 5 ; k++){
                if (j+k < 15){
                    check = game.om[i][j+k];
                    if (check == 'O') black_cnt++;
                    else if (check == 'X') {break;}
                    else {
                        space_cnt++;
                        a = i;
                        b = j+k;
                    }
                    if (black_cnt == 4 && space_cnt == 1) return 15*a+b;
                }
                else {break;}
            }
            white_cnt = 0;
            black_cnt = 0;
            space_cnt = 0;
            for (int k = 0 ; k < 5 ; k++){
                if (i+k < 15){
                    check = game.om[i+k][j];
                    if (check == 'O') black_cnt++;
                    else if (check == 'X') {break;}
                    else {
                        space_cnt++;
                        a = i+k;
                        b = j;
                    }
                    if (black_cnt == 4 && space_cnt == 1) return 15*a+b;
                }
                else {break;}
            }
            white_cnt = 0;
            black_cnt = 0;
            space_cnt = 0;
            for (int k = 0 ; k < 5 ; k++){
                if (i+k < 15 && j+k < 15){
                    check = game.om[i+k][j+k];
                    if (check == 'O') black_cnt++;
                    else if (check == 'X') {break;}
                    else {
                        space_cnt++;
                        a = i+k;
                        b = j+k;
                    }
                    if (black_cnt == 4 && space_cnt == 1) return 15*a+b;
                }
                else {break;}
            }
            white_cnt = 0;
            black_cnt = 0;
            space_cnt = 0;
            for (int k = 0 ; k < 5 ; k++){
                if (i+k < 15 && j-k > -1){
                    check = game.om[i+k][j-k];
                    if (check == 'O') black_cnt++;
                    else if (check == 'X') {break;}
                    else {
                        space_cnt++;
                        a = i+k;
                        b = j-k;
                    }
                    if (black_cnt == 4 && space_cnt == 1) return 15*a+b;
                }
                else {break;}
            }
            white_cnt = 0;
            black_cnt = 0;
            space_cnt = 0;
        }
    }

    // 우선순위 3
    a = 0;
    b = 0;
    for (int i = 0 ; i < 15 ; i++){
        for (int j = 0 ; j < 15 ; j++){
            for (int k = 0 ; k < 5 ; k++){
                if (j+k < 15){
                    check = game.om[i][j+k];
                    if (k == 0 && check == '\0'){
                        a_num[a] = i;
                        b_num[a] = j+k;
                        a++;
                        continue;
                    }
                    else if (k < 4 && check == 'X') continue;
                    else if (k == 4 && check == '\0'){
                        a_num[a] = i;
                        b_num[a] = j+k;
                        a = rand()%2;
                        return 15*a_num[a]+b_num[a];
                    }
                    else break;
                }
                else {
                    break;
                }
            }
            a = 0;
            for (int k = 0 ; k < 5 ; k++){
                if (i+k < 15){
                    check = game.om[i+k][j];
                    if (k == 0 && check == '\0'){
                        a_num[a] = i+k;
                        b_num[a] = j;
                        a++;
                        continue;
                    }
                    else if (k < 4 && check == 'X') continue;
                    else if (k == 4 && check == '\0'){
                        a_num[a] = i+k;
                        b_num[a] = j;
                        a = rand()%2;
                        return 15*a_num[a]+b_num[a];
                    }
                    else break;
                }
                else {
                    break;
                }
            }
            a = 0;
            for (int k = 0 ; k < 5 ; k++){
                if (i+k < 15 && j+k < 15){
                    check = game.om[i+k][j+k];
                    if (k == 0 && check == '\0'){
                        a_num[a] = i+k;
                        b_num[a] = j+k;
                        a++;
                        continue;
                    }
                    else if (k < 4 && check == 'X') continue;
                    else if (k == 4 && check == '\0'){
                        a_num[a] = i+k;
                        b_num[a] = j+k;
                        a = rand()%2;
                        return 15*a_num[a]+b_num[a];
                    }
                    else break;
                }
                else {
                    break;
                }
            }
            a = 0;
            for (int k = 0 ; k < 5 ; k++){
                if (i+k < 15 && j-k > -1){
                    check = game.om[i+k][j-k];
                    if (k == 0 && check == '\0'){
                        a_num[a] = i+k;
                        b_num[a] = j-k;
                        a++;
                        continue;
                    }
                    else if (k < 4 && check == 'X') continue;
                    else if (k == 4 && check == '\0'){
                        a_num[a] = i+k;
                        b_num[a] = j-k;
                        a = rand()%2;
                        return 15*a_num[a]+b_num[a];
                    }
                    else break;
                }
                else {
                    break;
                }
            }
            a = 0;
        }
    }

    // 우선순위 4
    for (int i = 0 ; i < 15 ; i++){
        for (int j = 0 ; j < 15 ; j++){
            for (int k = 0 ; k < 6 ; k++){
                if (j+k < 15){
                    check = game.om[i][j+k];
                    if (k == 0 && check == '\0'){
                        a_num[a] = i;
                        b_num[a] = j+k;
                        a++;
                        continue;
                    }
                    else if (b == 0 && k < 5 && check == '\0') {
                        a_num[a] = i;
                        b_num[a] = j+k;
                        b++;
                    }
                    else if (k < 5 && check == 'X') continue;
                    else if (k == 5 && check == '\0'){
                        return 15*a_num[a]+b_num[a];
                    }
                    else break;
                }
                else {
                    break;
                }
            }
            a = 0;
            b = 0;
            for (int k = 0 ; k < 6 ; k++){
                if (i+k < 15){
                    check = game.om[i+k][j];
                    if (k == 0 && check == '\0'){
                        a_num[a] = i+k;
                        b_num[a] = j;
                        a++;
                        continue;
                    }
                    else if (b == 0 && k < 5 && check == '\0') {
                        a_num[a] = i+k;
                        b_num[a] = j;
                        b++;
                    }
                    else if (k < 5 && check == 'X') continue;
                    else if (k == 5 && check == '\0'){
                        return 15*a_num[a]+b_num[a];
                    }
                    else break;
                }
                else {
                    break;
                }
            }
            a = 0;
            b = 0;
            for (int k = 0 ; k < 6 ; k++){
                if (i+k < 15 && j+k < 15){
                    check = game.om[i+k][j+k];
                    if (k == 0 && check == '\0'){
                        a_num[a] = i+k;
                        b_num[a] = j+k;
                        a++;
                        continue;
                    }
                    else if (b == 0 && k < 5 && check == '\0') {
                        a_num[a] = i+k;
                        b_num[a] = j+k;
                        b++;
                    }
                    else if (k < 5 && check == 'X') continue;
                    else if (k == 5 && check == '\0'){
                        return 15*a_num[a]+b_num[a];
                    }
                    else break;
                }
                else {
                    break;
                }
            }
            a = 0;
            b = 0;
            for (int k = 0 ; k < 6 ; k++){
                if (i+k < 15 && j-k > -1){
                    check = game.om[i+k][j-k];
                    if (k == 0 && check == '\0'){
                        a_num[a] = i+k;
                        b_num[a] = j-k;
                        a++;
                        continue;
                    }
                    else if (b == 0 && k < 5 && check == '\0') {
                        a_num[a] = i+k;
                        b_num[a] = j-k;
                        b++;
                    }
                    else if (k < 5 && check == 'X') continue;
                    else if (k == 5 && check == '\0'){
                        return 15*a_num[a]+b_num[a];
                    }
                    else break;
                }
                else {
                    break;
                }
            }
            a = 0;
            b = 0;
        }
    }

    // 우선순위 5
    for (int i = 0 ; i < 15 ; i++){
        for (int j = 0 ; j < 15 ; j++){
            for (int k = 0 ; k < 5 ; k++){
                if (j+k < 15){
                    check = game.om[i][j+k];
                    if (k == 0 && check == '\0'){
                        a_num[a] = i;
                        b_num[a] = j+k;
                        a++;
                        continue;
                    }
                    else if (k < 4 && check == 'O') continue;
                    else if (k == 4 && check == '\0'){
                        a_num[a] = i;
                        b_num[a] = j+k;
                        a = rand()%2;
                        return 15*a_num[a]+b_num[a];
                    }
                    else break;
                }
                else {
                    break;
                }
            }
            a = 0;
            for (int k = 0 ; k < 5 ; k++){
                if (i+k < 15){
                    check = game.om[i+k][j];
                    if (k == 0 && check == '\0'){
                        a_num[a] = i+k;
                        b_num[a] = j;
                        a++;
                        continue;
                    }
                    else if (k < 4 && check == 'O') continue;
                    else if (k == 4 && check == '\0'){
                        a_num[a] = i+k;
                        b_num[a] = j;
                        a = rand()%2;
                        return 15*a_num[a]+b_num[a];
                    }
                    else break;
                }
                else {
                    break;
                }
            }
            a = 0;
            for (int k = 0 ; k < 5 ; k++){
                if (i+k < 15 && j+k < 15){
                    check = game.om[i+k][j+k];
                    if (k == 0 && check == '\0'){
                        a_num[a] = i+k;
                        b_num[a] = j+k;
                        a++;
                        continue;
                    }
                    else if (k < 4 && check == 'O') continue;
                    else if (k == 4 && check == '\0'){
                        a_num[a] = i+k;
                        b_num[a] = j+k;
                        a = rand()%2;
                        return 15*a_num[a]+b_num[a];
                    }
                    else break;
                }
                else {
                    break;
                }
            }
            a = 0;
            for (int k = 0 ; k < 5 ; k++){
                if (i+k < 15 && j-k > -1){
                    check = game.om[i+k][j-k];
                    if (k == 0 && check == '\0'){
                        a_num[a] = i+k;
                        b_num[a] = j-k;
                        a++;
                        continue;
                    }
                    else if (k < 4 && check == 'O') continue;
                    else if (k == 4 && check == '\0'){
                        a_num[a] = i+k;
                        b_num[a] = j-k;
                        a = rand()%2;
                        return 15*a_num[a]+b_num[a];
                    }
                    else break;
                }
                else {
                    break;
                }
            }
            a = 0;
        }
    }

    // 우선순위 6
    for (int i = 0 ; i < 15 ; i++){
        for (int j = 0 ; j < 15 ; j++){
            for (int k = 0 ; k < 6 ; k++){
                if (j+k < 15){
                    check = game.om[i][j+k];
                    if (k == 0 && check == '\0'){
                        a_num[a] = i;
                        b_num[a] = j+k;
                        a++;
                        continue;
                    }
                    else if (b == 0 && k < 5 && check == '\0') {
                        a_num[a] = i;
                        b_num[a] = j+k;
                        a++;
                        b++;
                    }
                    else if (k < 5 && check == 'O') continue;
                    else if (k == 5 && check == '\0'){
                        a_num[a] = i;
                        b_num[a] = j+k;
                        a = rand()%3;
                        return 15*a_num[a]+b_num[a];
                    }
                    else break;
                }
                else {
                    break;
                }
            }
            a = 0;
            b = 0;
            for (int k = 0 ; k < 6 ; k++){
                if (i+k < 15){
                    check = game.om[i+k][j];
                    if (k == 0 && check == '\0'){
                        a_num[a] = i+k;
                        b_num[a] = j;
                        a++;
                        continue;
                    }
                    else if (b == 0 && k < 5 && check == '\0') {
                        a_num[a] = i+k;
                        b_num[a] = j;
                        a++;
                        b++;
                    }
                    else if (k < 5 && check == 'O') continue;
                    else if (k == 5 && check == '\0'){
                        a_num[a] = i+k;
                        b_num[a] = j;
                        a = rand()%3;
                        return 15*a_num[a]+b_num[a];
                    }
                    else break;
                }
                else {
                    break;
                }
            }
            a = 0;
            b = 0;
            for (int k = 0 ; k < 6 ; k++){
                if (i+k < 15 && j+k < 15){
                    check = game.om[i+k][j+k];
                    if (k == 0 && check == '\0'){
                        a_num[a] = i+k;
                        b_num[a] = j+k;
                        a++;
                        continue;
                    }
                    else if (b == 0 && k < 5 && check == '\0') {
                        a_num[a] = i+k;
                        b_num[a] = j+k;
                        a++;
                        b++;
                    }
                    else if (k < 5 && check == 'O') continue;
                    else if (k == 5 && check == '\0'){
                        a_num[a] = i+k;
                        b_num[a] = j+k;
                        a = rand()%3;
                        return 15*a_num[a]+b_num[a];
                    }
                    else break;
                }
                else {
                    break;
                }
            }
            a = 0;
            b = 0;
            for (int k = 0 ; k < 6 ; k++){
                if (i+k < 15 && j-k > -1){
                    check = game.om[i+k][j-k];
                    if (k == 0 && check == '\0'){
                        a_num[a] = i+k;
                        b_num[a] = j-k;
                        a++;
                        continue;
                    }
                    else if (b == 0 && k < 5 && check == '\0') {
                        a_num[a] = i+k;
                        b_num[a] = j-k;
                        a++;
                        b++;
                    }
                    else if (k < 5 && check == 'O') continue;
                    else if (k == 5 && check == '\0'){
                        a_num[a] = i+k;
                        b_num[a] = j-k;
                        a = rand()%3;
                        return 15*a_num[a]+b_num[a];
                    }
                    else break;
                }
                else {
                    break;
                }
            }
            a = 0;
            b = 0;
        }
    }

    // 우선순위 7
    for (int i = 0 ; i < 15 ; i++){
        for (int j = 0 ; j < 15 ; j++){
            for (int k = 0 ; k < 5 ; k++){
                if (j+k < 15){
                    check = game.om[i][j+k];
                    if (k == 0 && check == '\0'){
                        a_num[a] = i;
                        b_num[a] = j+k;
                        continue;
                    }
                    else if (k == 0 && check == 'O'){
                        b = 1;
                        continue;
                    }
                    else if (k < 4 && check == 'X') continue;
                    else if (b == 1 && k == 4 && check == '\0'){
                        a_num[a] = i;
                        b_num[a] = j+k;
                        return 15*a_num[a]+b_num[a];
                    }
                    else if (b == 0 && k == 4 && check == 'O'){
                        return 15*a_num[a]+b_num[a];
                    }
                    else break;
                }
                else {
                    break;
                }
            }
            a = 0;
            b = 0;
            for (int k = 0 ; k < 5 ; k++){
                if (i+k < 15){
                    check = game.om[i+k][j];
                    if (k == 0 && check == '\0'){
                        a_num[a] = i+k;
                        b_num[a] = j;
                        continue;
                    }
                    else if (k == 0 && check == 'O'){
                        b = 1;
                        continue;
                    }
                    else if (k < 4 && check == 'X') continue;
                    else if (b == 1 && k == 4 && check == '\0'){
                        a_num[a] = i+k;
                        b_num[a] = j;
                        return 15*a_num[a]+b_num[a];
                    }
                    else if (b == 0 && k == 4 && check == 'O'){
                        return 15*a_num[a]+b_num[a];
                    }
                    else break;
                }
                else {
                    break;
                }
            }
            a = 0;
            b = 0;
            for (int k = 0 ; k < 5 ; k++){
                if (i+k < 15 && j+k < 15){
                    check = game.om[i+k][j+k];
                    if (k == 0 && check == '\0'){
                        a_num[a] = i+k;
                        b_num[a] = j+k;
                        continue;
                    }
                    else if (k == 0 && check == 'O'){
                        b = 1;
                        continue;
                    }
                    else if (k < 4 && check == 'X') continue;
                    else if (b == 1 && k == 4 && check == '\0'){
                        a_num[a] = i+k;
                        b_num[a] = j+k;
                        return 15*a_num[a]+b_num[a];
                    }
                    else if (b == 0 && k == 4 && check == 'O'){
                        return 15*a_num[a]+b_num[a];
                    }
                    else break;
                }
                else {
                    break;
                }
            }
            a = 0;
            b = 0;
            for (int k = 0 ; k < 5 ; k++){
                if (i+k < 15 && j-k > -1){
                    check = game.om[i+k][j-k];
                    if (k == 0 && check == '\0'){
                        a_num[a] = i+k;
                        b_num[a] = j-k;
                        continue;
                    }
                    else if (k == 0 && check == 'O'){
                        b = 1;
                        continue;
                    }
                    else if (k < 4 && check == 'X') continue;
                    else if (b == 1 && k == 4 && check == '\0'){
                        a_num[a] = i+k;
                        b_num[a] = j-k;
                        return 15*a_num[a]+b_num[a];
                    }
                    else if (b == 0 && k == 4 && check == 'O'){
                        return 15*a_num[a]+b_num[a];
                    }
                    else break;
                }
                else {
                    break;
                }
            }
            a = 0;
            b = 0;
        }
    }


    while(true){
        a = rand()%15;
        b = rand()%15;
        if (game.om[a][b] == '\0'){
            return 15*a+b;
        }
    }
}

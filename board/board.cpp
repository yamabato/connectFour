#include <iostream>

/*
00 01 02 03 04 05 06
10 11 12 13 14 15 16
20 21 22 23 24 25 26
30 31 32 33 34 35 36
40 41 42 43 44 45 46
50 51 52 53 54 55 56
*/

void initBoard(int board[7][6]){
    for (int y=0; y<6; y++){
        for (int x=0; x<7; x++){
            board[x][y] = 0;
        }
    }
}

void showBoard(int board[7][6]){
    for (int y=0; y<6; y++){
        for (int x=0; x<7; x++){
            std::cout << board[x][y];
        }
        std::cout << std::endl;
    }
}

//hand 0:先手, 1:後手
void drop(int board[7][6], int row, int hand){
    if (row < 0 or row > 6){
        return;
    }

    for (int y=6; y>=0; y--){
        if (board[row][y]==0){
            board[row][y] = 1;
            return;
        }
    }
}

int main(){
    int board[7][6];
    initBoard(board);

    showBoard(board);

    drop(board, 0, 0);

    std::cout << std::endl;
    showBoard(board);

    return 0;
}

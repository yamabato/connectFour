#include <iostream>

/*
00 10 20 30 40 50 60
01 11 21 31 41 51 61
02 12 22 32 42 52 62
03 13 23 33 43 53 63
04 14 24 34 44 54 64
05 15 25 35 45 55 65
*/

void initBoard(int board[7][6]){
    for (int y=0; y<6; y++){
        for (int x=0; x<7; x++){
            board[x][y] = -1;
        }
    }
}

void showBoard(int board[7][6]){
    int piece;
    for (int y=0; y<6; y++){
        for (int x=0; x<7; x++){
            piece = board[x][y];

            if (piece == -1){
                std::cout << "-";
            }else if(piece == 0){
                std::cout << "O";
            }else{
                std::cout << "X";
            }
        }
        std::cout << std::endl;
    }
}

//hand 0:先手, 1:後手
void drop(int board[7][6], int row, int hand){
    if (row < 0 or row > 6){
        return;
    }

    for (int y=5; y>=0; y--){
        std::cout << row << std::endl;
        std::cout << y << std::endl;
        if (board[row][y]==-1){
            board[row][y] = hand;
            break;
        }
    }
}

int main(){
    int board[7][6];
    initBoard(board);

    showBoard(board);

    drop(board, 0, 0);
    drop(board, 0, 1);

    std::cout << std::endl;
    showBoard(board);

    return 0;
}

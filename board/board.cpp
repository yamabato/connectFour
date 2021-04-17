#include <string>
#include <iostream>

/*
00 10 20 30 40 50 60
01 11 21 31 41 51 61
02 12 22 32 42 52 62
03 13 23 33 43 53 63
04 14 24 34 44 54 64
05 15 25 35 45 55 65
*/
//hand 0:先手, 1:後手


void initBoard(int board[7][6]){
    for (int y=0; y<6; y++){
        for (int x=0; x<7; x++){
            board[x][y] = -1;
        }
    }
}

//先手:青 後手:赤
void showBoard(int board[7][6]){
    std::string LIGHT = "\033[2m";
    std::string RED = "\033[31m";
    std::string BLUE = "\033[34m";
    std::string RESET = "\033[0m";
    
    int piece;
    for (int y=0; y<6; y++){
        for (int x=0; x<7; x++){
            piece = board[x][y];

            if (piece == -1){
                std::cout << LIGHT + "-" + RESET;
            }else if(piece == 0){
                std::cout << BLUE + "O" + RESET;
            }else{
                std::cout << RED + "X" + RESET;
            }

            std::cout << " ";
        }
        std::cout << std::endl;
    }
}

bool drop(int board[7][6], int row, int hand){
    if (row < 0 or row > 6){
        return false;
    }

    for (int y=5; y>=0; y--){
        if (board[row][y]==-1){
            board[row][y] = hand;
            return true;
        }
    }

    return false;
}

int main(){
    int board[7][6];
    bool success;

    initBoard(board);

    showBoard(board);

    success = drop(board, 0, 0);
    success = drop(board, 0, 1);

    std::cout << std::endl;
    showBoard(board);

    return 0;
}

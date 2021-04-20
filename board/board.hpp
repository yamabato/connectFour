#include <vector>
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
    std::string GREEN = "\033[32m";
    std::string RESET = "\033[0m";
    
    int piece;
    for (int y=0; y<6; y++){
        for (int x=0; x<7; x++){
            piece = board[x][y];

            if (piece == 1){
                std::cout << RED + "X" + RESET;
            }else if(piece == 0){
                std::cout << BLUE + "O" + RESET;
            }else if(piece == -1){
                std::cout << LIGHT + "-" + RESET;
            }else{
                std::cout << GREEN + "!" + RESET;
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

bool isLegal(int board[7][6], int row){
    if (board[row][0] == -1){
        return true;
    }

    return false;
}

std::vector<int> legalRow(int board[7][6]){
    std::vector<int> rows;

    for (int x=0; x<7; x++){
        if (isLegal(board, x)){
            rows.push_back(x);
        }
    }

    return rows;
}

//2引き分け 0先手がち 1後手がち -1未決
int judge(int board[7][6]){
    int judgement = -1;
    int count = 0;
    int piece;
    int piece_count = 0;

    int start1[12][2];
    int start2[12][2];

    for (int y=0; y<6; y++){
        start1[y][0] = 0;
        start1[y][1] = y;
    }
    for (int x=1; x<7; x++){
        start1[x+5][0] = x;
        start1[x+5][1] = 5;
    }

    for (int x=0; x<7; x++){
        start2[x][0] = x;
        start2[x][1] = 0;
    }
    for (int y=1; y<6; y++){
        start2[y+5][0] = 5;
        start2[y+5][1] = y;
    }


    //横向きに調べる
    for (int y=0; y<6; y++){
        for (int x=0; x<7; x++){
            piece = board[x][y];
            if (piece == judgement){
                count++;
            }else{
                judgement = piece;
                count = 1;
            }

            piece_count += (piece == -1 ? 0 : 1);

            if (count >= 4 and piece != -1){
                return judgement;
            }
        }
    }

    judgement = -1;
    count = 0;

    //たてに調べる
    for (int x=0; x<7; x++){
        for (int y=0; y<6; y++){
            piece = board[x][y];
            if (piece == judgement){
                count++;
            }else{
                judgement = piece;
                count = 1;
            }

            if (count >= 4 and piece != -1){
                return judgement;
            }
        }
    }

    //右肩上がり
    int x = 0;
    int y = 0;
    for (int i=0; i<10; i++){
        x = start1[i][0];
        y = start1[i][1];
        judgement = -1;
        count = 0;
        while (x<7 && y<6){
            piece = board[x][y];
            if (piece == judgement){
                count++;
            }else{
                judgement = piece;
                count = 1;
            }

            if (count >= 4 and piece != -1){
                return judgement;
            }
            x++;
            y--;
        }
    }

    for (int i=0; i<10; i++){
        x = start2[i][0];
        y = start2[i][1];
        judgement = -1;
        count = 0;
        while (x<7 && y<6){
            piece = board[x][y];
            if (piece == judgement){
                count++;
            }else{
                judgement = piece;
                count = 1;
            }

            if (count >= 4 and piece != -1){
                return judgement;
            }
            x++;
            y++;
        }
    }

    return piece_count==42 ? 2 : -1;
}


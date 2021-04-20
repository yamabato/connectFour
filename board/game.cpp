#include <string>
#include <iostream>

#include "board.hpp"
#include "human.hpp"
#include "randomAI.hpp"

int getRow(int board[7][6], int hand, int (*firstFunc)(int[7][6], int), int (*lastFunc)(int[7][6], int)){
    int row;
    if (hand==0){
        row = firstFunc(board, hand);
    }else{
        row = lastFunc(board, hand);
    }

    return row;
}

int game(){
    int board[7][6];

    int hand = 0;
    int row;
    bool success;
    int judgement;

    int (*firstFunc)(int[7][6], int) = human;
    int (*lastFunc)(int[7][6], int) = randomAI;

    initBoard(board);


    for (int i=0; i<42; i++){
        std::cout << std::endl;
        std::cout << "0 1 2 3 4 5 6" << std::endl;
        showBoard(board);

        std::cout << (hand==0?"先手番":"後手番") << std::endl;
        row = getRow(board, hand, firstFunc, lastFunc);
        success = drop(board, row, hand);

        if (!success){
            if (hand==0){
                std::cout << "後手の勝利" << std::endl;
            }else{
                std::cout << "先手の勝利" << std::endl;
            }
        }

        judgement = judge(board);
        if (judgement == -1){
            hand = std::abs(hand-1);
            std::cout << std::endl;
        }else{
            showBoard(board);
            if (judgement == 0){
                std::cout << "先手の勝利" << std::endl;
                break;
            }else if (judgement == 1){
                std::cout << "後手の勝利" << std::endl;
                break;
            }else if (judgement == 2){
                std::cout << "引き分け" << std::endl;
                break;
            }
        }

    }

    return 0;
}

int main(){
    game();

    return 0;
}

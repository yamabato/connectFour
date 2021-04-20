#include <string>
#include <iostream>

#include "board.hpp"

int game(){
    int board[7][6];

    int hand = 0;
    std::string inp;
    int row;
    bool success;
    int judgement;

    initBoard(board);


    for (int i=0; i<42; i++){
        std::cout << std::endl;
        std::cout << "0 1 2 3 4 5 6" << std::endl;
        showBoard(board);

        while (true){
            std::cout << (hand==0?"先手番":"後手番") << std::endl;
            getline(std::cin, inp);

            try{
                row = std::stoi(inp);
                success = drop(board, row, hand);
                if (success){
                    break;
                }
            }catch(std::invalid_argument e){
            }catch(std::out_of_range e){
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

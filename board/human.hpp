#include <string>
#include <iostream>

int human(int board[7][6], int hand){
    bool legal;
    std::string inp;
    int row;

    while (true){
        std::cout << ":";
        getline(std::cin, inp);

        try{
            row = std::stoi(inp);
            legal = isLegal(board, row);
            if (legal){
                break;
            }
        }catch(std::invalid_argument e){
        }catch(std::out_of_range e){
        }
    }
    return row;
}

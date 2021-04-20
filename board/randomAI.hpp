#include <random>

int randomAI(int board[7][6], int hand){
    std::vector<int> legalRows = legalRow(board);

    std::random_device rnd;
    int row = rand() % legalRows.size();

    return row;
}

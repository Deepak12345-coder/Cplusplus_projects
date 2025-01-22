#pragma once
#include <vector>

class Create_board {
public:
    int size = 3;
    Create_board();  
    void print_board();  
    char check_win();  
    void start_game();  
    std::vector<std::vector<char>> board;  
};

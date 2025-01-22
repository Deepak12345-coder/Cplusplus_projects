#include "CreateBoard.h"
#include <iostream>

Create_board::Create_board() {
    
    board.resize(size, std::vector<char>(size, ' '));
}

void Create_board::print_board() {
   
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << "  " << board[i][j] << "  ";
            if (j < 2) std::cout << "|";  
        }
        std::cout << std::endl;
        if (i < 2) {
            std::cout << "-------------------" << std::endl; 
        }
    }
}

char Create_board::check_win() {
    // Check rows
    for (int i = 0; i < size; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return board[i][0];
        }
    }

    // Check columns
    for (int j = 0; j < size; ++j) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ') {
            return board[0][j];
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return board[0][2];
    }

    // If no winner, return ' ' indicating no winner
    return ' ';
}

void Create_board::start_game() {
    std::cout << "Let's start the game!" << std::endl;
    int move;
    char player = 'X';
    int turn;

    for (turn = 0; turn < 9; ++turn) {
        // Draw the board
        print_board();

        // Prompt for valid input
        while (true) {
            std::cout << "Player " << player << ", Enter your move (0-8): ";
            std::cin >> move;

            if (move < 0 || move > 8 || board[move / 3][move % 3] != ' ') {
                std::cout << "Invalid move. Try again.\n";
            }
            else {
                break;
            }
        }

        // Make the move
        board[move / 3][move % 3] = player;

        // Check for a win after making the move
        char winner = check_win();
        if (winner != ' ') {
            print_board();
            std::cout << "Player " << winner << " wins!" << std::endl;
            break;
        }

        // Switch to the other player
        player = (player == 'X') ? 'O' : 'X';
    }

    if (turn == 9 && check_win() == ' ') {
        print_board();
        std::cout << "It's a draw!" << std::endl;
    }
}

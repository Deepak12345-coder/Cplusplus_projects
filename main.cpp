#include<iostream>
#include<vector>
#include"CreateBoard.h"
using namespace std;
void play()
{
    Create_board tic_tac_toe_board;
    tic_tac_toe_board.start_game();
    cout << "Do you want play again if  yes enter 1 " << endl;
    int flag;
    cin >> flag;

    if (flag == 1)
    {
        play();
    }
}
int main()
{
    play();
    return 0;
}
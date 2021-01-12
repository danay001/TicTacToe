#include <iostream>
#include "Board.h"
#include "Player.h"

void clearScreen() {
    std::cout << std::endl;
    std::cout << "\033c";
    std::cout << std::endl;
    return;
}

void playGame(){
    Board game = Board();
    int curPlayerNum = 1;
    char curPlayer = 'X';
    char pos = ' ';

    std::cout << "Welcome to Tic-Tac-Toe" << std::endl;
    std::cout << "Player 1 is X and Player 2 is O" << std::endl;
    std::cout << std::endl;

    do{
        game.printBoard();

        do{
            std::cout << "Player " << curPlayerNum << " choose a position" << std::endl;
            std::cin >> pos;
        }while(!game.isValidMove(pos));
        game.setPlay(pos, curPlayer);

        curPlayer = curPlayer == 'X' ? 'O' : 'X';
        curPlayerNum = curPlayerNum == 1 ? 2 : 1;

        clearScreen();

    }while(!game.boardFull() && !game.checkWinner());

    game.printBoard();
    curPlayer = curPlayer == 'X' ? 'O' : 'X';
    curPlayerNum = curPlayerNum == 1 ? 2 : 1;

    //Condition the Nobody wins
    if(game.boardFull()){
        std::cout << "Tie. Nobody won" << std::endl;
    }
    //X Wins
    else{
        std::cout << "Player " << curPlayerNum << " wins!" << std::endl;
    }
    
}

int main(){

    playGame();

    return 0;
}
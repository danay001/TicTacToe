#include "Board.h"

Board::Board(){
    std::vector<char> tmp = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};
    this->gameBoard = tmp;
}

Board::~Board(){
    while(!gameBoard.empty()){
        gameBoard.pop_back();
    }
}

void Board::printBoard(){
    for(unsigned int i = 0; i < gameBoard.size(); i += 3){
        std::cout << " " << gameBoard.at(i) << " | " << gameBoard.at(i + 1) << " | " << gameBoard.at(i + 2) << std::endl;
        if(i < 6){
            std::cout << "===|===|===" << std::endl;
        }
    }
    std::cout << std::endl;
}

int Board::convertPos(char pos){
    return pos - 'a';
}

bool Board::isValidMove(char pos){
    //Check if entered position is a valid position
    if(pos < 'a' || pos > 'i'){
        return false;
    }
    int posIndex = convertPos(pos);
    //Check that entered position is not already taken
    if(gameBoard.at(posIndex) == 'X' || gameBoard.at(posIndex) == 'O' ){
        return false;
    }
    return true;
}

bool Board::boardFull(){
    for(unsigned int i = 0; i < gameBoard.size(); ++i){
        if(gameBoard.at(i) != 'X' || gameBoard.at(i) != 'O'){
            return false;
        }
    }
    return true;
}

bool Board::checkWinner(){
    //Check Rows
    for(unsigned int i = 0; i < gameBoard.size(); i += 3){
        if(gameBoard.at(i) == 'X' && gameBoard.at(i + 1) == 'X' && gameBoard.at(i + 2) == 'X'){
            return true;
        }
        else if(gameBoard.at(i) == 'O' && gameBoard.at(i + 1) == 'O' && gameBoard.at(i + 2) == 'O'){
            return true;
        }
    }
    //Check Columns
    for(unsigned int i = 0; i < 3; ++i){
        if(gameBoard.at(i) == 'X' && gameBoard.at(i + 3) == 'X' && gameBoard.at(i + 6) == 'X'){
            return true;
        }
        else if(gameBoard.at(i) == 'O' && gameBoard.at(i + 3) == 'O' && gameBoard.at(i + 6) == 'O'){
            return true;
        }
    }
    //Check Diagnols
    if(gameBoard.at(0) == 'X' && gameBoard.at(4) == 'X' && gameBoard.at(8) == 'X'){
        return true;
    }
    else if(gameBoard.at(2) == 'X' && gameBoard.at(4) == 'X' && gameBoard.at(6) == 'X'){
        return true;
    } 
    else if(gameBoard.at(0) == 'O' && gameBoard.at(4) == 'O' && gameBoard.at(8) == 'O'){
        return true;
    }
    else if(gameBoard.at(2) == 'O' && gameBoard.at(4) == 'O' && gameBoard.at(6) == 'O'){
        return true;
    }

    return false;
}

char Board::getSlot(int pos) const{
    return gameBoard.at(pos);
}

void Board::setPlay(char pos, char player){
    int posIndex = convertPos(pos);
    gameBoard.at(posIndex) = player;
}


#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>

class Board {  
  private:
    std::vector<char> gameBoard;

  public:
    Board();
    ~Board();
    void printBoard();
    int convertPos(char pos);
    bool isValidMove(char pos);
    bool boardFull();
    bool checkWinner();
    char getSlot(int pos) const;
    void setPlay(char pos, char player);
};

#endif
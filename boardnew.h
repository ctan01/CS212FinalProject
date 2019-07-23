#ifndef __BOARD_H__
#define __BOARD_H__
#include <iostream>
#include <cstdlib>
using namespace std;

class Board{

public:
    //CONSTURCTOR
    Board();

    void removePiece(int x, int y){boardArray[x][y] = 0;}
    bool isValid(int x, int y){return (x+y)%2 != 0;}
    bool isEmpty(int x, int y){return boardArray[x][y] == 0;}
    bool is1(int x, int y){return boardArray[x][y] == 1;}
    bool is2(int x, int y){return boardArray[x][y] == 2;}
	
    bool isLeftUp1(int x, int y){return boardArray[x-1][y-1] == 1;}
    bool isLeftUp2(int x , int y){return boardArray[x-1][y-1] == 2;}

    bool isRightUp1(int x, int y){return boardArray[x-1][y+1] == 1;}
    bool isRightUp2(int x , int y){return boardArray[x-1][y+1] == 2;}

    bool isLeftDown1(int x , int y){return boardArray[x+1][y-1] == 1;}
    bool isLeftDown2(int x, int y){return boardArray[x+1][y-1] == 2;}

    bool isRightDown1(int x , int y){return boardArray[x+1][y+1] == 1;}
    bool isRightDown2(int x , int y){return boardArray[x+1][y+1] == 2;}

    //INITIALIZE THE GAME
    void initializeBoard();
    //PRINT THE BOARD
    void printBoard();
    //DETERMINE IF THE GAME ENDS
    bool winningState();

    //MOVE PIECES
    void moveRightDown(int x, int y);
    void moveLeftDown(int x, int y);
    void moveRightUp(int x, int y);
    void moveLeftUp(int x, int y);
    void jumpRightDown(int x, int y);
    void jumpLeftDown(int x, int y);
    void jumpRightUp(int x, int y);
    void jumpLeftUp(int x, int y);

    //CHECK IF THE PIECE CAN JUMP OR MOVE
    bool canMoveRightUp(int x, int y);
    bool canMoveLefttUp(int x, int y);
    bool canMoveRightDown(int x, int y);
    bool canMoveLeftDown(int x, int y);
    bool canJumpRightUp(int x, int y);
    bool canJumpLeftUp(int x, int y);
    bool canJumpRightDown(int x, int y);
    bool canJumpLeftDown(int x, int y);
	
    //Count the amount of Ones and Twos on the board. 	
    int countOne();
    int countTwo();


private:
	 int boardArray[8][8];
	 bool objectAlreadyCreated;

};

#endif

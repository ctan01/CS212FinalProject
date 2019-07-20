#include "board.h"
using namespace std;

//Constructor and Initialization together
Board::Board()
{
    //if object is not created already then make a new one and initialize it
    if(objectAlreadyCreated == false)
    {
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
		    boardArray[i][j] = 0;
                if(isValid(i, j)){
                    if(i == 3 || i == 4){
                        boardArray[i][j] = 0;
                    }
                    else if(i > 4){
                        boardArray[i][j] = 2;

		    

void Board::printBoard(){
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			cout << boardArray[i][j] << "  ";
		}
		cout << endl;
    }

bool Board::winningState(){
	for(int i = 0; i < 8; i++){
	if(boardArray[0][i] == 2 || boardArray[7][i] == 1)
		return true;
	}
	return false;
}

void Board::moveRightDown(int x, int y){
	//invaild conditions
	if(isValid(x,y) == false){cout<< "Invalid Input!";}
	else if(isEmpty(x,y) == true){cout << "Invalid Input!";}
	else if(x == 7 || y == 7){cout<< "Invalid Move!";}
	else if(isEmpty(x+1, y+1) == false){cout<< "Invalid Move!";}
	//move the piece
	else{
		removePiece(x,y);
		boardArray[x+1][y+1] = 1;
	}
}

//check to see if the piece can move Right Downward without jumping.
bool Board::canMoveRightDown(int x, int y){ return isEmpty(x+1,y+1);}

void Board::moveLeftDown(int x, int y){
	//invaild conditions
	if(isValid(x,y) == false) {cout<< "Invalid Input!";}
	else if(isEmpty(x,y) == true){cout << "Invalid Input!";}
	else if(x == 7 || y == 0) {cout<< "Invalid Move!";}
	else if(boardArray[x+1][y-1] == 1) {cout<< "Invalid Move!";}
	//move the piece
	else{
		removePiece(x,y);
		boardArray[x+1][y-1] = 1;
	}
}

bool Board::canMoveLeftDown(int x, int y){ return isEmpty(x+1,y-1);}

void Board::moveRightUp(int x, int y){
	//invaild conditions
	if(isValid(x,y) == false) {cout<< "Invalid Input!";}
	else if(isEmpty(x,y) == true){cout << "Invalid Input!";}
	else if(x == 0 || y == 7){cout<< "Invalid Move!";}
	else if(boardArray[x-1][y+1] == 2){cout<< "Invalid Move!";}
	//move the piece
	else{
		removePiece(x,y);
		boardArray[x-1][y+1] = 2;
	}
}


bool Board::canMoveRightUp(int x, int y){ return isEmpty(x-1,y+1);}

void Board::moveLeftUp(int x, int y){
	//invaild conditions
	if(isValid(x,y) == false) {cout<< "Invalid Input!";}
	else if(isEmpty(x,y) == true){cout << "Invalid Input!";}
	else if(x == 0 || y == 0) {cout<< "Invalid Move!";}
	else if(boardArray[x-1][y-1] == 2) {cout<< "Invalid Move!";}
	//move the piece
	else{
		removePiece(x,y);
		boardArray[x-1][y-1] = 2;
	}
}

bool Board::canMoveLefttUp(int x, int y){ return isEmpty(x-1,y-1);}

void Board::jumpRightDown(int x, int y){
	//invaild conditions
	if(isValid(x,y) == false){cout<< "Invalid Input!";}
	else if(isEmpty(x,y) == true){cout << "Invalid Input!";}
	else if(x >= 6 || y >= 6){cout<< "Invalid Move!";}
	else if(boardArray[x+1][y+1] == 1){cout<< "Invalid Move!";}
	//move the piece and delete the opponents piece
	else{
		removePiece(x,y);
		int newX = x+2;
		int newY = y+2;
		boardArray[newX][newY] = 1;
		removePiece(x+1,y+1);
		//Check if the piece can jump again
		if(isLeftDown2(newX, newY) == true){
			jumpLeftDown(newX, newY);
		}
		if(isRightDown2(newX, newY) == true){
			jumpRightDown(newX, newY);
		}
	}
}

//check to see if it can jump Right downward.
bool Board::canJumpRightDown(int x, int y){ 
	if(boardArray[x+1][y+1]==2 && boardArray[x+2][y+2] == 0)
		return true;
	else return false;
}

void Board::jumpLeftDown(int x, int y){
	//invaild conditions
	if(isValid(x,y) == false) {cout<< "Invalid Input!";}
	else if(isEmpty(x,y) == true){cout << "Invalid Input!";}
	else if(x >= 6 || y <= 1) {cout<< "Invalid Move!";}
	else if(boardArray[x+2][y-2] == 1) {cout<< "Invalid Move!";}
	//move the piece and delete the opponents piece
	else{
		removePiece(x,y);
		int newX = x+2;
		int newY = y-2;
		boardArray[newX][newY] = 1;
		removePiece(x+1,y-1);
		//Check if the piece can jump again
		if(isLeftDown2(newX, newY) == true){
			jumpLeftDown(newX, newY);
		}
		if(isRightDown2(newX, newY) == true){
			jumpRightDown(newX, newY);
		}
	}
}

bool Board::canJumpLeftDown(int x, int y){ 
	if(boardArray[x+1][y-1]==2 && boardArray[x+2][y-2] == 0)
		return true;
	else return false;
}

void Board::jumpRightUp(int x, int y){
	//invaild conditions
	if(isValid(x,y) == false) {cout<< "Invalid Input!";}
	else if(isEmpty(x,y) == true){cout << "Invalid Input!";}
	else if(x <= 1 || y >= 6) {cout<< "Invalid Move!";}
	else if(boardArray[x-1][y+1] == 2) {cout<< "Invalid Move!";}
	//move the piece and delete the opponents piece
	else{
		removePiece(x,y);
		int newX = x-2;
		int newY = y+2;
		boardArray[newX][newY] = 2;
		removePiece(x-1,y+1);
		//Check if the piece can jump again
		if(isLeftUp1(newX, newY) == true){
			jumpLeftUp(newX, newY);
		}
		if(isRightUp1(newX, newY) == true){
			jumpRightUp(newX, newY);
		}
	}
}

bool Board::canJumpRightUp(int x, int y){
	if(boardArray[x-1][y+1]==1 && boardArray[x-2][y+2] == 0)
		return true;
	else return false;
}

void Board::jumpLeftUp(int x, int y){
	//invaild conditions
	if(isValid(x,y) == false) {cout<< "Invalid Input!";}
	else if(isEmpty(x,y) == true){cout << "Invalid Input!";}
	else if(x <= 1 || y<= 1) {cout<< "Invalid Move!";}
	else if(boardArray[x-1][y-1] == 2) {cout<< "Invalid Move!";}
	//move the piece and delete the opponents piece
	else{
		removePiece(x,y);
		int newX = x-2;
		int newY = y-2;
		boardArray[newX][newY] = 2;
		removePiece(x-1,y-1);
		//Check if the piece can jump again
		if(isLeftUp1(newX, newY) == true){
                	jumpLeftUp(newX, newY);
		}
		if(isRightUp1(newX, newY) == true){
	  		jumpRightUp(newX, newY);
		}
	}
}

bool Board::canJumpLeftUp(int x, int y){
	if(boardArray[x-1][y-1]==1 && boardArray[x-2][y-2] == 0)
		return true;
	else return false;
}


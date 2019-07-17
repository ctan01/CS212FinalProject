#ifndef __BOARD_H__
#define __BOARD_H__
#include <iostream>
#include <cstdlib>
using namespace std;

class board{

public:
    //CONSTURCTOR
    board(){

	board = {
		{0,1,0,1,0,1,0,1},
		{1,0,1,0,1,0,1,0},
		{0,1,0,1,0,1,0,1},
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},
		{2,0,2,0,2,0,2,0},
		{0,2,0,2,0,2,0,2},
		{2,0,2,0,2,0,2,0}
		};
    }

    void initialize board(){
	    for(int i = 0; i < 8; i++){
	    	for(int j = 0; j < 8; j++){
			boardArray[i][j] = 0;
			if(isValid(i, j)){
				if(i == 3 || i == 4){
					boardArray[i][j] = 0;
				}
				else if(i > 4){
					boardArray[i][j] = 2;
				}
				else{
					boardArray[i][j] = 1;
				}
			}
		}
		cout << endl;
	    }    
    }	
	
    void moveRightDown(int x, int y){
	    //Destiniation unvaild
	    if(isVaild(x,y) == false) {cout<< "Invalid Input!";}
	    else if(x == 7 || y == 7) {cout<< "Invalid Move!";
	    else if(isEmpty(x+1, y+1) == false) {cout<< "Invalid Move!";}
	    else{//move the piece
		    remove(x,y);
		    boardArray[x+1][y+1] = 1;
	    }
    }
	
    void moveLeftDown(int x, int y){
	    //Destiniation unvaild
	    if(isVaild(x,y) == false) {cout<< "Invalid Input!";}
	    else if(x == 7 || y == 0) {cout<< "Invalid Move!";}
	    else if(boardArray[x+1][y-1] == 1) {cout<< "Invalid Move!";}
	    else{//move the piece
		    remove(x,y);
		    boardArray[x+1][y-1] = 1;
	    }
    }
	
    void moveRightUp(int x, int y){
	    //Destiniation unvaild
	    if(isVaild(x,y) == false) {cout<< "Invalid Input!";}
	    elseif(x == 0 || y == 7)cout<< "Invalid Move!";}
	    else if(boardArray[x-1][y+1] == 2) {cout<< "Invalid Move!";}
	    else{//move the piece
		    remove(x,y);
		    boardArray[x-1][y+1] = 2;
	    }
    }
	
    void moveLeftUp(int x, int y){
	    //Destiniation unvaild
	    if(isVaild(x,y) == false) {cout<< "Invalid Input!";}
	    if(x == 0 || y == 0) {cout<< "Invalid Move!";}
	    if(boardArray[x-1][y-1] == 2) {cout<< "Invalid Move!";}
	    else{//move the piece
		    remove(x,y);
		    boardArray[x-1][y-1] = 2;
	    }
    }
	
    void jumpRightDown(int x, int y){
	    //Destiniation unvaild
	    if(isVaild(x,y) == false){cout<< "Invalid Input!";} 
	    else if(x >= 6 || y >= 6){cout<< "Invalid Move!";}
	    else if(boardArray[x+1][y+1] == 1){cout<< "Invalid Move!";}  
	    else{//move the piece and delete the opponents piece
		    remove(x,y);
		    int newX = x+2;
		    int newY = y+2;
		    boardArray[newX][newY] = 1;
		    remove(x+1,y+1);
		    //Check if the piece can jump again
		    if(isLeftDown2 == true){
			jumLeftDown(newX, newY);
		    }
		    if(isRightDown2 == true){
			jumpRightDown(newX, newY);
		    }
	    }
    }

    void jumpLeftDown(int x, int y){
	    //Destiniation unvaild
	    if(isVaild(x,y) == false) {cout<< "Invalid Input!";} 
	    else if(x >= 6 || y <= 1) {cout<< "Invalid Move!";}
	    else if(boardArray[x+2][y-2] == 1) {cout<< "Invalid Move!";}
	    else{//move the piece and delete the opponents piece
		    remove(x,y);
		    boardArray[x+2][y-2] = 1;
		    remove(x+1,y-1);
		    //Check if the piece can jump again
		    if(isLeftDown2 == true){
			jumLeftDown(newX, newY);
		    }
		    if(isRightDown2 == true){
			jumpRightDown(newX, newY);
		    }
	    }
    }
	
    void jumpRightUp(int x, int y){
	    //Destiniation unvaild
	    if(isVaild(x,y) == false) {cout<< "Invalid Input!";} 
	    else if(x <= 1 || y >= 6) {cout<< "Invalid Move!";}
	    else if(boardArray[x-1][y+1] == 2) {cout<< "Invalid Move!";}
	    else{//move the piece and delete the opponents piece
		    remove(x,y);
		    boardArray[x-2][y+2] = 2;
		    remove(x-1,y+1);
		    //Check if the piece can jump again
		    if(isLeftUp1 == true){
			jumLeftUp(newX, newY);
		    }
		    if(isRightUp1 == true){
			jumpRightUp(newX, newY);
		    }
	    }
    }
	
    void jumpLeftUp(int x, int y){
	    //Destiniation unvaild
	    if(isVaild(x,y) == false) {cout<< "Invalid Input!";} 
	    else if(x <= 1 || y<= 1) {cout<< "Invalid Move!";}
	    else if(boardArray[x-1][y-1] == 2) {cout<< "Invalid Move!";}
	    else{//move the piece and delete the opponents piece
		    remove(x,y);
		    boardArray[x-2][y-2] = 2;
		    remove(x-1,y-1);
		    //Check if the piece can jump again
		    if(isLeftUp1 == true){
			jumLeftUp(newX, newY);
		    }
		    if(isRightUp1 == true){
			jumpRightUp(newX, newY);
		    }
	    }
    }

	
    void remove(int x, int y){board[x][y] = 0;}
    bool isValid(int x, int y){return (x+y)%2 != 0;}
    bool isEmpty(int x, int y){return board[x][y] == 0;}
    bool is1(int x, int y){return board[x][y] == 1;}
    bool is2(int x, int y){return board[x][y] == 2;}
    bool isLeftUp1(int x, int y){return board[x-1][y-1] == 1;}
    bool isRightUp1(int x, int y){return board[x-1][y+1] == 1;}
    bool isLeftDown2(int x, int y){return board[x+1][y-1] == 2;}
    bool isLeftUp2(int x, int y){return board[x+1][y+1] == 2;}
   
private:
	static int boardArray[8][8];

};

#endif

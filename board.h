#ifndef __BOARD_H__
#define __BOARD_H__
#include <iostream>
#include <cstdlib>
using namespace std;

class board{

public:
	board(){

		board = {{0,1,0,1,0,1,0,1},
			 {1,0,1,0,1,0,1,0},
			 {0,1,0,1,0,1,0,1},
			 {0,0,0,0,0,0,0,0},
			 {0,0,0,0,0,0,0,0},
			 {2,0,2,0,2,0,2,0},
			 {0,2,0,2,0,2,0,2},
			 {2,0,2,0,2,0,2,0}};
	}
	
   void remove(int x, int y){ board[x][y] = 0;}

   void moveRightDown(int x, int y){
	   if((x+1)>7||(y+1)>7) {cout<< "Invalid Move!"; return;}
	   
	   if(boardArray[x+1][y+1] == 1) {cout<< "Invalid Move!"; return;}
	   
	   boardArray[x][y] = 0;
	   boardArray[x+1][y+1] = 1;
   }
	
   void moveLeftDown(int x, int y){
	   if((x+1)>7||(y-1)<0) {cout<< "Invalid Move!"; return;}
	   
	   if(boardArray[x+1][y-1] == 1) {cout<< "Invalid Move!"; return;}
	   
	   boardArray[x][y] = 0;
	   boardArray[x+1][y-1] = 1;
   }
	
   void moveRightUp(int x, int y){
	   if((x-1)<0||(y+1)>7) {cout<< "Invalid Move!"; return;}
	   
	   if(boardArray[x-1][y+1] == 2) {cout<< "Invalid Move!"; return;}
	   
	   boardArray[x][y] = 0;
	   boardArray[x-1][y+1] = 2;
   }
	
   void moveLeftUp(int x, int y){
	   if((x-1)<0||(y-1)<0) {cout<< "Invalid Move!"; return;}
	   
	   if(boardArray[x-1][y-1] == 2) {cout<< "Invalid Move!"; return;}
	   
	   boardArray[x][y] = 0;
	   boardArray[x-1][y-1] = 2;
   }
	
   void jumpDownRight(int x, int y){
	   if((x+2)>7||(y+2)>7) {cout<< "Invalid Move!"; return;}
	   
	   if(boardArray[x+1][y+1] == 1) {cout<< "Invalid Move!"; return;}  
	   
	   boardArray[x][y] = 0;
	   boardArray[x+2][y+2] = 1;
	   remove(x+1,y+1);
   }

   void jumpLeftDown(int x, int y){
	   if((x+2)>7||(y-2)<0) {cout<< "Invalid Move!"; return;}
	   
	   if(boardArray[x+2][y-2] == 1) {cout<< "Invalid Move!"; return;}
	   
	   boardArray[x][y] = 0;
	   boardArray[x+2][y-2] = 1;
	   remove(x+1,y-1);
   }
	
   void jumpRightUp(int x, int y){
	   if((x-2)<0||(y+2)>7) {cout<< "Invalid Move!"; return;}
	   
	   if(boardArray[x-1][y+1] == 2) {cout<< "Invalid Move!"; return;}
	   
	   boardArray[x][y] = 0;
	   boardArray[x-2][y+2] = 2;
	   remove(x-1,y+1);
   }
	
   void jumpLeftUp(int x, int y){
	   if((x-2)<0||(y-2)<0) {cout<< "Invalid Move!"; return;}
	   
	   if(boardArray[x-1][y-1] == 2) {cout<< "Invalid Move!"; return;}
	   
	   boardArray[x][y] = 0;
	   boardArray[x-2][y-2] = 2;
	   remove(x-1,y-1);
   }
	
   bool isValid(int x, int y){ return (x+y)%2 !=0;}
   bool isEmpty(int x, int y){ return board[x][y] == 0;}
   

private:
	static int boardArray[8][8];

};

#endif

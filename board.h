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
   bool isValid(int x, inty){ return (x+y)%2 !=0;}
   bool isEmpty(int x, int y){ return board[x][y] == 0;}
   

private:
	static int board[8][8];



};

#endif

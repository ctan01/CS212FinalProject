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
		 {1,0,1,0,1,0,1,0},
		 {0,1,0,1,0,1,0,1},
		 {1,0,1,0,1,0,1,0}};


}

private:
	static int board[8][8];



};
#endif

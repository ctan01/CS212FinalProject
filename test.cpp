#include "board.h"
#include "treeNode.h"


int main(){
  board testBoard;
  testBoard.printBoard();
  testBoard.moveLeftDown(2,3);
  testBoard.printBoard();
  testBoard.moveLeftDown(0,2);//expected to print "Invalid Move"
  
}

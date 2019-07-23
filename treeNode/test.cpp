#ifndef __TEST_CPP__
#define __TEST_CPP__
#include "board.cpp"
#include <iostream>
#include "treeNode.cpp"
using namespace std;

int main(){

  treeNode initialBoard; 
  //initialBoard.dfs(&initialBoard);
  initialBoard.data.printBoard();
return 0;



}


#endif

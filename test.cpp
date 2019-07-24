#ifndef __TEST_CPP__
#define __TEST_CPP__
#include "board.cpp"
#include <iostream>
#include "treeNode.cpp"
using namespace std;

int main(){
  Board a;
  a.printBoard();
  cout<<endl;
  treeNode initialBoard; 
  initialBoard.generateChild(&initialBoard);
  initialBoard.getChild(0)->data.printBoard();
return 0;



}


#endif

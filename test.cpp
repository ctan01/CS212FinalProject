#ifndef __TEST_CPP__
#define __TEST_CPP__
#include "board.cpp"
#include <iostream>
#include "treeNode.cpp"
using namespace std;

int main(){
  cout<<"original board"<<endl;
  Board a;
  a.printBoard();
  cout<<endl;
  cout<<"move 3rd column 2nd row pawn into right down"<<endl;
  a.moveLeftDown(2,1);
  a.printBoard();
  cout<<endl;
  cout<<"move 3rd column 2nd row pawn into right down, but its an empty space since we moved already, error message"<<endl;
  a.moveLeftDown(2,1);
  a.printBoard();
  cout<<endl;
  cout<<"move 4th column 1st row pawn into right down"<<endl;
  a.moveRightDown(3,0);
  a.printBoard();
  cout<<endl;
  cout<<"move 5th column 2nd row pawn into right up,but its white pawn, it cant move backward.error message"<<endl;
  a.moveRightDown(4,1);
  a.printBoard();
  cout<<endl;
  cout<<"move 5th column 2nd row pawn into right down, enemy pawn blocked, error "<<endl;
  a.moveRightDown(4,1);
  a.printBoard();
  cout<<endl;
  cout<<"lets try jump, jump 6th column 1st row pawn right up,it will capture enemy pawn and jump over "<<endl;
  a.jumpRightUp(5,0);
  a.printBoard();
  cout<<endl;
  cout<<"lets try jump again, jump 4th column 3rd row pawn right up,it failed because there is an enemy pawn block the path "<<endl;
  a.jumpRightUp(3,2);
  a.printBoard();
  cout<<endl;


  cout<<endl;
  treeNode initialBoard; 
  
  initialBoard.generateChild(&initialBoard);
  initialBoard.getChild(0)->data.printBoard();

return 0;



}


#endif

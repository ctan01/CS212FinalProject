#include "board.h"
#include "treeNode.h"
#include <iostream>
using namespace std;

int main(){
  treeNode initialBoard;
  treeNode winningBoard;
  queue<treeNode> outputQueue;
  winningBoard=treeNode.bfs(initialBoard);
  if(winningBoard.getParent()!=NULL)
  {
    outputQueue.push(winningBoard);
    winningBoard=(winningBoard.getParent());
  }
  if(outputQueue!=NULL)
  {
   outputQueue.front().printBoard();
  }
  return 0;
}

#ifndef __TREENODE_H__
#define __TREENODE_H__
#include <iostream>
#include <cstdlib>
#include "board.h"
#include "board.cpp"
#include <queue>
#include <stack>

using namespace std;

class treeNode{

  int countTurn=1; // global value to keep track of the turns of the pieces. 
           //initialize count to be odd, because black piece moves first in the original state. 
  public:
  
  //constructor
  treeNode();

  //copy constructor
  treeNode( treeNode *input);
 
  
  treeNode* getChild(int y);
  
  treeNode* getAllChild();
  
  
void addChild( treeNode *entry );
         
void winningMove(treeNode inParent);
  
void generateChild(treeNode *inParent);
  
  treeNode* bfs(treeNode* inParent);
 
              
  treeNode* dfs(treeNode* inParent);
    

  treeNode* UCS(treeNode *inParent,int x);
           
private:

    Board data;
    size_t numChildren;
    treeNode *parent;
    treeNode *children[30];
    
};


  void setChild( treeNode *entry, int pos);


#endif

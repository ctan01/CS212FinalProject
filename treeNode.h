#ifndef __TREENODE_H__
#define __TREENODE_H__
#include <iostream>
#include <cstdlib>
#include "board.h"
#include <queue>
#include <stack>

using namespace std;

class treeNode{
	
	global:size_t countTurn=1; // global value to keep track of the turns of the pieces. 
				   //initialize count to be odd, because black piece moves first in the original state. 
	
  public:
  
  //constructor
    treeNode();
	
	//we cannot create objects of same class in the constructor by using new keyword
//so we have to make a function named 'initialize' to initialize the pointers of a treenode
    void initialize();
  
  //copy constructor
    treeNode(const treeNode &input);
  
  void setChild(treeNode *entry, int pos） {     children[pos] = entry;  }
 
	
  treeNode* getChild(int y);
	
   treeNode* getAllChild();
  
  
 void addChild( treeNode *entry );
  
	
	
	
void generateChild(treeNode* inParent);

         
void winningMove(treeNode inParent);
	
	
	
  treeNode* bfs(treeNode* inParent);
 
              
  treeNode* dfs(treeNode* inParent);
    

	
	
	
	
	 treeNode* UCS(treeNode *inParent,int x);
           
   private:
    Board data;
    size_t numChildren;
    size_t capChildren;
    treeNode *parent;
    treeNode *children[capChildren];
    
};

#endif

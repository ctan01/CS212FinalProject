#ifndef __BTNODE_H__
#define __BTNODE_H__
#include <iostream>
#include <cstdlib>
#include "board.h"
#include <queue>

using namespace std;

class btNode{
  public:
    btNode(){
    numChildren = 0;
    capChildren = 100;
    data = board();
    parent = new btNode;
    children = new btNode*[capChildren];
    }
  
  void setChild( btNode** entry, int pos ){   children[pos] = entry; }
  
  
  void addChild( btNode** entry ){
     
     children[numChildren] = entry;
      numChildren++;
   }
  
  btNode** getChild( int y){return children [y];}
  
  
  btNode** getAllChild(){
     
     for( int i = 0; i<numChildren;i++){
       
        return children[i];}
     
   }
 
  
  btNode** genChild(btNode* input){
     
     
     
     
     
     
   }
           
  btNode** bfs(btNode* root){
    
    queue<board> bfsQueue;
    bfsQueue.push(parent);
    
    while( !bfsQueue.top().winningState())
    {
      genChild(bfsQueue.top());
      
        for(int i=0;i<numChildren;i++){
          
       bfsQueue.push(children [i])
       
        }
      
        bfsQueue.pop();
    }      
  }
              
  void dfs(btNode* parent){
    
    
    
    
  }
           
  private:
    board data;
    size_t numChildren;
    size_t capChildren;
    btNode *parent;
    btNode **children;
};

#endif

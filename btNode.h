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
    capChildren = 30;
    data = board();
    parent = new btNode;
    children = new btNode*[capChildren];
    }
  
  void setChild(btNode* inParent, btNode** entry, int pos){
   (*parent)-> children[pos] = entry;
  }
  
   void addChild(btNode* inParent, btNode** entry, int pos){
     
     (*inParent)-> children[pos+1] = entry;
      numChildren++;
   }
  
   btNode** getChild( int y){return (*parent) -> children [y];}
  
   btNode** getAllChild(){
     
     for( int i = 0; i<numChildren;i++){
       
        return (*parent) ->children[i];}
     
   }
 
   void generateChildren(btNode* input){
     
     while((*input)->data.
     
     
     
     
   }
           
  btNode** bfs(btNode* parent){
    
    queue<board> bfsQueue;
    bfsQueue.push(parent);
    size_t countChild=0;
    
    while( countChild < parent.numChildren)
    {
        if((*parent)-> children[countChild].winningState())
        
           { 
             return (*parent)-> children[numChildren];
             break;
           }
        
       bfsQueue.push((*parent)->children [countChild])
       countChild++;
    }       
    
    bfsQueue.pop();
    
    wwhile(!bfsQueue.empty())
      {
          bfs(bfsQueue.top(); 
      }
         
              }
           
  private:
    board data;
    size_t numChildren;
    size_t capChildren;
    btNode *parent;
    btNode **children;
};

#endif

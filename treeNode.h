#ifndef __TREENODE_H__
#define __TREENODE_H__
#include <iostream>
#include <cstdlib>
#include "board.h"
#include <queue>

using namespace std;

class treeNode{
  public:
  
  //constructor
    treeNode(){
    numChildren = 0;
    capChildren = 100;
    data = board();
    parent = new btNode;
    children = new btNode*[capChildren];
    }
  
  //copy constructor
    treeNode(btNode input){
      
     numChildren = input.numChildren;
     capChildren = input.capChildren;
     data = input.data;
      
     parent = input.parent;
      
     children = new btNode*[capChildren];
     for(int i = 0; i< input.numChildren;i++){ 
      children[i] = input.children[i]; 
     }
      
    }
  
  void setChild( treeNode** entry, int pos ){   children[pos] = entry; }
  
  
  void addChild( treeNode** entry ){
     
     children[numChildren] = entry;
      numChildren++;
   }
  
  treeNode** getChild(int y){return children [y];}
  
  
  treeNode** getAllChild(){
     
     for( int i = 0; i<numChildren;i++){
       
        return children[i];}
     
   }
  
  void setData( board entry) { data = entry;} 
  
  void genChild(treeNode* inParent){
     
     for(int i=0; i< 8;i++)
     {
        for(int j=0; j<8; j++)
        {
          treeNode tempNode; // temp  to store single child of the parent.
          board tempData; // temp data to store the board state so it wouldn't change the parent data when making a move. 
          
          if(inParent.winningState()) break;
          
          if(inParent.getData()[i][j]==1){
            
            //If it can jump down it will jump.
               if(inParent.data.canJumpRightDown(i,j))
                { 
                 tempData = inParent.data; 
                 tempChild.setData(temp);
                 inParent.addChild(
                }
            
               else if(canJumpLeftDown(i,j))
                { jumpLeftDown(i,j); }
            
            
            
            //If it can move down it will move.
               if(canMoveRightDown(i,j)){ moveRightDown(i,j);} 
               else if(canMoveLeftDown(i,j){ moveLeftDown(i,j);}
            
          }
          
        }
     }
     
     
     
     
   }
           
  treeNode** bfs(treeNode* root){
    
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
              
  void dfs(treeNode* parent){
    
    
    
    
  }
           
  private:
    board data;
    size_t numChildren;
    size_t capChildren;
    treeNode *parent;
    treeNode **children;
};

#endif

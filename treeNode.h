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
  
  void setChild( treeNode entry, int pos ){   children[pos] = entry; }
  
 
  void addChild( treeNode entry ){
     
     children[numChildren] = entry;
      numChildren++;
   }
  
  treeNode** getChild(int y){return children [y];}
  
  
  treeNode** getAllChild(){
     
     for( int i = 0; i<numChildren;i++){
       
        return children[i];}
     
   }
  
  void generateChild(treeNode* inParent){
     
    for(int i=0; i< 8;i++)
     {
      for(int j=0; j<8; j++)
        {
      
           board tempData; // temp data to store the board state so it wouldn't change the parent data when making a move. 
          
           if(inParent.data.winningState()) break; //check to see if the parent's board is already a winning state. 
          
           if(inParent.data[i][j]==1) //1 is on top of the board, representing pieces on top of the board. 
          {
            
            //If it can jump down it will jump. Jump has higher priority than move. It will only try to move if it can't jump.
            
            //Jump Right Down 
               if(inParent.data.canJumpRightDown(i,j)) 
                { 
                 treeNode tempNode = inParent; // store the parent state to tempNode before making the move (called the copy constructor)
                 
                 tempNode.data.jumpRightDown(); // Make the move with the tempNode
                 
                 inParent.addChild(tempNode); //add the tempNode to the parent's children
                }
            
            //Jump Left Down
               else if(inParent.data.canJumpLeftDown(i,j)) 
                { 
                 
                 treeNode tempNode = inParent; // store the parent state to tempNode before making the move 
                 
                 tempNode.data.jumpLeftDown(); // Make the move with the tempNode
                 
                 inParent.addChild(tempNode); //add the tempNode to the parent's children
                }
            
            //If it can move down it will move.
            
            //Move Right Down 
               else if(inParent.data.canMoveRightDown(i,j)) //
               
               {  treeNode tempNode = inParent; // store the parent state to tempNode before making the move (called the copy constructor)
                 
                 tempNode.data.moveRightDown(); // Make the move with the tempNode
                 
                 inParent.addChild(tempNode); //add the tempNode to the parent's children
               
               } 
            
             //Move Left Down
               else if(inParent.data.canMoveLeftDown(i,j)) //
               
               {  treeNode tempNode = inParent; // store the parent state to tempNode before making the move (called the copy constructor)
                 
                 tempNode.data.moveLeftDown(); // Make the move with the tempNode
                 
                 inParent.addChild(tempNode); //add the tempNode to the parent's children
               
               } 
            
           }
         
          
           if(inParent.data[i][j]==1) //2 is on bottom of the board, representing pieces on bottom of the board. 
          {
            
            //If it can jump up it will jump. Jump has higher priority than move. It will only try to move if it can't jump.
            
            //Jump Right Up
               if(inParent.data.canJumpRightUp(i,j)) 
                { 
                 treeNode tempNode = inParent; // store the parent state to tempNode before making the move (called the copy constructor)
                 
                 tempNode.data.jumpRightUp(); // Make the move with the tempNode
                 
                 inParent.addChild(tempNode); //add the tempNode to the parent's children
                }
            
            //Jump Left Up
               else if(inParent.data.canJumpLeftUp(i,j)) 
                { 
                 
                 treeNode tempNode = inParent; // store the parent state to tempNode before making the move 
                 
                 tempNode.data.jumpLeftUp(); // Make the move with the tempNode
                 
                 inParent.addChild(tempNode); //add the tempNode to the parent's children
                }
            
            //If it can move down it will move.
            
            //Move Right Up
               else if(inParent.data.canMoveRightUp(i,j)) //
               
               {  treeNode tempNode = inParent; // store the parent state to tempNode before making the move (called the copy constructor)
                 
                 tempNode.data.moveRightUp(); // Make the move with the tempNode
                 
                 inParent.addChild(tempNode); //add the tempNode to the parent's children
               
               } 
            
             //Move Left Up
               else if(inParent.data.canMoveLeftUp(i,j)) //
               
               {  treeNode tempNode = inParent; // store the parent state to tempNode before making the move (called the copy constructor)
                 
                 tempNode.data.moveLeftUp(); // Make the move with the tempNode
                 
                 inParent.addChild(tempNode); //add the tempNode to the parent's children
               
               } 
            
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

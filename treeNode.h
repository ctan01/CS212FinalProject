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
    treeNode(){
    numChildren = 0;
    data = Board();
    parent = NULL;
    for(int i=0; i<capChildren; i++)
    {
        children[i] = NULL;
    }
    }
	
	//we cannot create objects of same class in the constructor by using new keyword
//so we have to make a function named 'initialize' to initialize the pointers of a treenode
    void initialize()
    {
        parent = new treeNode;
        children = new treeNode*[capChildren];
    }
  
  //copy constructor
    treeNode(const treeNode &input){
      
     numChildren = input.numChildren;
     data = input.data;
     
     parent = input.parent;
      
     children = new treeNode*[capChildren];
	    
     for(int i = 0; i< input.numChildren;i++){ 
      children[i] = input.children[i]; 
     }
      
    }
  
  void setChild( treeNode **entry, int pos ){   children[pos] = entry; }
 
   treeNode* getParent(int y){
	if(parent[y] == NULL)
      {
          return NULL;
      }
      else
      {
          return parent[y];
    }
  }
   treeNode* getChild(int y){
      if(children[y] == NULL)
      {
          return NULL;
      }
      else
      {
          return children[y];
    }
  }
	
   treeNode** getAllChild(){

     for( int i = 0; i<numChildren;i++){

        return children[i];}

   }
  
  
 void addChild( treeNode *entry ){

     *children[numChildren] = entry;
     //we have to make children to point to their parent node
     //so parent pointer is assigned the address of the current node which is parent of newly created child
     children[numChildren]->parent = this;
      numChildren++;
   }
  
	
	
	
   void generateChild(treeNode* inParent){
	
	   
	if(countTurn %2!=0){ // if countTurn is odd, red piece moves. 
for(int i=0; i< 8;i++){
        for(int j=0; j<8; j++){


           if(inParent.data.winningState()) break; //check to see if the parent's board is already a winning state.

           if(inParent.data.boardArray[i][j]==2){ // we look for the 2 that is cloest to the oppoenet's edge becuase it is the 2 that is closest to wining


            //If it can jump down it will jump. Jump has higher priority than move. It will only try to move if it can't jump.

            //Jump Right Down
               if(inParent.data.canJumpRightDown(i,j))
                {
                 treeNode tempNode = *inParent; // store the parent state to tempNode before making the move (called the copy constructor)

                 tempNode.data.jumpRightDown(i , j); // Make the move with the tempNode

                 inParent.addChild(&tempNode); //add the tempNode to the parent's children
                }

            //Jump Left Down
             if(inParent.data.canJumpLeftDown(i,j))
                {

                 treeNode tempNode = *inParent; // store the parent state to tempNode before making the move

                 tempNode.data.jumpLeftDown(i , j); // Make the move with the tempNode

                 inParent.addChild(&tempNode); //add the tempNode to the parent's children
                }

            //If it can move down it will move.

            //Move Right Down
             if(inParent.data.canMoveRightDown(i,j)) //

               {  treeNode tempNode = *inParent; // store the parent state to tempNode before making the move (called the copy constructor)

                 tempNode.data.moveRightDown(i , j); // Make the move with the tempNode

                 inParent.addChild(&tempNode); //add the tempNode to the parent's children

               }

             //Move Left Down
             if(inParent.data.canMoveLeftDown(i,j)) //

               {  treeNode tempNode = *inParent; // store the parent state to tempNode before making the move (called the copy constructor)

                 tempNode.data.moveLeftDown(i , j); // Make the move with the tempNode

                 inParent.addChild(&tempNode); //add the tempNode to the parent's children

               }

           }
    }
}
}

	if(countTurn%2==0){ // if countTurn is even, white piece moves
for(int i = 7; i < 0; i--){
	for(int j = 7; j < 0; j--){
           if(inParent.data[i][j]==1) // look for the 1 that is cloest to the opponent's side
          {

            //If it can jump up it will jump. Jump has higher priority than move. It will only try to move if it can't jump.

            //Jump Right Up
               if(inParent.data.canJumpRightUp(i,j))
                {
                 treeNode tempNode = *inParent; // store the parent state to tempNode before making the move (called the copy constructor)

                 tempNode.data.jumpRightUp(i , j); // Make the move with the tempNode

                 inParent.addChild(&tempNode); //add the tempNode to the parent's children
                }

            //Jump Left Up
             if(inParent.data.canJumpLeftUp(i,j))
                {

                 treeNode tempNode = *inParent; // store the parent state to tempNode before making the move

                 tempNode.data.jumpLeftUp(i , j); // Make the move with the tempNode

                 inParent->addChild(&tempNode); //add the tempNode to the parent's children
                }

            //If it can move down it will move.

            //Move Right Up
             if(inParent.data.canMoveRightUp(i,j)) //

               {  treeNode tempNode = *inParent; // store the parent state to tempNode before making the move (called the copy constructor)

                 tempNode.data.moveRightUp(i , j); // Make the move with the tempNode

                 inParent->addChild(&tempNode); //add the tempNode to the parent's children

               }

             //Move Left Up
             if(inParent.data.canMoveLeftUp(i,j)) //

               {  treeNode tempNode = *inParent; // store the parent state to tempNode before making the move (called the copy constructor)

                 tempNode.data.moveLeftUp(i , j); // Make the move with the tempNode

                 inParent->addChild(&tempNode); //add the tempNode to the parent's children

               }

           }
    }
}
}

}
          
  void winningMove(treeNode inParent){
	  
	  
   	//generate Winning move first. WINNING MOVE
for(int i = 0; i < 8; i++){
	if(inParent.data[1][i] == 2){
		if(canMoveRightUp(1, i) == true){
			treeNode tempNode = inParent;
			tempNode.moveRihgtUp(1, i);
			 inParent.addChild(tempNode);
		
		}
		else if(canMoveLeftUp(1, i) == true){
			treeNode tempNode = inParent;
			tempNode.moveLeftUp(1, i);
			inParent.addChild(tempNode);
		}
	}
	
	if(inParent.data[1][i] ==1){
		if(canMoveRightDown(6,i)==true){
			treeNode tempNode = inParent;
			tempNode.moveRightDown(6,i);
			inParent.addChild(tempNode);
		}
		else if(canMoveLeftDown(6,i)==true){
			treeNode tempNode = inParent;
			tempNode.moveLeftDown(6,i);
			inParent.addChild(tempNode);
		}
		
	}
}	  
	  
  }
	
	
	
  treeNode* bfs(treeNode* inParent)
  {  
    queue<treeNode> bfsQueue;
    bfsQueue.push(inParent);
    
    while( !bfsQueue.empty() && !bfsQueue.front().data.winningState())
    {
      generateChild(bfsQueue.front()); //if the front Node in queue is not in a winning state, then generate all children of this Node.
      
        for(int i=0;i<bfsQueue.front().numChildren;i++)
          {
           bfsQueue.push(bfsQueue.front()* children [i]); // push all the generated children of inParent into the queue
          }
      
      if(bfsQueue.front().data.winningState())
      {
        return bfsQueue.front();      
      }
      
      bfsQueue.pop();   // now we can pop the front Node that is not in a winning state.
     
    }      
  }
              
  treeNode* dfs(treeNode* inParent)
    
{   
    
    stack<board> dfsStack;
    
    stack.push(inParent);
    
    while( !dfsStack.top().winningState())
   {
     generateChild(dfsStack.top()); //generate all the children top the top item on the stack.
      
           dfsStack.push(dfsStack.top()* children [i]); // push the first generated children of inParent into the stack
      
               
      if(dfsStack.top().data.winningState())
      {
        return dfsStack.top();      
      }
      
      dfsStack.pop();
      
   }
}
	
	
	
	
	 treeNode* UCS(treeNode *inParent,int x) //Uniform Cost Search
{
 
  if(x==1){ // search for path that least white piece got taken out of the game.
  
  	  stack<treeNode> stack1;
	  stack<treeNode> stack2; 
	  
   	  stack1.push(inParent);
     
   	while(!stack1.empty() && !stack1.top().data.winningState()){
        
           	  generateChildren(stack1.top()); //generate all the children of the Node has highest priority.
	  
	 	int minCost = -1;
	 	int minCostPos = 0;
	  
  	 for(int i =0; i<stack1.top().numChildren; i++){ // using the for loop to find the position of children that cost the least 1 piece.
		  
		if((stack1.top().countOne() - stack1.top()->children[i].countOne()) < minCost){
			  
			  minCost = stack1.top().countOne() - stack1.top()->children[i].countOne();
		 	 minCostPos = i;
        	}
  	 }
	  
	  //Now we store the child that cost the least piece to stack2; 
	  //clear stack1, and push that child to stack1;
	  
	  stack2.push(stack1.top()->children[minCostPos]);
	  stack1.pop();
	  stack1.push(stack2.top());
	  stack2.pop(); 
    }
	  
    	 return stack1.top(); //when the while loop terminates, the winnign state with the most 2 piece will be returned.
  }

		 
 	if(x==2){ // search for path that least white piece got taken out of the game.
  
  		  stack<treeNode> stack1;
		  stack<treeNode> stack2; 
	  
   		  stack1.push(inParent);
     
   	while(!stack1.empty() && !stack1.top().data.winningState()){
        
            	 generateChildren(stack1.top()); //generate all the children of the Node has highest priority.
	  
		 int minCost = -1;
		 int minCostPos = 0;
	  
  	 for(int i =0; i<stack1.top().numChildren; i++){ // using the for loop to find the position of children that cost the least 2 piece.
		  
		if((stack1.top().countTwo() - stack1.top()->children[i].countTwo()) < minCost){
			  
			  minCost = stack1.top().countTwo() - stack1.top()->children[i].countTwo();
			  minCostPos = i;
        }
   }
	  
	  //Now we store the child that cost the least piece to stack2; 
	  //clear stack1, and push that child to stack1;
	  
	  stack2.push(stack1.top()->children[minCostPos]);
	  stack1.pop();
	  stack1.push(stack2.top());
	  stack2.pop(); 
    }
	  
    	 return stack1.top(); //when the while loop terminates, the winnign state with the most 2 piece will be returned.
    ]

}
           
   private:
    Board data;
    size_t numChildren;
    size_t capChildren;
    treeNode *parent;
    treeNode *children[capChildren];
    
};

#endif

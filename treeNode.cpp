#ifndef __TREENODE_CPP__
#define __TREENODE_CPP__

#include "treeNode.h"
using namespace std;

treeNode::treeNode(){
    numChildren = 0;
    parent=NULL;
    data=Board();
   
    for(int i=0; i<capChildren; i++)
    {
        children[i] = NULL;
    }
	
    }

  
  //copy constructor
    treeNode::treeNode( treeNode *input){
      
     numChildren = input->numChildren;
     data = input->data;
     
     parent=input->parent;
	    
     for(int i = 0; i< input -> numChildren;i++){ 
      children[i] = input->children[i]; 
     }
      
    }
 
	
  treeNode* treeNode::getChild(int y){

      if(children[y] == NULL)
      {
          return NULL;
      }
      else
      {
          return children[y];
    }
  }
	
  treeNode* treeNode::getAllChild(){

     for( int i = 0; i<numChildren;i++){
        
        return children[i];}

   }
  
  
 void treeNode::addChild( treeNode *entry ){

     children[numChildren] = entry;
     //we have to make children to point to their parent node
     //so parent pointer is assigned the address of the current node which is parent of newly created child
     children[numChildren]->parent=this;
      numChildren++;
   }
   
  
	
	
	
      void treeNode::generateChild(treeNode *inParent){
	
	   
	if(countTurn %2!=0){ // if countTurn is odd, red piece moves. 

for(int i=0; i< 7;i++){
        for(int j=0; j<7; j++){


           //if(inParent->data.winningState()) return; //check to see if the parent's board is already a winning state.

           if(inParent->data.search(i,j)==1){ // we look for the 1 that is cloest to the oppoenet's edge becuase it is the 2 that is closest to wining


            //If it can jump down it will jump. Jump has higher priority than move. It will only try to move if it can't jump.

            //Jump Right Down
               if(inParent->data.canJumpRightDown(i,j)==true)
                {
                 treeNode tempNode = inParent; // store the parent state to tempNode before making the move (called the copy constructor)

                 tempNode.data.jumpRightDown(i , j); // Make the move with the tempNode

                 inParent->addChild(&tempNode); //add the tempNode to the parent's children
                 cout<<"attempt RD jump"<<endl;
                 tempNode.data.printBoard();
                 cout<<endl;
                }

            //Jump Left Down
             if(inParent->data.canJumpLeftDown(i,j)==true)
                {

                 treeNode tempNode = inParent; // store the parent state to tempNode before making the move

                 tempNode.data.jumpLeftDown(i , j); // Make the move with the tempNode

                 inParent->addChild(&tempNode); //add the tempNode to the parent's children
                }

            //If it can move down it will move.

            //Move Right Down
             if(inParent->data.canMoveRightDown(i,j)==true) //

               {  treeNode tempNode = inParent; // store the parent state to tempNode before making the move (called the copy constructor)

                 tempNode.data.moveRightDown(i , j); // Make the move with the tempNode

                 inParent->addChild(&tempNode); //add the tempNode to the parent's children
                                cout<<"attempt RD move"<<numChildren<<endl;
                 tempNode.data.printBoard();
                 cout<<endl;
               }
	

             //Move Left Down
             if(inParent->data.canMoveLeftDown(i,j)==true) //

               {  treeNode tempNode = inParent; // store the parent state to tempNode before making the move (called the copy constructor)

                 tempNode.data.moveLeftDown(i , j); // Make the move with the tempNode

                 inParent->addChild(&tempNode); //add the tempNode to the parent's children
                 cout<<"attempt LD move"<<numChildren<<endl;
                 tempNode.data.printBoard();
                 cout<<endl;
               }

           }
    }
}
}




	if(countTurn%2==0){ // if countTurn is even, white piece moves

for(int i = 7; i >= 0; i--){
	   for(int j = 7; j >= 0; j--){
          
           if(inParent->data.search(i,j)==2) // look for the 2 that is cloest to the opponent's side
          {

            //If it can jump up it will jump. Jump has higher priority than move. It will only try to move if it can't jump.

            //Jump Right Up
               if(inParent->data.canJumpRightUp(i,j))
                {
                 treeNode tempNode = inParent; // store the parent state to tempNode before making the move (called the copy constructor)

                 tempNode.data.jumpRightUp(i , j); // Make the move with the tempNode

                 inParent->addChild(&tempNode); //add the tempNode to the parent's children
                }

            //Jump Left Up
             if(inParent->data.canJumpLeftUp(i,j))
                {

                 treeNode tempNode = inParent; // store the parent state to tempNode before making the move

                 tempNode.data.jumpLeftUp(i , j); // Make the move with the tempNode

                 inParent->addChild(&tempNode); //add the tempNode to the parent's children
                }

            //If it can move down it will move.

            //Move Right Up
             if(inParent->data.canMoveRightUp(i,j)) //

               {  treeNode tempNode = inParent; // store the parent state to tempNode before making the move (called the copy constructor)

                 tempNode.data.moveRightUp(i , j); // Make the move with the tempNode

                 inParent->addChild(&tempNode); //add the tempNode to the parent's children

               }

             //Move Left Up
             if(inParent->data.canMoveLeftUp(i,j)) //

               {  treeNode tempNode = inParent; // store the parent state to tempNode before making the move (called the copy constructor)

                 tempNode.data.moveLeftUp(i , j); // Make the move with the tempNode

                 inParent->addChild(&tempNode); //add the tempNode to the parent's children

               }

           }
    }
}
}
}

          
  /*void winningMove(treeNode inParent){
	  
	  
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
	  
  }*/
	
	void treeNode::setChild( treeNode* entry, int pos ) { children[pos] = entry; }
	
  treeNode* treeNode::bfs(treeNode* inParent)
  {  
    queue<treeNode> bfsQueue;
    bfsQueue.push(inParent);
    
    while( !bfsQueue.empty() && !bfsQueue.front().data.winningState())
    {
	
      generateChild(&bfsQueue.front()); //if the front Node in queue is not in a winning state, then generate all children of this Node.
      
        for(int i=0;i<bfsQueue.front().numChildren;i++)
          {
           bfsQueue.push(bfsQueue.front().children [i]); // push all the generated children of inParent into the queue
          }
      
      if(bfsQueue.front().data.winningState())
      {
        return &bfsQueue.front();      
      }
      
      bfsQueue.pop();   // now we can pop the front Node that is not in a winning state.
     
    }      
  }
              
   treeNode* treeNode::dfs(treeNode* inParent)
    
{   
    
    stack<treeNode> dfsStack;
    dfsStack.push(inParent);
    
    while( !dfsStack.empty() && !dfsStack.top().data.winningState())
   {
     generateChild(&dfsStack.top()); //generate all the children top the top item on the stack.
      
           dfsStack.push(dfsStack.top().children [0]); // push the first generated children of inParent into the stack
      
               
      if(dfsStack.top().data.winningState())
      {
        return &dfsStack.top();      
      }
      
      dfsStack.pop();
      
   }
}
 
#endif
        return children[i];}

   }
  
  
 void treeNode::addChild( treeNode *entry ){

     children[numChildren] = entry;
     //we have to make children to point to their parent node
     //so parent pointer is assigned the address of the current node which is parent of newly created child
     children[numChildren]->parent = this;
      numChildren++;
   }
   
  
	
	
	
   void treeNode::generateChild(treeNode *inParent){
	
	   
	if(countTurn %2!=0){ // if countTurn is odd, red piece moves. 

for(int i=0; i< 8;i++){
        for(int j=0; j<2; j++){


           if(inParent->data.winningState()) return; //check to see if the parent's board is already a winning state.

           if(inParent->data.search(i,j)==1){ // we look for the 2 that is cloest to the oppoenet's edge becuase it is the 2 that is closest to wining


            //If it can jump down it will jump. Jump has higher priority than move. It will only try to move if it can't jump.

            //Jump Right Down
               if(inParent->data.canJumpRightDown(i,j)==true)
                {
                 treeNode *tempNode = inParent; // store the parent state to tempNode before making the move (called the copy constructor)

                 tempNode->data.jumpRightDown(i , j); // Make the move with the tempNode

                 inParent->addChild(tempNode); //add the tempNode to the parent's children
                }

            //Jump Left Down
             if(inParent->data.canJumpLeftDown(i,j)==true)
                {

                 treeNode *tempNode = inParent; // store the parent state to tempNode before making the move

                 tempNode->data.jumpLeftDown(i , j); // Make the move with the tempNode

                 inParent->addChild(tempNode); //add the tempNode to the parent's children
                }

            //If it can move down it will move.

            //Move Right Down
             if(inParent->data.canMoveRightDown(i,j)==true) //

               {  treeNode *tempNode = inParent; // store the parent state to tempNode before making the move (called the copy constructor)

                 tempNode->data.moveRightDown(i , j); // Make the move with the tempNode

                 inParent->addChild(tempNode); //add the tempNode to the parent's children

               }}}}

             //Move Left Down
            if(inParent->data.canMoveLeftDown(i,j)==true) //

               {  treeNode *tempNode = inParent; // store the parent state to tempNode before making the move (called the copy constructor)

                 tempNode->data.moveLeftDown(i , j); // Make the move with the tempNode

                 inParent->addChild(tempNode); //add the tempNode to the parent's children

               }

           }
    }
}

}


	if(countTurn%2==0){ // if countTurn is even, white piece moves

for(int i = 7; i < 0; i--){
	   for(int j = 7; j < 0; j--){
          
           if(inParent->data.search(i,j)==1) // look for the 1 that is cloest to the opponent's side
          {

            //If it can jump up it will jump. Jump has higher priority than move. It will only try to move if it can't jump.

            //Jump Right Up
               if(inParent->data.canJumpRightUp(i,j))
                {
                 treeNode *tempNode = inParent; // store the parent state to tempNode before making the move (called the copy constructor)

                 tempNode->data.jumpRightUp(i , j); // Make the move with the tempNode

                 inParent->addChild(tempNode); //add the tempNode to the parent's children
                }

            //Jump Left Up
             if(inParent->data.canJumpLeftUp(i,j))
                {

                 treeNode *tempNode = inParent; // store the parent state to tempNode before making the move

                 tempNode->data.jumpLeftUp(i , j); // Make the move with the tempNode

                 inParent->addChild(tempNode); //add the tempNode to the parent's children
                }

            //If it can move down it will move.

            //Move Right Up
             if(inParent->data.canMoveRightUp(i,j)) //

               {  treeNode *tempNode = inParent; // store the parent state to tempNode before making the move (called the copy constructor)

                 tempNode->data.moveRightUp(i , j); // Make the move with the tempNode

                 inParent->addChild(tempNode); //add the tempNode to the parent's children

               }

             //Move Left Up
             if(inParent->data.canMoveLeftUp(i,j)) //

               {  treeNode *tempNode = inParent; // store the parent state to tempNode before making the move (called the copy constructor)

                 tempNode->data.moveLeftUp(i , j); // Make the move with the tempNode

                 inParent->addChild(tempNode); //add the tempNode to the parent's children

               }

           }
    }
}
}

}
          
  /*void winningMove(treeNode inParent){
	  
	  
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
	  
  }*/
	
	void treeNode::setChild( treeNode* entry, int pos ) { children[pos] = entry; }
	
  treeNode* treeNode::bfs(treeNode* inParent)
  {  
    queue<treeNode> bfsQueue;
    bfsQueue.push(inParent);
    
    while( !bfsQueue.empty() && !bfsQueue.front().data.winningState())
    {
	
      generateChild(&bfsQueue.front()); //if the front Node in queue is not in a winning state, then generate all children of this Node.
      
        for(int i=0;i<bfsQueue.front().numChildren;i++)
          {
           bfsQueue.push(bfsQueue.front().children [i]); // push all the generated children of inParent into the queue
          }
      
      if(bfsQueue.front().data.winningState())
      {
        return &bfsQueue.front();      
      }
      
      bfsQueue.pop();   // now we can pop the front Node that is not in a winning state.
     
    }      
  }
              
   treeNode* treeNode::dfs(treeNode* inParent)
    
{   
    
    stack<treeNode> dfsStack;
    dfsStack.push(inParent);
    
    while( !dfsStack.empty() && !dfsStack.top().data.winningState())
   {
     generateChild(&dfsStack.top()); //generate all the children top the top item on the stack.
      
           dfsStack.push(dfsStack.top().children [0]); // push the first generated children of inParent into the stack
      
               
      if(dfsStack.top().data.winningState())
      {
        return &dfsStack.top();      
      }
      
      dfsStack.pop();
      
   }
}
 
#endif

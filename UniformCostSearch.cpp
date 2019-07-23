    
#include "board.h"
#include "board.cpp"
#include "treeNode.h"
#include "treeNOde.cpp"
using namespace std;

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
	  
  	 for(int i =0; i<stack1.top()->numChildren; i++){ // using the for loop to find the position of children that cost the least 1 piece.
		  
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
}

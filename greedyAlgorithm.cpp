treeNode* greedyAlg(treeNode* inParent){
	treeNode *curr; 
	curr = inParent;
	board temp1;
	int closest1i = 7;
	int closest2i = 0;
	int cloestIndex = 0;
	int disFromEdge; 
	int closestDis = 7;
	board temp2;
	while(!curr.data.winningState()){//find the node that contains the board that have a piece closest to the enemy's edge.
		for(int k = 0; k < numChildren; k++){
			for(int i=0; i< 8;i++){
       				for(int j=0; j<8; j++){
					boardArray[i][j] == 2;
					if(i < closest2i){
						cloest2i = i;
					}
				}
			}
			for(int i = 7; i < 0; i--){
				for(int j = 7; j < 0; j--){
					boardArray[i][j] == 1;
					if(i > cloest1i){
						cloest1i = i;
					}
				}
			}
			if(cloest2i > (7 - cloest1i)){
				disFromEdge = cloest2i;
			}
			else{
				disFromEdge = 7 - cloest1i;
			}
			if(disFromEdge < closestDis){
				closestDis = disFromEdge;
				cloestIndex = k;
			}
				
		}//k
		
	}
}

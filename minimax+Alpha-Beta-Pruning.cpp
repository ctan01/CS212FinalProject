

  int* minimaxforplayer1(treeNode* inParent){//this function make the decision whether player should make offense move or defence move. it returns an array that contains two variables: the i and j of the desire pawn
     
     int posi1,posj1,posi2,posj2;//int variable that record the deepest player1 node and player 2 node
	  
     treeNode tempNode = inParent;//make a temp node so it wont effect the original stat of the board.
	  
     int* ar[1];//the array that store the coordinate
	  
   for(int i=6; i>=0;i--){//find the pawn that closest to the winning line
   	 for(int j=7; j>=0; j--){     
     	 	  if(inParent.data[i][j]==1&&ABP(inparent,i,j)==true)
		  {//check ABP 
			posi1=i;
			posj1=j;
		  }
  		  else	{}
 	  }		 
      }
	  
   for(int i=1; i<8;i++){//find the opponent pawn that closest to the winning line
    	for(int j=0; j<8; j++){ 
    		 if(inParent.data[i][j]==2){
			posi2=i;
			posj2=j;
		}
	}
}
   if(posi2<7-posi1){//if opponent pawn is closer then we must check if there is a pawn can kill it otherwise we will lose first
     
     	 if(canJumpRightDown(posi2-1,posj2-1)==ture){//check if down-left pawn can kill the opponent pawn
		ar[0]=posi2-1;
		ar[1]=posj2-1;
		return ar;
	}
      else if(canJumpLeftDown(inparent.data[posi2-1],inparent.data[posj2+1])==ture){//check if down-right pawn can kill the opponent pawn
		ar[0]=posi2-1;
		ar[1]=posj2+1;
		return ar;
	}
      else{
		ar[0]=posi1;
		ar[1]=posj1;
		return ar;//means no pawns are avaliable to kill the opponent pawn
	} 
      else{//means we will win first so we dont have to worry about the opponent pawn since we are closer.
		ar[0]=posi1;
		ar[1]=posj1;
		return ar;
	}
}

  




//___________________________________________________________________________________________//







int* minimaxforplayer2(treeNode* inParent){//this function make the decision whether player should make offense move or defence move. it returns an array that contains two variables: the i and j of the desire pawn
     
	int posi1,posj1,posi2,posj2;//int variable that record the deepest player1 node and player 2 node
        treeNode tempNode = inParent;//make a temp node so it wont effect the original stat of the board.
     	int* ar[1];//the array that store the coordinate
   for(int i=1; i<8;i++){//find the pawn that closest to the winning line
   	 for(int j=0; j<8; j++){     
     	   if(inParent.data[i][j]==2&&ABP(inparent,i,j)==true){//check ABP 
		posi1=i;
		posj1=j;
		}
	   else{
	   }
       }
   }
	
   for(int i=6; i>=0;i--){//find the opponent pawn that closest to the winning line
    	for(int j=7; j>=0; j--){ 
   	  if(inParent.data[i][j]==1){
		posi2=i;
		posj2=j;
		}
	}
}
	
   if(7-posi2<posi1){//if opponent pawn is closer then we must check if there is a pawn can kill it otherwise we will lose first
     
      if(canJumpRightUp(posi2+1,posj2-1)==ture){//check if down-left pawn can kill the opponent pawn
		ar[0]=posi2+1;
		ar[1]=posj2-1;
		return ar;
	}
      else if(canJumpLeftUp(inparent.data[posi2+1],inparent.data[posj2+1])==ture){//check if down-right pawn can kill the opponent pawn
		ar[0]=posi2+1;
		ar[1]=posj2+1;
		return ar;
	}
      else{
		ar[0]=posi1;
		ar[1]=posj1;
		return ar;//means no pawns are avaliable to kill the opponent pawn
	} 
      else{//means we will win first so we dont have to worry about the opponent pawn since we are closer.
		ar[0]=posi1;
		ar[1]=posj1;
		return ar;
	}
}

//___________________________________________________________________________________________//




 bool ABP(treeNode* inparent,int i, int j){//alpha-beta-pruning,to check if you make the move will the opponent able to kill the pawn that you recently moved
		
	 if(inparent.data[i][j]==2){
		 
		  if(inparent.data[i-2][j+2]==1&&inparent.data[i-2][j]==1&&inparent.data[i-2][j-2]==1){//player2 POV
		 	  return false;//all 3 spots have opponent pawns, which our pawn will be killed after the move
			}
	 
	else{
		
	  if(inparent.data[i+2][j+2]==2&&inparent.data[i+2][j]==2&&inparent.data[i+2][j-2]==2){//player1 POV
		  
	   return false;//all 3 spots have opponent pawns, which our pawn will be killed after the move
	}
	  return true; 
	}
}
	

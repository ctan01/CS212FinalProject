#include <iostream>

#include <cstdlib>

using namespace std;



class Board{



public:

    //CONSTURCTOR

    Board();



    void removePiece(int x, int y){boardArray[x][y] = 0;}

    bool isValid(int x, int y){return (x+y)%2 != 0;}

    bool isEmpty(int x, int y){return boardArray[x][y] == 0;}

    bool is1(int x, int y){return boardArray[x][y] == 1;}

    bool is2(int x, int y){return boardArray[x][y] == 2;}

	

    bool isLeftUp1(int x, int y){return boardArray[x-1][y-1] == 1;}

    bool isLeftUp2(int x , int y){return boardArray[x-1][y-1] == 2;}



    bool isRightUp1(int x, int y){return boardArray[x-1][y+1] == 1;}

    bool isRightUp2(int x , int y){return boardArray[x-1][y+1] == 2;}



    bool isLeftDown1(int x , int y){return boardArray[x+1][y-1] == 1;}

    bool isLeftDown2(int x, int y){return boardArray[x+1][y-1] == 2;}



    bool isRightDown1(int x , int y){return boardArray[x+1][y+1] == 1;}

    bool isRightDown2(int x , int y){return boardArray[x+1][y+1] == 2;}



    //INITIALIZE THE GAME

    void initializeBoard();

    //PRINT THE BOARD

    void printBoard();

    //DETERMINE IF THE GAME ENDS

    bool winningState();



    //MOVE PIECES

    void moveRightDown(int x, int y);

    void moveLeftDown(int x, int y);

    void moveRightUp(int x, int y);

    void moveLeftUp(int x, int y);

    void jumpRightDown(int x, int y);

    void jumpLeftDown(int x, int y);

    void jumpRightUp(int x, int y);

    void jumpLeftUp(int x, int y);



    //CHECK IF THE PIECE CAN JUMP OR MOVE

    bool canMoveRightUp(int x, int y);

    bool canMoveLefttUp(int x, int y);

    bool canMoveRightDown(int x, int y);

    bool canMoveLeftDown(int x, int y);

    bool canJumpRightUp(int x, int y);

    bool canJumpLeftUp(int x, int y);

    bool canJumpRightDown(int x, int y);

    bool canJumpLeftDown(int x, int y);

	

    //Count the amount of Ones and Twos on the board. 	

    int countOne();

    int countTwo();





private:

	 int boardArray[8][8];

      bool objectAlreadyCreated;



};

Board::Board()

{

/*

	{0,1,0,1,0,1,0,1},

	{1,0,1,0,1,0,1,0},

	{0,1,0,1,0,1,0,1},

	{0,0,0,0,0,0,0,0},

	{0,0,0,0,0,0,0,0},

	{2,0,2,0,2,0,2,0},

	{0,2,0,2,0,2,0,2},

	{2,0,2,0,2,0,2,0}

*/

    //if object is not created already then make a new one and initialize it

    if(objectAlreadyCreated == false)

    {

        for(int i = 0; i < 8; i++){

            for(int j = 0; j < 8; j++){

		    boardArray[i][j] = 0;

                if(isValid(i, j)){

                    if(i == 3 || i == 4){

                        boardArray[i][j] = 0;

                    }

                    else if(i > 4){

                        boardArray[i][j] = 2;

			    }

                    else{

                        boardArray[i][j] = 1;

                    }

                }

            }

        }

    }

    //object created

    objectAlreadyCreated = true;

}



void Board::printBoard(){

	for(int i = 0; i < 8; i++){

		for(int j = 0; j < 8; j++){

			cout << boardArray[i][j] << "  ";

		}

		cout << endl;

    }}



bool Board::winningState(){

	for(int i = 0; i < 8; i++){

	if(boardArray[0][i] == 2 || boardArray[7][i] == 1)

		return true;

	}

	return false;

}



void Board::moveRightDown(int x, int y){

	//invaild conditions

	if(isValid(x,y) == false){cout<< "Invalid Input!";}

	else if(x == 7 || y == 7){cout<< "Invalid Move!";}

	else if(isEmpty(x+1, y+1) == false){cout<< "Invalid Move!";}

	//move the piece

	else{

		removePiece(x,y);

		boardArray[x+1][y+1] = 1;

	}

}



//check to see if the piece can move Right Downward without jumping.

bool Board::canMoveRightDown(int x, int y){ return isEmpty(x+1,y+1);}



void Board::moveLeftDown(int x, int y){

	//invaild conditions

	//if(isValid(x,y) == false) {cout<< "Invalid Input!";}else

	 if(x == 7 || y == 0) {cout<< "Invalid Move!";}

	else if(boardArray[x+1][y-1] == 1) {cout<< "Invalid Move!";}

	//move the piece

	else{

		removePiece(x,y);

		boardArray[x+1][y-1] = 1;

	}

}



bool Board::canMoveLeftDown(int x, int y){ return isEmpty(x+1,y-1);}



void Board::moveRightUp(int x, int y){

	//invaild conditions

	if(isValid(x,y) == false) {cout<< "Invalid Input!";}

	else if(x == 0 || y == 7){cout<< "Invalid Move!";}

	else if(boardArray[x-1][y+1] == 2){cout<< "Invalid Move!";}

	//move the piece

	else{

		removePiece(x,y);

		boardArray[x-1][y+1] = 2;

	}

}





bool Board::canMoveRightUp(int x, int y){ return isEmpty(x-1,y+1);}



void Board::moveLeftUp(int x, int y){

	//invaild conditions

	if(isValid(x,y) == false) {cout<< "Invalid Input!";}

	else if(x == 0 || y == 0) {cout<< "Invalid Move!";}

	else if(boardArray[x-1][y-1] == 2) {cout<< "Invalid Move!";}

	//move the piece

	else{

		removePiece(x,y);

		boardArray[x-1][y-1] = 2;

	}

}



bool Board::canMoveLefttUp(int x, int y){ return isEmpty(x-1,y-1);}



void Board::jumpRightDown(int x, int y){

	//invaild conditions

	if(isValid(x,y) == false){cout<< "Invalid Input!";}

	else if(x >= 6 || y >= 6){cout<< "Invalid Move!";}

	else if(boardArray[x+1][y+1] == 1){cout<< "Invalid Move!";}

	//move the piece and delete the opponents piece

	else{

		removePiece(x,y);

		int newX = x+2;

		int newY = y+2;

		boardArray[newX][newY] = 1;

		removePiece(x+1,y+1);

		//Check if the piece can jump again

		if(isLeftDown2(newX, newY) == true){

			jumpLeftDown(newX, newY);

		}

		if(isRightDown2(newX, newY) == true){

			jumpRightDown(newX, newY);

		}

	}

}



//check to see if it can jump Right downward.

bool Board::canJumpRightDown(int x, int y){ 

	if(boardArray[x+1][y+1]==2 && boardArray[x+2][y+2] == 0)

		return true;

	else return false;

}



void Board::jumpLeftDown(int x, int y){

	//invaild conditions

	if(isValid(x,y) == false) {cout<< "Invalid Input!";}

	else if(x >= 6 || y <= 1) {cout<< "Invalid Move!";}

	else if(boardArray[x+2][y-2] == 1) {cout<< "Invalid Move!";}

	//move the piece and delete the opponents piece

	else{

		removePiece(x,y);

		int newX = x+2;

		int newY = y-2;

		boardArray[newX][newY] = 1;

		removePiece(x+1,y-1);

		//Check if the piece can jump again

		if(isLeftDown2(newX, newY) == true){

			jumpLeftDown(newX, newY);

		}

		if(isRightDown2(newX, newY) == true){

			jumpRightDown(newX, newY);

		}

	}

}



bool Board::canJumpLeftDown(int x, int y){ 

	if(boardArray[x+1][y-1]==2 && boardArray[x+2][y-2] == 0)

		return true;

	else return false;

}



void Board::jumpRightUp(int x, int y){

	//invaild conditions

	if(isValid(x,y) == false) {cout<< "Invalid Input!";}

	else if(x <= 1 || y >= 6) {cout<< "Invalid Move!";}

	else if(boardArray[x-1][y+1] == 2) {cout<< "Invalid Move!";}

	//move the piece and delete the opponents piece

	else{

		removePiece(x,y);

		int newX = x-2;

		int newY = y+2;

		boardArray[newX][newY] = 2;

		removePiece(x-1,y+1);

		//Check if the piece can jump again

		if(isLeftUp1(newX, newY) == true){

			jumpLeftUp(newX, newY);

		}

		if(isRightUp1(newX, newY) == true){

			jumpRightUp(newX, newY);

		}

	}

}



bool Board::canJumpRightUp(int x, int y){

	if(boardArray[x-1][y+1]==1 && boardArray[x-2][y+2] == 0)

		return true;

	else return false;

}



void Board::jumpLeftUp(int x, int y){

	//invaild conditions

	if(isValid(x,y) == false) {cout<< "Invalid Input!";}

	else if(x <= 1 || y<= 1) {cout<< "Invalid Move!";}

	else if(boardArray[x-1][y-1] == 2) {cout<< "Invalid Move!";}

	//move the piece and delete the opponents piece

	else{

		removePiece(x,y);

		int newX = x-2;

		int newY = y-2;

		boardArray[newX][newY] = 2;

		removePiece(x-1,y-1);

		//Check if the piece can jump again

		if(isLeftUp1(newX, newY) == true){

                	jumpLeftUp(newX, newY);

		}

		if(isRightUp1(newX, newY) == true){

	  		jumpRightUp(newX, newY);

		}

	}

}



bool Board::canJumpLeftUp(int x, int y){

	if(boardArray[x-1][y-1]==1 && boardArray[x-2][y-2] == 0)

		return true;

	else return false;

}

	

int Board:: countOne(){

	int count;

	for(int i=0;i<8;i++){

		for(int j=0;j<8;j++){

			if(boardArray[i][j] ==1){

				count++;

			}

		}

	}

	return count;

}

	

	

int Board:: countTwo(){

	int count;

	for(int i=0;i<8;i++){

		for(int j=0;j<8;j++){

			if(boardArray[i][j] ==2){

				count++;

			}

		}

	}

	return count;

}
int main()
{
Board a;
a.printBoard();
cout<<"position 4th line 2nd pawn move to the left down"<<endl;
a.moveLeftDown(3,1);
a.printBoard();
}

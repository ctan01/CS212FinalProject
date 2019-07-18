#include "board.h"
using namespace std;

void Board::printBoard(){
    	cout << "|----|----|----|----|----|----|----|----|" << endl;
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			cout << "| " << boardArray[i][j] << "  ";
		}
		cout << "|" << endl << "|----|----|----|----|----|----|----|----|" << endl;
	}
	    cout << endl;
    }

     bool winningState(){
	    for(int i = 0; i < 8; i++){
	    	if(boardArray[0][i] == 2 || boardArray[7][i] == 1)
			return true;
	    }
	    return false;
   }

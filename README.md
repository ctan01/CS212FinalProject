# CS212FinalProject

1. Project description: Draughts is played on an 8x8 chessboard. There are 2 players in the game, each side takes 12 pieces of one color and place one on each of the black squares in the first 3 rows of your side. The winning condition of the game is when any one of the 12 pieces has reached the other side of the board. Our program is intended to generate all possible movement of a draught game by using a tree class similar to the sample code. 

2. The board class is used to represent the game board 

3. The tree class is used to store states of the game, where the root of the tree will be the initial state and each children of a  treeNode will store the possible move of its parent. 

4. A function for BFS and DFS.

5. Three search algorithm or decision-making algorithm. 

run the test.cpp which has main inside.
what we did and what we couldn't solve:


We debugged board class. it works perfectly. as you can see in the test.cpp. when it can move/jump, it will. block by other pawn or selected square has wrong pawn/empty will create error message. it also can double jump. those thing we all debugged.

for tree class. it initializes. However, the generate child function meant to generate all outcomes under certain board, and add them into a treeNode *array. however, I put a print function under each if function and use a numChild to check how many outcomes it has. it works in the generate function. But once we put them into the array. it gives some crazy output. I think it has something to do with the pointer array and the link of parent in the addChild function. the bfs dfs should works perfectly if the addChild function work correctly. since its all recursion stack queue. the 3 algorithm we only can provide idea and the code. But we cant debug it since the addChild doesnt work.

# initial_lab
Lab3
Amee Rothman
arothman11
475030

ERRORS:
I did not realize that when checking a function in a conditional for if statements or while loops, it calls the function. I was calling functions multiple times in places where I should have just been checking and was getting alot of errors. I fixed this by setting a local variable equal to the return value of the fucntion so I could check the return value of a function multiple times without calling it over and over again.

TEST CASES:

BADLY FORMED COMMAND LINE
	H:\repos\lab3\lab3\Debug>lab3.exe
	Invalid number of arguments.
	There is an error
	usage: lab3.exe Enter 1 valid argument.
This printed out the correct ussage message for the poorly formed command line


WELL FORMED COMMAND LINE
	H:\repos\lab3\lab3\Debug>lab3.exe TicTacToe
	4
	3
	2
	1
	0
	 0 1 2 3 4

	Enter one of the following: A valid coordinate (x,y) to make your move, or quit to stop playing
This correctly printed out the empty board and prompted the user to input coordinates

BAD COORDINATES
	22
	Could not read input
	Enter one of the following: A valid coordinate (x,y) to make your move, or quit to stop playing

	1
	Could not read input
	Enter one of the following: A valid coordinate (x,y) to make your move, or quit to stop playing
This correctly printed out an error message that the input could not be read because it was in the wrong format and reprompted the user to input valid coordinates

	4,4
	Coordinates out of range. Enter an x coordinate between 1-3 and a y coordinate between 1-3.
	Enter one of the following: A valid coordinate (x,y) to make your move, or quit to stop playing
This correctly printed out an error message indicating the coordinates were out of range.

GOOD COORDINATES
	1,1
	4
	3
	2
	1   x
	0
	 0 1 2 3 4

	Player x: 1, 1;
	Enter one of the following: A valid coordinate (x,y) to make your move, or quit to stop playing
This correctly plotted the coordinate on the board, printed out the players move, and prompted the next player to make a move.

	3,3
	4
	3       o
	2
	1   x
	0
	 0 1 2 3 4

	Player o: 3, 3;
	Enter one of the following: A valid coordinate (x,y) to make your move, or quit to stop playing
This correctly switched to the other players turn, and plotted their coordinates as well as printed out thier move.

WINNING: This correctly ended the game after player x made their winning move and printed out that they won.
vertical win
	1,3
	4
	3   x   o
	2   x
	1   x o
	0
	 0 1 2 3 4

	Player x: 1, 1; 1, 2; 1, 3;
	Player x wins.

diagonal win
	3,3
	4
	3       x
	2   o x
	1   x o
	0
	 0 1 2 3 4

	Player x: 1, 1; 2, 2; 3, 3;
	Player x wins.

horizontal win
	3,1
	4
	3   o
	2   o
	1   x x x
	0
	 0 1 2 3 4

	Player x: 1, 1; 2, 1; 3, 1;
	Player x wins.

QUIT
	quit
	User Quit. Number of moves remaining: 7
Correctly ends the game and prints out correct remaining number of moves after quit.

SPOT TAKEN
	1,3
	Spot is already taken! Try Again.
	Enter one of the following: A valid coordinate (x,y) to make your move, or quit to stop playing
Correctly identifies when a spot is full and reprompts user to input valid coordinate.

DRAW
	4
	3   x x o
	2   o o x
	1   x o x
	0
	 0 1 2 3 4

	Player x: 1, 1; 1, 3; 2, 3; 3, 1; 3, 2;
	Game Over. There is no winner. Number of Moves Played: 9. No winning moves remain.
Correctly prints out when there is a draw--no user wins.
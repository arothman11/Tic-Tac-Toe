#pragma once
#include "GamePieces.h"
#include "GameBoard.h"
#include "CommonFunctions.h"

class TicTacToe {
	friend ostream& operator<<(ostream& out, const TicTacToe& game_object);
	public:
		TicTacToe();
		bool done();
		bool draw();
		int prompt(unsigned int& x, unsigned int& y);
		int turn();
		int play();
	private:
		vector<game_piece> board;
		int board_width = 5;
		int board_height = 5;
		bool player = 0;
		bool winningplayer = 0;
		unsigned int num_moves = 9;
		//functions to check different ways of winning
		bool vertical(vector<game_piece> board, int board_width, int board_height);
		bool horizontal(vector<game_piece> board, int board_width, int board_height);
		bool diagonal(vector<game_piece> board, int board_width, int board_height);
};

ostream& operator<<(ostream& out, const TicTacToe& game_object);


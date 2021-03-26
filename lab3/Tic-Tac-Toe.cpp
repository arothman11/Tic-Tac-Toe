#include "Tic-Tac-Toe.h"

TicTacToe::TicTacToe() {
	game_piece empty_piece (nocolor, "", " ");
	for (int i = 0; i < (board_width * board_height); ++i) {
		board.push_back(empty_piece);
	}
}

ostream& operator<<(ostream& out, const TicTacToe& game_object) {
	for (int y = game_object.board_height - 1; y >= 0; --y) {
		out << y << " ";
		for (int x = 0; x <= game_object.board_width - 1; ++x) {
			out << game_object.board[game_object.board_width * y + x].display_ << " ";
		}
		out << endl;
	}
	out << " 0 1 2 3 4 " << endl;
	return out;
}

bool TicTacToe::done() {
	return vertical(board, board_width, board_height) || horizontal(board, board_width, board_height) || diagonal(board, board_width, board_height);
}

bool TicTacToe::vertical(vector<game_piece> board, int board_width, int board_height) {
	for (int x = 1; x < board_width - 1; ++x) {
		string display = board[board_width * 2 + x].display_;
		if (display != " ") {
			if ((display == board[board_width * 1 + x].display_) && (display == board[board_width * 3 + x].display_)) {
				if (board[board_width * 2 + x].display_ == "x") {
					winningplayer = 0;
				}
				else if(board[board_width * 2 + x].display_ == "o"){
					winningplayer = 1;
				}
				return true;
			}
		}
	}
	return false;
}

bool TicTacToe::horizontal(vector<game_piece> board, int board_width, int board_height) {
	for (int y = 1; y < board_height - 1; ++y) {
		string display = board[board_width * y + 2].display_;
		if (display != " ") {
			if ((display == board[board_width * y + 1].display_) && (display == board[board_width * y + 3].display_)) {
				if (board[board_width * y + 2].display_ == "x") {
					winningplayer = 0;
				}
				else if (board[board_width * y + 2].display_ == "o") {
					winningplayer = 1;
				}
				return true;
			}
		}
	}
	return false;
}


bool TicTacToe::diagonal(vector<game_piece> board, int board_width, int board_height) {
	string center = board[board_width * 2 + 2].display_;
	if (center != " ") {
		if (((center == board[board_width * 3 + 1].display_) && (center == board[board_width * 1 + 3].display_)) || ((center == board[board_width * 1 + 1].display_) && (center == board[board_width * 3 + 3].display_))) {
			if (board[board_width * 2 + 2].display_ == "x") {
				winningplayer = 0;
			}
			else if (board[board_width * 2 + 2].display_ == "o") {
				winningplayer = 1;
			}
			return true;
		}
	}
	return false;
}

bool TicTacToe::draw() {
	if (num_moves == 0 && done() == false) {
		return true;
	}
	return false;
}

int TicTacToe::prompt(unsigned int& x, unsigned int& y) {
	string input;
	cout << "Enter one of the following: A valid coordinate (x,y) to make your move, or quit to stop playing" << endl;
	cin >> input;

	if (input == "quit") {
		return quit;
	}

	comma_to_space(input);
	istringstream iss(input);

	if ((iss >> x) &&  (iss >> y)) {
		if ((1 <= x && x <= 3)  && (1 <= y && y <= 3)) {
			return success;
		}
		cout << "Coordinates out of range. Enter an x coordinate between 1-3 and a y coordinate between 1-3." << endl;
		return bad_coordinates;
	}

	cout << "Could not read input" << endl;
	return bad_coordinates;
}


int TicTacToe::turn() {
	unsigned int x;
	unsigned int y;

	int promptvalue = 1;
	while (promptvalue != success) {
		promptvalue = prompt(x, y);
		if (promptvalue == quit) {
			return quit;
		}
		if (board[board_width * y + x].display_ != " ") {
			cout << "Spot is already taken! Try Again." << endl;
			promptvalue = space_full;
		}
	}

	board[board_width * y + x].display_ = (player) ? "o" : "x";
	board[board_width * y + x].color_ = (player) ? black : red;
	board[board_width * y + x].name_ = (player) ? "player o" : "player x";

	cout << *this << endl;

	string playervalue = (player) ? "o" : "x";
	cout << "Player " << playervalue << ": ";

	for (int x = 1; x <= 3; ++x) {
		for (int y = 1; y <= 3; ++y) {
			if (board[board_width * y + x].display_ == playervalue) {
				cout << x << ", " << y << "; ";
			}
		}
	}
	cout << endl;
	num_moves--;
	player = !player;
	return success;
}

int TicTacToe::play() {
	cout << *this << endl;

	bool done_value = false;
	bool draw_value = false;
	int turn_value = 0;

	while (((done_value = done()) == false) && ((draw_value = draw()) == false) && (num_moves != 0) && ((turn_value = turn())!= quit)) {
		
	}

	if (done_value == true) {
		if (winningplayer == 0) {
			cout << "Player x wins." << endl;
		}
		else if (winningplayer == 1) {
			cout << "Player o wins." << endl;
		}
		
		return success;
	}
	else if (draw_value == true) {
		cout << "Game Over. There is no winner. Number of Moves Played: 9. No winning moves remain." << endl;
		return gameover_draw;

	}
	else if (turn_value == quit) {
		cout << "User Quit. Number of moves remaining: " << num_moves << endl;
		return gameover_quit;
	}

	return success;
}





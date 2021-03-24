#include "GameBoard.h"

//function to check dimensions
int dimensions(ifstream& file, unsigned int& width, unsigned int& height) {
	string local;
	//getline returns true if successful
	if (getline(file, local)) {
		//pass into istringstream
		istringstream iss(local);
		if ((iss >> width) && (iss >> height)) {
			//check dimensions
			return success;
		}
		else {
			return bad_board_dimensions;
		}
	}
	return cannotread;
}

//function to read game pieces
int read_gamepieces(ifstream& file, vector<game_piece>& v, unsigned int width, unsigned int height) {
	string local;
	//check is set to no_well_formed_pieces and is set to board_success if everything is successful, otherwise is not reset and returns no_well_formed_pieces
	int check = no_well_formed_pieces;

	while (getline(file, local)) {
		istringstream iss(local);
		string color;
		string name;
		string display;
		unsigned int row;
		unsigned int column;


		if (iss >> color && iss >> name && iss >> display && iss >> column && iss >> row) {
			piece_color colorz = string_to_piece_color(color);
			//checking with nested if statements because need to pass color through string_to_piece_color
			if ((column <= width && row <= height) && (colorz != invalid)) {
				//reset color, display, and name in the vector
				int index = width * row + column;
				v[index].color_ = colorz;
				v[index].display_ = display;
				v[index].name_ = name;
				check = board_success;
			}
			else {
				//if not true, skips to next iteration
				continue;
			}
		}
		else {
			//if not true, skips to next iteration
			continue;
		}

	}
	return check;
}

//print board function
int print_pieces(const vector<game_piece>& v, unsigned int width, unsigned int height) {
	int size = width * height;
	//check to see if num pieces in vector matches size of board
	if (v.size() == size) {
		for (size_t y = height - 1; y != -1; --y) {
			//iterating in the y direction
			//size_t instead of unsigned int (as in Piazza post)
			for (unsigned int x = 0; x <= width - 1; ++x) {
				//iterating in the x direction
				int index = width * y + x;
				//print the display at the index in the vector
				cout << v[index].display_ << " ";
			}
			cout << endl;
		}
		return success;
	}
	return size_error;
}
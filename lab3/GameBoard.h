#pragma once
#include "CommonFunctions.h"
#include "GamePieces.h"


enum board_result {
	board_success,
	bad_board_dimensions,
	cannotread,
	no_well_formed_pieces,
	size_error
};

int dimensions(ifstream& file, unsigned int& width, unsigned int& height);

int read_gamepieces(ifstream& file, vector<game_piece>& v, unsigned int width, unsigned int height);

int print_pieces(const vector<game_piece>& v, unsigned int width, unsigned int height);
#pragma once
#pragma once
#include "CommonFunctions.h"


enum piece_color {
	invalid = -1,
	nocolor = 0,
	red,
	black,
	white
};

string piece_color_to_lowercase(piece_color color);

piece_color string_to_piece_color(string color);

struct game_piece {
	game_piece(piece_color color, string name, string display);
	piece_color color_;
	string name_;
	string display_;
};

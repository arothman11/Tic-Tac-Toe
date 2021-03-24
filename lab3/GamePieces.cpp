#include "GamePieces.h"

//function to turn piece color to strings
string piece_color_to_lowercase(piece_color color) {
	switch (color) {
	case nocolor:
		return "no color specified";
		break;
	case red:
		return "red";
		break;
	case black:
		return "black";
		break;
	case white:
		return "white";
		break;
	default:
		return "invalid color";
		break;
	}
}

//function that calls lowercase on strings and returns piececolors
piece_color string_to_piece_color(string color) {
	lowercase(color);
	if (color == "red") {
		return red;
	}
	if (color == "black") {
		return black;
	}
	if (color == "white") {
		return white;
	}
	if (color == "nocolor" || color == " ") {
		return nocolor;
	}
	return invalid;
}

game_piece::game_piece(piece_color color, string name, string display)
	: color_(color), name_(name), display_(display) {}
#pragma once
#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <ctype.h>
#include <sstream>
#include <string>
//including everything here and then include CommonFucntions.h in every other header file so it can access

using namespace std;

enum arrayindicies {
	programname,
	input_file,
	num_arguments
};

enum result {
	success,
	file_unopen,
	usage_message_error,
	quit,
	bad_coordinates,
	space_full,
	gameover_draw,
	gameover_quit
};


int usagemessage(string programname, string message);

void lowercase(string& r);

void comma_to_space(string& input);

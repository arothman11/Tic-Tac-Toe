#include "CommonFunctions.h"

//takes in 2 strings and returns the usagemessage error
int usagemessage(string programname, string message) {
    cout << "There is an error" << endl;
    cout << "usage: " << programname << message << endl;
    return usage_message_error;
}

void lowercase(string& r) {
    for (unsigned int i = 0; i < r.size(); ++i) {
        if (r[i] >= 'A' && r[i] <= 'Z') {
            r[i] = r[i] - ('A' - 'a');
            //difference from uppercase to lowercase is the same amongst any letter using A-a but can use any upper and lowercase pair of the same letter
        }
    }
}

void comma_to_space(string& input) {
    for (unsigned int i = 0; i < input.size(); ++i) {
        if (input[i] == ',') {
            input[i] = ' ';
        }
    }
}



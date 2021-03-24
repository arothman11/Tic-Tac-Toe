#pragma once
#include "Tic-Tac-Toe.h"


int main(int argc, char* argv[]){

    if (argc != 1) {
        cout << "Invalid number of arguments." << endl;
        cout << usagemessage(argv[programname], "Enter 1 valid argument.");
    }
    if (argv[input_file] != "TicTacToe") {
        cout << "Incorrect File Name." << endl;
        cout << usagemessage(argv[programname], "Enter TicTacToe.");
    }

    TicTacToe game;
    return game.play();

}


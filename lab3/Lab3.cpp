#pragma once
#include "Tic-Tac-Toe.h"


int main(int argc, char* argv[]){
    string TTT = "TicTacToe";
    //if filename not given
    if (argc != num_arguments) {
        cout << "Invalid number of arguments." << endl;
        usagemessage(argv[programname], "Enter 1 valid argument.");
    }
    //if wrong filename
    if (argv[input_file] != TTT) {
        cout << argv[input_file] << endl;
        cout << "Incorrect File Name." << endl;
        usagemessage(argv[programname], "Enter TicTacToe.");
    }
    //run game
    TicTacToe game;
    return game.play();

}


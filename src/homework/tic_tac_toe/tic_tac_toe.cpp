#include "tic_tac_toe.h"
//cpp

void ticTacToe::startGame(string firstPlayer) {
	if (firstPlayer == O || firstPlayer == X) {
		player = firstPlayer;
	}
	else {
		error += "Player must be X or O.";
	}
}

void ticTacToe::markBoard(int postition) {
	if (position <= 9 && position >= 1 && player != "") {

	}
	else {
		error += "Position must be 1 to 9.";
	}
}

string ticTacToe::getPlayer() const
{
	return string();
}

void ticTacToe::setNextPlayer() {
	if (player == X) {
		player == O;
	}
	else {
		player == X;
	}
}

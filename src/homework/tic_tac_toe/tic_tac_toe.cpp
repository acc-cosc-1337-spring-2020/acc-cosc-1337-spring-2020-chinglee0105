#include "tic_tac_toe.h"
//cpp

void ticTacToe::startGame(string firstPlayer) {
	if (firstPlayer == "O" || firstPlayer == "X") {
		player = firstPlayer;
	}
	else {
		throw error ("Player must be X or O.");
	}
}

void ticTacToe::markBoard(int position) {
	if (position > 9 || position < 1) {
		throw error ("Position must be 1 to 9.");
	}

	if (player == "") {
		throw error ("Must start game first.");
	}

	setNextPlayer();
}

void ticTacToe::setNextPlayer() {
	if (player == "X") {
		player = "O";
	}
	else {
		player = "X";
	}
}
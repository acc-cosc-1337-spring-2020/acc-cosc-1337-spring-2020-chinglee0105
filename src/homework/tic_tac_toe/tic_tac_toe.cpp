#include "tic_tac_toe.h"

using std::cout;
using std::size_t;
//cpp

void ticTacToe::startGame(string firstPlayer) {
	if (!(firstPlayer == "O" || firstPlayer == "X")) {
		throw error("Player must be X or O.");
	}

	player = firstPlayer;

	clearBoard();
}

void ticTacToe::markBoard(int position) {
	if (position > 9 || position < 1) {
		throw error ("Position must be 1 to 9.");
	}

	if (player == "") {
		throw error ("Must start game first.");
	}

	pegs[position - 1] = player;

	setNextPlayer();
}

void ticTacToe::displayBoard() const {
	for (int i = 0; i < 9; i += 3) {
		cout << pegs[i] << "|" << pegs[i + 1] << "|" << pegs[i + 2] << "\n";
	}
}

bool ticTacToe::gameOver() {
	return checkBoardFull();
}

void ticTacToe::setNextPlayer() {
	if (player == "X") {
		player = "O";
	}
	else {
		player = "X";
	}
}

void ticTacToe::clearBoard() {
	for (auto &peg : pegs) {
		peg = " ";
	}
}

bool ticTacToe::checkBoardFull() {
	for (size_t i = 0; i < pegs.size(); ++i) {
		if (pegs[i] == " ") {
			return false;
		}
	}
	return true;
}

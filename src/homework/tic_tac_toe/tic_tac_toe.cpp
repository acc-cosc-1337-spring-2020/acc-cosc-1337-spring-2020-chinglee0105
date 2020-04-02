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



string ticTacToe::getWinner() {
	return winner;
}



bool ticTacToe::gameOver() {
	if (checkColumnWin() == true || checkRowWin() == true || checkDiagonalWin() == true) {
		setWinner();
	}
	else {
		winner = "C";
	}
	return checkBoardFull();
}



bool ticTacToe::checkColumnWin() {
	bool column1 = pegs[0] == pegs[3] && pegs[3] == pegs[6];
	bool column2 = pegs[1] == pegs[4] && pegs[4] == pegs[7];
	bool column3 = pegs[2] == pegs[5] && pegs[5] == pegs[8];

	return column1 || column2 || column3;
}



bool ticTacToe::checkRowWin() {
	bool row1 = pegs[0] == pegs[1] && pegs[1] == pegs[2];
	bool row2 = pegs[3] == pegs[4] && pegs[4] == pegs[5];
	bool row3 = pegs[6] == pegs[7] && pegs[7] == pegs[8];

	return row1 || row2 || row3;
}



bool ticTacToe::checkDiagonalWin() {
	bool diagonal1 = pegs[0] == pegs[4] && pegs[4] == pegs[8];
	bool diagonal2 = pegs[6] == pegs[4] && pegs[4] == pegs[2];

	return diagonal1 || diagonal2;
}



void ticTacToe::setWinner() {
	if (player == "X") {
		winner = "O";
	}
	else {
		winner = "X";
	}
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
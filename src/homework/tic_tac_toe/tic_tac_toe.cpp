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

	if (gameOver() == false) {
		setNextPlayer();
	}
}



void ticTacToe::displayBoard() const {
	for (int i = 0; i < 9; i += 3) {
		cout << pegs[i] << "|" << pegs[i + 1] << "|" << pegs[i + 2] << "\n";
	}
}



string ticTacToe::getWinner() const {
	return winner;
}



bool ticTacToe::gameOver() {
	if (checkColumnWin() == true || checkRowWin() == true || checkDiagonalWin() == true) {
		setWinner();
		return true;
	}
	else if (checkBoardFull() == true) {
		winner = "C";
		return true;
	}
	else {
		return false;
	}
}



bool ticTacToe::checkColumnWin() {
	bool column1 = pegs[0].compare(pegs[3]) == 0 && pegs[3].compare(pegs[6]) == 0 && pegs[6].compare(" ") != 0;
	bool column2 = pegs[1].compare(pegs[4]) == 0 && pegs[4].compare(pegs[7]) == 0 && pegs[7].compare(" ") != 0;
	bool column3 = pegs[2].compare(pegs[5]) == 0 && pegs[5].compare(pegs[8]) == 0 && pegs[8].compare(" ") != 0;

	return column1 || column2 || column3;
}



bool ticTacToe::checkRowWin() {
	bool row1 = pegs[0].compare(pegs[1]) == 0 && pegs[1].compare(pegs[2]) == 0 && pegs[2].compare(" ") != 0;
	bool row2 = pegs[3].compare(pegs[4]) == 0 && pegs[4].compare(pegs[5]) == 0 && pegs[5].compare(" ") != 0;
	bool row3 = pegs[6].compare(pegs[7]) == 0 && pegs[7].compare(pegs[8]) == 0 && pegs[8].compare(" ") != 0;

	return row1 || row2 || row3;
}



bool ticTacToe::checkDiagonalWin() {
	bool diagonal1 = pegs[0].compare(pegs[4]) == 0 && pegs[4].compare(pegs[8]) == 0 && pegs[8].compare(" ") != 0;
	bool diagonal2 = pegs[6].compare(pegs[4]) == 0 && pegs[4].compare(pegs[2]) == 0 && pegs[2].compare(" ") != 0;

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
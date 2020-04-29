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
	if (position > pegs.size() || position < 1) {
		throw error("Position must be 1 to 9.");
	}

	if (player == "") {
		throw error("Must start game first.");
	}

	pegs[position - 1] = player;

	if (gameOver() == false) {
		setNextPlayer();
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



ticTacToe::ticTacToe(vector<string> p, string win)
	: pegs{ p }, winner{ win }  {
}



bool ticTacToe::checkColumnWin() {
	return false;
}



bool ticTacToe::checkRowWin() {
	return false;
}



bool ticTacToe::checkDiagonalWin() {
	return false;
}



void ticTacToe::setWinner() {
	if (player == "X") {
		winner = "X";
	}
	else {
		winner = "O";
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
	for (auto& peg : pegs) {
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



ostream& operator<<(ostream& out, const ticTacToe& t) {

	for (std::size_t i = 0; i < t.pegs.size(); i += sqrt(t.pegs.size()))
	{
		out << t.pegs[i] << "|" << t.pegs[i + 1] << "|" << t.pegs[i + 2];

		if (t.pegs.size() == 16)
		{
			out << "|" << t.pegs[i + 3];
		}

		out << "\n";
	}

	return out;
}



istream& operator>>(istream& in, ticTacToe& t) {

	int position;

	cout << "Enter your position Player " << t.getPlayer() << ": ";
	in >> position;

	t.markBoard(position);

	return in;
}
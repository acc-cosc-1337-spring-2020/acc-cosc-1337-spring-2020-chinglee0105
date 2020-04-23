#include "tic_tac_toe_manager.h"

using std::cout;
using std::move;

//cpp

void ticTacToeManager::saveGame(unique_ptr<ticTacToe>& b) {
	move(games);
	updateWinnerCount(b.getWinner());
	getWinnerTotal(oWin, xWin, ties);
}



void ticTacToeManager::getWinnerTotal(int& o, int& x, int& t) {
	o = oWin;
	x = xWin;
	t = ties;
}



void ticTacToeManager::updateWinnerCount(string winner) {
	if (winner == "X") {
		xWin += 1;
	}
	else if (winner == "O") {
		oWin += 1;
	}
	else {
		ties += 1;
	}
}



ostream& operator<<(ostream& out, const ticTacToeManager& manager) {

	for (auto& game : manager.games) {

		out << game << "\n";
	}

	out << "X Wins: " << manager.xWin << "\n";
	out << "O Wins: " << manager.oWin << "\n";
	out << "Ties: " << manager.ties << "\n";
	out << "\n";

	return out;
}
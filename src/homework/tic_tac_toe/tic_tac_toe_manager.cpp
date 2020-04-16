#include "tic_tac_toe_manager.h"

using std::cout;

//cpp

void ticTacToeManager::saveGame(const ticTacToe b) {
	games.push_back(b);
	updateWinnerCount(b.getWinner());
	getWinnerTotal(oWin, xWin, ties);
}



void ticTacToeManager::getWinnerTotal(int& o, int& x, int& t) {
	cout << "X Wins: " << x << "\n";
	cout << "O Wins: " << o << "\n";
	cout << "Ties: " << t << "\n";
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
	
	int numOfTies = 0;
	int numOfXWins = 0;
	int numOfOWins = 0;
	string allBoards = "";

	for (auto& game : manager.games) {

		out << game << "\n";
		string winner = game.getWinner();

		if (winner == "X") {

			++numOfXWins;
		}

		else if (winner == "O") {
			++numOfOWins;
		}

		else {
			++numOfTies;
		}
		out << "X Wins: " << numOfXWins << "\n";
		out << "O Wins: " << numOfOWins << "\n";
		out << "Ties: " << numOfTies << "\n";
		out << "\n";
	}
	return out;
}

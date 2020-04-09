#include "tic_tac_toe_manager.h"

//cpp

void ticTacToeManager::saveGame(const ticTacToe b) {
	games.push_back(b);
	updateWinnerCount(b.getWinner());
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

		game.displayBoard();
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

	}
	return out;
}

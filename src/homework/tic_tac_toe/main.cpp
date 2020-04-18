#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include<iostream>

using std::cout;
using std::cin;

int main() {

	bool proceed = true;

	string decisionToProceed;
	string player;

	int position;

	vector<reference_wrapper<ticTacToe>> games;

	while (player != "X" && player != "O") {

		try {
			cout << "Welcome to game of Tic Tac Toe!" << "\n";
			cout << "Select your mark (X/O): ";
			cin >> player;
		}

		catch (error e) {
			cout << e.getMessage();
		}
	}

	ticTacToe games = ticTacToe(3);
	ticTacToeManager manager;

	ticTacToe(3).startGame(player);

	while (proceed) {

		for (int i = 0; i < 9; ++i) {

			if (ticTacToe(3).gameOver() == false) {

				try {
					cin >> ticTacToe(3);
					cout << ticTacToe(3);
				}

				catch (error e) {
					cout << e.getMessage() << "\n";
				}
			}

			else {
				break;
			}
		}

		cout << ticTacToe(3).getWinner() << " win the game!" << "\n";
		cout << "\n";

		manager.saveGame(ticTacToe(3));

		cout << "Do you wish to continue? (Y/N): ";
		cin >> decisionToProceed;

		if (decisionToProceed != "y" && decisionToProceed != "Y") {

			proceed = false;
		}

		else {

			ticTacToe(3).startGame(player);
		}
	}

	cout << "\n";

	cout << manager;

	cout << "Game Over.";
}
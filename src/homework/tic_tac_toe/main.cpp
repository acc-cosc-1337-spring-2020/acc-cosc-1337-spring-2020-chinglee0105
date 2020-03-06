#include "tic_tac_toe.h"
#include<iostream>

using std::cout;
using std::cin;

int main() {
	bool proceed = true;
	string decisionToProceed;
	int position;

	cout << "First player is X \n";

	ticTacToe game;

	game.startGame("X");

	while (proceed) {
		for (int i = 0; i < 9; ++i) {
			cout << "Enter your position Player " << game.getPlayer() << ": ";
			cin >> position;

			try {
				game.markBoard(position);
			}

			catch (error e) {
				cout << e.getMessage() << "\n";
			}
		}

		cout << "Do you wish to continue? (Y/N): ";
		cin >> decisionToProceed;

		if (decisionToProceed != "y" && decisionToProceed != "Y") {
			proceed = false;
		}
	}

	cout << "End of program.";
}
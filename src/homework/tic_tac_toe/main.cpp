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

	ticTacToe game;
	ticTacToeManager manager;

	game.startGame(player);

	while (proceed) {

		for (int i = 0; i < 9; ++i) {

			if (game.gameOver() == false) {
					
				try {
					cin >> game;
					cout << game;
				}

				catch (error e) {
					cout << e.getMessage() << "\n";
				}
			}

			else {
				break;
			}
		}

		cout << game.getWinner() << " win the game!" << "\n";
		cout << "\n";

		manager.saveGame(game);

		cout << "Do you wish to continue? (Y/N): ";
		cin >> decisionToProceed;

		if (decisionToProceed != "y" && decisionToProceed != "Y") {

			proceed = false;
		}
		
		else{

			game.startGame(player);
		}
	}

	cout << "\n";

	cout << manager;

	cout << "Game Over.";
}
#include "tic_tac_toe.h"
#include<iostream>

using std::cout;
using std::cin;

int main() {
	bool proceed = true;

	string decisionToProceed;
	string player;

	int position;
	while (player != "X" && player != "O") {
		try
		{
			cout << "Welcome to game of Tic Tac Toe!" << "\n";
			cout << "Select your mark (X/O): ";
			cin >> player;
		}
		catch (error e) 
		{
			cout << e.getMessage();
		}
		
	} 

	ticTacToe game;

	game.startGame(player);

	while (proceed) {
		for (int i = 0; i < 9; ++i) {
			try {
				if (game.gameOver() == false) {
					cout << "Enter your position Player " << game.getPlayer() << ": ";
					cin >> position;
					game.markBoard(position);
					game.displayBoard();
				}
				else {
					cout << game.getWinner() << " win the game!" << "\n";
					break;
				}
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

	cout << "Game Over.";
}
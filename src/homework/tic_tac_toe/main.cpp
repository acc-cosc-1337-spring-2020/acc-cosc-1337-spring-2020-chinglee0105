#include "tic_tac_toe_manager.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include <iostream>
#include <memory>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::unique_ptr;
using std::make_unique;
using std::move;

int main()
{
	unique_ptr<ticTacToeManager> manager = make_unique<ticTacToeManager>();
	string cont;
	unique_ptr<ticTacToe> game;
	do
	{
		int game_type;

		cout << "\nTictactoe 3 or 4?";
		cin >> game_type;

		if (game_type == 3) {
			game = make_unique <ticTacToe3>();
		}
		else if (game_type == 4) {
			game = make_unique <ticTacToe4>();
		}


		string player = "Y";

		while (!(player == "O" || player == "X"))
		{
			try
			{
				cout << "Enter player: ";
				cin >> player;

				game->startGame(player);
			}
			catch (error e)
			{
				cout << e.getMessage();
			}
		}

		int choice = 1;

		do
		{
			try
			{
				cin >> *game;
				cout << *game;
			}
			catch (error e)
			{
				cout << e.getMessage();
			}

		} while (!game->gameOver());

		manager->saveGame(game);

		cout << "\nWinner: " << game->getWinner() << "\n";

		cout << "Enter Y to play again: ";
		cin >> cont;

	} while (cont == "Y");

	cout << *manager;

	return 0;
}
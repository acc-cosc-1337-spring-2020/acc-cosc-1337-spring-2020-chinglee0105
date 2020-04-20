#include "tic_tac_toe_manager.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include<iostream>
#include<functional>

using std::cout; using std::cin; using std::string;

int main()
{
	ticTacToeManager manager;
	string cont;
	std::vector<std::reference_wrapper<ticTacToe>> games;

	do
	{
		int game_type;
		cout << "\nTictactoe 3 or 4?";
		cin >> game_type;
		ticTacToe3 game3;
		ticTacToe4 game4;

		if (game_type == 3)
		{
			games.push_back(game3);
		}
		else if (game_type == 4)
		{
			games.push_back(game4);
		}

		std::reference_wrapper<ticTacToe> game = games.back();

		string player = "Y";

		while (!(player == "O" || player == "X"))
		{
			try
			{
				cout << "Enter player: ";
				cin >> player;

				game.get().startGame(player);
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
				cin >> game.get();
				cout << game.get();
			}
			catch (error e)
			{
				cout << e.getMessage();
			}

		} while (!game.get().gameOver());

		manager.saveGame(game.get());

		cout << "\nWinner: " << game.get().getWinner() << "\n";

		cout << "Enter Y to play again: ";
		cin >> cont;

	} while (cont == "Y");

	cout << manager;

	return 0;
}
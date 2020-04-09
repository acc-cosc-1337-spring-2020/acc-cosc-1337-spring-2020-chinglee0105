#include<string>
#include<iostream>
#include <vector>

using std::vector;
using std::string;

//h
class ticTacToe {
public:
	string getPlayer() const { return player; }

	void startGame(string firstPlayer);
	void markBoard(int postition);
	void displayBoard() const;

	string getWinner() const;

	bool gameOver();


private:
	string player;
	string winner;
	vector<string> pegs{ 9, " " };

	bool checkColumnWin();
	bool checkRowWin();
	bool checkDiagonalWin();

	void setWinner();
	void setNextPlayer();
	void clearBoard();

	bool checkBoardFull();
};

class error {
public:
	error(string msg) : message{ msg } {}
	string getMessage() const { return message; }

private:
	string message;
};
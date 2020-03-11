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

	bool gameOver();


private:
	string player;
	vector<string> pegs{ 9, " " };

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
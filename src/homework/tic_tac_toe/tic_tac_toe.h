#include<string>

using std::string;

//h
class ticTacToe {
public:
	void startGame(string firstPlayer);
	void markBoard(int postition);
	string getPlayer() const { return player; }

private:
	string player;

	void setNextPlayer();
};

class error {
public:
	error(string msg) : message{ msg } {}
	string getMessage() const { return message; }

private:
	string message;
};
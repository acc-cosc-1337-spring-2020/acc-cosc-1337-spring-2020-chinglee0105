#include<string>

using std::string;

//h
class ticTacToe {
public:
	string getMessage;

	void startGame(string firstPlayer);
	void markBoard(int postition);
	string getPlayer()const;

private:
	string message;
	string player;

	void setNextPlayer();
};

class error {
	error(string msg) : message{ msg } {}
};
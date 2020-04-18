#ifndef TIC_TAC_TOE
#define TIC_TAC_TOE

#include <string>
#include <iostream>
#include <vector>

using std::vector;
using std::string;
using std::ostream;
using std::istream;

//h
class ticTacToe {

	public:
		string getPlayer() const { return player; }
		string getWinner() const;

		void startGame(string firstPlayer);
		void markBoard(int postition);

		bool gameOver();

		friend ostream& operator<<(ostream& out, const ticTacToe& t);
		friend istream& operator>>(istream& in, ticTacToe& t);

		ticTacToe( int size ):pegs(size*size, ""){}

	protected:
		vector<string> pegs{ 9, " " };

		virtual bool checkColumnWin();
		virtual bool checkRowWin();
		virtual bool checkDiagonalWin();

	private:
		string player;
		string winner;

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

#endif
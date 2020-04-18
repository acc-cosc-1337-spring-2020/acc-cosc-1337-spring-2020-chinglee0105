#ifndef TIC_TAC_TOE_4
#define TIC_TAC_TOE_4

#include "tic_tac_toe.h"
#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::ostream;

//h
class ticTacToe4 : public ticTacToe {

	public:
		ticTacToe4() = default;

		explicit ticTacToe4(int size) : ticTacToe(size) {}

	private:
		bool checkColumnWin();
		bool checkRowWin();
		bool checkDiagonalWin();
};
#endif
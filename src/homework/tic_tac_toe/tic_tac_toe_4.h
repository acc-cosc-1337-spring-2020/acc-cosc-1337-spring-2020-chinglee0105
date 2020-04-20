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
		

		ticTacToe4() : ticTacToe(4) {}

	private:
		bool checkColumnWin();
		bool checkRowWin();
		bool checkDiagonalWin();
};
#endif
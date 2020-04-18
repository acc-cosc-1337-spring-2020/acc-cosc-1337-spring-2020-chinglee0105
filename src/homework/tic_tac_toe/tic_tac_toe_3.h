#ifndef TIC_TAC_TOE_3
#define TIC_TAC_TOE_3

#include "tic_tac_toe.h"
#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::ostream;

//h
class ticTacToe3 : public ticTacToe {

	public:
		ticTacToe3() = default;

		explicit ticTacToe3(int size) : ticTacToe(size) {}

	private:
		bool checkColumnWin();
		bool checkRowWin();
		bool checkDiagonalWin();
};
#endif
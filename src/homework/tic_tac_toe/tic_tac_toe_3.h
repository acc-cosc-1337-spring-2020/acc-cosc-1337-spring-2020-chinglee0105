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
class ticTacToe3 {

public:

	bool checkColumnWin3();
	bool checkRowWin3();
	bool checkDiagonalWin3();

private:

};
#endif
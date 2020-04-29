//h
#ifndef TIC_TAC_TOE_DATA
#define TIC_TAC_TOE_DATA

#include "tic_tac_toe.h"
#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::ostream;

//h
class ticTacToeDATA : public ticTacToe {

	public:
		void savePegs(const vector<string>& pgs);

	private:

};
#endif
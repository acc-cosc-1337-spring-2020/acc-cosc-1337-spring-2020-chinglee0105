//h
#ifndef TIC_TAC_TOE_DATA
#define TIC_TAC_TOE_DATA

#include "tic_tac_toe.h"
#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::unique_ptr;

//h
class ticTacToeData : public ticTacToe {

	public:
		void saveGames(const vector<unique_ptr<ticTacToe>>& games);
		vector<unique_ptr<ticTacToe>> getGames();

	private:

};
#endif
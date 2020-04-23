#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H

#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include <vector>
#include <string>
#include <iostream>
#include <memory>

using std::vector;
using std::string;
using std::ostream;
using std::unique_ptr;

//h
class ticTacToeManager {

	public:
		void saveGame(unique_ptr<ticTacToe>& b);
		void getWinnerTotal(int& o, int& x, int& t);

		friend ostream& operator << (ostream& out, const ticTacToeManager& manager);

	private:
		vector<unique_ptr<ticTacToe>> games;

		int xWin = 0;
		int oWin = 0;
		int ties = 0;

		void updateWinnerCount(string winner);
};
#endif
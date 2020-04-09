#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H

#include "tic_tac_toe.h"
#include <vector>
#include <string>
#include<iostream>

using std::vector;
using std::string;
using std::ostream;

//h
class ticTacToeManager {
public:
	void saveGame(const ticTacToe b);

	friend ostream& operator << (ostream& out, const ticTacToeManager& manager);

private:
	vector<ticTacToe> games;
	int xWin;
	int oWin;
	int ties;

	void updateWinnerCount(string winner);
};
#endif
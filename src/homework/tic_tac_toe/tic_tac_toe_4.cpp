#include "tic_tac_toe_4.h"

/*
class function check_column_win
Win by column if and return true if (each column index)
0, 1,  2,  3 
4, 5,  6,  7 
8, 9, 10, 11 
12,13,14, 15 
else
false
*/
bool ticTacToe4::checkColumnWin4() {
	bool column1 = pegs[0].compare(pegs[3]) == 0 && pegs[3].compare(pegs[6]) == 0 && pegs[6].compare(" ") != 0;
	bool column2 = pegs[1].compare(pegs[4]) == 0 && pegs[4].compare(pegs[7]) == 0 && pegs[7].compare(" ") != 0;
	bool column3 = pegs[2].compare(pegs[5]) == 0 && pegs[5].compare(pegs[8]) == 0 && pegs[8].compare(" ") != 0;

	return column1 || column2 || column3;
}



/*
class function check_row_win
Win by row if
0, 1,  2,  3 are equal
4, 5,  6,  7 are equal
8, 9, 10, 11 are equal 
12,13,14, 15 are equal
*/
bool ticTacToe4::checkRowWin4() {
	bool row1 = pegs[0].compare(pegs[1]) == 0 && pegs[1].compare(pegs[2]) == 0 && pegs[2].compare(" ") != 0;
	bool row2 = pegs[3].compare(pegs[4]) == 0 && pegs[4].compare(pegs[5]) == 0 && pegs[5].compare(" ") != 0;
	bool row3 = pegs[6].compare(pegs[7]) == 0 && pegs[7].compare(pegs[8]) == 0 && pegs[8].compare(" ") != 0;

	return row1 || row2 || row3;
}



/*
class function check_diagonal_win
Win diagonally
0, 1,  2,  3
4, 5,  6,  7
8, 9, 10, 11
12,13,14, 15

*/
bool ticTacToe4::checkDiagonalWin4() {
	bool diagonal1 = pegs[0].compare(pegs[4]) == 0 && pegs[4].compare(pegs[8]) == 0 && pegs[8].compare(" ") != 0;
	bool diagonal2 = pegs[6].compare(pegs[4]) == 0 && pegs[4].compare(pegs[2]) == 0 && pegs[2].compare(" ") != 0;

	return diagonal1 || diagonal2;
}
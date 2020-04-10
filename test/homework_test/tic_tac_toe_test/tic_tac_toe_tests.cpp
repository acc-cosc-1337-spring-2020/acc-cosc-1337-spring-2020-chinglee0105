#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}



TEST_CASE("Test can’t call mark board before start game") {
	ticTacToe game;
	REQUIRE_THROWS_AS(game.markBoard(1), error);
}



TEST_CASE("Test start game accepts only X or O") {
	ticTacToe game;
	REQUIRE_THROWS_AS(game.startGame("Y"), error);
}



TEST_CASE("Test set first player to X") {
	ticTacToe game;
	game.startGame("X");
	REQUIRE(game.getPlayer() == "X");
}



TEST_CASE("Test set first player to O") {
	ticTacToe game;
	game.startGame("O");
	REQUIRE(game.getPlayer() == "O");
}



TEST_CASE("Test start game with X game flow") {
	ticTacToe game;
	game.startGame("X");
	REQUIRE(game.getPlayer() == "X");

	game.markBoard(4);
	REQUIRE(game.getPlayer() == "O");
}



TEST_CASE("Test start game with O game flow") {
	ticTacToe game;
	game.startGame("O");
	REQUIRE(game.getPlayer() == "O");

	game.markBoard(2);
	REQUIRE(game.getPlayer() == "X");
}



TEST_CASE("Test game ends when board is full") {
	ticTacToe game;
	game.startGame("X");

	for (int i = 1; i < 7; ++i) {
		game.markBoard(i);
		REQUIRE(game.gameOver() == false);
	}
	
	game.markBoard(9);
	game.markBoard(7);
	game.markBoard(8);
	REQUIRE(game.gameOver() == true);
}



TEST_CASE("Test Mark Position accepts values from 1 to 9 only") {
	ticTacToe game;
	game.startGame("X");

	REQUIRE_THROWS_AS(game.markBoard(0), error);
	REQUIRE_THROWS_AS(game.markBoard(10), error);

	game.markBoard(5);
}



TEST_CASE("Test game over if 9 slots are selected") {
	ticTacToe game;
	game.startGame("X");

	game.markBoard(1);
	game.markBoard(2);
	game.markBoard(3);
	game.markBoard(4);
	game.markBoard(5);
	game.markBoard(6);
	game.markBoard(7);
	game.markBoard(8);
	game.markBoard(9);

	REQUIRE(game.gameOver() == true);
}



TEST_CASE("Test win by first column") {
	ticTacToe game;
	game.startGame("X");

	REQUIRE(game.gameOver() == false);
	game.markBoard(1);

	REQUIRE(game.gameOver() == false);
	game.markBoard(2);

	REQUIRE(game.gameOver() == false);
	game.markBoard(4);

	REQUIRE(game.gameOver() == false);
	game.markBoard(5);

	REQUIRE(game.gameOver() == false);
	game.markBoard(7);

	REQUIRE(game.gameOver() == true);

	REQUIRE(game.getWinner() == "X");
}



TEST_CASE("Test win by second column") {
	ticTacToe game;
	game.startGame("X");

	REQUIRE(game.gameOver() == false);
	game.markBoard(2);

	REQUIRE(game.gameOver() == false);
	game.markBoard(1);

	REQUIRE(game.gameOver() == false);
	game.markBoard(5);

	REQUIRE(game.gameOver() == false);
	game.markBoard(3);

	REQUIRE(game.gameOver() == false);
	game.markBoard(8);

	REQUIRE(game.gameOver() == true);

	REQUIRE(game.getWinner() == "X");
}



TEST_CASE("Test win by third column") {
	ticTacToe game;
	game.startGame("X");

	REQUIRE(game.gameOver() == false);
	game.markBoard(3);

	REQUIRE(game.gameOver() == false);
	game.markBoard(1);

	REQUIRE(game.gameOver() == false);
	game.markBoard(6);

	REQUIRE(game.gameOver() == false);
	game.markBoard(2);

	REQUIRE(game.gameOver() == false);
	game.markBoard(9);

	REQUIRE(game.gameOver() == true);

	REQUIRE(game.getWinner() == "X");
}



TEST_CASE("Test win by first row") {
	ticTacToe game;
	game.startGame("X");

	REQUIRE(game.gameOver() == false);
	game.markBoard(1);

	REQUIRE(game.gameOver() == false);
	game.markBoard(4);

	REQUIRE(game.gameOver() == false);
	game.markBoard(2);

	REQUIRE(game.gameOver() == false);
	game.markBoard(5);

	REQUIRE(game.gameOver() == false);
	game.markBoard(3);

	REQUIRE(game.gameOver() == true);

	REQUIRE(game.getWinner() == "X");
}



TEST_CASE("Test win by second row") {
	ticTacToe game;
	game.startGame("X");

	REQUIRE(game.gameOver() == false);
	game.markBoard(4);

	REQUIRE(game.gameOver() == false);
	game.markBoard(1);

	REQUIRE(game.gameOver() == false);
	game.markBoard(5);

	REQUIRE(game.gameOver() == false);
	game.markBoard(2);

	REQUIRE(game.gameOver() == false);
	game.markBoard(6);

	REQUIRE(game.gameOver() == true);

	REQUIRE(game.getWinner() == "X");
}



TEST_CASE("Test win by third row") {
	ticTacToe game;
	game.startGame("X");

	REQUIRE(game.gameOver() == false);
	game.markBoard(7);

	REQUIRE(game.gameOver() == false);
	game.markBoard(2);

	REQUIRE(game.gameOver() == false);
	game.markBoard(8);

	REQUIRE(game.gameOver() == false);
	game.markBoard(5);

	REQUIRE(game.gameOver() == false);
	game.markBoard(9);

	REQUIRE(game.gameOver() == true);

	REQUIRE(game.getWinner() == "X");
}



TEST_CASE("Test win by diagonally from top left") {
	ticTacToe game;
	game.startGame("X");

	REQUIRE(game.gameOver() == false);
	game.markBoard(1);

	REQUIRE(game.gameOver() == false);
	game.markBoard(2);

	REQUIRE(game.gameOver() == false);
	game.markBoard(5);

	REQUIRE(game.gameOver() == false);
	game.markBoard(4);

	REQUIRE(game.gameOver() == false);
	game.markBoard(9);

	REQUIRE(game.gameOver() == true);

	REQUIRE(game.getWinner() == "X");
}



TEST_CASE("Test win by diagonally from bottom left") {
	ticTacToe game;
	game.startGame("X");

	REQUIRE(game.gameOver() == false);
	game.markBoard(7);

	REQUIRE(game.gameOver() == false);
	game.markBoard(2);

	REQUIRE(game.gameOver() == false);
	game.markBoard(5);

	REQUIRE(game.gameOver() == false);
	game.markBoard(4);

	REQUIRE(game.gameOver() == false);
	game.markBoard(3);

	REQUIRE(game.gameOver() == true);

	REQUIRE(game.getWinner() == "X");
}



TEST_CASE("Test for no winner") {
	ticTacToe game;
	game.startGame("X");

	REQUIRE(game.gameOver() == false);
	game.markBoard(1);

	REQUIRE(game.gameOver() == false);
	game.markBoard(2);

	REQUIRE(game.gameOver() == false);
	game.markBoard(3);

	REQUIRE(game.gameOver() == false);
	game.markBoard(4);

	REQUIRE(game.gameOver() == false);
	game.markBoard(6);

	REQUIRE(game.gameOver() == false);
	game.markBoard(5);

	REQUIRE(game.gameOver() == false);
	game.markBoard(7);

	REQUIRE(game.gameOver() == false);
	game.markBoard(9);

	REQUIRE(game.gameOver() == false);
	game.markBoard(8);

	REQUIRE(game.gameOver() == true);
}
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test can’t call mark board before start game (SEE EXAMPLE BELOW)") {
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

	for (int i = 1; i < 9; ++i) {
		game.markBoard(i);
		REQUIRE(game.gameOver() == false);
	}

	game.markBoard(9);
	REQUIRE(game.gameOver() == true);
}
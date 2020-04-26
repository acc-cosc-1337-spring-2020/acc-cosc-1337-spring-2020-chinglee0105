#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_manager.h"

using std::make_unique;

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}



TEST_CASE("Test can’t call mark board before start game") {
	unique_ptr<ticTacToe> game = make_unique <ticTacToe3>();
	REQUIRE_THROWS_AS(game->markBoard(1), error);
}



TEST_CASE("Test start game accepts only X or O") {
	unique_ptr<ticTacToe> game = make_unique <ticTacToe3>();
	REQUIRE_THROWS_AS(game->startGame("Y"), error);
}



TEST_CASE("Test set first player to X") {
	unique_ptr<ticTacToe> game = make_unique <ticTacToe3>();
	game->startGame("X");
	REQUIRE(game->getPlayer() == "X");
}



TEST_CASE("Test set first player to O") {
	unique_ptr<ticTacToe> game = make_unique <ticTacToe3>();
	game->startGame("O");
	REQUIRE(game->getPlayer() == "O");
}



TEST_CASE("Test start game with X game flow") {
	unique_ptr<ticTacToe> game = make_unique <ticTacToe3>();
	game->startGame("X");
	REQUIRE(game->getPlayer() == "X");

	game->markBoard(2);
	REQUIRE(game->getPlayer() == "O");
}



TEST_CASE("Test start game with O game flow") {
	unique_ptr<ticTacToe> game = make_unique <ticTacToe3>();
	game->startGame("O");
	REQUIRE(game->getPlayer() == "O");

	game->markBoard(2);
	REQUIRE(game->getPlayer() == "X");
}



TEST_CASE("Test game ends when board is full") {
	unique_ptr<ticTacToe> game = make_unique <ticTacToe3>();
	game->startGame("X");

	for (int i = 1; i < 7; ++i) {
		game->markBoard(i);
		REQUIRE(game->gameOver() == false);
	}
	
	game->markBoard(9);
	game->markBoard(7);
	game->markBoard(8);
	REQUIRE(game->gameOver() == true);
}



TEST_CASE("Test Mark Position accepts values from 1 to 9 only") {
	unique_ptr<ticTacToe> game = make_unique <ticTacToe3>();
	game->startGame("X");

	REQUIRE_THROWS_AS(game->markBoard(0), error);
	REQUIRE_THROWS_AS(game->markBoard(10), error);

	game->markBoard(5);
}



TEST_CASE("Test game over if 9 slots are selected") {
	unique_ptr<ticTacToe> game = make_unique <ticTacToe3>();
	game->startGame("X");

	game->markBoard(1);
	game->markBoard(2);
	game->markBoard(3);
	game->markBoard(4);
	game->markBoard(5);
	game->markBoard(6);
	game->markBoard(7);
	game->markBoard(8);
	game->markBoard(9);

	REQUIRE(game->gameOver() == true);
}



TEST_CASE("Test win by first column") {
	unique_ptr<ticTacToe> game = make_unique <ticTacToe3>();
	game->startGame("X");

	REQUIRE(game->gameOver() == false);
	game->markBoard(1);

	REQUIRE(game->gameOver() == false);
	game->markBoard(2);

	REQUIRE(game->gameOver() == false);
	game->markBoard(4);

	REQUIRE(game->gameOver() == false);
	game->markBoard(5);

	REQUIRE(game->gameOver() == false);
	game->markBoard(7);

	REQUIRE(game->gameOver() == true);

	REQUIRE(game->getWinner() == "X");
}



TEST_CASE("Test win by second column") {
	unique_ptr<ticTacToe> game = make_unique <ticTacToe3>();
	game->startGame("X");

	REQUIRE(game->gameOver() == false);
	game->markBoard(2);

	REQUIRE(game->gameOver() == false);
	game->markBoard(1);

	REQUIRE(game->gameOver() == false);
	game->markBoard(5);

	REQUIRE(game->gameOver() == false);
	game->markBoard(3);

	REQUIRE(game->gameOver() == false);
	game->markBoard(8);

	REQUIRE(game->gameOver() == true);

	REQUIRE(game->getWinner() == "X");
}



TEST_CASE("Test win by third column") {
	unique_ptr<ticTacToe> game = make_unique <ticTacToe3>();
	game->startGame("X");

	REQUIRE(game->gameOver() == false);
	game->markBoard(3);

	REQUIRE(game->gameOver() == false);
	game->markBoard(1);

	REQUIRE(game->gameOver() == false);
	game->markBoard(6);

	REQUIRE(game->gameOver() == false);
	game->markBoard(2);

	REQUIRE(game->gameOver() == false);
	game->markBoard(9);

	REQUIRE(game->gameOver() == true);

	REQUIRE(game->getWinner() == "X");
}



TEST_CASE("Test win by first row") {
	unique_ptr<ticTacToe> game = make_unique <ticTacToe3>();
	game->startGame("X");

	REQUIRE(game->gameOver() == false);
	game->markBoard(1);

	REQUIRE(game->gameOver() == false);
	game->markBoard(4);

	REQUIRE(game->gameOver() == false);
	game->markBoard(2);

	REQUIRE(game->gameOver() == false);
	game->markBoard(5);

	REQUIRE(game->gameOver() == false);
	game->markBoard(3);

	REQUIRE(game->gameOver() == true);

	REQUIRE(game->getWinner() == "X");
}



TEST_CASE("Test win by second row") {
	unique_ptr<ticTacToe> game = make_unique <ticTacToe3>();
	game->startGame("X");

	REQUIRE(game->gameOver() == false);
	game->markBoard(4);

	REQUIRE(game->gameOver() == false);
	game->markBoard(1);

	REQUIRE(game->gameOver() == false);
	game->markBoard(5);

	REQUIRE(game->gameOver() == false);
	game->markBoard(2);

	REQUIRE(game->gameOver() == false);
	game->markBoard(6);

	REQUIRE(game->gameOver() == true);

	REQUIRE(game->getWinner() == "X");
}



TEST_CASE("Test win by third row") {
	unique_ptr<ticTacToe> game = make_unique <ticTacToe3>();
	game->startGame("X");

	REQUIRE(game->gameOver() == false);
	game->markBoard(7);

	REQUIRE(game->gameOver() == false);
	game->markBoard(2);

	REQUIRE(game->gameOver() == false);
	game->markBoard(8);

	REQUIRE(game->gameOver() == false);
	game->markBoard(5);

	REQUIRE(game->gameOver() == false);
	game->markBoard(9);

	REQUIRE(game->gameOver() == true);

	REQUIRE(game->getWinner() == "X");
}



TEST_CASE("Test win by diagonally from top left") {
	unique_ptr<ticTacToe> game = make_unique <ticTacToe3>();
	game->startGame("X");

	REQUIRE(game->gameOver() == false);
	game->markBoard(1);

	REQUIRE(game->gameOver() == false);
	game->markBoard(2);

	REQUIRE(game->gameOver() == false);
	game->markBoard(5);

	REQUIRE(game->gameOver() == false);
	game->markBoard(4);

	REQUIRE(game->gameOver() == false);
	game->markBoard(9);

	REQUIRE(game->gameOver() == true);

	REQUIRE(game->getWinner() == "X");
}



TEST_CASE("Test win by diagonally from bottom left") {
	unique_ptr<ticTacToe> game = make_unique <ticTacToe3>();
	game->startGame("X");

	REQUIRE(game->gameOver() == false);
	game->markBoard(7);

	REQUIRE(game->gameOver() == false);
	game->markBoard(2);

	REQUIRE(game->gameOver() == false);
	game->markBoard(5);

	REQUIRE(game->gameOver() == false);
	game->markBoard(4);

	REQUIRE(game->gameOver() == false);
	game->markBoard(3);

	REQUIRE(game->gameOver() == true);

	REQUIRE(game->getWinner() == "X");
}



TEST_CASE("Test for no winner") {
	unique_ptr<ticTacToe> game = make_unique <ticTacToe3>();
	game->startGame("X");

	REQUIRE(game->gameOver() == false);
	game->markBoard(1);

	REQUIRE(game->gameOver() == false);
	game->markBoard(2);

	REQUIRE(game->gameOver() == false);
	game->markBoard(3);

	REQUIRE(game->gameOver() == false);
	game->markBoard(4);

	REQUIRE(game->gameOver() == false);
	game->markBoard(6);

	REQUIRE(game->gameOver() == false);
	game->markBoard(5);

	REQUIRE(game->gameOver() == false);
	game->markBoard(7);

	REQUIRE(game->gameOver() == false);
	game->markBoard(9);
	
	REQUIRE(game->gameOver() == false);
	game->markBoard(8);

	REQUIRE(game->gameOver() == true);
}


TEST_CASE("Win by first column4") {
	std::unique_ptr<ticTacToe> game4 = std::make_unique<ticTacToe4>();
	game4->startGame("X");
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(1);//X        
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(2);//O          
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(5);//X          
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(6);//O          
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(9);//X
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(16);//O          
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(13);//X
	//X wins
	REQUIRE(game4->gameOver() == true);
	REQUIRE(game4->getWinner() == "X");
}

TEST_CASE("Win by second column4") {
	std::unique_ptr<ticTacToe> game4 = std::make_unique<ticTacToe4>();
	game4->startGame("X");
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(2);//X        
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(1);//O          
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(6);//X          
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(4);//O          
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(10);//X
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(7);//O          
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(14);//X
	//X wins
	REQUIRE(game4->gameOver() == true);
}

TEST_CASE("Win by third column4") {
	std::unique_ptr<ticTacToe> game4 = std::make_unique<ticTacToe4>();
	game4->startGame("X");
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(3);//X        
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(1);//O          
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(7);//X          
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(2);//O          
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(11);//X
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(16);//O          
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(15);//X
	//X wins
	REQUIRE(game4->gameOver() == true);
}
TEST_CASE("Win by fourth column4") {
	std::unique_ptr<ticTacToe> game4 = std::make_unique<ticTacToe4>();
	game4->startGame("X");
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(4);//X        
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(1);//O          
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(8);//X          
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(2);//O          
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(12);//X
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(15);//O          
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(16);//X
	//X wins
	REQUIRE(game4->gameOver() == true);
}

TEST_CASE("Win by first row4") {
	std::unique_ptr<ticTacToe> game4 = std::make_unique<ticTacToe4>();
	game4->startGame("X");
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(1);//X        
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(7);//O          
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(2);//X          
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(7);//O          
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(3);//X
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(9);//O          
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(4);//X
	//X wins
	REQUIRE(game4->gameOver() == true);
}

TEST_CASE("Win by second row4") {
	std::unique_ptr<ticTacToe> game4 = std::make_unique<ticTacToe4>();
	game4->startGame("X");
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(5);//X        
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(1);//O          
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(6);//X          
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(9);//O          
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(7);//X
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(10);//O          
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(8);//X
	//X wins
	REQUIRE(game4->gameOver() == true);
}

TEST_CASE("Win by third row4") {
	std::unique_ptr<ticTacToe> game4 = std::make_unique<ticTacToe4>();
	game4->startGame("X");
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(9);//X        
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(1);//O          
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(10);//X          
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(2);//O          
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(11);//X
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(3);//O          
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(12);//X
	//X wins
	REQUIRE(game4->gameOver() == true);
}
TEST_CASE("Win by fourth row4") {
	std::unique_ptr<ticTacToe> game4 = std::make_unique<ticTacToe4>();
	game4->startGame("X");
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(13);//X        
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(1);//O          
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(14);//X          
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(2);//O          
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(15);//X
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(3);//O          
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(16);//X
	//X wins
	REQUIRE(game4->gameOver() == true);
}

TEST_CASE("Win by diagonally top left4") {
	std::unique_ptr<ticTacToe> game4 = std::make_unique<ticTacToe4>();
	game4->startGame("X");
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(1);//X        
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(4);//O          
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(6);//X          
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(2);//O          
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(11);//X
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(3);//O          
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(16);//X
	//X wins
	REQUIRE(game4->gameOver() == true);
}

TEST_CASE("Win by diagonally bottom left4") {
	std::unique_ptr<ticTacToe> game4 = std::make_unique<ticTacToe4>();
	game4->startGame("X");
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(4);//X        
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(1);//O          
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(7);//X          
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(2);//O          
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(10);//X
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(3);//O          
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(13);//X
	//X wins
	REQUIRE(game4->gameOver() == true);
}

TEST_CASE("For no Winner4") {
	std::unique_ptr<ticTacToe> game4 = std::make_unique<ticTacToe4>();
	game4->startGame("X");
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(1);//X        
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(2);//O          
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(3);//X          
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(4);//O          
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(6);//X
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(5);//O        
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(8);//X          
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(7);//O          
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(10);//X          
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(9);//O          
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(12);//X          
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(11);//O          
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(13);//X          
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(14);//O          
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(15);//X          
	REQUIRE(game4->gameOver() == false);
	game4->markBoard(16);//O          
	REQUIRE(game4->gameOver() == true);
}




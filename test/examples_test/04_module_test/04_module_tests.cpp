#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "bank_account.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test bankAccount constructor") {
	bankAccount account(500);

	REQUIRE(account.get_balance() == 500);
}

TEST_CASE("Test bankAccount deposit") {
	bankAccount account(500);

	REQUIRE(account.get_balance() == 500);

	account.deposit(50);
	REQUIRE(account.get_balance() == 550);

	REQUIRE_THROWS_AS(account.deposit(-50), invalid);
	REQUIRE(account.get_balance() == 550);
}

TEST_CASE("Test bankAccount withdraw") {
	bankAccount account(500);

	account.withdraw(50);
	REQUIRE(account.get_balance() == 450);

	REQUIRE_THROWS_AS(account.withdraw(-1), invalid);
	REQUIRE(account.get_balance() == 450);

	REQUIRE_THROWS_AS(account.withdraw(451), invalid);
	REQUIRE(account.get_balance() == 450);
}

TEST_CASE("Test bankAccount default constuctor balance 0") {
	bankAccount account;
	REQUIRE(account.get_balance() == 0);
}

TEST_CASE("Test bankAccount initial open deposit >= 25") {
	bankAccount account;
	REQUIRE(account.get_balance() == 0);

	account.open(25);
	REQUIRE(account.get_balance() == 25);
}

TEST_CASE("Test bankAccount initial open deposit < 25") {
	bankAccount account;
	REQUIRE(account.get_balance() == 0);

	REQUIRE_THROWS_AS(account.open(24), invalid);
}

TEST_CASE("Test bankAccount static rate initialization") {
	bankAccount account;

	REQUIRE(account.get_rate() == 0.025);
}
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
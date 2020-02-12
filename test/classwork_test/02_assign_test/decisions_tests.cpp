#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "decision.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test gross_pay function") {
	REQUIRE(gross_pay(40, 7) == 280);
	REQUIRE(gross_pay(50, 7) == 385);
}


#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "loops.h"
#include "rectangle.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test calculateArea") {
	rectangle r (4, 5);
	REQUIRE(r.functionAreas() == 20);

	rectangle r(10, 10);
	REQUIRE(r.functionAreas() == 100);

	rectangle r(100, 10);
	REQUIRE(r.functionAreas() == 1000);
}
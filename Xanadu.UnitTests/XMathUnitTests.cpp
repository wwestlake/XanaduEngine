
#include "stdafx.h"

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "Vector3d.h"

TEST_CASE("Vector3d is created", "[Vector3d") {

	Xanadu::XMath::Vector3d v3da(1, 2, 3);
	Xanadu::XMath::Vector3d v3db(1, 2, 3);

	SECTION("Vector3d created properly ") {
		REQUIRE(v3da.X() == 1);
		REQUIRE(v3da.Y() == 2);
		REQUIRE(v3da.Z() == 3);
		REQUIRE(v3db.X() == 1);
		REQUIRE(v3db.Y() == 2);
		REQUIRE(v3db.Z() == 3);
	}

	SECTION("Vector3d addition") {
		Xanadu::XMath::Vector3d result = v3da + v3db;
		REQUIRE(result.X() == 2);
		REQUIRE(result.Y() == 4);
		REQUIRE(result.Z() == 6);
	}


}


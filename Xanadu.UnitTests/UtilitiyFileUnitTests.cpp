
#include "catch.hpp"
#include "XanaduUtilities.h"


TEST_CASE("File opens and reads a file", "[Xanadu::Utilities::File]") {

	Xanadu::Utilities::TextFile file("test.txt");

	REQUIRE(file.GetContents().length() == 35);
	REQUIRE(file.GetFileSize() == 38);
}
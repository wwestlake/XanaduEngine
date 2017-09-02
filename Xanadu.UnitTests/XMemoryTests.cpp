#include "catch.hpp"
#include "Xanadu.Engine/XMemory.h"

using namespace Xanadu::Engine;

TEST_CASE("XMemory allocates pages", "[Xanadu::Engine::XMemory]") {

	XMemory mem(1024 * 1024, 1024);

	REQUIRE(mem.GetAvailableMemory() == 1024 * 1024 * 1024);


}
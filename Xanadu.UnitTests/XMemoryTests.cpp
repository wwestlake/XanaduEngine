#include "catch.hpp"
#include "Xanadu.Engine/XAllocator.h"
#include <vector>

using namespace Xanadu::Engine;

class Test {
public:
	int test(int x) {
		return x;
	}

};

#define PROGRESS 100

TEST_CASE("XAllocator allocates memory", "[Xanadu::Engine::XXAllocator]") {

	// allocate just enough memory for 10,000 Test objects
	std::cout << "Test initializing" << std::endl;
	auto alloc = XAllocator((sizeof(Test) + 8) * 10000, 1);
	std::vector<Test*> tests;
	// allocate 10,000 test objects
	std::cout << "Allocate objects" << std::endl;

	for (int i = 0; i < 10000; i++) {
		tests.push_back(alloc.Allocate<Test>());
		if ((i % PROGRESS) == 0) {
			std::cout << "."; cout.flush();
		}
	}
	std::cout << std::endl;
	SECTION("Allocate and run object") {
		std::cout << "Run objects" << std::endl;

		// call a method on each object
		int i = 0;
		for (auto iter = tests.begin(); iter != tests.end(); ++iter) {
			REQUIRE((*iter)->test(i) == i);
			i++;
			if ((i % PROGRESS) == 0) {
				std::cout << "."; cout.flush();
			}
		}
	}
	std::cout << std::endl;

	SECTION("Deallocate and reallocate, then run objects") {
		// deallocate 10,000 test objects
		std::cout << "Deallocate objects" << std::endl;
		for (int i = 0; i < 10000; i++) {
			alloc.Dealocate(tests[i]);
			if ((i % PROGRESS) == 0) {
				std::cout << "."; cout.flush();
			}
		}
		std::cout << std::endl;

		tests.clear();

		std::cout << "Reallocate objects" << std::endl;
		// allocate 10,000 test objects
		for (int i = 0; i < 10000; i++) {
			tests.push_back(alloc.Allocate<Test>());
			if ((i % PROGRESS) == 0) {
				std::cout << "."; cout.flush();
			}
		}
		std::cout << std::endl;

		// call a method on each object
		std::cout << "Run objects" << std::endl;
		int i = 0;
		for (auto iter = tests.begin(); iter != tests.end(); ++iter) {
			REQUIRE((*iter)->test(i) == i);
			i++;
			if ((i % PROGRESS) == 0) {
				std::cout << "."; cout.flush();
			}
		}
		std::cout << std::endl;

	}

}



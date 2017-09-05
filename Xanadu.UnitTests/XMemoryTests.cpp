#include "catch.hpp"
#include "Xanadu.Engine/XAllocator.h"
#include <vector>

using namespace Xanadu::Engine;

class Test {
public:

	size_t test() {
		return _i;
	}

	void set(size_t i) {
		_i = i;
	}

private:
	size_t _i;
	size_t block[20];
};

#define PROGRESS 1000
#define TEST_QTY 100000

TEST_CASE("XAllocator allocates memory", "[Xanadu::Engine::XXAllocator]") {

	// allocate just enough memory for 10,000 Test objects
	std::cout << "Test initializing" << std::endl;
	auto alloc = XAllocator(1024 * 1024 * 1024, 2);
	std::vector<Test*> tests;
	// allocate 10,000 test objects
	std::cout << "Allocate objects" << std::endl;

	for (int i = 0; i < TEST_QTY; i++) {
		auto item = alloc.Allocate<Test>();
		item->set(i);
		tests.push_back(item);
		if ((i % PROGRESS) == 0) {
			std::cout << "."; cout.flush();
		}
	}
	std::cout << std::endl;
	//SECTION("Run object") {
		std::cout << "Run objects" << std::endl;

		// call a method on each object
		int i = 0;
		for (auto iter = tests.begin(); iter != tests.end(); ++iter) {
			REQUIRE((*iter)->test() == i);
			i++;
			if ((i % PROGRESS) == 0) {
				std::cout << "."; cout.flush();
			}
		}
	//}
	std::cout << std::endl;

	//SECTION("Deallocate and reallocate, then run objects") {
		// deallocate 10,000 test objects
		std::cout << "Deallocate objects" << std::endl;
		for (int i = 0; i < TEST_QTY; i++) {
			alloc.Dealocate(tests[i]);
			if ((i % PROGRESS) == 0) {
				std::cout << "."; cout.flush();
			}
		}
		std::cout << std::endl;

		tests.clear();

		std::cout << "Reallocate objects" << std::endl;
		// allocate 10,000 test objects
		for (int i = 0; i < TEST_QTY; i++) {
			auto item = alloc.Allocate<Test>();
			item->set(i);
			tests.push_back(item);
			if ((i % PROGRESS) == 0) {
				std::cout << "."; cout.flush();
			}
		}
		std::cout << std::endl;

		// call a method on each object
		std::cout << "Run objects" << std::endl;
		i = 0;
		for (auto iter = tests.begin(); iter != tests.end(); ++iter) {
			REQUIRE((*iter)->test() == i);
			i++;
			if ((i % PROGRESS) == 0) {
				std::cout << "."; cout.flush();
			}
		}
		std::cout << std::endl;

	//}

}



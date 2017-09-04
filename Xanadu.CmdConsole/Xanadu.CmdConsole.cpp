// Xanadu.CmdConsole.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <boost/intrusive/avltree.hpp>
#include "Xanadu.XMath/Matrix4x4.h"

using namespace std;
using namespace boost::intrusive;

struct Record : public avl_set_base_hook<optimize_size<true>> {
	size_t size;
	bool in_use;

	Record(size_t _size, bool _in_use) {
		size = _size;
		in_use = _in_use;
	}

	friend bool operator< (const Record& a, const Record& b)
	{
		return a.size < b.size;
	}
	friend bool operator> (const Record& a, const Record& b)
	{
		return a.size > b.size;
	}
	friend bool operator== (const Record& a, const Record& b)
	{
		return a.size == b.size;
	}

};

typedef avltree<Record> tree_t;

struct GreaterThan {
	bool operator() (const Record& rec, const size_t size) const
	{
		std::cout << "A: " << rec.size << std::endl;
		return (rec.size <= size);
	}
	bool operator() (const size_t size, const Record& rec) const
	{
		std::cout << "B: " << rec.size << std::endl;
		return (size >= rec.size);
	}
};

#define PI 3.141592658
#define DEG2RAD(deg) (deg * (PI / 180.0))


int main() {


	Record a1(10, true);
	Record a2(20, true);
	Record a3(30, true);
	Record a4(40, true);
	Record a5(50, false);
	Record a6(60, false);

	tree_t tree;

	tree.push_back(a1);
	tree.push_back(a2);
	tree.push_back(a3);
	tree.push_back(a4);
	tree.push_back(a5);
	tree.push_back(a6);

	auto a = tree.find(35, GreaterThan());

	if (a != tree.end() //&& !(*a).in_use
		) {

		std::cout << (*a).size << std::endl;

	}
	else {
		std::cout << "Not found" << std::endl;
	}
	char in[255];
	std::cin >> in;

	return 0;
}


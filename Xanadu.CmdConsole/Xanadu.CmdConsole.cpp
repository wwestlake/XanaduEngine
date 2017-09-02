// Xanadu.CmdConsole.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <boost/intrusive/avltree.hpp>

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
		return !rec.in_use && (rec.size <= size);
	}
	bool operator() (const size_t size, const Record& rec) const
	{
		std::cout << "B: " << rec.size << std::endl;
		return !rec.in_use && (size >= rec.size);
	}
};




int main() {
	tree_t tree;

	for (int i = 1; i <= 10; i++) {
		tree.push_back(*(new Record( i * 10, false)));
	}

	auto a = tree.find(65, GreaterThan());
	//auto b = tree.find(GreaterThan(), 65);

	if (a != tree.end()) {
		cout << "Found: " << (*a).size << endl;
	}

	for (auto iter = tree.begin(); iter != tree.end(); ++iter) {
		std::cout << "Loaded: " << (*iter).size << std::endl;
	}


	for (; a != tree.end(); ++a) {
		std::cout << (*a).size << std::endl;
	}



	char in[255];
	std::cin >> in;

	return 0;
}


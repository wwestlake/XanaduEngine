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
		return !rec.in_use && (rec.size <= size);
	}
	bool operator() (const size_t size, const Record& rec) const
	{
		std::cout << "B: " << rec.size << std::endl;
		return !rec.in_use && (size >= rec.size);
	}
};

#define PI 3.141592658
#define DEG2RAD(deg) (deg * (PI / 180.0))


int main() {

	auto mat = Xanadu::XMath::Matrix4x4::Identity();
	auto xrot = Xanadu::XMath::Quaternion(DEG2RAD(180), 1, 0, 0);
	auto yrot = Xanadu::XMath::Quaternion(DEG2RAD(180), 0, 1, 0);
	auto zrot = Xanadu::XMath::Quaternion(DEG2RAD(180), 0, 0, 1);

	cout << mat << endl;

	auto rotmatx = mat.MakeRotation(xrot);
	auto rotmaty = mat.MakeRotation(yrot);
	auto rotmatz = mat.MakeRotation(zrot);

	cout << rotmatx << endl;
	cout << rotmaty << endl;
	cout << rotmatz << endl;



	char in[255];
	std::cin >> in;

	return 0;
}


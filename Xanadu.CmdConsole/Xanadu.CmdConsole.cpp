// Xanadu.CmdConsole.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <sstream>
#include <iostream>
#include <random>
#include <functional>
#include <vector>

using namespace std;

string percent(float x) {
	stringstream ss;
	ss << (x * 100) << "%";
	return ss.str();
}


int main() {

	std::default_random_engine generator;
	std::uniform_int_distribution<int> dist(1, 6);
	auto dice = std::bind(dist, generator);

	auto data = vector<int>();

	int max = 655360;

	for (int i = 0; i < 20; i++) data.push_back(0);


	for (int i = 0; i < max; i++) {
		auto d = dice() + dice();
		data[d]++;
	}

	for (int i = 2; i <= 12; i++) {
		cout << i << ": " << percent((float)data[i] / (float)max) << endl;
	}


	char in[255];
	std::cin >> in;

	return 0;
}


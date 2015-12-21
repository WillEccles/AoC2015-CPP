#include "stdafx.h"
#include "Day18.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void Day18::run(int part) {
	bool part2{ part == 2 };

	vector<string> lights;

	cout << "Initializing yard lights... ";

	fstream file("Day 18 Input.txt");
	string line;

	string buffer = "";

	// zeroes for the top and bottom of the grid
	// later I will have to iterate from 1-100, since 0 and 101 will ALWAYS be 0
	for (int q = 0; q < 102; q++) {
		buffer += "0";
	}

	lights.push_back(buffer);

	while (file >> line) {
		lights.push_back("0" + line + "0");
	}

	lights.push_back(buffer);

	cout << "DONE" << endl;

	// look through each row 100 times and set each light
	for (int row = 1; row < 101; row++) {
		for (int col = 1; col < 101; col++) {
			
		}
	}

	int on = 0;

	for (string r : lights) {
		for (char l : r) {
			if (l == '1') on++;
		}
	}

	if (!part2) cout << "There are " << on << " lights on." << endl;

	cin.get();
}
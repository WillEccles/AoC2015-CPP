#include "stdafx.h"
#include "Day17.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

vector<int> containers;

void Day17::run(int part) {

	bool part2 { part == 2 };

	fstream file("Day 17 Input.txt");
	int con;

	while (file >> con) {
		// add each container
		containers.push_back(con);
	}

	cout << "Loaded " << containers.size() << " containers." << endl;

	int combos = 0;

	

	cout << "There are " << combos << " combinations that add up to 150." << endl;
}
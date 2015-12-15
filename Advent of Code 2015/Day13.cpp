#include "stdafx.h"
#include "Day13.h"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <map>

using namespace std;

/*
THIS IS A HEAVILY MODIFIED CHANGE TO MY DAY9, WHICH IS NEARLY THE SAME PROBLEM
THANKS TO /U/TEHJIMMEH'S SOLUTION, I NOW KNOW I CAN ACTUALLY USE PERMUTATIONS :D
*/


// this should just contain all names
vector<string> names;

// name: {name1: 5, name2: 6}, name2... etc
map<string, map<string, int>> happiness;

void Day13::run() {
	cout << "Reading file... ";

	fstream file("Day 13 Input.txt");
	string name1, name2;
	int change;

	// for part 2
	addPerson("me");

	// store names and happiness values
	while (file >> name1 >> change >> name2) {
		addPerson(name1); addPerson(name2);
		
		happiness[name1][name2] = change;
		// for part 2:
		happiness["me"][name1] = 0;
		happiness["me"][name2] = 0;
	}

	sort(names.begin(), names.end());

	cout << "DONE" << endl;
	cout << "Doing math... ";

	int tries = 0;

	int highest = 0;

	int current = 0;

	do {
		current = happiness[*(names.end() - 1)][*(names.begin())] + happiness[*(names.begin())][*(names.end() - 1)];

		for (auto thing = names.begin(); thing != names.end() - 1; thing++) {
			current += happiness[*thing][*(thing + 1)] + happiness[*(thing + 1)][*thing];
		}

		highest = std::max(current, highest);
	} while (next_permutation(names.begin(), names.end()));

	cout << "DONE" << endl << "[IN PART 2] Maximum: " << highest;

	cin.get();

}

void Day13::addPerson(string name) {
	if (std::find(names.begin(), names.end(), name) != names.end()) {
		// if the name already exists
	}
	else {
		names.push_back(name);
	}
}
#include "stdafx.h"
#include "Day17.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

// there are certainly much better ways to do this (/u/willkill did his in like 40 lines and executed both parts in something like .05s)
// this just happens to be the way I did it, using a bit of a hint from someone else's code, since I am not exactly a pro at this kind of thing

void Day17::run(int part) {

	bool part2 { part == 2 };

	vector<int> containers;

	fstream file("Day 17 Input.txt");
	int con;

	while (file >> con) {
		// add each container
		containers.push_back(con);
	}

	cout << "Loaded " << containers.size() << " containers." << endl;

	int combos = 0;

	vector<vector<int>> subsets;

	// load up all the subsets into the subsets vector
	vector<vector<int>> subset;
	vector<int> empty;
	subset.push_back(empty);

	for (int i = 0; i < containers.size(); i++) {
		vector<vector<int>> tempsubset = subset;

		for (int j = 0; j < tempsubset.size(); j++) {
			tempsubset[j].push_back(containers[i]);
		}

		for (int k = 0; k < tempsubset.size(); k++) {
			subset.push_back(tempsubset[k]);
		}
	}

	// subsets now contains all subsets of the containers list
	subsets = subset;

	// for part 2
	bool foundlowest = false;
	int lowest = 99999999;

	// now go through the subsets
	for (auto sub : subsets) {
		if (part2 && sub.size() > lowest) break;

		int total = 0;

		for (int a : sub) total += a;

		if (total == 150 && !part2) combos++;
		if (total == 150 && part2) {
			if (!foundlowest) foundlowest = true;
			lowest = sub.size();
			cout << "Lowest : " << lowest;
			combos++;
		}
	}

	cout << "There are " << combos << " combinations that add up to 150." << endl;

	cin.get();
}
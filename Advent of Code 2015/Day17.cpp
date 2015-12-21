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

	// used later on in both part 1 and part 2
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
	int lowest = 99999999;

	// now go through the subsets
	for (auto sub : subsets) {

		int total = 0;

		for (int a : sub) total += a;

		

		if (total == 150 && !part2) combos++;
		if (total == 150 && part2) {
			if (sub.size() < lowest) {
				lowest = sub.size();
				// set this to 1 because since there is now at least one known it can't be 0
				combos = 1;
			}
			else if (sub.size() == lowest) combos++;
		}
	}

	if (!part2) cout << "There are " << combos << " combinations that add up to 150." << endl;
	else cout << "Lowest number: " << lowest << " with " << combos << " combinations." << endl;

	cin.get();
}
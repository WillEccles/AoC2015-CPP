#include "stdafx.h"
#include "Day16.h"
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>

std::vector<int> sueids;
std::map<int, std::map<std::string, int>> sues;

// all possible items
std::string items[10] = {"children", "cats", "samoyeds", "pomeranians", "akitas", "vizslas", "goldfish", "trees", "cars", "perfumes"};
// needed items
std::map<std::string, int> needs;

void Day16::run(int part) {
	bool part2{ part == 2 };

	std::cout << "Shuffling papers and poking calculators..." << std::endl;

	std::fstream reqs("Day 16 Reqs.txt");
	std::string item;
	int q;

	// aquire the 
	while (reqs >> item >> q) {
		needs[item] = q;
	}

	reqs.close();

	std::fstream file("Day 16 Input.txt");
	std::string val1, val2, val3;
	int sueid, num1, num2, num3;

	// every sue has exactly 3 items
	while (file >> sueid >> val1 >> num1 >> val2 >> num2 >> val3 >> num3) {
		sueids.push_back(sueid);
		
		// store input
		for (std::string itemname : items) {
			// this sets the value to one that will never come up in the input for those inputs that you "can't remember"
			sues[sueid][itemname] = -1;
		}

		sues[sueid][val1] = num1;
		sues[sueid][val2] = num2;
		sues[sueid][val3] = num3;
	}

	file.close();

	int suehas = 0;

	// now just loop through and see which of the sues has all of the requirements
	for (int s = 1; s <= sueids.size(); s++) {
		if (!part2) {
			for (std::string itemid : items) {
				if (sues[s][itemid] != -1 && sues[s][itemid] == needs[itemid]) {
					suehas++;
				}
			}
		}
		else {
			// for part 2, cats and trees require GREATER THAN what is required for part 1
			//             pomeranians and goldfish require FEWER THAN what is required for part 1
			for (std::string itemid : items) {
				if (itemid != "cats" && itemid != "trees" && itemid != "pomeranians" && itemid != "goldfish") {
					// for checking all the other items
					if (sues[s][itemid] != -1 && sues[s][itemid] == needs[itemid]) {
						suehas++;
					}
				}
				else if (itemid == "cats" || itemid == "trees") {
					if (sues[s][itemid] != -1 && sues[s][itemid] > needs[itemid]) {
						suehas++;
					}
				}
				else if (itemid == "pomeranians" || itemid == "goldfish") {
					if (sues[s][itemid] != -1 && sues[s][itemid] < needs[itemid]) {
						suehas++;
					}
				}
			}
		}
		if (suehas == 3) {
			std::cout << "Sue: " << s << std::endl;
			break;
		}
		suehas = 0;
	}

	std::cin.get();
}
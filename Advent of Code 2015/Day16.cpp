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

void Day16::run() {
	std::cout << "Shuffling papers and poking calculators..." << std::endl;

	std::fstream reqs("Day 16 Reqs.txt");
	std::string item;
	int q;

	// aquire the 
	while (reqs >> item >> q) {
		needs[item] = q;
		std::cout << "Item: " << item << " [" << q << " needed]" << std::endl;
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

		//std::cout << "Stored Sue #" << sueid << " " << val1 << " " << num1 << std::endl;
	}

	file.close();

	// this will store what we believe to be the proper sue
	std::vector<int> propersues;
	int suehas = 0;

	// now just loop through and see which of the sues has all of the requirements
	for (int s = 1; s <= sueids.size(); s++) {
		for (std::string itemid : items) {
			if (sues[s][itemid] != -1 && sues[s][itemid] == needs[itemid]) {
				suehas++;
				//std::cout << "suehas: " << suehas << " s: " << s << " itemid: " << itemid << " sues[s][itemid]: " << sues[s + 1][itemid] << " needs[itemid]: " << needs[itemid] << std::endl;
			}
		}
		if (suehas == 3) {
			std::cout << "Sue: " << s << std::endl;
			break;
		}
		suehas = 0;
	}

	std::cout << "DONE" << std::endl;
	//std::cout << "The correct Aunt Sue is Sue #" << propersue << "." << std::endl;

	std::cin.get();
}
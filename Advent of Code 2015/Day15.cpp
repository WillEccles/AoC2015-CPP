#include "stdafx.h"
#include "Day15.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

/*
NOTES:

You can only measure ingredients in whole-teaspoon amounts accurately, and you have to be accurate so you can reproduce your results in the future. The total score of a cookie can be found by adding up each of the properties (negative totals become 0) and then multiplying together everything except calories.

For instance, suppose you have these two ingredients:

Butterscotch: capacity -1, durability -2, flavor 6, texture 3, calories 8
Cinnamon: capacity 2, durability 3, flavor -2, texture -1, calories 3

Then, choosing to use 44 teaspoons of butterscotch and 56 teaspoons of cinnamon (because the amounts of each ingredient must add up to 100) would result in a cookie with the following properties:

A capacity of 44*-1 + 56*2 = 68
A durability of 44*-2 + 56*3 = 80
A flavor of 44*6 + 56*-2 = 152
A texture of 44*3 + 56*-1 = 76

Multiplying these together (68 * 80 * 152 * 76, ignoring calories for now) results in a total score of 62842880, which happens to be the best score possible given these ingredients. If any properties had produced a negative total, it would have instead become zero, causing the whole score to multiply to zero.
*/

vector<string> inames;

map<string, map<string, int>> ingredients;

void Day15::run() {
	std::cout << "Reading from file... ";

	fstream file("Day 15 Input.txt");
	string _name;
	int _capacity, _durability, _flavor, _texture, _calories;

	while (file >> _name >> _capacity >> _durability >> _flavor >> _texture >> _calories) {
		inames.push_back(_name);

		ingredients[_name]["capacity"] = _capacity;
		ingredients[_name]["durability"] = _durability;
		ingredients[_name]["flavor"] = _flavor;
		ingredients[_name]["texture"] = _texture;
		ingredients[_name]["calories"] = _calories;
	}

	std::cout << "DONE" << endl;
	std::cout << "Doing numbery things... ";

	// I need to total 100

	map<string, int> quantities;
	int total = 0;

	for (int frosting = 0; frosting <= 100; frosting++) {
		for (int candy = 0; candy <= 100 - frosting; candy++) {
			for (int butterscotch = 0; butterscotch <= 100 - (frosting + candy); butterscotch++) {
				for (int sugar = 0; sugar <= 100 - (butterscotch + frosting + candy); sugar++) {
					if (frosting + sugar + candy + butterscotch == 100) {

						quantities["Frosting"] = frosting;
						quantities["Candy"] = candy;
						quantities["Butterscotch"] = butterscotch;
						quantities["Sugar"] = sugar;

						int cap = 0, dur = 0, flav = 0, tex = 0, cal = 0;

						for (auto ing : inames) {
							cap += quantities[ing] * ingredients[ing]["capacity"];
							dur += quantities[ing] * ingredients[ing]["durability"];
							flav += quantities[ing] * ingredients[ing]["flavor"];
							tex += quantities[ing] * ingredients[ing]["texture"];
							cal += quantities[ing] * ingredients[ing]["calories"];
						}

						// this statement has been modified for part 2                     v-- HERE
						if (parseQ(cap) * parseQ(dur) * parseQ(flav) * parseQ(tex) > total && cal == 500) {
							total = parseQ(cap) * parseQ(flav) * parseQ(dur) * parseQ(tex);
						}
					}
				}
			}
		}
	}
	
	std::cout << "DONE" << endl;

	std::cout << "[PART 2] The highest score should be " << total << "." << endl;

	std::cin.get();

}

int Day15::parseQ(int Q) {
	if (Q < 0) return 0;
	else return Q;
}
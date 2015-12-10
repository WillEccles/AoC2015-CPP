#include "stdafx.h"
#include "Day9.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <map>

using namespace std;

// this should just contain all cities
vector<string> cities;

// this should be in the form of ["city1 city2"] = 420
map<string, int> combosanddists;

// the order these are in will be randomized to get the distances between two things at those incices
int indices[8] = {0,1,2,3,4,5,6,7};

// maximum combos of these cities, since there are 8. 8! = 40320
const int fact8 = 40320;

void Day9::run() {
	cout << "Reading file... ";

	fstream file("Day 9 Input.txt");
	string city1, city2, to, equals;
	int dist;

	while (file >> city1 >> to >> city2 >> equals >> dist) {
		// need to store each city part 1, then store each second city
		addCity(city1); addCity(city2);

		// store combo + opposite combo
		storeCombo(city1, city2, dist);
	}

	cout << "DONE" << endl;
	cout << "Doing math... ";

	int tries = 0;

	// lowest distance achieved
	int lowdist = 99999999;
	// highest distance achieved
	int highdist = 0;

	// current distance
	int _dist = 0;

	string city3, city4, city5, city6, city7, city8;

	// while this is going to be random and may very well take more than 8! tries, this should be sufficient if run more than once.
	while (tries != fact8) {
		// randomize order of 0-8
		random_shuffle(indices, indices + 8);

		city1 = cities[indices[0]];
		city2 = cities[indices[1]];
		city3 = cities[indices[2]];
		city4 = cities[indices[3]];
		city5 = cities[indices[4]];
		city6 = cities[indices[5]];
		city7 = cities[indices[6]];
		city8 = cities[indices[7]];

		// find out how long this will take
		_dist = combosanddists[city1 + city2] + combosanddists[city2 + city3] + combosanddists[city3 + city4] + combosanddists[city4 + city5] + combosanddists[city5 + city6] + combosanddists[city6 + city7] + combosanddists[city7 + city8];

		if (_dist < lowdist) lowdist = _dist;
		if (_dist > highdist) highdist = _dist;

		tries++;
	}

	cout << "DONE" << endl << "Lowest distance is most likely " << lowdist << "." << endl;
	cout << "The longest distance is most likely " << highdist << "." << endl;

	cin.get();

}

void Day9::addCity(string cityName) {
	if (std::find(cities.begin(), cities.end(), cityName) != cities.end()) {
		// if the city exists
	}
	else {
		cities.push_back(cityName);
	}
}

void Day9::storeCombo(string city1, string city2, int dist) {
	combosanddists[city1 + city2] = dist;
	combosanddists[city2 + city1] = dist;
}
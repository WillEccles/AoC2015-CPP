#include "stdafx.h"
#include "Day14.h"
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <set>
#include <algorithm>

using namespace std;

// MY INPUT FILE IS SETUP THIS WAY:
// name, speed (km/s), time at max speed, time at rest after that

const int RUNNING = 0;
const int RESTING = 1;

map<string, map<string, int>> deer;

vector<string> deernames;

void Day14::run() {

	fstream file("Day 14 Input.txt");

	string name;
	int speed, tas, tar;

	while (file >> name >> speed >> tas >> tar) {
		deer[name]["speed"] = speed;
		deer[name]["time at speed"] = tas;
		deer[name]["time at rest"] = tar;
		deer[name]["current state"] = RUNNING;
		deer[name]["time at state"] = 0;
		deer[name]["distance"] = 0;
		// part 2
		deer[name]["points"] = 0;

		deernames.push_back(name);
	}

	vector<string> leaders;
	int leadDist = 0;

	for (int TIMES = 0; TIMES < 2503; TIMES++) {
		for (string n : deernames) {
			if (deer[n]["current state"] == RUNNING) {
				if (deer[n]["time at state"] == deer[n]["time at speed"]) {
					deer[n]["current state"] = RESTING;
					deer[n]["time at state"] = 1;
				}
				else {
					deer[n]["time at state"]++;
					deer[n]["distance"] += deer[n]["speed"];
				}
			}
			else {
				if (deer[n]["time at state"] == deer[n]["time at rest"]) {
					deer[n]["current state"] = RUNNING;
					deer[n]["time at state"] = 1;
					deer[n]["distance"] += deer[n]["speed"];
				}
				else {
					deer[n]["time at state"]++;
				}
			}

			// this is for part 2
			if (deer[n]["distance"] > leadDist) {
				leaders.clear();
				leadDist = deer[n]["distance"];
				leaders.push_back(n);
			}
			else if (deer[n]["distance"] == leadDist) {
				leaders.push_back(n);
			}
		}

		// in part 2 at the end of each second we have to give a point to the lead reindeer (or multiple if there is a tie)
		for (auto d : leaders) {
			deer[d]["points"]++;
		}

		leadDist = 0;
		leaders.clear();
	}

	int farthest = 0;
	for (auto n : deernames) {
		if (deer[n]["distance"] > farthest) farthest = deer[n]["distance"];
	}

	int points = 0;
	for (auto d : deernames) {
		if (deer[d]["points"] > points) points = deer[d]["points"];
	}


	
	cout << "Max distance was " << farthest << "km." << endl;
	cout << "Most points accumulated was " << points << "." << endl;

	cin.get();
}

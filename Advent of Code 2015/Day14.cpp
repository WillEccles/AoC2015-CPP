#include "stdafx.h"
#include "Day14.h"
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <fstream>


using namespace std;

// MY INPUT FILE IS SETUP THIS WAY:
// name, speed (km/s), time at max speed, time at rest after that

#define RUNNING 0
#define RESTING 1

#define REPEAT(x) for (int TIMES = 0; TIMES < x; TIMES++)

map<string, map<string, int>> deer;

vector<string> deernames;

void Day14::run() {

	fstream file("Day 14 Input.txt");

	string name;
	int speed, tas, tar;

	while (file >> name >> speed >> tas >> tar) {
		deer[name]["mspeed"] = speed;
		deer[name]["time at speed"] = tas;
		deer[name]["time at rest"] = tar;
		deer[name]["current state"] = RUNNING;
		deer[name]["time at state"] = 0;
		deer[name]["distance"] = 0;

		deernames.push_back(name);
	}

	REPEAT(2503) {
		for (string n : deernames) {
			if (deer[n]["current state"] == RUNNING) {
				if (deer[n]["time at state"] == deer[n]["time at speed"] + 1) {
					deer[n]["current state"] = RESTING;
					deer[n]["time at state"] = 1;
				}
				else {
					deer[n]["time at state"]++;
					deer[n]["distance"] += speed;
				}
			}
			else {
				if (deer[n]["time at state"] == deer[n]["time at rest"] + 1) {
					deer[n]["current state"] = RUNNING;
					deer[n]["time at state"] = 1;
					deer[n]["distance"] += speed;
				}
				else {
					deer[n]["time at state"]++;
				}
			}
		}
	}

	int furthest = 0;
	for (string n : deernames) {
		deer[n]["distance"] < furthest ? furthest += 0 : furthest = deer[n]["distance"];
	}

	cout << "Max distance was " << furthest << "km." << endl;

	cin.get();
}
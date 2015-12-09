#include "stdafx.h"
#include "Day6.h"
#include <iostream>
#include <regex>
#include <string>
#include <fstream>
#include <sstream>

/*
--- Day 6: Probably a Fire Hazard ---

Because your neighbors keep defeating you in the holiday house decorating contest year after year, you've decided to deploy one million lights in a 1000x1000 grid.

Furthermore, because you've been especially nice this year, Santa has mailed you instructions on how to display the ideal lighting configuration.

Lights in your grid are numbered from 0 to 999 in each direction; the lights at each corner are at 0,0, 0,999, 999,999, and 999,0. The instructions include whether to turn on, turn off, or toggle various inclusive ranges given as coordinate pairs. Each coordinate pair represents opposite corners of a rectangle, inclusive; a coordinate pair like 0,0 through 2,2 therefore refers to 9 lights in a 3x3 square. The lights all start turned off.

To defeat your neighbors this year, all you have to do is set up your lights by doing the instructions Santa sent you in order.

For example:

turn on 0,0 through 999,999 would turn on (or leave on) every light.
toggle 0,0 through 999,0 would toggle the first line of 1000 lights, turning off the ones that were on, and turning on the ones that were off.
turn off 499,499 through 500,500 would turn off (or leave off) the middle four lights.

After following the instructions, how many lights are lit?

*/

// for the record, i already have the file saved as Day 6 Input.txt

using namespace std;

// must be static, nobody is really sure why
static bool lights[1000][1000] = { {0} };

// these look funny because i have modified my file
regex on("turnon.*");
regex off("turnoff.*");
regex toggle("toggle.*");

int lightson = 0;

void Day6::run() {
	cout << "I'm gonna read through the file now and do some math." << endl;
	cout << "This may take quite a while, since there's a lot of looping and such to be done." << endl;
	cout << "Reading through file..." << endl;

	readfile();

	cout << "According to my calculations, there are now " << lightson << " lights on." << endl;
}

void Day6::readfile() {
	// so first let's set up to read the file
	string line;

	ifstream infile("Day 6 Input.txt");

	int x1, x2, y1, y2;
	string instruction, through;

	while (infile >> instruction >> x1 >> y1 >> through >> x2 >> y2) {
		cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
		
		if (regex_search(instruction, on)) {
			for (int i = x1; i <= x2; i++) {
				for (int j = y1; j <= y2; j++) {
					lights[i][j] = 1;
				}
			}
		}
		else if (regex_search(instruction, off)) {
			for (int i = x1; i <= x2; i++) {
				for (int j = y1; j <= y2; j++) {
					lights[i][j] = 0;
				}
			}
		}
		else if (regex_search(instruction, toggle)) {
			for (int i = x1; i <= x2; i++) {
				for (int j = y1; j <= y2; j++) {
					lights[i][j] = !lights[i][j];
				}
			}
		}

		
	}

	cout << ">>>DONE" << endl;

	cout << "Calculating how many lights are on... ";

	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			if (lights[i][j] == 1) {
				lightson++;
			}
		}
	}

	cout << "DONE" << endl;
}
#include "stdafx.h"
#include "Day1.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

// since I already did 1-3 in Java, this is going to be as minimal as possible, though not a one-liner unless possible

void Day1::run() {
	int f = 0;
	char line[] = getline(fstream("Day 1 Input.txt"));
	f += count(f.begin(), f.end(), '(');
	f -= count(f.begin(), f.end(), ')');
	cout << "He is on floor " << f << "." << endl;
	system("pause");
}

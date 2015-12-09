#include "stdafx.h"
#include "Day5.h"
#include <iostream>
#include <regex>
#include <string>
#include <fstream>

/*
--- Day 5: Doesn't He Have Intern-Elves For This? ---

Santa needs help figuring out which strings in his text file are naughty or nice.

A nice string is one with all of the following properties:

It contains at least three vowels (aeiou only), like aei, xazegov, or aeiouaeiouaeiou.
It contains at least one letter that appears twice in a row, like xx, abcdde (dd), or aabbccdd (aa, bb, cc, or dd).
It does not contain the strings ab, cd, pq, or xy, even if they are part of one of the other requirements.

For example:

ugknbfddgicrmopn is nice because it has at least three vowels (u...i...o...), a double letter (...dd...), and none of the disallowed substrings.
aaa is nice because it has at least three vowels and a double letter, even though the letters used by different rules overlap.
jchzalrnumimnmhp is naughty because it has no double letter.
haegwjzuvuyypxyu is naughty because it contains the string xy.
dvszwmarrgswjxmb is naughty because it contains only one vowel.

How many strings are nice?

PASSED - 236 nice strings
*/

using namespace std;

// just to make things nicer for myself later
#define MATCH(str, reg) regex_search(str, reg)

// to match the 3+ vowels rule
regex vowels("([^aeiou]*[aeiou]+[^aeiou]*){3,}");
// this matches the pairs of letters
// the \1 here matches the first capture group, which is the ([a-zA-Z]) here
regex pairs(".*([a-zA-Z])\\1.*");
// and this MATCHES the strings that are not allowed, so it must be used to see if it DOESNT match -> success
regex illegals(".*(ab|cd|pq|xy)+.*");

// number of nice strings
int nice = 0;

void Day5::run() {

	cout << "Reading text file..." << endl;
	// this will read the file and decide how many nice strings there are
	readfile();

	// now we just report the answer!
	cout << "Santa has " << nice << " nice strings!" << endl;

	cin.get();
}

void Day5::readfile() {
	string line;

	ifstream infile("Day 5 Input.txt");

	while (getline(infile, line)) {
		cout << "Testing '" << line << "'... ";
		if (MATCH(line, vowels) && MATCH(line, pairs) && !MATCH(line, illegals)) {
			nice++;
			
			// color [bf] background, foreground -  and colors are green and black
			cout << "PASS" << endl;
		}
		else {
			cout << "FAIL" << endl;
		}
	}
}
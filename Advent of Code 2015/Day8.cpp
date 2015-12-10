#include "stdafx.h"
#include "Day8.h"
#include <iostream>
#include <string>
#include <fstream>
#include <regex>

/*
--- Day 8: Matchsticks ---

Space on the sleigh is limited this year, and so Santa will be bringing his list as a digital copy. He needs to know how much space it will take up when stored.

It is common in many programming languages to provide a way to escape special characters in strings. For example, C, JavaScript, Perl, Python, and even PHP handle special characters in very similar ways.

However, it is important to realize the difference between the number of characters in the code representation of the string literal and the number of characters in the in-memory string itself.

For example:

"" is 2 characters of code (the two double quotes), but the string contains zero characters.
"abc" is 5 characters of code, but 3 characters in the string data.
"aaa\"aaa" is 10 characters of code, but the string itself contains six "a" characters and a single, escaped quote character, for a total of 7 characters in the string data.
"\x27" is 6 characters of code, but the string itself contains just one - an apostrophe ('), escaped using hexadecimal notation.

Santa's list is a file that contains many double-quoted string literals, one on each line. The only escape sequences used are \\ (which represents a single backslash), \" (which represents a lone double-quote character), and \x plus two hexadecimal characters (which represents a single character with that ASCII code).

Disregarding the whitespace in the file, what is the number of characters of code for string literals minus the number of characters in memory for the values of the strings in total for the entire file?

For example, given the four strings above, the total number of characters of string code (2 + 5 + 10 + 6 = 23) minus the total number of characters in memory for string values (0 + 3 + 7 + 1 = 11) is 23 - 11 = 12.
*/


using namespace std;

// for counting actual output characters
string &lines = string("");
// for counting characters of code that are in memory
string &memlines = string("");
string &memlines2 = string("");

// this just makes things easier later on when replacing all the things
#define REG_REPLACE(str) regex_replace(regex_replace(regex_replace(regex_replace(str, memquotes, ""), doubleslash, "_"), asciihex, "_"), actualquotes, "_")
// this one is for part 2
// will have to add 2 to each one to account for the encoded "", hence the +"22" at the end
#define REG_REPLACE2(str) regex_replace(regex_replace(regex_replace(regex_replace(str, memquotes, "__"), doubleslash, "____"), asciihex, "_____"), actualquotes, "____") + "22"

/* these must be used in this order */
// since every line is a string made up of a quote on either side, we should remove the " from the beginning and ending of each line
regex memquotes("^\"|\"$"); // replace with "" (PART 2: "__")
// get rid of pairs of backslashes, since there will never be just 2 in front of a " or a hex code. there can only be 3 or 1 in front of those.
regex doubleslash("\\\\\\\\"); // replace with "_" (PART 2: "____")
// take care of any hex codes in the form of \xab
regex asciihex("\\\\x[a-zA-Z0-9]{2}"); // replace with "_" (PART 2: 
// now get rid of any instances of \" which leaves just a " in the string
regex actualquotes("\\\\\""); // replace with "_"

void Day8::run() {
	lines = "";
	memlines = "";
	memlines2 = "";

	cout << "Storing all lines... ";

	// now, as I just said, we are going to collect all lines into an array and into a string
	fstream file("Day 8 Input.txt");

	string line;

	while (getline(file, line)) {
		lines += REG_REPLACE(line);
		memlines += line;
		memlines2 += REG_REPLACE2(line);
	}

	cout << "DONE" << endl;
	cout << endl << "Done!" << endl;
	cout << "Length in memory: " << memlines.length() << endl;
	cout << "Actual length: " << lines.length() << endl;
	cout << "Difference: " << memlines.length() - lines.length() << endl;
	cout << "Part 2 answer: " << memlines2.length() - memlines.length() << endl;

	cin.get();
}
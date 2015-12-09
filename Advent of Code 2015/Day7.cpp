#include "stdafx.h"
#include "Day7.h"
#include <iostream>
#include <regex>
#include <fstream>
#include <string>
#include <map>
#include <sstream>


// instructions (thank goodness for folding!)
/*
--- Day 7: Some Assembly Required ---

This year, Santa brought little Bobby Tables a set of wires and bitwise logic gates! Unfortunately, little Bobby is a little under the recommended age range, and he needs help assembling the circuit.

Each wire has an identifier (some lowercase letters) and can carry a 16-bit signal (a number from 0 to 65535). A signal is provided to each wire by a gate, another wire, or some specific value. Each wire can only get a signal from one source, but can provide its signal to multiple destinations. A gate provides no signal until all of its inputs have a signal.

The included instructions booklet describes how to connect the parts together: x AND y -> z means to connect wires x and y to an AND gate, and then connect its output to wire z.

For example:

123 -> x means that the signal 123 is provided to wire x.
x AND y -> z means that the bitwise AND of wire x and wire y is provided to wire z.
p LSHIFT 2 -> q means that the value from wire p is left-shifted by 2 and then provided to wire q.
NOT e -> f means that the bitwise complement of the value from wire e is provided to wire f.

Other possible gates include OR (bitwise OR) and RSHIFT (right-shift). If, for some reason, you'd like to emulate the circuit instead, almost all programming languages (for example, C, JavaScript, or Python) provide operators for these gates.

For example, here is a simple circuit:

123 -> x
456 -> y
x AND y -> d
x OR y -> e
x LSHIFT 2 -> f
y RSHIFT 2 -> g
NOT x -> h
NOT y -> i

After it is run, these are the signals on the wires:

d: 72
e: 507
f: 492
g: 114
h: 65412
i: 65079
x: 123
y: 456

In little Bobby's kit's instructions booklet (provided as your puzzle input), what signal is ultimately provided to wire a?
*/

using namespace std;

// various patterns to match the types of instructions we may find in the list
regex wiretowire("[a-z]{1,2} -> [a-z]{1,2}");
regex valtowire("[0-9]+ -> [a-z]{1,2}");
regex notwire("NOT [a-z]{1,2} -> [a-z]{1,2}");
regex wireopnum("[a-z]+ (AND|OR|RSHIFT|LSHIFT) [0-9]+ -> [a-z]+");
regex numopwire("[0-9]+ (AND|OR|RSHIFT|LSHIFT) [a-z]+ -> [a-z]+");
regex wireopwire("[a-z]+ (AND|OR|RSHIFT|LSHIFT) [a-z]+ -> [a-z]+");

map<string, uint16_t> wires;

void Day7::run() {
	
	// none of this is needed, simply run Day 7.js in a console in a browser.
	// using VS Code, I just manipulated the text to all look like code and then stored it as js

	/*string line, wire1, wire2, wire3, arrow, op;
	int num;

	ifstream file("Day 7 Input.txt");

	while (getline(file, line)) {
		istringstream l(line);

		// parse which type of line it is
		if (regex_match(line, wiretowire) && l >> wire1 >> arrow >> wire2) {

		}
		else if (regex_match(line, valtowire) && l >> num >> arrow >> wire1) {

		}
		else if (regex_match(line, notwire) && (l >> op >> wire1 >> arrow >> wire2)) {

		}
		else if (regex_match(line, wireopnum) && (l >> wire1 >> op >> num >> arrow >> wire2)) {

		}
		else if (regex_match(line, numopwire) && (l >> num >> op >> wire1 >> arrow >> wire2)) {

		}
		else if (regex_match(line, wireopwire) && (l >> wire1 >> op >> wire2 >> arrow >> wire3)) {

		}
	}

	cin.get();

	*/
}
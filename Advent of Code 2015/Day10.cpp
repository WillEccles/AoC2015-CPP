#include "stdafx.h"
#include "Day10.h"
#include <iostream>
#include <string>

using namespace std;

#define REPEAT(x) for (int I = 0; I < x; I++)

// this is my input
string input = "1113122113";

void Day10::run() {
	cout << "Running algorithm on " << input << "... ";

	string tempinput = "";
	string lastChar = "x";
	int count = 0;
	string temp;

	// we need to run this 40 times
	REPEAT(50) {
		// read through the previous result (or the input, as the case may be)
		for (int i = 0; i <= input.length(); i++) {
			// input[i] is now the current character
			temp = input[i];

			
			
			// if the current char in the input == the last one 
			if (temp == lastChar) {

				count++;
			}
			else {

				// there is now a new character, also we should set the count to 1
				if (lastChar == "x") {
					
					lastChar = temp;
					count = 1;
				}
				else {
					// since this isn't the first character
					tempinput += to_string(count) + lastChar;

					lastChar = temp;
					count = 1;
				}
			}

		}

		// store temporary input as current
		input = tempinput;
		tempinput = "";
		count = 0;
		lastChar = 'x';
	}

	// we want the length of the result

	cout << "DONE" << endl << "The length of the result is " << input.length() << "." << endl;

	cin.get();
}
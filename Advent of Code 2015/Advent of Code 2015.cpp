// Advent of Code 2015.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include "Day5.h"
#include "Day6.h"
#include "Day7.h"
#include "Day8.h"

using namespace std;

#define RUN(day) day.run();

Day5 d5;
Day6 d6;
Day7 d7;
Day8 d8;

// here is where I just run each day's class
int main()
{
	RUN(d5);
    return 0;
}


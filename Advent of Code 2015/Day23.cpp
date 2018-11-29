#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <string>

// set registers to 0
std::map<char, int> registers = {{'a', 1}, {'b', 0}};

typedef struct intruction {
	std::string com;
	std::string arg1;
	std::string arg2;
} instruction;

int main(void) {
	std::ifstream program("input23.txt");
	if (!program) {
		std::cerr << "Couldn't open file.\n";
		return 1;
	}

	std::vector<instruction> instructions;

	std::string line;
	std::stringstream ss;
	while (std::getline(program, line)) {
		ss = std::stringstream(line);
		instruction i;
		ss >> i.com;
		ss >> i.arg1;
		if (!ss.eof())
			ss >> i.arg2;
		instructions.push_back(i);
	}

	program.close();

	std::string com, arg1, arg2;
	char reg;
	for (int i = 0; i < instructions.size();) {
		com = instructions[i].com;
		arg1 = instructions[i].arg1;
		reg = arg1[0];
		arg2 = instructions[i].arg2;

		if (com == "hlf") {
			registers[reg] /= 2;
			i++;
		} else if (com == "tpl") {
			registers[reg] *= 3;
			i++;
		} else if (com == "inc") {
			registers[reg]++;
			i++;
		} else if (com == "jmp") {
			ss = std::stringstream(arg1);
			int offset;
			ss >> offset;
			i += offset;
		} else if (com == "jie") {
			if (registers[reg] % 2 != 0) i++;
			else {
				ss = std::stringstream(arg2);
				int offset;
				ss >> offset;
				i += offset;
			}
		} else if (com == "jio") {
			if (registers[reg] != 1) i++;
			else {
				ss = std::stringstream(arg2);
				int offset;
				ss >> offset;
				i += offset;
			}
		}
	}

	std::cout << "b: " << registers['b'] << std::endl;

	return 0;
}

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include "wrethreading.h"
#include "wrestrings.h"
#include <string>
#include <regex>
#include <cstdio>

const std::string molecule = "CRnCaSiRnBSiRnFArTiBPTiTiBFArPBCaSiThSiRnTiBPBPMgArCaSiRnTiMgArCaSiThCaSiRnFArRnSiRnFArTiTiBFArCaCaSiRnSiThCaCaSiRnMgArFYSiRnFYCaFArSiThCaSiThPBPTiMgArCaPRnSiAlArPBCaCaSiRnFYSiThCaRnFArArCaCaSiRnPBSiRnFArMgYCaCaCaCaSiThCaCaSiAlArCaCaSiRnPBSiAlArBCaCaCaCaSiThCaPBSiThPBPBCaSiRnFYFArSiThCaSiRnFArBCaCaSiRnFYFArSiThCaPBSiThCaSiRnPMgArRnFArPTiBCaPRnFArCaCaCaCaSiRnCaCaSiRnFYFArFArBCaSiThFArThSiThSiRnTiRnPMgArFArCaSiThCaPBCaSiRnBFArCaCaPRnCaCaPMgArSiRnFYFArCaSiThRnPBPMgAr";

typedef struct replacement {
	std::string pattern;
	std::string r;
	std::set<std::string> molecules;
} replacement;

using namespace wrestd::threading;
using namespace wrestd::strings;

int main(void) {
	std::ifstream input("input19.txt");
	if (!input) {
		std::cerr << "Couldn't load file.\n";
		return 1;
	}

	std::vector<replacement> replacements;

	std::string s1, s2, s3;
	while (input >> s1 >> s2 >> s3) {
		replacement r;
		r.pattern = s1;
		r.r = s3;
		replacements.push_back(r);
	}

	input.close();

	std::set<std::string> all_molecules;

	parallel_foreach<replacement>(replacements, 0,
		[](replacement r, std::size_t n) -> replacement {
			std::string out;
			int index = molecule.find(r.pattern, index);
			while (index != molecule.npos) {
				out = molecule;
				out.erase(index, r.pattern.length());
				out.insert(index, r.r);
				index += r.pattern.length();
				r.molecules.insert(out);
				index = molecule.find(r.pattern, index);
			}
			return r;
		}
	);

	for (auto &r : replacements) {
		all_molecules.insert(r.molecules.begin(), r.molecules.end());
	}

	std::cout << all_molecules.size() << '\n';

	return 0;
}

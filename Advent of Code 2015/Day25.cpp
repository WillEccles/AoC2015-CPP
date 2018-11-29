#include <iostream>
#include <vector>
#include <cstdio>

const unsigned long long SEED = 20151125ULL;
unsigned long long f(unsigned long long x) { return (x * 252533ULL) % 33554393ULL; }

unsigned long long code_gen(int r, int c) {
	int row = 0; // 1
	int col = 0; // 1
	const int d = c+r-1;

	std::vector<std::vector<unsigned long long> > grid(d, std::vector<unsigned long long>(d, 0ULL));

	grid[row][col] = SEED; // 1, 1 = seed

	unsigned long long last = grid[row][col];
	for (row = 1; row < d && col < d; row++) {
		int _r = row;
		for (col = 0; col <= row; col++, _r--) {
			grid[_r][col] = f(last);
			last = grid[_r][col];
		}
	}

	/*
	for (int _r = 0; _r < d; _r++) {
		for (int _c = 0; _c < d; _c++) {
			std::printf("%8llu ", grid[_r][_c]);
		}
		std::cout << '\n';
	}
	*/

	return grid[r-1][c-1];
}

int main(void) {
	std::cout << code_gen(3010, 3019) << std::endl;
	return 0;
}

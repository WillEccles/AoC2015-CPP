#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <fstream>

const int bossHP = 109;
const int bossDMG = 8;
const int bossARMOR = 2;

typedef struct item {
	int cost;
	int damage;
	int armor;
} item;

bool itemeq(item &a, item &b) {
	return (a.cost == b.cost &&
			a.damage == b.damage &&
			a.armor == b.armor);
}

std::vector<item> weapons;
std::vector<item> armor;
std::vector<item> rings1;
std::vector<item> rings2; // same as rings1

// simulate a fight between the boss and the player with the given items
// returns whether or not you won
bool simulate(item &w, item &a, item &r1, item &r2) {
	int bosshp = bossHP;
	int playerhp = 100;
	int playerdmg = w.damage + a.damage + r1.damage + r2.damage;
	int playerarmor = w.armor + a.armor + r1.armor + r2.armor;

	bool playerturn = true;
	while (playerhp > 0 && bosshp > 0) {
		if (playerturn) {
			bosshp -= (playerdmg - bossARMOR);
		} else { // boss's turn
			playerhp -= (bossDMG - playerarmor);
		}

		playerturn = !playerturn;
	}

	return playerhp > 0;
}

// part 1 of the puzzle
void part1() {
	int minSpent = 999999;
	for (item &w : weapons) { // need a weapon always
		// for each weapon, test with every armor (including a 0 0 0 for the option of not taking armor)
		int gold = w.cost;
		for (item &a : armor) {
			gold += a.cost;
			// test with both rings missing
			if (simulate(w, a, rings1[0], rings1[0])) {
				if (gold < minSpent)
					minSpent = gold;
			}

			for (item &r : rings1) {
				gold += r.cost;
				if (simulate(w, a, r, rings1[0])) {
					if (gold < minSpent)
						minSpent = gold;
				}

				for (item &r2 : rings2) {
					if (itemeq(r, r2)) continue; // can't have more than one of each ring
					
					gold += r2.cost;
					if (simulate(w, a, r, r2)) {
						if (gold < minSpent)
							minSpent = gold;
					}

					gold -= r2.cost;
				}

				gold -= r.cost;
			}

			gold -= a.cost;
		}
	}

	std::printf("Min cost to win: %d\n", minSpent);
}

// part 2 of the puzzle
void part2() {
	int maxSpent = 0;
	for (item &w : weapons) { // need a weapon always
		// for each weapon, test with every armor (including a 0 0 0 for the option of not taking armor)
		int gold = w.cost;
		for (item &a : armor) {
			gold += a.cost;
			// test with both rings missing
			if (!simulate(w, a, rings1[0], rings1[0])) {
				if (gold > maxSpent)
					maxSpent = gold;
			}

			for (item &r : rings1) {
				gold += r.cost;
				if (!simulate(w, a, r, rings1[0])) {
					if (gold > maxSpent)
						maxSpent = gold;
				}

				for (item &r2 : rings2) {
					if (itemeq(r, r2)) continue; // can't have more than one of each ring
					
					gold += r2.cost;
					if (!simulate(w, a, r, r2)) {
						if (gold > maxSpent)
							maxSpent = gold;
					}

					gold -= r2.cost;
				}

				gold -= r.cost;
			}

			gold -= a.cost;
		}
	}

	std::printf("Max cost to lose: %d\n", maxSpent);
}

int main(void) {
	std::ifstream infile("shopday21.txt");
	if (!infile) {
		std::cerr << "Error opening shop file!\n";
		return 1;
	}

	std::vector<item> *currentShop = &weapons; // just reference each shop
	int c, d, a;
	while (infile >> c >> d >> a) {
		if (c == 0) {
			if (currentShop == &weapons)
				currentShop = &armor;
			else if (currentShop == &armor)
				currentShop = &rings1;
		}

		item i;
		i.cost = c;
		i.damage = d;
		i.armor = a;
		currentShop->push_back(i);
	}

	rings2 = std::vector<item>(rings1);

	infile.close();

	part1();
	part2();

	return 0;
}


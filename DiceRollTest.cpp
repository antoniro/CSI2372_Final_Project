#include <iostream>
#include "Dice.h"


int main() {
	for (int i = 0; i < 10; i++) {
		std::cout << "Dice roll " << i + 1 << ": " << RandomDice::distr(RandomDice::generator) << std::endl;
	}

	std::cin.get();
}
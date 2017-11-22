#include <iostream>
#include "Dice.h"
#include "RollOfDice.h"


int main() {
	RollOfDice r1;
	RollOfDice r2;
	Dice b(Colour::BLUE);
	Dice r(Colour::RED);
	Dice g(Colour::GREEN);
	Dice y(Colour::YELLOW);
	Dice w(Colour::WHITE);

	r1.addDice(b);
	r1.addDice(r);
	r1.addDice(g);
	r1.roll();

	std::cout << "Dice roll 1: ";
	for (Dice d : r1) {
		std::cout << d << "  ";
	}
	std::cout << std::endl;

	r1.removeAllDice();
	r1.addDice(y);
	r1.addDice(w);
	r1.roll();
	std::cout << "Dice roll 2: ";
	for (Dice d : r1) {
		std::cout << d << "  ";
	}
	std::cout << std::endl;

	std::cin.get();
}
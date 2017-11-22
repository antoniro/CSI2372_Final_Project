#pragma once

#include <random>
#include <iostream>
#include "Colour.h"

struct RandomDice {
	static std::random_device rDevice;
	static std::mt19937 generator;
	static std::uniform_int_distribution<int> distr;
};

struct Dice {
	Colour const colour;
	int face;
	int roll();
	Dice(Colour const);
};

std::ostream& operator<<(std::ostream&, Dice const&);		// Overload insertion operator for printing a Dice to an output stream

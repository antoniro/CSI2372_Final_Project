#pragma once

#include <random>
#include <iostream>
#include "Colour.h"

struct RandomDice {
	static std::random_device rDevice;
	static std::mt19937 generator;
	static std::uniform_int_distribution<int> distr;
};

//Initialize static members of the struct RandomDice
std::random_device RandomDice::rDevice;
std::mt19937 RandomDice::generator(RandomDice::rDevice());
std::uniform_int_distribution<int> RandomDice::distr(1, 6);

struct Dice {
	Colour const colour;
	int face;
	int roll();
	Dice(Colour const);
};

std::ostream& operator<<(std::ostream&, Dice& const);		// Overload insertion operator for printing a Dice to an output stream

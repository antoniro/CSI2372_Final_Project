#include "Dice.h"


int Dice::roll()
{
	face = RandomDice::distr(RandomDice::generator);
	return face;
}

Dice::Dice(Colour const col) : colour{col}
{
}

std::ostream & operator<<(std::ostream & os, Dice & const dice)
{
	os << dice.face;
	return os;
}

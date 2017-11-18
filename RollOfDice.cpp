//
//  RollOfDice.cpp
//  FProject
//


#include <stdio.h>
#include "RollOfDice.h"

void RollOfDice::addDice(Dice & dice)
{
	diceRoll.push_back(dice);
}

void RollOfDice::removeAllDice()
{
	diceRoll.clear;
}

void RollOfDice::roll()
{
	for (Dice d : diceRoll) {
		d.roll();
	}
}

RollOfDice RollOfDice::pair(Dice & d)
{
	RollOfDice r;
	Dice w(Colour::WHITE);
	w.roll();
	r.addDice(d);
	r.addDice(w);
	return r;
}

std::vector<Dice>::iterator RollOfDice::begin()
{
	return diceRoll.begin();
}

std::vector<Dice>::const_iterator RollOfDice::begin() const
{
	return diceRoll.begin();;
}

std::vector<Dice>::iterator RollOfDice::end()
{
	return diceRoll.end();
}

std::vector<Dice>::const_iterator RollOfDice::end() const
{
	return diceRoll.end();
}

RollOfDice::operator int() const
{
	int result;
	for (auto d : diceRoll) {
		result += d.face;
	}

	return result;
}

std::ostream & operator<<(std::ostream &, RollOfDice & const)
{
	// TODO: insert return statement here
}

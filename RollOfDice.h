#pragma once

#include <vector>
#include <iostream>
#include "Dice.h"

class RollOfDice {
public:
	void roll();
	RollOfDice pair();
	RollOfDice *begin();			// Overload begin() member function for use with range-based for loops
	RollOfDice *end();				// Overload end() menber function for use with range-based for loops
	operator int() const;			// Overload conversion operator to int

private:
	std::vector<Dice> diceRoll;
};

std::ostream& operator<<(std::ostream&, const RollOfDice&);	// Overload insertion operator for printing a RollOfDice to an output stream
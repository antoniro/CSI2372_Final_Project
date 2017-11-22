
#ifndef RollOfDice_h
#define RollOfDice_h

#pragma once

#include <vector>
#include <iostream>
#include "Dice.h"

class RollOfDice {
public:    
    void addDice(Dice&);
	void removeAllDice();
	void roll();   
    RollOfDice pair(Dice&);

	// Overload begin() member function for use with range-based for loops
    std::vector<Dice>::iterator begin();
	std::vector<Dice>::const_iterator begin() const;

	// Overload end() menber function for use with range-based for loops
    std::vector<Dice>::iterator end();
	std::vector<Dice>::const_iterator end() const;

	// Overload conversion operator to int
    operator int() const;

    friend std::ostream& operator<<(std::ostream&, RollOfDice const&);

private:
    std::vector<Dice> diceRoll;
};

std::ostream& operator<<(std::ostream&, RollOfDice const&);	// Overload insertion operator for printing a RollOfDice to an output stream

#endif /* RollOfDice_h */

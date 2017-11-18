//
//  RollOfDice.h
//  FProject
//
//  Created by Arthur Mbouche on 2017-11-16.
//  Copyright © 2017 Arthur Mbouche. All rights reserved.
//

#ifndef RollOfDice_h
#define RollOfDice_h

#pragma once

#include <vector>
#include <iostream>
#include "Dice.h"

class RollOfDice {
public:
    int sizeReserved;
    RollOfDice(int nDice);
    void roll();
    void removeAllDice();
    void addDice(Dice & newDice);
    std::vector<Dice> pair(Dice & white, Dice & random);
    RollOfDice *begin() const;	// Overload begin() member function for use with range-based for loops
    RollOfDice *end() const;		// Overload end() menber function for use with range-based for loops
    operator int() const;			// Overload conversion operator to int
    friend std::ostream& operator<<(std::ostream&,const RollOfDice&);
    
private:
    std::vector<Dice> diceRoll;
};

std::ostream& operator<<(std::ostream&, const RollOfDice&);	// Overload insertion operator for printing a RollOfDice to an output stream

#endif /* RollOfDice_h */

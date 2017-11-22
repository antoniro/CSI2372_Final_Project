//
//  Dice.h
//  FProject
//
//  Created by Arthur Mbouche on 2017-11-16.
//  Copyright © 2017 Arthur Mbouche. All rights reserved.
//

#ifndef Dice_h
#define Dice_h

#pragma once
#include <random>
#include <iostream>
#include "Colour.h"


struct RandomDice {
    static std::random_device rDevice;
    int random= random_value();
    static int random_value(){
        static std::mt19937 mersenne_generator{std::random_device{}()};
        static std::uniform_int_distribution<int> diceDistribution(1,6);
        return diceDistribution(mersenne_generator);
    }
};

struct Dice {
    const Colour colour;
    int face;
    RandomDice forRoll;
    int roll();
   friend std::ostream& operator<<(std::ostream&, const Dice&);
};

std::ostream& operator<<(std::ostream&, const Dice&);		// Overload insertion operator for printing a Dice to an output stream
#endif /* Dice_h */

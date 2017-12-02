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
    Colour colour;
    int face;
    int roll();
    Dice( const Colour);
};

std::ostream& operator<<(std::ostream&, Dice const &);

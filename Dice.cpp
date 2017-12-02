#include "Dice.h"

//Initialize static members of the struct RandomDice
std::random_device RandomDice::rDevice;
std::mt19937 RandomDice::generator(RandomDice::rDevice());
std::uniform_int_distribution<int> RandomDice::distr(1, 6);

int Dice::roll()
{
    face = RandomDice::distr(RandomDice::generator);
    return face;
}

Dice::Dice( const Colour col ) : colour(col)
{
}

std::ostream & operator<<(std::ostream & os, Dice const & dice)
{
    os << dice.face;
    return os;
}


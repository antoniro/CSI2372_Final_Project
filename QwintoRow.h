#pragma once

#include <array>
#include <vector>
#include <iostream>
#include "Colour.h"

template<Colour const C>
class QwintoRow {
public:
	bool validate();
	int& operator[] (int& const);
	friend std::ostream& operator<<(std::ostream&, QwintoRow<C>& const);

private:
	int const invalidIndex;
	std::vector<int> bonusIndex;
	std::array<int, 10> row;
};

template<Colour const C>
std::ostream& operator<<(std::ostream&, QwintoRow<C>& const);

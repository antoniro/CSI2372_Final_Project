#pragma once

#include <array>
#include <vector>
#include <iostream>
#include "Colour.h"

template<Colour C>
class QwintoRow {
public:
	bool validate();
	int& operator[] (cont int&);
	friend std::ostream& operator<<(std::ostream&, const QwintoRow<C>&);

private:
	int invalidIndex;
	std::vector<int> bonusIndex;
	std::array<int, 10> row;
};

template<Colour C>
std::ostream& operator<<(std::ostream&, const QwintoRow<C>&);

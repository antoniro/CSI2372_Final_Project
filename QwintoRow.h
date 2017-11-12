#pragma once

#include <array>
#include "Colour.h"

template<Colour C>
class QwintoRow {
public:
	int& operator[] (cont int i);
	bool validate();

private:
	std::array<string, 10> row;
};

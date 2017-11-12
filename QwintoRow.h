#pragma once

#include <array>

template<Colour C>
class QwintoRow {
public:
	int& operator[] (cont int i);
	bool validate();

private:
	std::array<string, 10> row;
};

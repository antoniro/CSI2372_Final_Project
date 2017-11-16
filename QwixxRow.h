#pragma once

#include <array>
#include "Colour.h"

template<class T, Colour C>
class QwixxRow {
public:
	QwixxRow& operator+=(const QwixxRow&);
	friend std::ostream& operator<<(std::ostream&, const QwixxRow<T, C>&);

private:
	int std::array<int, 12> row;
};

template<class T, Colour C>
std::ostream& operator<<(std::ostream&, const QwixxRow<T, C>&);
#pragma once

#include <array>
#include "Colour.h"

template<class T, Colour const C>
class QwixxRow {
public:
	QwixxRow& operator+=(QwixxRow& const);
	friend std::ostream& operator<<(std::ostream&, QwixxRow<T, C>& const);

private:
	T row;
};

template<class T, Colour const C>
std::ostream& operator<<(std::ostream&, QwixxRow<T, C>& const);
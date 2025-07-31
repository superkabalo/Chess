#include <iostream>
#include "Rook.h"


Rook::Rook()
{
	_color = -ONE; // set values
	_coordinates = Point();
	_type = ' ';
}

Rook::Rook(const int color, const Point& coordinates, const char type)
{
	_color = color;  // set values
	_coordinates = coordinates;
	_type = type;
}

Rook::~Rook()
{
	_color = ZERO;  // clear values
	_coordinates = Point();
	_type = (' ');
}

bool Rook::canMove(const Point& dst, Figure* board[][SIZE]) const
{
	return isStraightMove(dst, board);
}

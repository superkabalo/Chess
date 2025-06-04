#include "Bishop.h"

Bishop::Bishop()
{
	_color = -ONE; // set values
	_coordinates = Point();
	_type = ' ';
}

Bishop::Bishop(const int color, const Point& coordinates, const char type)
{
	_color = color;  // set values
	_coordinates = coordinates;
	_type = type;
}

Bishop::~Bishop()
{
	_color = ZERO;  // clear values
	_coordinates = Point();
	_type = (' ');
}

bool Bishop::canMove(const Point& dst, Figure* board[][SIZE]) const
{
	return isDiagonalMove(dst, board);
}
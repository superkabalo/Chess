#include "Queen.h"

Queen::Queen()
{
	_color = -ONE; // set values
	_coordinates = Point();
	_type = ' ';
}

Queen::Queen(const int color, const Point& coordinates, const char type)
{
	_color = color;  // set values
	_coordinates = coordinates;
	_type = type;
}

Queen::~Queen()
{
	_color = ZERO;  // clear values
	_coordinates = Point();
	_type = (' ');
}

bool Queen::canMove(const Point& dst, Figure* board[][SIZE]) const
{
	return isStraightMove(dst, board) || isDiagonalMove(dst, board);
}
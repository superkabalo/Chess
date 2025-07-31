#include "Knight.h"
#include "None.h"

Knight::Knight()
{
	_color = -ONE; // set values
	_coordinates = Point();
	_type = ' ';
}

Knight::Knight(const int color, const Point& coordinates, const char type)
{
	_color = color;  // set values
	_coordinates = coordinates;
	_type = type;
}

Knight::~Knight()
{
	_color = ZERO;  // clear values
	_coordinates = Point();
	_type = (' ');
}

bool Knight::canMove(const Point& dst, Figure* board[][SIZE]) const
{
	int deltaX = abs(dst.getX() - _coordinates.getX());
	int deltaY = abs(dst.getY() - _coordinates.getY());

	// Check if the move is in an L-shape (two squares in one direction and one square perpendicular)
	return ((deltaX == TWO && deltaY == ONE) || (deltaX == ONE && deltaY == TWO));
}
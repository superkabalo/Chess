#include "King.h"


King::King()
{
	_color = -ONE; // set values
	_coordinates = Point();
	_type = ' ';
}

King::King(const int color, const Point& coordinates, const char type)
{
	_color = color;  // set values
	_coordinates = coordinates;
	_type = type;
}

King::~King()
{
	_color = ZERO;  // clear values
	_coordinates = Point();
	_type = (' ');
}

bool King::canMove(const Point& dst, Figure* board[][SIZE]) const
{
	if (dst == Point(_coordinates.getX() + ONE, _coordinates.getY())  || dst == Point(_coordinates.getX() - ONE, _coordinates.getY()) ||  // check if the movement from current point (coordinates)
		dst == Point(_coordinates.getX(), _coordinates.getY() + ONE) || dst == Point(_coordinates.getX(), _coordinates.getY() - ONE) ||  // to dst fits all the way that the king can move
		dst == Point(_coordinates.getX() + ONE, _coordinates.getY() + ONE) ||
		dst == Point(_coordinates.getX() + ONE, _coordinates.getY() - ONE) ||
		dst == Point(_coordinates.getX() - ONE, _coordinates.getY() - ONE) ||
		dst == Point(_coordinates.getX() - ONE, _coordinates.getY() + ONE))
	{
		return true;
	}
	return false;
}

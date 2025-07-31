#include "None.h"


None::None()
{
	_color = -ONE; // set values
	_coordinates = Point();
	_type = NONE;
}

None::None(const Point& coordinates)
{
	_color = -ONE;  // set values
	_coordinates = coordinates;	
	_type = NONE;
}

None::~None()
{
	_color = ZERO;  // clear values
	_coordinates = Point();
	_type = (' ');
}

bool None::canMove(const Point& dst, Figure* board[][SIZE]) const
{
	return false;  // none is an empty square and thus it cannot move
}

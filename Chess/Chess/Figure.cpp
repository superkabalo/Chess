#include "Figure.h"
#include "None.h"
#include <iostream>
class None;  // to prevent infinite calling of None to Figure and Figure to None

Figure::Figure() : _color(-ONE), _coordinates(Point()), _type(' ')  // initiate values
{
}

Figure::~Figure()
{
	_color = -ONE;  // clear values
	_coordinates = Point();
	_type = (' ');
}

void Figure::moveFigure(const Point& dst, Figure* board[][SIZE])
{
	/*if (board[SIZE - _coordinates.getY()][_coordinates.getX() - ONE]->getType() == 'P' ||
		board[SIZE - _coordinates.getY()][_coordinates.getX() - ONE]->getType() == 'p')
	{
		board[SIZE - _coordinates.getY()][_coordinates.getX() - ONE].setIsFirstMove(true);
	}*/
	board[SIZE - _coordinates.getY()][_coordinates.getX() - ONE] = new None(Point(_coordinates));  // set None in src location
	_coordinates = dst;  // move figure
	board[SIZE - _coordinates.getY()][_coordinates.getX() - ONE] = this;  // set current figure in new location on board
}

bool Figure::isStraightMove(const Point& dst, Figure* board[][SIZE]) const
{
	int deltaX = abs(_coordinates.getX() - dst.getX());  // margin between x and y values of the movement
	int deltaY = abs(_coordinates.getY() - dst.getY());
	if (deltaX > ZERO && deltaY == ZERO)  // check if movement is on X axis
	{
		for (int i = ONE; i < deltaX; i++)  // go over all squares between current location and dst
		{
			if (_coordinates.getX() > dst.getX() && board[SIZE - _coordinates.getY()][_coordinates.getX() - i - ONE]->getType() != NONE)  // if movement is to the left -> check if there is a figure i squares to the left
			{
				return false;
			}
			if (_coordinates.getX() < dst.getX() && board[SIZE - _coordinates.getY()][_coordinates.getX() + i - ONE]->getType() != NONE)  // if movement is to the right -> check if there is a figure i squares to the right
			{
				return false;
			}
		}
	}
	else if (deltaY > ZERO && deltaX == ZERO)  // check if movement is on Y axis
	{
		for (int i = ONE; i < deltaY; i++)  // // go over all squares between current location and dst
		{
			if (_coordinates.getY() > dst.getY() && board[SIZE - _coordinates.getY() + i][_coordinates.getX() - ONE]->getType() != NONE)  // if movement is down -> check if there is a figure i squares down (Y is inverted)
			{
				return false;
			}
			if (_coordinates.getY() < dst.getY() && board[SIZE - _coordinates.getY() - i][_coordinates.getX() - ONE]->getType() != NONE) // if movement is up -> check if there is a figure i squares up (Y is inverted)
			{
				return false;
			}
		}
	}
	else  // if movement is on more than one axis
	{
		return false;
	}
	return true;
}

bool Figure::isDiagonalMove(const Point& dst, Figure* board[][SIZE]) const
{
	int deltaX = abs(_coordinates.getX() - dst.getX());
	int deltaY = abs(_coordinates.getY() - dst.getY());
	if (deltaX != deltaY)  // Check if someone tried to make an undiagonal move with the bishop
	{
		return false;
	}
	for (int i = ONE; i < deltaX; i++)  // deltaX == deltaY...
	{  // check if there are figures in the way of the bishop, note that the Y axis is inverted in the array
		if (dst.getX() > _coordinates.getX() && dst.getY() > _coordinates.getY() &&  // if movement is right and up
			board[SIZE - _coordinates.getY() - i][_coordinates.getX() + i - ONE]->getType() != NONE)  // check if there is a figure i squares right and up
		{
			return false;
		}
		else if (dst.getX() > _coordinates.getX() && dst.getY() < _coordinates.getY() &&  // if movement is right and down
			board[SIZE - _coordinates.getY() + i][_coordinates.getX() + i - ONE]->getType() != NONE)  // check if there is a figure i squares right and down
		{
			return false;
		}
		else if (dst.getX() < _coordinates.getX() && dst.getY() > _coordinates.getY() &&  // if movement is left and up
			board[SIZE - _coordinates.getY() - i][_coordinates.getX() - i - ONE]->getType() != NONE)  // check if there is a figure i squares left and up
		{
			return false;
		}
		else if (dst.getX() < _coordinates.getX() && dst.getY() < _coordinates.getY() &&  // if movement is left and down
			board[SIZE - _coordinates.getY() + i][_coordinates.getX() - i - ONE]->getType() != NONE)  // check if there is a figure i squares left and down
		{
			return false;
		}
	}
}

char Figure::getType() const
{
	return _type;
}

int Figure::getColor() const
{
	return _color;
}

Point Figure::getCoordinates() const
{
	return _coordinates;
}

void Figure::successfulMove()
{

}
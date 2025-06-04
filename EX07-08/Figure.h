#pragma once
#include "Point.h"
#define SIZE 8
#define WHITE 0
#define BLACK 1

#define NONE	'#'

// Numbers
#define ZERO	0
#define ONE		1
#define TWO		2

class Figure
{
protected:
	int _color;
	Point _coordinates;
	char _type;

	bool isStraightMove(const Point& dst, Figure* board[][SIZE]) const;
	bool isDiagonalMove(const Point& dst, Figure* board[][SIZE]) const;

public:
	/// <summary>
	/// C'TOR
	/// </summary>
	Figure();
	/// <summary>
	/// D'TOR
	/// </summary>
	virtual ~Figure();

	/// <summary>
	/// method checks if figure can move to given point
	/// </summary>
	/// <param name="dst">Point of dst point</param>
	/// <param name="board">Board on which to check if the figure can move</param>
	/// <returns>bol of whether figure can move to specified location or not</returns>
	virtual bool canMove(const Point& dst, Figure* board[][SIZE]) const = 0;
	/// <summary>
	/// method moves figure to given Point
	/// </summary>
	/// <param name="dst"Point of dst point></param>
	/// <param name="board">board on which to move the figure</param>
	void moveFigure(const Point& dst, Figure* board[][SIZE]);
	/// <summary>
	/// method changes fields accordingly if the move was successful
	/// </summary>
	virtual void successfulMove();


	/// <summary>
	/// method gets figure type
	/// </summary>
	/// <returns>char of figre type</returns>
	char getType() const;
	/// <summary>
	/// method gets figure color
	/// </summary>
	/// <returns>int of figure color</returns>
	int getColor() const;
	/// <summary>
	/// method gets figure coorinates
	/// </summary>
	/// <returns>Point of figure coordinates</returns>
	Point getCoordinates() const;
};
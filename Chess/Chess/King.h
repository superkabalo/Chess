#pragma once
#include "Figure.h"

class King : public Figure
{
public:
	/// <summary>
	/// C'TOR
	/// </summary>
	King();
	/// <summary>
	/// C'TOR with values
	/// </summary>
	/// <param name="color">int of figure color</param>
	/// <param name="coordinates">Point with figure coordinates</param>
	/// <param name="type">char with figure type</param>
	King(const int color, const Point& coordinates, const char type);
	/// <summary>
	/// D'TOR
	/// </summary>
	virtual ~King() override;

	/// <summary>
	/// method checks if figure can move to given point
	/// </summary>
	/// <param name="dst">Point of dst point</param>
	/// <returns>bool of whether figure can move to specified location or not</returns>
	virtual bool canMove(const Point& dst, Figure* board[][SIZE]) const;
};
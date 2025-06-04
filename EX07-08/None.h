#pragma once
#include "Figure.h"

class None : public Figure
{
public:
	/// <summary>
	/// C'TOR
	/// </summary>
	None();
	/// <summary>
	/// C'TOR with values
	/// </summary>
	/// <param name="coordinates">Point with figure coordinates</param>
	None(const Point& coordinates);
	/// <summary>
	/// D'TOR
	/// </summary>
	virtual ~None() override;

	/// <summary>
	/// method checks if figure can move to given point
	/// </summary>
	/// <param name="dst">Point of dst point</param>
	/// <param name="board">Board on which to check if the figure can move</param>
	/// <returns>bool of whether figure can move to specified location or not</returns>
	virtual bool canMove(const Point& dst, Figure* board[][SIZE]) const;
};
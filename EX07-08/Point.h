#pragma once

#define ZERO	0

class Point
{
public:
	// CTORS & DTORS
	/// <summary>
	/// Creator that
	/// Initializes the fields
	/// </summary>
	/// <param name="x">X coordinate</param>
	/// <param name="y">Y coordinate</param>
	Point(const int x, const int y);

	/// <summary>
	/// Copy creator
	/// He coopies other
	/// point into this
	/// </summary>
	/// <param name="other">Other point</param>
	Point(const Point& other);
	/// <summary>
	/// From the beginning
	/// resets the fields
	/// </summary>
	Point();
	/// <summary>
	/// Distractor
	/// He's a useless
	/// piece of shit,
	/// but he should
	/// still be here,
	/// he's a fagot
	/// by the way
	/// </summary>
	~Point();

	// Getters
	/// <summary>
	/// Returns the X
	/// coordinate
	/// </summary>
	/// <returns>int _x</returns>
	int getX() const;

	/// <summary>
	/// Returns the Y
	/// coordinate
	/// </summary>
	/// <returns>int _y</returns>
	int getY() const;

	// Operators
	/// <summary>
	/// Overrides the + operator
	/// to connect the coordinates
	/// of two points
	/// </summary>
	/// <param name="other">The second point</param>
	/// <returns>new Point with new coordinates</returns>
	Point operator+(const Point& other) const;

	/// <summary>
	/// Adds other point to this
	/// </summary>
	/// <param name="other">other point</param>
	/// <returns> this point</returns>
	Point& operator+=(const Point& other);

	/// <summary>
	/// Equals other point to this
	/// </summary>
	/// <param name="other">other pint</param>
	/// <returns>this point</returns>
	Point& operator=(const Point& other);

	/// <summary>
	/// Compares this point to another
	/// </summary>
	/// <param name="other">other point</param>
	/// <returns>if the points are equal or not</returns>
	bool operator==(const Point& other) const;


private:
	int _x;
	int _y;
};
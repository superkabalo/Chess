#include "Point.h"

Point::Point(const int x, const int y)
{
	this->_x = x;  // set values...
	this->_y = y;
}

Point::Point(const Point& other)
{
	this->_x = other.getX();
	this->_y = other.getY();
}

Point::Point()
{
	this->_x = ZERO;
	this->_y = ZERO;
}

Point::~Point()
{
	this->_x = ZERO;
	this->_y = ZERO;
}

int Point::getX() const
{
	return this->_x;
}

int Point::getY() const
{
	return this->_y;
}

Point Point::operator+(const Point& other) const
{
	return Point(this->_x + other.getX(), this->_y + other.getY());  // add all point values
}

Point& Point::operator+=(const Point& other)
{
	this->_x += other.getX();
	this->_y += other.getY();
	return *this;
}

Point& Point::operator=(const Point& other)
{
	this->_x = other.getX();
	this->_y = other.getY();
	return *this;
}

bool Point::operator==(const Point& other) const
{
	return this->_y == other.getY() && this->_x == other.getX();  // compare all point values
}
#include "Point.hpp"

Point::Point() : x(0), y(0) {}
Point::Point(const Fixed a, const Fixed b): x(a), y(b) {}
Point::~Point() {}
const Fixed& Point::getX() const
{
	return this->x;
}
const Fixed& Point::getY() const
{
	return this->y;
}
Point::Point(const Point& a): x(a.getX()), y(a.getY()) {} 
Point Point::operator=(const Point& a)
{
	(void)a;
    return (*this);
}

#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"
class Point
{
	private:
		const Fixed x;
		const Fixed y;
	public:
		Point();
		Point(const Fixed a,  const Fixed b);
		~Point();
		Point operator=(const Point& a);
		Point(const Point& obj);
		const Fixed& getX() const;
		const Fixed& getY() const ;
};

#endif

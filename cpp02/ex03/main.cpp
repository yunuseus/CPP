#include "Point.hpp"
#include <iostream>

static Fixed cross(const Point& a, const Point& b, const Point& c)
{
    return (b.getX() - a.getX()) * (c.getY() - a.getY())
         - (b.getY() - a.getY()) * (c.getX() - a.getX());
}

bool bsp(Point const a, Point const b, Point const c, Point const p)
{
    Fixed area = cross(a, b, c);
    if (area == Fixed(0))
    {
        std::cout << "there is no triangle" << std::endl;
        return false;
    }

    Fixed c1 = cross(a, b, p);
    Fixed c2 = cross(b, c, p);
    Fixed c3 = cross(c, a, p);

    bool allPos = (c1 > Fixed(0)) && (c2 > Fixed(0)) && (c3 > Fixed(0));
    bool allNeg = (c1 < Fixed(0)) && (c2 < Fixed(0)) && (c3 < Fixed(0));
    return allPos || allNeg;
}

int main()
{
	Point a(Fixed(0),Fixed(0));
	Point b(Fixed(1.5f),Fixed(1.5f));
	Point c(Fixed(2.5f),Fixed(0));
	Point p(Fixed(1.3f), Fixed(1.2f));
	std::cout << bsp(a ,b ,c ,p)<< std::endl;
	return 0;
}
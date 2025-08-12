#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
class Fixed
{
	private:
	int value;
	static const int fractionalBits = 8;
	public:
	Fixed(int a);
	~Fixed();
	float toFloat(void) const;
	int toInt(void) const;
	 

};
std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif
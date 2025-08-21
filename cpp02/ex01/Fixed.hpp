#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>
class Fixed
{
	private:
	int value;
	static const int fractionalBits = 8;
	public:
	Fixed& operator=(const Fixed& a);
	Fixed(const Fixed& other);
	Fixed();
	Fixed(float a);
	Fixed(int a);
	~Fixed();
	float toFloat(void) const;
	int toInt(void) const;
	int getRawBits(void) const;
	void setRawBits(int const raw);
	 

};
std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif
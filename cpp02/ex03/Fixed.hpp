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
	Fixed(const Fixed& other);
	Fixed();
	Fixed(float a);
	Fixed(int a);
	~Fixed();
	float toFloat(void) const;
	int toInt(void) const;
	int getRawBits(void) const;
	void setRawBits(int const raw);
	Fixed& operator=(const Fixed& a);
	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);
	Fixed operator+(const Fixed& a) const;
    Fixed operator-(const Fixed& a) const;
    Fixed operator*(const Fixed& a) const;
    Fixed operator/(const Fixed& a) const;
	bool operator<(const Fixed&a) const;
	bool operator>(const Fixed& a) const;
	bool operator==(const Fixed& a) const;
	bool operator<=(const Fixed& a) const;
	bool operator>=(const Fixed& a) const;
	bool operator!=(const Fixed& a) const;
	static Fixed&       min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed&       max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);

	 

};
std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif
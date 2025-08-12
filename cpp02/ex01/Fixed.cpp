#include "Fixed.hpp"

Fixed::Fixed(int a)
{
    this->value = a;
}
Fixed::~Fixed()
{

}

int Fixed::toInt() const
{
    return value << fractionalBits;
}
float Fixed::toFloat() const
{
        return static_cast<float>(value) / (1 << fractionalBits);

}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
    os << obj.toFloat();
    return os;
}
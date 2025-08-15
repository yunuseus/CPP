#include "Fixed.hpp"
Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::Fixed(int a)
{
    std::cout << "Int constructor called" << std::endl;

    this->value = a << fractionalBits;
}
Fixed::Fixed(float a)
{
    std::cout << "Float constructor called" << std::endl;

    this->value = static_cast<int>(roundf(a * (1 << fractionalBits)));
}
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
    return this->value;
}
void Fixed::setRawBits(int a)
{
    this->value = a;
}

int Fixed::toInt() const
{
    return value >> fractionalBits;
}
float Fixed::toFloat() const
{
    return static_cast<float>(value) / (1 << fractionalBits);

}

Fixed Fixed::operator+(const Fixed& a) const
{
    Fixed r;
    r.setRawBits(this->getRawBits() + a.getRawBits());
    return r;
}
Fixed Fixed::operator-(const Fixed& a) const
{
    Fixed r;
    r.setRawBits(this->getRawBits() - a.getRawBits());
    return r;
}
Fixed& Fixed::operator=(const Fixed& a)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &a)
        this->value = a.getRawBits();
    return (*this);
}
Fixed& Fixed::operator++()
{
    this->value += (1 << fractionalBits);
    return *this;
}
Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    this->value += (1 << fractionalBits);
    return tmp;
}

Fixed& Fixed::operator--()
{
    this->value -= (1 << fractionalBits);
    return *this;
}
Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    this->value -= (1 << fractionalBits);
    return tmp;
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
    os << obj.toFloat();
    return os;
}
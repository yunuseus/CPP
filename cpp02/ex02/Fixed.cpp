#include "Fixed.hpp"
Fixed::Fixed()
{
    this->setRawBits(0);
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
void Fixed::setRawBits(int const raw)
{
    this->value = raw;
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
Fixed Fixed::operator*(const Fixed& a) const
{
   Fixed r;
    long long tmp = static_cast<long long>(this->getRawBits()) *
                    static_cast<long long>(a.getRawBits());
    r.setRawBits(static_cast<int>(tmp >> fractionalBits));
    return r;
}
Fixed Fixed::operator/(const Fixed& a) const
{
    Fixed r;
    long long num = static_cast<long long>(this->getRawBits()) << fractionalBits;
    r.setRawBits(static_cast<int>(num / static_cast<long long>(a.getRawBits())));
    return r;
}

Fixed& Fixed::operator++()
{
    ++this->value;
    return *this;
}
Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    ++this->value;
    return tmp;
}

Fixed& Fixed::operator--()
{
    --this->value;
    return *this;
}
Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    --this->value;
    return tmp;
}
bool Fixed::operator<(const Fixed& a) const
{
   return this->getRawBits() < a.getRawBits();
}

bool Fixed::operator>(const Fixed& a) const
{
   return this->getRawBits() > a.getRawBits();
}
bool Fixed::operator>=(const Fixed& a) const
{
   return this->getRawBits() >= a.getRawBits();
}
bool Fixed::operator<=(const Fixed& a) const
{
   return this->getRawBits() <= a.getRawBits();
}
bool Fixed::operator==(const Fixed& a) const
{
   return this->getRawBits() == a.getRawBits();
}
bool Fixed::operator!=(const Fixed& a) const
{
   return this->getRawBits() != a.getRawBits();
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
    os << obj.toFloat();
    return os;
}

Fixed& Fixed:: min(Fixed& a, Fixed& b)
{
    if (b < a)
        return b;
    else
        return a;
}

Fixed& Fixed:: max(Fixed& a, Fixed& b)
{
    if (b > a)
        return b;
    else
        return a;
}

const Fixed& Fixed:: min(const Fixed& a,  const Fixed& b)
{
    if (b < a)
        return b;
    else
        return a;
}
const Fixed& Fixed:: max(const Fixed& a, const Fixed& b)
{
    if (b > a)
        return b;
    else
        return a;
}
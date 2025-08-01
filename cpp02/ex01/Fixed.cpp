#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : value(0) {}

Fixed::Fixed(const int intValue) {
    value = intValue << fractionalBits;
}

Fixed::Fixed(const float floatValue) {
    value = roundf(floatValue * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed &other) : value(other.value) {}

Fixed &Fixed::operator=(const Fixed &other) {
    if (this != &other) {
        value = other.value;
    }
    return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits() const {
    return value;
}

void Fixed::setRawBits(int const raw) {
    value = raw;
}

float Fixed::toFloat() const {
    return static_cast<float>(value) / (1 << fractionalBits);
}


int Fixed::toInt() const {
    return value >> fractionalBits; 
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}

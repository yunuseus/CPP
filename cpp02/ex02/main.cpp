#include <iostream>
#include "Fixed.hpp"
int main( void ) 
{
Fixed a(10);
Fixed b(5);
std::cout << a << std::endl;
std::cout << a / b << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;


return 0;
}
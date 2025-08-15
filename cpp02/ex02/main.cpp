#include <iostream>
#include "Fixed.hpp"
int main( void ) 
{
Fixed a(3);
Fixed b(4);
std::cout << a << std::endl;
std::cout << a + b << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;


return 0;
}
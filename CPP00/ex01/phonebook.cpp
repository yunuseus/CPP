#include "phonebook.hpp"
#include <iostream>
#include <stdlib.h>

size_t ft_strlen(std:: string s1)
{
	size_t i = 0;
	while (s1[i] != '\0')
		i++;
	return i;
}

int	ft_strcmp(std:: string s1, std:: string s2, size_t n)
{
	size_t	i;
	char	*a;
	char	*b;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void selection(std:: string select)
{
	if (ft_strcmp(select, "ADD", ft_strlen(select)) == 0)
	{
		std:: cout << "add yapılıyor" << std:: endl;
	}
	if (ft_strcmp(select, "SEARCH", ft_strlen(select)) == 0)
	{
		std:: cout << "search yapılıyor" << std:: endl;
	}
	if (ft_strcmp(select, "EXIT", ft_strlen(select)) == 0)
	{
		std:: cout << "exit yapılıyor" << std:: endl;
	}
}

int main()
{
	PhoneBook book;
	Contact contacs;
	contacs.setter("yunus", 0);
	std:: string select;
	std:: cout << contacs.getter(0);
	while (1)
	{
	
		std:: cout << ""<< std::endl;
		std:: cin >> select;
		std:: cout << std:: endl;
		selection(select);
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 14:50:27 by yalp              #+#    #+#             */
/*   Updated: 2025/10/29 15:05:49 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
int main()
{
    try 
    {
        Bureaucrat a("yunus", 42);
        std::cout << a.getName() << ", bureaucrat grade " << a.getGrade() << std::endl;
    }
    catch (const std::exception& e) 
    {
        std::cout << e.what() << std::endl;
    }

}
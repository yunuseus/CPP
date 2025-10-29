/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 14:38:05 by yalp              #+#    #+#             */
/*   Updated: 2025/10/29 15:05:39 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("default"), grade(150){}

Bureaucrat::Bureaucrat(const std::string name, int grade): name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
}

Bureaucrat::~Bureaucrat(){}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

int Bureaucrat::getGrade()
{
    return this->grade;
}

std::string Bureaucrat::getName()
{
    return this->name;
}
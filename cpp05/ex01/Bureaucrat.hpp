/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 14:38:02 by yalp              #+#    #+#             */
/*   Updated: 2025/10/29 15:02:39 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Bureaucrat
{
    private:
    const std::string name;
    int grade;
    public:
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();
    std::string getName();
    int getGrade();
    class GradeTooHighException : public std::exception
    {
        public:
        virtual const char* what() const throw();
    };  
    class GradeTooLowException : public std::exception
    {
        public:
        virtual const char* what() const throw();
    };  
};

std::ostream& operator<<(std::ostream& os, Bureaucrat& bureaucrat);
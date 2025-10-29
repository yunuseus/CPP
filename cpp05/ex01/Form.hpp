/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 18:35:47 by yalp              #+#    #+#             */
/*   Updated: 2025/10/29 18:43:18 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

class Form
{
  private:
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;
    public:
    Form();
    Form(const std::string name, int gradeToSign, int gradeToExecute);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();
    const std::string getName() const;
    bool getIsSigned() const;   
    int getGradeToSign() const;
    int getGradeToExecute() const;
    void beSigned(Bureaucrat& b);
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
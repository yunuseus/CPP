#include "Form.hpp"

Form::Form() : _name("Default Form"), _isSigned(false), _signGrade(150), _execGrade(150) {}

Form::Form(const std::string& name, int signGrade, int execGrade)
    : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) {
    if (_signGrade < 1 || _execGrade < 1) {
        throw Form::GradeTooHighException();
    }
    if (_signGrade > 150 || _execGrade > 150) {
        throw Form::GradeTooLowException();
    }
}

Form::Form(const Form& src)
    : _name(src._name), _isSigned(src._isSigned), _signGrade(src._signGrade), _execGrade(src._execGrade) {}

Form& Form::operator=(const Form& rhs) {
    if (this != &rhs) {
        _isSigned = rhs._isSigned;
    }
    return *this;
}

Form::~Form() {}

const std::string& Form::getName() const {
    return _name;
}

bool Form::getIsSigned() const {
    return _isSigned;
}

int Form::getSignGrade() const {
    return _signGrade;
}

int Form::getExecGrade() const {
    return _execGrade;
}

void Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > _signGrade) {
        throw Form::GradeTooLowException();
    }
    _isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Form grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << "Form: " << f.getName() 
       << ", Signed: " << (f.getIsSigned() ? "Yes" : "No")
       << ", Required Sign Grade: " << f.getSignGrade()
       << ", Required Exec Grade: " << f.getExecGrade();
    return os;
}

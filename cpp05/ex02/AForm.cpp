#include "AForm.hpp"

AForm::AForm() : _name("Default AForm"), _isSigned(false), _signGrade(150), _execGrade(150) {}

AForm::AForm(const std::string& name, int signGrade, int execGrade)
    : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) {
    if (_signGrade < 1 || _execGrade < 1) {
        throw AForm::GradeTooHighException();
    }
    if (_signGrade > 150 || _execGrade > 150) {
        throw AForm::GradeTooLowException();
    }
}

AForm::AForm(const AForm& src)
    : _name(src._name), _isSigned(src._isSigned), _signGrade(src._signGrade), _execGrade(src._execGrade) {}

AForm& AForm::operator=(const AForm& rhs) {
    if (this != &rhs) {
        _isSigned = rhs._isSigned;
    }
    return *this;
}

AForm::~AForm() {}

const std::string& AForm::getName() const {
    return _name;
}

bool AForm::getIsSigned() const {
    return _isSigned;
}

int AForm::getSignGrade() const {
    return _signGrade;
}

int AForm::getExecGrade() const {
    return _execGrade;
}

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > _signGrade) {
        throw AForm::GradeTooLowException();
    }
    _isSigned = true;
}

void AForm::execute(Bureaucrat const & executor) const {
    if (!_isSigned) {
        throw AForm::FormNotSignedException();
    }
    if (executor.getGrade() > _execGrade) {
        throw AForm::GradeTooLowException();
    }
    executeAction();
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed!";
}

std::ostream& operator<<(std::ostream& os, const AForm& f) {
    os << "Form: " << f.getName() 
       << ", Signed: " << (f.getIsSigned() ? "Yes" : "No")
       << ", Required Sign Grade: " << f.getSignGrade()
       << ", Required Exec Grade: " << f.getExecGrade();
    return os;
}

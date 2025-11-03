#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"

AForm::AForm() : _name("Default"), _isSigned(false), _gradeSign(150), _gradeExec(150)
{
	std::cout << "Default constructor called" << std::endl;
}

AForm::AForm(const std::string &name, bool isSigned, const int gradeSign,
	const int gradeExec) : _name(name), _isSigned(isSigned),
	_gradeSign(gradeSign), _gradeExec(gradeExec)
{
	std::cout << "Constructor called" << std::endl;
}

AForm::AForm(const AForm &copy) : _name(copy._name), _isSigned(copy._isSigned),
	_gradeSign(copy._gradeSign), _gradeExec(copy._gradeExec)
{
}

AForm &AForm::operator=(const AForm &copy)
{
    if (this != &copy)
		_isSigned = copy._isSigned;
	return (*this);
}

AForm::~AForm()
{
	std::cout << "Destructor called" << std::endl;
}

std::string AForm::getName() const
{
	return (this->_name);
}

bool AForm::getSigned() const
{
	return (this->_isSigned);
}

int AForm::getGradeSign() const
{
	return (this->_gradeSign);
}

int AForm::getGradeExec() const
{
	return (this->_gradeExec);
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeSign)
        throw AForm::GradeTooLowException();
    _isSigned = true;
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
    // this changes 0->false or 1->true in the final result
    out << std::boolalpha;
	out << "AForm:\n" <<  "Name: " << form.getName() << "\nSigned: " << form.getSigned() << "\nGrade to sign: " << form.getGradeSign() << "\nGrade to execute: " << form.getGradeExec();
	return out;
}
#include "Bureaucrat.hpp"
#include "AForm.hpp"

// Forme canoniques
AForm::AForm() : _name("Default"), _is_signed(0), _grade_sign(150), _grade_execute(150) {}

AForm::AForm(const std::string& name, int grade_sign, int grade_execute) : _name(name), _is_signed(0) {
	if (grade_execute < 1 || grade_sign < 1)
		throw GradeTooHighException();
	else if (grade_execute > 150 || grade_sign > 150)
		throw GradeTooLowException();
	_grade_execute = grade_execute;
	_grade_sign = grade_sign;
	return ;
}

AForm::AForm(const AForm& other) : _name(other._name), _is_signed(other._is_signed), _grade_sign(other._grade_sign),  _grade_execute(other._grade_execute) {}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other)
	{
        _is_signed = other._is_signed;
		_grade_sign = other._grade_sign;
        _grade_execute = other._grade_execute;

	}
	return (*this);
}

AForm::~AForm() {}

// Getters
int AForm::getGradeSign() const {
	return (_grade_sign);
}

int AForm::getGradeExecute() const {
	return (_grade_execute);
}

bool AForm::getIsSigned() const {
	return (_is_signed);
}

std::string AForm::getName() const	{
	return (_name);
}

// Méthodes
void AForm::execute(Bureaucrat const & executor) const {
	if (!_is_signed)
		throw FormNotSignedException();
	if (executor.getGrade() > _grade_execute)
		throw GradeTooLowException();
	action();
}

void AForm::action() const {}

void AForm::beSigned(const Bureaucrat &bureaucrat)	{
    if (bureaucrat.getGrade() <= _grade_sign)
		_is_signed = true;
	else
		throw GradeTooLowException();
}

// Surcharge de l'opérateur <<
std::ostream &operator<<(std::ostream &os, AForm const &other) {
	os << other.getName() << ", grade to sign " << other.getGradeSign() << ", grade to execute " << other.getGradeExecute() << ", signed -> " << other.getIsSigned() << std::endl;
	return (os);
}

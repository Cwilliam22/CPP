#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form() : _name("Default"), _is_signed(0), _grade_sign(150), _grade_execute(150) {}

Form::Form(const std::string& name, int grade_execute, int grade_sign) : _name(name), _is_signed(0) {
	if (grade_execute < 1 || grade_sign < 1)
		throw GradeTooHighException();
	else if (grade_execute > 150 || grade_sign > 150)
		throw GradeTooLowException();
	_grade_execute = grade_execute;
	_grade_sign = grade_sign;
	return ;
}

Form::Form(const Form& other) : _name(other._name), _is_signed(other._is_signed), _grade_sign(other._grade_sign),  _grade_execute(other._grade_execute) {}

Form& Form::operator=(const Form& other) {
	if (this != &other)
	{
        _is_signed = other._is_signed;
		_grade_sign = other._grade_sign;
        _grade_execute = other._grade_execute;

	}
	return (*this);
}

Form::~Form() {}

std::string Form::getName() const	{
	return (_name);
}

void Form::beSigned(const Bureaucrat &bureaucrat)	{
    if (bureaucrat.getGrade() <= _grade_sign)
		_is_signed = true;
	else
		throw GradeTooLowException();
}

int Form::getGradeSign() const {
	return (_grade_sign);
}

int Form::getGradeExecute() const {
	return (_grade_execute);
}

bool Form::getIsSigned() const {
	return (_is_signed);
}

std::ostream &operator<<(std::ostream &os, Form const &other) {
	os << other.getName() << ", grade to sign " << other.getGradeSign() << ", grade to execute " << other.getGradeExecute() << ", signed -> " << other.getIsSigned() << std::endl;
	return (os);
}

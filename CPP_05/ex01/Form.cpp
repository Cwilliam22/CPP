#include "Bureaucrat.hpp"
#include "Form.hpp"

static int checkGrade(int grade) {
	if (grade < 1)
		throw Form::GradeTooHighException();
	else if (grade > 150)
		throw Form::GradeTooLowException();
	return (grade);
}

Form::Form() : _name("Default"), _is_signed(0), _grade_sign(150), _grade_execute(150) {}

Form::Form(const std::string& name, int grade_execute, int grade_sign) : _name(name), _is_signed(0), _grade_sign(checkGrade(grade_sign)), _grade_execute(checkGrade(grade_execute)) {}

Form::Form(const Form& other) : _name(other._name), _is_signed(other._is_signed), _grade_sign(other._grade_sign),  _grade_execute(other._grade_execute) {}

Form& Form::operator=(const Form& other) {
	if (this != &other)
        _is_signed = other._is_signed;
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

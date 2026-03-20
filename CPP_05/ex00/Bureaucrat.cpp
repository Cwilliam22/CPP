#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade)
{
	try
	{
		if (grade < 1)
			throw std::exception("GradeTooHighException");
		else if (grade > 150)
			throw std::exception("GradeTooLowException");
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		throw;
	}
	_name = name;
	_grade = grade;
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		_name = other._name;
		_grade = other._grade;
	}
	return (*this);
}

std::string Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
		throw std::runtime_error("GradeTooHighException");
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw std::runtime_error("GradeTooLowException");
	_grade++;
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

const char * Bureaucrat::InvalidNameException::what() const throw()
{
	return "Invalid name: Name must not be empty and must not contain digits.";
}


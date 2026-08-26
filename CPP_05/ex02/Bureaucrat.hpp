#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <algorithm>
#include <string>
#include <cctype>
#include <iostream>
#include <fstream>
#include <cmath>
#include <exception>

#include "Bureaucrat.hpp"

class Form;

class Bureaucrat
{
	private:
		std::string _name;
		int _grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		bool is_name(const std::string& name) const;
		void signForm(Form &form);

		std::string getName() const;
		int getGrade() const;

		void decrementGrade();
		void incrementGrade();

		// Class pour l'exception "grade > 150"
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw() {
					return ("Grade is too low!");
				}
		};

		// Class pour l'exception "grade < 1"
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw() {
					return ("Grade is too high!");
				}
		};

		// Class pour l'exception "invalid name"
		class InvalidNameException : public std::exception
		{
			public:
				const char* what() const throw() {
					return ("Invalid name: Name must not be empty and must not contain digits.");
				}
		};
		

};

std::ostream &operator<<(std::ostream & os, Bureaucrat const &other);

#endif
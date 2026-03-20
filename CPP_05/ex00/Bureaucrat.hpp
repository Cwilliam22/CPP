#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <algorithm>
#include <string>
#include <cctype>
#include <iostream>
#include <fstream>
#include <cmath>

class Bureaucrat
{
	private:
		std::string _name;
		int _grade;

	public:
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		virtual ~Bureaucrat();

		std::string getName() const;
		int getGrade() const;

		void decrementGrade();
		void incrementGrade();

		const char *GradeTooLowException::what() const throw();
		const char *InvalidNameException::what() const throw();

};

#endif
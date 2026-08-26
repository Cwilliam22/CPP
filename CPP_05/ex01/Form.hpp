#ifndef FORM_HPP
#define FORM_HPP

#include <algorithm>
#include <string>
#include <cctype>
#include <iostream>
#include <fstream>
#include <cmath>
#include <exception>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string _name;
        bool _is_signed;
		int _grade_sign;
    	int _grade_execute;

	public:
        Form();
		Form(const std::string& name, int grade_execute, int grade_sign);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		// Méthodes
		void beSigned(const Bureaucrat &bureaucrat);
		
		// Getters
        std::string getName() const;
		bool getIsSigned() const;
		int getGradeSign() const;
		int getGradeExecute() const;        

        // Class pour l'exception "grade > 150"
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw() {
					return "Grade is too low!";
				}
		};

		// Class pour l'exception "grade < 1"
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw() {
					return "Grade is too high!";
				}
		};

};

std::ostream &operator<<(std::ostream &os, Form const &other);

#endif 
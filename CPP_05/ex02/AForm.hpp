#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <cctype>
#include <iostream>
#include <exception>
#include <stdlib.h>
#include <fstream>

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
        bool _is_signed;
		int _grade_sign;
    	int _grade_execute;

	public:
        AForm();
		AForm(const std::string& name, int grade_sign, int grade_execute);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		// Méthodes
		void execute(Bureaucrat const & executor) const;
		virtual void action() const = 0;
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

		// Class pour l'exception "form not signed"
		class FormNotSignedException : public std::exception
		{
			public:
				const char* what() const throw() {
					return ("Form is not signed!");
				}
		};

};

std::ostream &operator<<(std::ostream &os, AForm const &other);

#endif 
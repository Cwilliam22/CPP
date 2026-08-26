#include "Bureaucrat.hpp"
#include "Form.hpp"

// output : <name>, bureaucrat grade <grade>
int main(void)
{
	std::cout << "\033[36m" << std::endl << "Test ex01" << "\033[0m" << std::endl;

	std::cout << "\033[36m" << std::endl << "Test too high and too low creation for Form" << "\033[0m" << std::endl;
	try
	{
		Form form_invalid1("form1", 1500, 1500);
	}
	catch(const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		Form form_invalid2("form2", -10, -10);
	}
	catch(const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\033[36m" << std::endl << "Test sign and Form with valid grades" << "\033[0m" << std::endl;
	Form form("Form", 150, 150);
	Bureaucrat bureaucrat1("William", 150);
	try
	{
		std::cout << form;
		std::cout << bureaucrat1;
		bureaucrat1.signForm(form);
	}
	catch(const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << form;
	std::cout << bureaucrat1;

	std::cout << "\033[36m" << std::endl << "Test sign Form with too low grade" << "\033[0m" << std::endl;
	Form form_copy1("Form", 150, 150);
	form = form_copy1;
	try
	{
		std::cout << form;
		std::cout << bureaucrat1;
		std::cout << "Incrementing Form's grades to sign and execute +1 " << std::endl;
		form.incrementGradeSign();
		form.incrementGradeExecute();
		bureaucrat1.signForm(form);
	}
	catch(const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << form;
	std::cout << bureaucrat1;

	std::cout << "\033[36m" << std::endl << "Test sign Form with too high grade" << "\033[0m" << std::endl;
	Form form_copy2("Form", 149, 149);
	form = form_copy2;
	try
	{
		std::cout << form;
		std::cout << bureaucrat1;
		std::cout << "Incrementing Bureaucrat's grade +2 " << std::endl;
		bureaucrat1.incrementGrade();
		bureaucrat1.incrementGrade();
		bureaucrat1.signForm(form);
	}
	catch(const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << form;
	std::cout << bureaucrat1;

	std::cout << "\033[36m" << std::endl << "Test sign Form with too low grade but after decrementing" << "\033[0m" << std::endl;
	Form form_copy3("Form", 149, 149);
	form = form_copy3;
	try
	{
		std::cout << form;
		std::cout << bureaucrat1;
		std::cout << "Decrementing Bureaucrat's grade -2 " << std::endl;
		bureaucrat1.decrementGrade();
		bureaucrat1.decrementGrade();
		bureaucrat1.signForm(form);
	}
	catch(const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << form;
	std::cout << bureaucrat1;

	return (0);
}
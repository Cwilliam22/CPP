#include "Bureaucrat.hpp"

// output : <name>, bureaucrat grade <grade>
int main(void)
{
	std::cout << "\033[36m" << std::endl << "Test ex00" << "\033[0m" << std::endl;

	std::cout << "\033[36m" << std::endl << "Test too high and too low creation" << "\033[0m" << std::endl;
	try
	{
		Bureaucrat Sleeper1("William", 1500);
	}
	catch(const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat Sleeper2("Willsko", -10);
	}
	catch(const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\033[36m" << std::endl << "Test increasing" << "\033[0m" << std::endl;
	Bureaucrat Gaspard("Gaspard", 2);
	std::cout << Gaspard;
	try
	{
		Gaspard.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << Gaspard;
	
	try
	{
		Gaspard.incrementGrade();
	}
	catch(const std::exception& e)
	{
	std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << Gaspard;



	std::cout << "\033[36m" << std::endl << "Test decreasing" << "\033[0m" << std::endl;
	Bureaucrat Yosko("Yosko", 149);
	std::cout << Yosko;
	try
	{
		Yosko.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << Yosko;
	
	try
	{
	Yosko.decrementGrade();
	}
	catch(const std::exception& e)
	{
	std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << Yosko;
	
	return (0);
}
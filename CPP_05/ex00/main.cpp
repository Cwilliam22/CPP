#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat a("Jean", 150);
	// output : <name>, bureaucrat grade <grade>
	std::cout << a.getName() << ", bureaucrat grade " << a.getGrade() << std::endl;
	return (0);
}
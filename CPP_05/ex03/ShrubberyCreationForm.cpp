#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Default Target") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::action() const {
    std::ofstream outfile((_target + std::string("_shrubbery")).c_str());
    if (outfile.is_open())
    {
        outfile << "      *          " << std::endl;
        outfile << "     /.\\        " << std::endl;
        outfile << "    /..'\\       " << std::endl;
        outfile << "    /'.'\\       " << std::endl;
        outfile << "   /.''.'\\      " << std::endl;
        outfile << "   /.'.'.\\      " << std::endl;
        outfile << "  /'.''.'.\\     " << std::endl;
        outfile << "  ^^^[_]^^^      " << std::endl;

        outfile.close();
    }
    else 
        throw ShrubberyCreationForm::OpenTargetFileException();
}

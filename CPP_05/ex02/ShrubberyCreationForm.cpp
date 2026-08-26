#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target)
{
    *this = other;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
    if ()
    {
        /*
        # #### ####
      ### \/#|### |/####
     ##\/#/ \||/##/_/##/_#
   ###  \/###|/ \/ # ###
 ##_\_#\_\## | #/###_/_####
## #### # \ #| /  #### ##/##
 __#_--###`  |{,###---###-~
           \ }{
            }}{
            }}{
       ejm  {{}
      , -=-~{ .-^- _
            `}
             {
*/
    }
    else 
        throw ShrubberyCreationForm::OpenTargetFFileException();
}


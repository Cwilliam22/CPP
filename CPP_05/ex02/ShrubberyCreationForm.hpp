#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target; // nom du fichier de sortie pour le dessin de l'arbre

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), _target(target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

		class OpenTargetFFileException : public std::exception
		{
			public:
				const char* what() const throw() {
					return ("Could not open and write the file!");
				}
		};

		
		void execute(Bureaucrat const &executor) const;
};

#endif
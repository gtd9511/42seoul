#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm(target, SIGN, EXEC)
{
    std::cout << "ShrubberyCreationForm has been created.\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy.getName(), SIGN, EXEC)
{
    std::cout << "ShrubberyCreationForm " << copy.getName() << " constructor has been called.\n";
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
    std::cout << "(cannot change form's name)\n" ;
    this->setRequiredGradeSign(copy.getRequiredGradeSign());
    this->setRequiredGradeExecute(copy.getRequiredGradeExecute());
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor has been called.\n";
}
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
        AForm::check(executor);
        
        std::string filename = this->getName() + "_shrubbery";
        std::ofstream file(filename.c_str());
        if (!file.is_open()) {
                std::cerr << "Error: could not create file " << filename << std::endl;
                return;
        }
                file << " _____   _                             ___  _____  _____                      _ \n"
                "|_   _| | |                           /   |/ __  \\/  ___|                    | |\n"
                "  | |   | |      ___  __   __  ___   / /| |`' / /'\\ `--.   ___   ___   _   _ | |\n"
                "  | |   | |     / _ \\ \\ \\ / / / _ \\ / /_| |  / /   `--. \\ / _ \\ / _ \\ | | | || |\n"
                " _| |_  | |____| (_) | \\ V / |  __/ \\___  |./ /___/\\__/ /|  __/| (_) || |_| || |\n"
                " \\___/  \\_____/ \\___/   \\_/   \\___|     |_/\\_____/\\____/  \\___| \\___/  \\__,_||_|\n";

                



        file.close();
}
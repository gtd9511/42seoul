#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    /*
    
    Bureaucrat b1 = Bureaucrat("seongmik", 1);
    Bureaucrat b2 = Bureaucrat("ebang", 150);
    PresidentialPardonForm fp1 = PresidentialPardonForm("home");
    RobotomyRequestForm fr1 = RobotomyRequestForm("home");
    ShrubberyCreationForm fs1 = ShrubberyCreationForm("home");

    */

    {
        std::cout << "\nTest 1 : should execute PresidentialPardonForm.\n";
        Bureaucrat b1 = Bureaucrat("seongmik", 1);
        
        PresidentialPardonForm fp1 = PresidentialPardonForm("home");
        
        
        try{
            b1.signForm(fp1);
            b1.executeForm(fp1);
        }
        catch(std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    
    {
        std::cout << "\nTest 2 : should \"not\" execute PresidentialPardonForm.(notSigned)\n";
        Bureaucrat b1 = Bureaucrat("seongmik", 1);
        
        PresidentialPardonForm fp1 = PresidentialPardonForm("home");
        
        try {
            b1.executeForm(fp1);
        }
        catch(std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }

    {
        std::cout << "\nTest 3 : should \"not\" execute PresidentialPardonForm.(exec)\n";
        Bureaucrat b1 = Bureaucrat("seongmik", 1);
        Bureaucrat b2 = Bureaucrat("ebang", 150);
        PresidentialPardonForm fp1 = PresidentialPardonForm("home");
        
        try{
            b1.signForm(fp1);
            b2.executeForm(fp1);
        } catch(std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }

    }


    
    std::cout << "\nTest 4 : should  execute RobotomyRequestForm..()\n";
    try 
    {
        Bureaucrat b1 = Bureaucrat("seongmik", 1);
        RobotomyRequestForm fr1 = RobotomyRequestForm("home");
    
        b1.signForm(fr1);
        b1.executeForm(fr1);
    }
    catch(std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }


    try
    {
        std::cout << "\nTest 5 : should \"not\" execute RobotomyRequestForm..(notSigned)\n";
        Bureaucrat b1 = Bureaucrat("seongmik", 1);
        RobotomyRequestForm fr1 = RobotomyRequestForm("home");

        b1.executeForm(fr1);
    }
    catch(std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    {
        
        std::cout << "\nTest 6 : should \"not\" execute RobotomyRequestForm..(exec)\n";
        try 
        {
            Bureaucrat b1 = Bureaucrat("seongmik", 1);
            Bureaucrat b2 = Bureaucrat("ebang", 150);
            
            RobotomyRequestForm fr1 = RobotomyRequestForm("home");
            b1.signForm(fr1);
            b2.executeForm(fr1);
        }
        catch(std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }


    {
        std::cout << "\nTest 7 : should  execute ShrubberyCreationForm\n";
        try
        {
            Bureaucrat b1 = Bureaucrat("seongmik", 1);
            ShrubberyCreationForm fs1 = ShrubberyCreationForm("home");
            b1.signForm(fs1);
            b1.executeForm(fs1);
        }
        catch(std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }

    {
        std::cout << "\nTest 8 : should \"not\" execute ShrubberyCreationForm(notSigned)\n";
        try 
        {
            Bureaucrat b1 = Bureaucrat("seongmik", 1);
            ShrubberyCreationForm fs1 = ShrubberyCreationForm("home");
            b1.executeForm(fs1);
        }
        catch(std::exception &e)
        {   
            std::cerr << e.what() << std::endl;
        }
    }

    {
        
        std::cout << "\nTest 9 : should \"not\" execute ShrubberyCreationForm(exec)\n";
        try
        {
            Bureaucrat b2 = Bureaucrat("ebang", 150);
            ShrubberyCreationForm fs1 = ShrubberyCreationForm("home");
            b2.signForm(fs1);
            b2.executeForm(fs1);
        }
        catch(std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }

    {
        std::cout << "\nTest 10 : Forms copy constructor\n";
        try 
        {
            PresidentialPardonForm fp1 = PresidentialPardonForm("home");
            RobotomyRequestForm fr1 = RobotomyRequestForm("home");
            ShrubberyCreationForm fs1 = ShrubberyCreationForm("home");
            PresidentialPardonForm tempp(fp1);
            std::cout << tempp << std::endl;
        
            RobotomyRequestForm tempr(fr1);
            std::cout << tempr << std::endl;
            
            ShrubberyCreationForm temps(fs1);
            std::cout << temps << "\n";
        }
        catch(std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    



    {

        std::cout << "\nTest 11 : Forms copy operator\n";
        PresidentialPardonForm fp1 = PresidentialPardonForm("home");
        RobotomyRequestForm fr1 = RobotomyRequestForm("home");
        ShrubberyCreationForm fs1 = ShrubberyCreationForm("home");
        ShrubberyCreationForm temp("temp");
        std::cout << temp << "\n";
        temp = fs1;
        std::cout << temp << "\n";
    }

}
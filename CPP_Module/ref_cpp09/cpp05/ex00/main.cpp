#include "Bureaucrat.hpp"

int main()
{
    //예외 케이스 : too high
    std::cout << "Test 1 : has to throw GradeTooHighException" << std::endl;
    try
    {
        Bureaucrat b1 = Bureaucrat("ebang1" , 0);
    }
    catch(std::exception &e)
    {
        std::cerr << e.what();
    }

    std::cout << "\n\nTest 2 : has to throw GradeTooLowException" << std::endl;
    try
    {
        Bureaucrat b2 = Bureaucrat("ebang2" , 151);
    }
     catch(std::exception &e)
    {
        std::cerr << e.what();
    }


    std::cout << "\n\nTest 3 : has to throw GradeTooHighException" << std::endl;
    try
    {
        Bureaucrat b3 = Bureaucrat("ebang3" , 1);
        b3.incrementGrade();
        std::cout << b3;
    }
     catch(std::exception &e)
    {
        std::cerr << e.what();
    }
    

    std::cout << "\n\nTest 4 : has to throw GradeTooLowException" << std::endl;
    try 
    {
        Bureaucrat b4 = Bureaucrat("ebang4" , 150);
        b4.decrementGrade();
        std::cout << b4;
    }
    catch(std::exception &e){
        std::cerr << e.what();
    }


    std::cout << "\n\nTest 5: Normal case" << std::endl;
    try {
        Bureaucrat b5 = Bureaucrat("ebang5" , 25);
        std::cout << b5;
        b5.decrementGrade();
        std::cout << "\nafter decrementGrade: ";
        std::cout << b5;
        b5.incrementGrade();
        std::cout << "\nafter incrementGrade: ";
        std::cout << b5;
        std::cout << "\nafter using copy constructor \n";
        Bureaucrat c1(b5);
        std::cout << c1;
        std::cout << "\nafter using copy operator \n";
        c1 = b5;
        std::cout << c1;}
    catch(std::exception &e)
    {
        std::cerr << e.what();
    }
}
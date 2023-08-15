#include "Bureaucrat.hpp"

int main()
{
    std::cout << "Test1 : should throw Grade too High exception.\n";
    
    try{
        Form f1 = Form("Form1", 0, 3);
    }
    catch(std::exception &e)
    {
        std::cerr << e.what();
        
    }

    std::cout << "\nTest2 : should throw Grade too High exception.\n";
    try{
            Form f2 = Form("Form2", 3, 0);
    }
     catch(std::exception &e)
    {
        std::cerr << e.what();
    }

    std::cout << "\nTest3 : should throw Grade too Low exception.\n";
    try {
        Form f3 = Form("Form3", 151, 3);
    }
     catch(std::exception &e)
    {
        std::cerr << e.what();
    }

    std::cout << "\nTest4 : should throw Grade too Low exception.\n";
    try {
        Form f4 = Form("Form4", 3, 151);
    }
     catch(std::exception &e)
    {
        std::cerr << e.what();
    }

    std::cout << "\n\nTest5 : should throw Grade too High exception.\n";
    try
    {
        Form f5 = Form("Form5", 50, 3);
        Bureaucrat b1 = Bureaucrat("ebang1", 51);
        b1.signForm(f5);
    }
     catch(std::exception &e)
    {
        std::cerr << e.what();
    }

    std::cout << "\n\nTest6 : Normal case - Form getters, copy constructor\n";
    try 
    {
        Form f1 = Form("Form1", 3, 50);
        std::cout << f1.getName() << " " << f1.getIfSigned() << " " << f1.getRequiredGradeExecute() << " "  << f1.getRequiredGradeSign() << std::endl;
        Form f6(f1);
        std::cout << f6;
    }
     catch(std::exception &e)
    {
        std::cerr << e.what() ;
    }

    std::cout << "\n\nTest7 : Normal case - Form copy operator\n";
    try 
    {
        Form f1 = Form("Form1", 3, 50);
        Form f7("Form7", 100, 100);
        f7 = f1;
        std::cout << f7;
    }
    catch(std::exception &e)
    {
        std::cerr << e.what() ;
    }
}
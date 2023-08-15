#include "Intern.hpp"
#include "Bureaucrat.hpp"

void check()
{
    system("leaks Intern");
}

int main()
{
    Intern i1 = Intern();
    Bureaucrat b1 = Bureaucrat("ebang", 1);
    AForm *f;

    std::cout << "\nTest1 : intern should make presidential pardon test.\n";
    try
    {
        f = NULL;
        f = i1.makeForm("presidential pardon", "target1");
        b1.signForm(*f);
        b1.executeForm(*f);
        delete f;
    }
    catch(std::exception &e)
    {
        std::cerr<< e.what() << std::endl;
        if(!f)
            delete f;
    }

    std::cout << "\nTest2 : intern should make Robotomy Request test.\n";
    try {
        f = NULL;
        f = i1.makeForm("robotomy request", "target2");
        b1.signForm(*f);
        b1.executeForm(*f);
        delete f;
    }
    catch(std::exception &e)
    {
        std::cerr<< e.what() << std::endl;
        if(!f)
            delete f;

    }

    std::cout << "\nTest3 : intern should make Shruberry Creation test.\n";
    try {
        f = NULL;
        f = i1.makeForm("shruberry creation", "target2");
        b1.signForm(*f);
        b1.executeForm(*f);
        delete f;
    }
    catch(std::exception &e)
    {
        std::cerr<< e.what() << std::endl;
        if(!f)
            delete f;
    }

     std::cout << "\nTest4 : intern should fail to make form.\n";
    try {
        f = NULL;
        f = i1.makeForm("shruberry creatio", "target2");
        b1.signForm(*f);
        b1.executeForm(*f);
        delete f;
    }
    catch(std::exception &e)
    {
        std::cerr<< e.what() << std::endl;
        if(!f)
            delete f;
    }
    atexit(check);
}
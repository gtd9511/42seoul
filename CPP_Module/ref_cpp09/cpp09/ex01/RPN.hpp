#pragma once
#ifndef RPN_HPP
# define RPN_HPP
#include <iostream>
#include <string>
#include <stack>

class RPN
{
private:
        RPN();
        RPN(const RPN& copy);
        RPN& operator=(const RPN& copy);
        ~RPN();
        /* data */
public:
    static long long parseAndCalculate(int count, char **str);
    static bool isoperand(char c);

    
    class DividedByZero: public std::exception{
        virtual const char *what(void) const throw();
    };
        class ExpressionFailure: public std::exception{
        virtual const char *what(void) const throw();
    };

};

#endif // RPN_HPP
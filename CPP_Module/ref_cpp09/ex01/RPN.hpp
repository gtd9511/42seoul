#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <stack>
#include <algorithm>
#include <sstream>

#define SET_W  30

class RPN {
    private:
        std::string _argv;
        std::stack<double> _rpn;
        std::stack<std::string> _splitString;
        int countNumbers;

        RPN();
        void split();
        void validateInput(std::string s);
        bool isOperator(char op);
        void calculate();
        double calculator(double a, double b, char op);
    public:

        RPN(char *argv);
        RPN(const RPN& ref);
        RPN&	operator=(const RPN&);
        ~RPN();

        void ReversePolishNotation();

        class Error : public std::exception {
        public:
            const char* what() const throw();
        };
};


#endif
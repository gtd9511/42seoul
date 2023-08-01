#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(char *argv) {
  this->_argv = argv;
}

RPN::RPN(const RPN& origin) {
  *this = origin;
}


RPN& RPN::operator=(const RPN& origin) {
  if (this != &origin) {
    this->_argv = origin._argv;
    this->_splitString = origin._splitString;
    this->_rpn = origin._rpn;
  }
  return *this;
}

RPN::~RPN() {}

void RPN::ReversePolishNotation() 
{
    try 
    {
        split();
        calculate();
    } 
    catch (std::exception& e) 
    {
        std::cerr << e.what() << std::endl;
    }
}

void RPN::split() 
{
    std::istringstream ss(this->_argv);
    std::string stringBuffer;
    std::stack<std::string> tmp;
    while (std::getline(ss, stringBuffer, ' ')) 
    {
        if (stringBuffer.empty()) 
            continue;
        tmp.push(stringBuffer);
    }
    this->countNumbers = 0;
    while (!tmp.empty()) 
    {
        this->_splitString.push(tmp.top());
        validateInput(tmp.top());
        tmp.pop();
    }
    if (2 * this->countNumbers - this->_splitString.size() != 1) 
        throw RPN::Error();
}

void RPN::validateInput(std::string s) {
    if (s.length() == 1 && (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/'))
        return ;
    char *ptr = NULL;
    double value = std::strtod(s.c_str(), &ptr);
    if (value == 0.0 && !std::isdigit(s[0])) 
        throw RPN::Error();
    if (*ptr && std::strcmp(ptr, "f")) 
        throw RPN::Error();
    if (value < 0 || value >= 10) 
        throw RPN::Error();
    ++this->countNumbers;
}

bool RPN::isOperator(char op) 
{
  return (op == '+' || op == '-' || op == '*' || op == '/');
}

double RPN::calculator(double a, double b, char op) 
{
    if (op == '+') return (a + b);
    if (op == '-') return (a - b);
    if (op == '*') return (a * b);
    if (b == 0) 
        throw RPN::Error();
    return (a / b);
}

void RPN::calculate() 
{
    while (!this->_splitString.empty()) 
    {
        std::string tmp = this->_splitString.top();
        if (isOperator(tmp[0])) 
        {
            if (this->_rpn.size() < 2) 
                throw RPN::Error();
            double a, b;
            b = this->_rpn.top();
            this->_rpn.pop();
            a = this->_rpn.top();
            this->_rpn.pop();
            this->_rpn.push(this->calculator(a, b, tmp[0]));
            this->_splitString.pop();
        }
        else 
        {
            double value = std::strtod(this->_splitString.top().c_str(), NULL);
            this->_rpn.push(value);
            this->_splitString.pop();
        }
    }
    std::cout << this->_rpn.top() << std::endl;
}

const char* RPN::Error::what() const throw() 
{
  return "Error";
}

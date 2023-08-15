#include "RPN.hpp"

bool RPN::isoperand(char c){
    return c == '+' || c == '-' || c == '/' || c =='*';
}

long long RPN::parseAndCalculate(int count, char **str){
    std::string expression;
    std::stack<long long> stack;
   for(int i = 1; i < count; i++){
        expression = str[i];
        for(unsigned int j = 0; j < expression.length(); j++)
        {
            char token = expression[j];
            long long x = 0;
            if (token == ' ')
                continue;
            if('0' <= token && token <= '9'){
                x = token - '0';
            }
            else if(isoperand(token)){
                if (stack.empty() == true)
                    throw ExpressionFailure();
                long long num1 = stack.top();
                stack.pop();
                if (stack.empty() == true)
                    throw ExpressionFailure();
                long long num2 = stack.top();
                stack.pop();
                switch(token){
                    case '+' : 
                        x = num2 + num1;
                        break;            
                    case '-' :
                        x = num2 - num1;
                        break;
                    case '*' : 
                        x =  num2 * num1;
                        break;
                    case '/':
                        if(num1 == 0)
                            throw DividedByZero();
                        x = num2 / num1;
                        break;
                }
            }   
            else {
                std::cout << token << " : ";
                throw ExpressionFailure();
            }
            stack.push(x);
        }
   }
   if(stack.empty()){
        std::cout << "2\n";
        throw ExpressionFailure();
    }
    long long ret =  stack.top();
    stack.pop();
   if(stack.empty() == false){
        throw ExpressionFailure();
   }
    return ret;
}

const char *RPN::DividedByZero::what() const throw ()
{
    return "cannot divided by zero.\n";
}

const char *RPN::ExpressionFailure::what() const throw ()
{
    return "wrong Expression.\n";
}
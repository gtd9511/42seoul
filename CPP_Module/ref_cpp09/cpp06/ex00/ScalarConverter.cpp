#include "ScalarConverter.hpp"
bool ScalarConverter::isnum = true;
bool ScalarConverter::f_print_flag= true;
bool ScalarConverter::isSpecial = false;
bool ScalarConverter::isFloat =  false;
bool ScalarConverter::isError =  false;

ScalarConverter::ScalarConverter() 
{}

ScalarConverter::ScalarConverter(const ScalarConverter& copy)
{
    isnum = copy.isnum;
    this->f_print_flag = copy.f_print_flag;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy)
{
    if(this != &copy){
        this->f_print_flag = copy.f_print_flag;
    }
    return *this;
}

ScalarConverter::~ScalarConverter()
{}

void ScalarConverter::convert(std::string str){
    isnum = true;
    isSpecial = false;
    if(str == "nan" || str == "inf" || str == "-inf")
        isSpecial = true;
    for(unsigned int i = 0; i < str.length(); i++)
    {
        if (!isdigit(str[i]) && str[i] != '.')//정수형 아님
            isnum = false;
        if(str[i] == 'f')//문자, 소수점, 오류 가능성
        {
            if (i == str.length() - 1 && str.length() != 1)//소수점임
                isFloat = true;
            else if(str.length() != 1)
                isError = true;                
        }
       else if(isprint(str[i]))
        {
            if(!isnum && !isFloat && !isSpecial && str.length() != 1)
                isError = true;
        }
    }

    print_char(str);
    print_int(str);
    print_float(str);
    print_double(str);
}

void ScalarConverter::print_char(std::string str){

    std::cout << "char: ";
    if(isSpecial == true || isError == true)
    {
        std::cout << "impossible.\n";
        return;
    }

    if(str.length() == 1){
        char c = str[0];
        if('0' <= c && c <= '9')
            c -= '0';
        if(c > std::numeric_limits<char>::max() || c < std::numeric_limits<char>::min())
            std::cout << "impossible\n";
        else if(isprint(c) == false)
            std::cout << "Non displayable\n";
        else
            std::cout << "\'" << c << "\'\n";

    }
    else {
        double d = strtod(str.c_str(), NULL);
        char c = static_cast<char>(d);
        if(c > std::numeric_limits<char>::max() || c < std::numeric_limits<char>::min())
            std::cout << "impossible\n";
        else if(isprint(c) == false)
            std::cout << "Non displayable\n";
        else
            std::cout << "\'" << c << "\'\n";
    }
}

void ScalarConverter::print_int(std::string str){
    
    std::cout << "int: ";
    if (!isnum && !isSpecial && !isFloat && !isError)
    {
        if (str.length() == 1)
            std::cout << static_cast<int>(str[0])  << "\n";
        else
            std::cout << "impossible2\n";
    }
    else {
        char *endPtr;
        double d = strtod(str.c_str(), &endPtr);
        int i = static_cast<int>(d);
        if(isSpecial || isError)
            std::cout << "impossible\n";
        else if (i > std::numeric_limits<int>::max() || i < std::numeric_limits<int>::min())
            std::cout << "impossible\n";
        else
            std::cout << i << "\n";
    }
}

void ScalarConverter::print_float(std::string str){
    
    std::cout << "float: ";
     if(isnum == false){
        if(str.length() == 1)//문자 한개 출력
        {
            double d = static_cast<double>(str[0]);
            std::cout << d << ".0f\n";
            return;
        }
    }
    char *endPtr;
    long double d = strtod(str.c_str(), &endPtr);
    float f = static_cast<float>(d);

    if(isSpecial)
        f_print_flag = 0;
    if (((f > std::numeric_limits<float>::max() || f < std::numeric_limits<float>::min()) && f != 0 && isSpecial == false) || isError)
        std::cout << "impossible\n";
    else {
        std::setprecision(16);
        std::cout << f;
        if(isSpecial)
            std::cout << "f\n";
        else
            std::cout << ".0f\n";
    }
    //출력문
    
}

void ScalarConverter::print_double(std::string str){
    
    std::cout <<"double: ";
    int f_print_flag = 1;
    char *endPtr;

    if(!isnum && !isFloat && !isSpecial){
        if(str.length() == 1)
        {
            double d = static_cast<double>(str[0]);
            std::cout << d << ".0\n";
        }   
        else
            std::cout << "impossible\n";
    }
    else{
        long double d = strtod(str.c_str(), &endPtr);
        if(isSpecial)
            f_print_flag = 0;
        if ((d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min() || isError) && !isSpecial)
        {
            std::cout << "impossible";
            return;
        }
        else {
            std::setprecision(16);
            std::cout << d;
        }
        if(f_print_flag)
                std::cout << ".0";
        std::cout << "\n";
    }
}
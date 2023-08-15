#pragma once
#ifndef ScalarConverter_HPP
# define ScalarConverter_HPP
# define NONDISPLAYABLE 0
# define IMPOSSIBLE 1
#include <iostream>
#include <limits>
#include <iomanip>
#include <cmath>
#include <string>

class ScalarConverter
{
private:
        static bool isnum;
        static bool f_print_flag;
        static bool isSpecial;
        static bool isFloat;
        static bool isError;
public:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& copy);
        ScalarConverter& operator=(const ScalarConverter& copy);
        ~ScalarConverter();

        static void convert(std::string str);

        static void print_char(std::string str);
        static void print_int(std::string str);
        static void print_float(std::string str);
        static void print_double(std::string str);
};

#endif // ScalarConverter_HPP
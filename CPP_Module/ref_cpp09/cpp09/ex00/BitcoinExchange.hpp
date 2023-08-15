#pragma once
#ifndef BitcoinExchange_HPP
# define BitcoinExchange_HPP
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <cstdlib>

typedef std::map<std::string, std::string> DataForm;
class BitcoinExchange 
{
private:
        enum error{
                TOOEARLY =0 ,
                BADINPUT = 1,
                VALID = 5
        };
        static DataForm Data;
        static DataForm inputData;
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& copy);
        BitcoinExchange& operator=(const BitcoinExchange& copy);
        ~BitcoinExchange();
public:
        // static bool cmp(std::map<std::string, std::string> a, std::map<std::string, std::string> b);
        static void dateValidate(std::string strDate);
        static void MonthInvalidDateCheck(long long year, long long month, long long date);
        static void valueValidate(std::string value);
        static void loadData();
        static void checkData();
        static std::pair<std::string, std::string> parseOneLine(std::string str, std::string delimeter);
        static void ParseAndSaveDatabase(DataForm &data, std::string filename, std::string delimeter);
        static void parseInputDataAndPrintOutput(std::string filename);
        static double loadExchangeRateResult(std::string value, DataForm::iterator data);

        class DataLoadFailure: public std::exception{
                virtual const char *what(void) const throw();
        };
        class InputDataLoadFailure: public std::exception{
                virtual const char *what(void) const throw();
        };
        class InvalidDateFailure: public std::exception{
                virtual const char *what(void) const throw();
        };
        class InvalidValueFailure: public std::exception{
                virtual const char *what(void) const throw();
        };
        class InvalidValueNotPositive: public std::exception{
                virtual const char *what(void) const throw();
        };
        class InvalidDateTooEarly: public std::exception{
                virtual const char *what(void) const throw();
        };
        class InvalidValueTooLarge: public std::exception{
                virtual const char *what(void) const throw();
        };
        class InvalidInputFailure: public std::exception{
                virtual const char *what(void) const throw();
        };
};

#endif // BitcoinExchange_HPP
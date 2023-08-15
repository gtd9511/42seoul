#include "BitcoinExchange.hpp"
DataForm BitcoinExchange::Data = DataForm();
DataForm BitcoinExchange::inputData = DataForm();

void BitcoinExchange::dateValidate(std::string strDate){
    long long  year, month, date;

    if(strDate[4] != '-' || strDate[7] != '-'){
        throw InvalidDateFailure();
    }
    long long integer;
    std::string::iterator it = strDate.begin();
    while(it != strDate.end()){
        integer = 0;
        while(*(it) != '-' && it != strDate.end())
        {
            if(!isdigit(*it))
                throw InvalidDateFailure();
            integer = integer * 10 + *it - '0';
            it++;
        }
        year = integer;
        integer = 0;
        it++;
        while(*(it) != '-' && it != strDate.end())
        {
            if(!isdigit(*it))
                throw InvalidDateFailure();
            integer = integer * 10 + *it - '0';
            it++;
        }
        month = integer;
        integer = 0;
        it++;
        while(it != strDate.end()){
            if(!isdigit(*it))
                throw InvalidDateFailure();
            integer = integer * 10 + *it - '0';
            it++;
        }
        date = integer;
    }
    if(1900 > year || year > 2023 || month > 12 || month < 1)
        throw InvalidDateFailure();
    
    MonthInvalidDateCheck(year, month, date);
    return ;
}


std::pair<std::string, std::string> BitcoinExchange::parseOneLine(std::string str, std::string delimeter){
    std::pair<std::string, std::string> temp;
    char date[128]; 
    char value[128];
    int whiteSpaceNum = 0;

    size_t pos = str.find(delimeter, 0);
    if(pos != std::string::npos)
    {
        //date parser
        for(whiteSpaceNum = 0; (0 <= (pos - whiteSpaceNum - 1) && (pos - whiteSpaceNum -1) < str.size()) && str[pos - whiteSpaceNum -1] == ' '; whiteSpaceNum++);
        str.copy(date, pos - whiteSpaceNum, 0);
        date[pos- whiteSpaceNum] = '\0';
        std::string strDate = date;
        //value parser
        for(whiteSpaceNum = 0; (0 <= (pos + whiteSpaceNum + 1) && (pos + whiteSpaceNum + 1) < str.size()) && str[pos + whiteSpaceNum + 1] == ' '; whiteSpaceNum++);
        str.copy(value, str.size() - pos - 1 - whiteSpaceNum , pos + whiteSpaceNum + 1);
        value[str.size() - pos - 1 - whiteSpaceNum] = '\0';
        std::string strValue = value;
        temp.first = strDate;
        temp.second = strValue;
        return temp;
    }
    else{
        throw InvalidInputFailure();
    }
}

void BitcoinExchange::ParseAndSaveDatabase(DataForm &data, std::string filename, std::string delimeter){
    std::ifstream database;
    std::string str;
    std::pair<std::string, std::string> temp;        

    bool firstLine = true;
    database.open(filename);
    if(database.rdstate())
        throw DataLoadFailure();
    while(database.eof() == false){
        std::getline(database, str, '\n');
        if(database.eof())
            break;
        //첫째줄은 넘긴다.
        if(firstLine) {
            firstLine = false; continue;
        }
        try {
            temp = parseOneLine(str, delimeter);
            data.insert(std::make_pair(temp.first, temp.second));
        }
        catch(std::exception &e){
            continue;
        }
    }
    database.close();
}

void BitcoinExchange::loadData(){
    std::cout << "***start loading data....***\n";
    try
    {
        ParseAndSaveDatabase(Data, "data.csv", ",");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        throw e;
    }
    std::cout << "***finish loading data....***\n";
}

void BitcoinExchange::checkData(){
    DataForm::iterator it;
    for(it = inputData.begin(); it != inputData.end(); it++){
        std::cout << it->first << " " << it->second << "\n";
    }
}


void  BitcoinExchange::MonthInvalidDateCheck(long long  year, long long month, long long date){
    switch(month){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if(date > 31)
                throw InvalidDateFailure();
            break;
        case 2:
            if (year % 400 == 0){
                if (date > 29)
                    throw InvalidDateFailure();
            }
            else if(year % 100 == 0){
                if(date > 28)
                    throw InvalidDateFailure();
            }
            else if(year % 4 == 0){
                if(date > 29)
                    throw InvalidDateFailure();
            }
            else{
                if(date > 28)
                    throw InvalidDateFailure();
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if(date < 0 || date > 30)
                throw InvalidDateFailure();
            break;
    }
    return;
}

void BitcoinExchange::parseInputDataAndPrintOutput(std::string filename){
   
    std::ifstream database;
    std::string str;        
    DataForm::iterator mit;
    std::string strValue;
    std::string strDate;

    bool firstLine = true;
    database.open(filename);
    if (database.rdstate())
        throw DataLoadFailure();
    while (database.eof() == false){
        std::getline(database, str, '\n');
        //첫째줄은 넘긴다. 
        if(firstLine) {
            firstLine = false; continue;
        }
        try{
            std::pair<std::string, std::string> temp = parseOneLine(str, "|");
            strDate = temp.first;
            strValue = temp.second;
            dateValidate(strDate);
            mit = Data.upper_bound(strDate);
            if(mit == Data.begin())
                throw InvalidDateTooEarly();
            valueValidate(strValue);
            if(database.eof())
                break;
    }
    catch(std::exception &e){
        std::cout << e.what();
        continue;
    }
        std::setprecision(10);
        std::cout << strDate << " => " << strValue << " = " << loadExchangeRateResult(strValue, --mit) << "\n";
    }
    database.close();
}

double BitcoinExchange::loadExchangeRateResult(std::string value, DataForm::iterator data){
    double operand1 = std::strtod(value.c_str(), NULL);
    double operand2 = std::strtod(data->second.c_str(), NULL);
    return operand1 * operand2;
}

void BitcoinExchange::valueValidate(std::string value){

    long long integer = 0;
    long long deci = 0;
    for(unsigned int i = 0; i < value.length(); i++){
        long long num = 0;
        while (isdigit(value[i])){
            num = num * 10 + value[i] - '0';
            i++;
        }
        integer = num;
        if(value[i] == '.')
        {
            i++;
            num = 0;
            while(isdigit(value[i])){
                num = num * 10 + value[i] - '0';
                i++;
            }
            deci = num;
            if(value[i] != '\0')
                throw InvalidValueFailure();
        }
        else{
            if(value[i] != '\0')
                throw InvalidValueFailure();
        }
    }
    std::stringstream strInteger;
    strInteger << integer;
    std::stringstream strDeci;
    strDeci << deci;
    std::string resultValue = strInteger.str() + '.' + strDeci.str();
    long long ret = std::strtoll(resultValue.c_str(), NULL, 10);

    if(ret > 1000)
        throw InvalidValueTooLarge();
    if(ret < 0)    
        throw InvalidValueNotPositive();
}

const char *BitcoinExchange::DataLoadFailure::what() const throw ()
{
    return "data load failed.\n";
}

const char *BitcoinExchange::InputDataLoadFailure::what() const throw ()
{
    return "input data load failed.\n";
}


const char *BitcoinExchange::InvalidDateFailure::what() const throw ()
{
    return "not a valid date format.\n";
}

const char *BitcoinExchange::InvalidValueFailure::what() const throw ()
{
    return "wrong value.\n";
}

const char *BitcoinExchange::InvalidValueNotPositive::what() const throw ()
{
    return "not a positive number.\n";
}

const char *BitcoinExchange::InvalidValueTooLarge::what() const throw ()
{
    return "too large a number.\n";
}

const char *BitcoinExchange::InvalidDateTooEarly::what() const throw ()
{
    return "date too early.\n";
}

const char *BitcoinExchange::InvalidInputFailure::what() const throw ()
{
    return "bad input\n";
}
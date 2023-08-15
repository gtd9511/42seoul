#include "BitcoinExchange.hpp"



int main(int argc, char **argv){
    if(argc != 2){
        std::cout << "usage : ./btc [input filename]\n";
        return 1;
    }
    try
    {
        BitcoinExchange::loadData();
        std::string filename = argv[1];
        
        BitcoinExchange::parseInputDataAndPrintOutput(filename);
       }
    catch(std::exception &e){
        std::cout << e.what() << std::endl;
        return 1;
    }
}
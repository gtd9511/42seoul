#include "BitcoinExchange.hpp"
// void leaks() {
//   system("leaks btc");
// }

int main(int argc, char **argv)
{
	// atexit(leaks);
	BitcoinExchange bitcoinex;

	if(argc != 2){
		std::cout << "Error: could not open file." << std::endl;
		return 0;
	}
	bitcoinex.checkCsvFile();
	bitcoinex.checkInputFile(argv[1]);
	bitcoinex.Bitcoin(argv[1]);

}

#include "PmergeMe.hpp"


int main(int argc, char **argv){

	if(argc == 1){
		std::cout << "usage: PmergeMe [args]";
		return 1;
	}
	PmergeMe p;
    p.sortCompare(argv);

}
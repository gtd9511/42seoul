#include "Span.hpp"

void check(){
	system("leaks Span");
}
int main() {

	std::cout << "------------------test start!---------------\n";
	
	{
		std::cout << "------------------test1---------------\n";	
		try{
			Span span(6);
			span.addNumber(0);
			span.addNumber(1);
			span.addNumber(2);
			for(unsigned int i = 0 ; i < span.size(); i++)
				std::cout << span.getNum(i) << " ";
			std::cout << "\n";
			std::cout << "shortest "<<   span.shortestSpan() << std::endl;
			std::cout << "longest " << span.longestSpan() << std::endl;
		}
		catch (std::runtime_error &e){
			std::cout << e.what() << std::endl;
		}
	}
	
	std::cout << "\n------------------test2---------------\n";
	{
		try{
			Span span(10);
			for(int i = 0; i < 111; i++){
				span.addNumber(i);
			}
			for(unsigned int i = 0 ; i < span.size(); i++)
				std::cout << span.getNum(i) << " ";
			std::cout << "\n";
		}
		catch (std::runtime_error &e){
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "\n------------------test3---------------\n";
	{
		try{
			srand(time(NULL));
			Span span(6);
			for(unsigned int i = 0; i < span.getMaxSize(); i++){
				span.addNumber(rand() % 100);
			}
			for(unsigned int i = 0 ; i < span.size(); i++)
				std::cout << (span.getNum(i)) << " ";
			std::cout << "\n";

			std::cout << "size : " << span.size() << std::endl;
			std::cout << "shortest "<<   span.shortestSpan() << std::endl;
			std::cout << "longest " << span.longestSpan() << std::endl;
		}
		catch (std::runtime_error &e){
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "\n------------------test4---------------\n";
	
	{
	try
	{
		Span span(10);
		for(int i = 0; i < 9; i++){
			span.addNumber(i);
		}
		Span copySpan(span);
		std::cout << "copySpan size : " << copySpan.size() << " max size : " << copySpan.getMaxSize() << std::endl;
		for(unsigned int i = 0 ; i < span.size(); i++)
			std::cout << copySpan.getNum(i) << " ";

		std::cout << std::endl;
		Span span2(5);
		for(int i = 0; i < 5; i++){
			span2.addNumber(i);
		}
		copySpan = span2;
		std::cout << "copySpan size : " << copySpan.size() << " max size : " << copySpan.getMaxSize() << std::endl;
		for(unsigned int i = 0 ; i < copySpan.size(); i++)
			std::cout << copySpan.getNum(i) << " ";

		std::cout << std::endl;

		span2.changeNum(0, 10);
		std::cout << "span2 \n";
		for(unsigned int i = 0 ; i < span2.size(); i++)
			std::cout << span2.getNum(i) << " ";
		std::cout << std::endl;

		std::cout << "copySpan \n";
		for(unsigned int i = 0 ; i < copySpan.size(); i++)
			std::cout << copySpan.getNum(i) << " ";
		std::cout << std::endl;

	}
	catch (std::runtime_error &e){
			std::cout << e.what() << std::endl;
		}
	}
	{	
		std::cout << "\n--------test5----------\n";
		std::vector<int> willBePushed;
		srand(time(NULL));
		for(int i = 0; i < 100; i++){
			willBePushed.push_back(rand());
		}
		Span span(100000);
		span.insert(willBePushed.begin(), willBePushed.end());
		for(unsigned int i = 0; i < span.size(); i++){
			std::cout << span.getNum(i) << " ";
		}
		std::cout << "\n";
		
	}



	std::cout << "\n--------------------------------end of test-----------------------------------\n";
	// atexit(check);

    return 0;
}

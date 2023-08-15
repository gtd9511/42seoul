#include "easyfind.hpp"

int main() {

    {
        int arr[]= {1, 2, 3, 4, 5};
        std::vector<int> intVec(arr, arr + 5);
        std::cout << "----------test1 vector<int>----------\n";
        
        std::vector<int>::iterator it = intVec.begin();
        std::vector<int>::iterator ite = intVec.end();
        while(it != ite){
            std::cout << *it << " ";
            it++;
        }
        
        std::cout << std::endl;
        try {
            std::cout << "find 3\n";
            std::vector<int>::iterator it = easyfind(intVec, 3);
            std::cout << "Value found at index: " << std::distance(intVec.begin(), it) << std::endl;
        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
        
        try {
            std::cout << "find 6\n";
            std::vector<int>::iterator it = easyfind(intVec, 6);
            std::cout << "Value found at index: " << std::distance(intVec.begin(), it) << std::endl;
        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
            std::cout << std::endl;
    }

    {

        std::cout << "\n----------test2 vector<char>----------\n";
        std::vector<char> charVec;
        for(int i = 0; i < 10; i++)
            charVec.push_back('a' + i);
        std::vector<char>::iterator it = charVec.begin();
        std::vector<char>::iterator ite = charVec.end();
        while(it != ite){
            std::cout << *it << " ";
            it++;
        }
        
        std::cout << std::endl;
        for(int i = 0; i < 10; i++)
            std::cout << charVec[i] << " ";
        std::cout << std::endl;
        try {
             std::cout << "find b\n";
            std::vector<char>::iterator it = easyfind(charVec, 'b');
            std::cout << "Value found at index: " << std::distance(charVec.begin(), it) << std::endl;
        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
            std::cout << std::endl;
    }

        {

        std::cout << "\n----------test3 list<int>----------\n";
        std::list<int> intList;
        for(int i = 0; i < 10; i++){
            intList.push_front(i * 10);
        }
        std::list<int>::iterator it = intList.begin();
        std::list<int>::iterator ite = intList.end();
        while(it != ite){
            std::cout << *it << " ";
            it++;
        }
        std::cout << std::endl;


        std::cout << std::endl;
          try {
            std::cout << "find 50\n";
            std::list<int>::iterator find = easyfind(intList, 50);
            std::cout << "Value found at index: " << std::distance(intList.begin(), find) << std::endl;
        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
            std::cout << std::endl;
    }

     {

        std::cout << "\n----------test4 deque<int>----------\n";
        std::deque<int> intDeque;
        for(int i = 0; i < 10; i++){  
            intDeque.push_front(i * 10);
        }
        std::deque<int>::iterator it = intDeque.begin();
        std::deque<int>::iterator ite = intDeque.end();
        while(it != ite){
            std::cout << *it << " ";
            it++;
        }
        std::cout << std::endl;
          try {
            std::cout << "find 70\n";
            std::deque<int>::iterator find = easyfind(intDeque, 70);
            std::cout << "Value found at index: " << std::distance(intDeque.begin(), find) << std::endl;
        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
            std::cout << std::endl;
    }
    
    return 0;
}
#include "iter.hpp"

typedef struct data Data;
struct data{
    int data;
    int idx;

    friend std::ostream& operator<<(std::ostream &os, const Data d){
            os << "[" << d.idx <<"] :  " << d.data << "\n";
            return os;
    }
   
};

int main(){
    std::cout << "----------- test 1 ----------\n";
    int array1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    ::iter(array1, 10, simpleFunction<int>);
    std::cout << std::endl;

    std::cout << "----------- test 2 ----------\n";
    const int array2[10] = {0, 1, 2, 3, 4, 5, 6, 7 ,8, 9};
    ::iter(array2, 10, simpleFunction<const int>);
    std::cout << std::endl;


    std::cout << "----------- test 3 ----------\n";
    double array3[10] = {1.0, 2.0, 3.1, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9999, 10.000123};
    ::iter(array3, 10, simpleFunction<double>);
    std::cout << std::endl;

    std::cout << "----------- test 4 ----------\n";
    std::string array4[5] = {"hello", "world", "42", "global", "new"};
    ::iter(array4, 5, simpleFunction<std::string>);
    std::cout << std::endl;

    std::cout << "----------- test 5 ----------\n";
    data darray[4] = {{1, 0}, {2, 1} , {3, 2}, {4, 3}};
    ::iter(darray, 4, simpleFunction<Data>);
    std::cout << std::endl;
}
#include "Whatever.hpp"
template <typename T>
void testSwap(T a, T b){
    std::cout << "before swap\n";
    std::cout << "a : " << a << " b : " << b << "\n";
    swap(a, b);
    std::cout << "after swap\n";
    std::cout << "a : " << a << " b : " << b << "\n";
}

template <typename T>
void testMin(T a, T b){
    std::cout << "\n min test \n";
    std::cout << "a : " << a << " b : " << b << "\n";
    std::cout << "min result: ";
    std::cout << ::min(a, b) << std::endl;
}

template <typename T>
void testMax(T a, T b){
    std::cout << "\n max test \n";
    std::cout << "a : " << a << " b : " << b << "\n";
    std::cout << "max result: ";
    std::cout << ::max(a, b) << std::endl;
}
int main(){
    int a = 2, b = 3;
    std::cout << "----------test 1---------\n";
    testSwap(a, b);
    testMin(a, b);
    testMax(a, b);
    
    
    std::cout << "\n----------test 2---------\n";
    const int c = 1005, d = -43;
    testSwap(c, d);
    testMin(c, d);
    testMax(c, d);

    std::cout << "\n----------test 3---------\n";
    char e = 'g', f = 'p';
    testSwap(e, f);
    testMin(e, f);
    testMax(e, f);

    std::cout << "\n----------test 4---------\n";
    double g = 2.2, h = 3.3;
    testSwap(g, h);
    testMin(g, h);
    testMax(g, h);

    std::cout << "\n----------test 5---------\n";
    static int i = 10, j = 110341;
    testSwap(i, j);
    testMin(i, j);
    testMax(i, j);
    

    std::cout << "\n----------test 6---------\n";
    std::string str1 = "helloworld", str2 = "hello42";
    testSwap(str1, str2);
    testMin(str1, str2);
    testMax(str1, str2);
    
}
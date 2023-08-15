#include "Array.hpp"
#include <cstdlib>
#include <algorithm>

typedef struct data  Data;
struct data{
    int idx;
    int num;
    Data &operator=(int value){
        num = value;
        return *this;
    }
};

std::ostream &operator<<(std::ostream &os, const Data &d){
    os << "[" << d.idx  << "] : " <<  d.num << "\n";
    return os;
}


void check(){
    system("leaks Array");
}


int main(){
    
    {
        std::cout << "-------------test1-------------\n";
        Array<int> arr1(5);
        for(unsigned int i = 0; i < arr1.size(); i++){
            arr1[i] = static_cast<int>(i + 1);
        }

        for(unsigned int i = 0; i < arr1.size(); i++){
            std::cout << arr1[i] << " ";
        }
    
    
    
        std::cout << "\n-------------test2-------------\n";
        Array<int> arr2(arr1);
        std::cout << "arr1: \n";
        for(unsigned int i = 0; i < arr1.size(); i++){
            std::cout << arr1[i] << " ";
        }
        std::cout << "\narr2: \n";
        for(unsigned int i = 0; i < arr1.size(); i++){
            std::cout << arr2[i] << " ";
        }


        Array<int> arrCopy;
        arrCopy = arr2;
        std::cout << "\narrCopy: \n";
        for(unsigned int i= 0; i < arr1.size(); i++){
            std::cout << arrCopy[i] << " ";
        }
        std::cout << std::endl;

        arr2[2] = 100;
        std::cout << "\narr2: \n";
        for(unsigned int i = 0; i < arr1.size(); i++){
            std::cout << arr2[i] << " ";
        }
        std::cout << "\narrCopy: \n";
        for(unsigned int i= 0; i < arr1.size(); i++){
            std::cout << arrCopy[i] << " ";
        }
        std::cout << std::endl;


    //서로 다른 타입을 지정하는 것은 불가능.
        // try{
        //     Array<double> arrDouble;
        //     arrDouble = arr2;
        //     std::cout << "\narrDouble: \n";
        //     for(unsigned int i= 0; i < arr1.size(); i++){
        //         std::cout << arrCopy[i] << " ";
        //     }
        // }
        // catch(std::exception & e){
        //     std::cerr << e.what();
        // }
        std::cout << std::endl;

    }


    {
        std::cout << "\n-------------test3-------------\n";
        Array<Data> arr3(5);
        for(unsigned int i = 0; i < arr3.size(); i++){
            arr3[i].idx = i;
            arr3[i].num = i  *  10;
        }

        for(unsigned int i = 0; i < arr3.size(); i++){
            std::cout << arr3[i] << " ";
        }
        std::cout << std::endl;
        //구조체 인덱스 접근 불가
        arr3[2] = 1000;
        for(unsigned int i = 0; i < arr3.size(); i++){
            std::cout << arr3[i] << " ";
        }
        std::cout << std::endl;

    }

    {
        std::cout << "\n-------------test4-------------\n";
        Array<char> arr4(10);
        std::cout << &arr4 << "\n";
        std::cout << arr4[0] << "\n";
    }   

    {

        //const int 같은 형은 사용불가: 선언과(생성자) 동시에 초기화가 불가능.    new T[n] 으로 할당 후 값 넣는 것만 가능.
        srand(time(NULL));
        std::cout << "\n-------------test5-------------\n";
        Array<int> arr5(10);

        for(unsigned int i = 0; i < 10; i++){
            arr5[i] = rand();
        }

           for(unsigned int i = 0; i < 10; i++){
            std::cout << "[" << i << "]: " << arr5[i] << " \n";
        }
        
        try{
                arr5[-1] = -1;
        }
        catch(std::exception &e){
            std::cerr << e.what() ;
        }

        std::cout << std::endl;
    }
    {
        std::cout << "\n-------------test6-------------\n";
        Array<int> arr6(10);

        for(unsigned int i = 0; i < arr6.size(); i++){
            arr6[i] = 100 - i;
        }
        std::cout << "\narr6: \n";
        for(unsigned int i = 0; i < arr6.size(); i++){
            std::cout << arr6[i] << " ";
        }

        // std::sort(&arr6[0], &arr6[9]);
        // std::sort(&arr6[0], &arr6[10]);
        std::sort(&arr6[0], &arr6[9] +1);
        std::cout << "\nafter sort arr6: \n";
        for(unsigned int i = 0; i < arr6.size(); i++){
            std::cout << arr6[i] << " ";
        }
        std::cout << std::endl;
        int value = arr6[0];
        std::cout << "value : " << value << "\n";

    }
    {
        std::cout << "\n-------------test7-------------\n";
        const Array<int> arr7(10);
        int value = arr7[0];
        std::cout << "value : " << value <<"\n";
        const int value2 = arr7[1];
        std::cout << "value2 : " << value2 <<"\n";

    }
    // atexit(check);

}
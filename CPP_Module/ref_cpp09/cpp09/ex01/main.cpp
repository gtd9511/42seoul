#include "RPN.hpp"
/*
예상되는 input
"8 9 * 9 - 9 - 9 - 4 - 1 +"
"7 7 * 7 -"
"1 2 * 2 / 2 * 2 4 - +"

"(1 + 1)" -> Error

0. 공백으로 기준으로 파싱
1. 유효성 검사
2. 숫자이면 스택에 push
3. 연산자이면 스택에서 두개 pop 해서 두개의 피 연산자 연산.
4. 



*/


int main(int argc, char **argv){
    //후위연산자 풀이
    //하나씩 valid 체크하면서 스택에 담는다.
    //스택에서 꺼내면서 연산을 하되, 괄호의 유효성 검사도 하면서 한다.
    // " " 안에 받는 문자열도 파싱을 따로 해야할 것 같다. 
    //화이팅이다 은정

    if (argc != 2){
        std::cout << "usage : ./RPN [mathematical expression]\n";
    }
    int ret;
    try {
        ret = RPN::parseAndCalculate(argc, argv);

        std::cout << ret << "\n";
    }
    catch(std::exception &e){
        std::cout << e.what();
    }
}
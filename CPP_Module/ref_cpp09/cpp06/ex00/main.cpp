#include "ScalarConverter.hpp"

int main(int argc, char *argv[]){

    if(argc == 1){
        std::cout << "arguments usage : ./convert argument" << std::endl;
        return 1;
    }
    ScalarConverter s;
    s.convert(static_cast<std::string>(argv[1]));

}

/*
test argv
0
10.0
f
42.0f
42.0fq
nan
inf
-inff
test
11111
42.5
43.7
42.7ff
1.111111
*/

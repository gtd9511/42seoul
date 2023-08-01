#include "RPN.hpp"

// void leaks() {
//   system("leaks RPN");
// }

int main(int argc, char **argv) {
//   atexit(leaks);
    if (argc != 2) {
        std::cerr <<"Error" << std::endl;
        return 0;
    }
    RPN rpn(argv[1]);
    rpn.ReversePolishNotation();
    return 0;
}

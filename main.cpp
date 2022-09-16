#include "Calculator.h"
#include <conio.h>

CalculatorType option[2] = {INFIX, SUFFIX};

int main() {
    std::cout << "================= Calculator =================" << std::endl;
    std::cout << "============== Author: NULL0x7f ==============" << std::endl;
    std::cout << "please choose a calculator type." << std::endl;
    std::cout << "[ 1 ] Infix" << std::endl;
    std::cout << "[ 2 ] Suffix" << std::endl;
    char opt = getch();
    while (opt != '1' && opt != '2') {
        std::cout << "please enter 1 or 2." << std::endl;
        opt = getch();
    }
    Calculator::run(option[opt - '1']);
    return 0;
}
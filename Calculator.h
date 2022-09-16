/**
 * @file Calculator.h
 * @author NULL0x7f
 * @brief #&Ef@i$Lt^on_Y$hw
 * @date 2022-09-15
 */
#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

#include "ExprInterpreter.h"
#include "SuffixExprInterpreter.h"

enum CalculatorType {
    INFIX,
    SUFFIX
};

class Calculator {
public:
    static void claculate(CalculatorType type) {
        std::cout << "calc> ";
        std::string text;
        getline(std::cin, text);
        if (text.size() == 0)
            return;
        try {
            double ans;
            switch (type) {
            case INFIX:
                ans = ExprInterpreter(ExprParser(Lexer(text))).interpret();
                break;
            case SUFFIX:
                ans = SuffixExprInterpreter(Lexer(text)).interpret();
                break;
            default:
                throw Exception("Calculator type error");
                break;
            }
            if (fabs(ans) < EPS) std::cout << 0 << std::endl;
            else std::cout << ans << std::endl;
        } catch(const Exception& e) {
            std::cerr << e.what() << '\n';
        }
    }
    static void run(CalculatorType type) {
        while (true) {
            claculate(type);
        }
    }
};

#endif
/**
 * @file SuffixExprInterpreter.h
 * @author NULL0x7f
 * @brief #&Ef@i$Lt^on_Y$hw
 * @date 2022-09-16
 */
#ifndef _SUFFIX_EXPR_INTERPRETER_H_
#define _SUFFIX_EXPR_INTERPRETER_H_

#include "Lexer.h"
#include "Stack.h"
#include "Token.h"
#include "TokenDouble.h"
#include "TokenChar.h"

class SuffixExprInterpreter {
private:
    Lexer lexer;
    Stack<double> operands;
public:
    SuffixExprInterpreter() {}
    SuffixExprInterpreter(const Lexer& lexer) : lexer(lexer) {}

    double interpret() {
        Token* token = lexer.analyze();
        while (token->getType() != EoF) {
            if (token->getType() == NUMBER) {
                operands.push(dynamic_cast<TokenDouble*>(token)->getValue());
            } else {
                if ((int)operands.size() < 2)
                    throw Exception("Invalid syntax");
                double num1 = operands.top();
                operands.pop();
                double num2 = operands.top();
                operands.pop();
                switch (token->getType()) {
                case PLUS:
                    operands.push(num1 + num2);
                    break;
                case MINUS:
                    operands.push(num1 - num2);
                    break;
                case MUL:
                    operands.push(num1 * num2);
                    break;
                case DIV:
                    if (fabs(num2) < EPS)
                        throw Exception("dived by 0");
                    operands.push(num1 / num2);
                    break;
                case POW:
                    operands.push(pow(num1, num2));
                    break;
                default:
                    throw Exception("Invalid syntax");
                    break;
                }
            }
            token = lexer.analyze();
        }
        if (operands.size() != (int)1)
            throw Exception("Invalid syntax");
        return operands.top();
    }
};

#endif

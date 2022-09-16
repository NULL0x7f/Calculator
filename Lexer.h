/**
 * @file Lexer.h
 * @author NULL0x7f
 * @brief #&Ef@i$Lt^on_Y$hw
 * @date 2022-09-14
 */
#ifndef _LEXER_H_
#define _LEXER_H_

#include "Token.h"
#include "TokenDouble.h"
#include "TokenChar.h"
#include "CharChecker.h"
#include "Exception.h"

class Lexer {
private:
    std::string text;
    int pos;
    char curChar;
public:
    Lexer() {}
    Lexer(const std::string& text) : text(text) {
        pos = 0;
        curChar = text[pos];
    }
    
    void advance() {
        pos++;
        if (pos > (int)text.size() - 1)
            curChar = '\0';
        else
            curChar = text[pos];
    }
    void skipWhiteSpace() {
        while (curChar != '\0' && isWhiteSpace(curChar)) {
            advance();
        }
    }
    double proNumber() {
        double res = 0;
        bool hasDigitPrePoint, hasDigitAfterPoint;
        hasDigitPrePoint = isdigit(curChar);
        while (curChar != '\0' && isdigit(curChar)) {
            res = 10 * res + curChar - '0';
            advance();
        }
        if (curChar == '.') {
            advance();
            hasDigitAfterPoint = isdigit(curChar);
            if (!(hasDigitPrePoint || hasDigitAfterPoint)) {
                throw Exception("Invalid number");
            }
            double l = 0.1;
            while (isdigit(curChar)) {
                res += l * (curChar - '0');
                l *= 0.1;
                advance();
            }
        }
        if (curChar == 'e') {
            advance();
            double num = 0;
            bool sign = false;
            if (curChar == '-') {
                sign = true;
                advance();
            }
            if (!isdigit(curChar)) {
                throw Exception("Invalid number");
            }
            while (isdigit(curChar)) {
                num = 10 * num + curChar - '0';
                advance();
            }
            res = res * pow(10, sign ? -num : num);
        }
        return res;
    }
    Token* analyze() {
        while (curChar != '\0') {
            if (isWhiteSpace(curChar)) {
                skipWhiteSpace();
                continue;
            }
            if (isdigit(curChar) || curChar == '.') {
                return static_cast<Token*>(new TokenDouble(NUMBER, proNumber()));
            }
            if (curChar == '+') {
                advance();
                return static_cast<Token*>(new TokenChar(PLUS, '+'));
            }
            if (curChar == '-') {
                advance();
                return static_cast<Token*>(new TokenChar(MINUS, '-'));
            }
            if (curChar == '*') {
                advance();
                return static_cast<Token*>(new TokenChar(MUL, '*'));
            }
            if (curChar == '/') {
                advance();
                return static_cast<Token*>(new TokenChar(DIV, '/'));
            }
            if (curChar == '^') {
                advance();
                return static_cast<Token*>(new TokenChar(POW, '^'));
            }
            if (curChar == '(') {
                advance();
                return static_cast<Token*>(new TokenChar(LPAREN, '('));
            }
            if (curChar == ')') {
                advance();
                return static_cast<Token*>(new TokenChar(RPAREN, ')'));
            }
            throw Exception("Invalid character");
        }
        return new Token(EoF);
    }
};

#endif
/**
 * @file Token.h
 * @author NULL0x7f
 * @brief #&Ef@i$Lt^on_Y$hw
 * @date 2022-09-14
 */
#ifndef _TOKEN_H_
#define _TOKEN_H_

#include <bits/stdc++.h>

const double EPS = 1e-50;

enum TokenType {
    NUMBER,
    PLUS,
    MINUS,
    MUL,
    DIV,
    POW,
    EoF,
    LPAREN,
    RPAREN
};

class Token {
private:
    TokenType type;
public:

    Token() {}
    Token(const TokenType& type) : type(type) {}

    virtual std::string className() { return "Token"; }

    TokenType getType() const { return type; }
    void setType(const TokenType& type) { this->type = type; }
};

#endif
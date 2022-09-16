/**
 * @file TokenDouble.h
 * @author NULL0x7f
 * @brief #&Ef@i$Lt^on_Y$hw
 * @date 2022-09-14
 */
#ifndef _TOKEN_DOUBLE_H_
#define _TOKEN_DOUBLE_H_

#include "Token.h"

class TokenDouble : public Token {
private:
    double value;
public:
    TokenDouble() {}
    TokenDouble(const TokenType& type, const double& value) : Token(type), value(value) {}

    std::string className() { return "TokenDouble"; }

    double getValue() const { return value; }
    void setValue(const double& value) { this->value = value; }
};

#endif
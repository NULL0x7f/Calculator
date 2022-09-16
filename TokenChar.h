/**
 * @file TokenChar.h
 * @author NULL0x7f
 * @brief #&Ef@i$Lt^on_Y$hw
 * @date 2022-09-14
 */
#ifndef _TOKEN_CHAR_H_
#define _TOKEN_CHAR_H_

#include "Token.h"

class TokenChar : public Token {
private:
    char value;
public:
    TokenChar() {}
    TokenChar(const TokenType& type, const char& value) : Token(type), value(value) {}

    std::string className() { return "TokenChar"; }

    char getValue() const { return value; }
    void setValue(const char& value) { this->value = value; }
};

#endif
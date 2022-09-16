/**
 * @file Parser.h
 * @author NULL0x7f
 * @brief #&Ef@i$Lt^on_Y$hw
 * @date 2022-09-15
 */
#ifndef _PARSER_H_
#define _PARSER_H_

#include "Lexer.h"

class Parser {
private:
    Lexer lexer;
    Token* curToken;
public:
    Parser() {}
    Parser(const Lexer& lexer) : lexer(lexer) { curToken = this->lexer.analyze(); }
    
    Lexer getLexer() const { return lexer; }
    void setLexer(const Lexer& lexer) { this->lexer = lexer; }
    Token* getCurToken() const { return curToken; }
    void setCurToken(Token* curToken) { this->curToken = curToken; }

    void eat(const TokenType& tokenType) {
        if (curToken->getType() == tokenType)
            curToken = lexer.analyze();
        else
            throw Exception("Invalid syntax");
    }
};

#endif
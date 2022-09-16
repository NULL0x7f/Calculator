/**
 * @file UnaryOp.h
 * @author NULL0x7f
 * @brief #&Ef@i$Lt^on_Y$hw
 * @date 2022-09-15
 */
#ifndef _UNARY_OP_H_
#define _UNARY_OP_H_

#include "AST.h"
#include "TokenChar.h"

class UnaryOp : public AST {
private:
    TokenChar token;
    AST* operands;
public:
    UnaryOp() {}
    UnaryOp(const TokenChar& token, AST* operands) : token(token), operands(operands) {}

    std::string className() { return "UnaryOp"; }

    AST* getOperands() const { return operands; }
    void setOperands(AST* operands) { this->operands = operands; }
    TokenChar getToken() const { return token; }
    void setToken(const TokenChar& token) { this->token = token; }
    char getOp() const { return token.getValue(); }
};

#endif
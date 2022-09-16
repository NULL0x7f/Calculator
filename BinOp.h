/**
 * @file BinOp.h
 * @author NULL0x7f
 * @brief #&Ef@i$Lt^on_Y$hw
 * @date 2022-09-14
 */
#ifndef _BIN_OP_H_
#define _BIN_OP_H_

#include "AST.h"
#include "TokenChar.h"

class BinOP : public AST {
private:
    AST* left;
    TokenChar token;
    AST* right;
public:
    BinOP() {}
    BinOP(AST* left, const TokenChar& token, AST* right) : left(left), token(token), right(right) {}

    std::string className() { return "BinOp"; }

    AST* getLeft() const { return left; }
    void setLeft(AST* left) { this->left = left; }
    AST* getRight() const { return right; }
    void setRight(AST* right) { this->right = right; }
    TokenChar getToken() const { return token; }
    void setToken(const TokenChar& token) { this->token = token; }
    char getOp() const { return token.getValue(); }
};

#endif
/**
 * @file Num.h
 * @author NULL0x7f
 * @brief #&Ef@i$Lt^on_Y$hw
 * @date 2022-09-14
 */
#ifndef _NUM_H_
#define _NUM_H_

#include "AST.h"
#include "TokenDouble.h"

class Num : public AST {
private:
    TokenDouble token;
public:
    Num() {}
    Num(const TokenDouble& token) : token(token) {}

    std::string className() { return "Num"; }

    TokenDouble getToken() const { return token; }
    double getValue() const { return token.getValue(); }
};

#endif
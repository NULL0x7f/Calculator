/**
 * @file AST.h
 * @author NULL0x7f
 * @brief #&Ef@i$Lt^on_Y$hw
 * @date 2022-09-14
 */
#ifndef _AST_H_
#define _AST_H_

#include <string>

class AST {
public:
    AST() {}
    virtual std::string className() { return "AST"; }
};

#endif
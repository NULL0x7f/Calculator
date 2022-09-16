/**
 * @file ExprParser.h
 * @author NULL0x7f
 * @brief #&Ef@i$Lt^on_Y$hw
 * @date 2022-09-15
 */
#ifndef _EXPR_PARSER_H_
#define _EXPR_PARSER_H_

#include "Parser.h"
#include "AST.h"
#include "Num.h"
#include "UnaryOp.h"
#include "BinOp.h"

class ExprParser : public Parser {
public:
    ExprParser() {}
    ExprParser(const Lexer& lexer) : Parser(lexer) {}


    // para = null | expr (,expr)*

    // func = ident(para)

    // factor = number | (expr) | func
    AST* factor() {
        Token* token = Parser::getCurToken();
        if (token->getType() == NUMBER) {
            eat(NUMBER);
            return new Num(*dynamic_cast<TokenDouble*>(token));
        }
        if (token->getType() == LPAREN) {
            eat(LPAREN);
            AST* node = expr();
            eat(RPAREN);
            return node;
        }
        throw Exception("Invalid syntax");
    }

    // sign = ('+' | '-')*factor
    AST* sign() {
        Token* token = Parser::getCurToken();
        if (token->getType() == PLUS) {
            eat(PLUS);
            return new UnaryOp(*dynamic_cast<TokenChar*>(token), sign());
        }
        if (token->getType() == MINUS) {
            eat(MINUS);
            return new UnaryOp(*dynamic_cast<TokenChar*>(token), sign());
        }
        return factor();
    }

    // pow = sign(^pow)
    AST* pow() {
        AST* node = sign();
        Token* token = Parser::getCurToken();
        if (token->getType() == POW) {
            eat(POW);
            return new BinOP(node, *dynamic_cast<TokenChar*>(token), pow());
        }
        return node;
    }

    // term = pow (('*' | '-')pow)*
    AST* term() {
        AST* node = pow();
        while (Parser::getCurToken()->getType() == MUL || Parser::getCurToken()->getType() == DIV) {
            Token* token = Parser::getCurToken();
            if (token->getType() == MUL) {
                eat(MUL);
            } else if (token->getType() == DIV) {
                eat(DIV);
            }
            node = new BinOP(node, *dynamic_cast<TokenChar*>(token), pow());
        }
        return node;
    }

    // expr = term(('+' | '-')term)*
    AST* expr() {
        AST* node = term();
        while (Parser::getCurToken()->getType() == PLUS || Parser::getCurToken()->getType() == MINUS) {
            Token* token = Parser::getCurToken();
            if (token->getType() == PLUS) {
                eat(PLUS);
            } else if (token->getType() == MINUS) {
                eat(MINUS);
            }
            node = new BinOP(node, *dynamic_cast<TokenChar*>(token), term());
        }
        return node;
    }
};

#endif
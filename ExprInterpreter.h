/**
 * @file ExprInterpreter.h
 * @author NULL0x7f
 * @brief #&Ef@i$Lt^on_Y$hw
 * @date 2022-09-15
 */
#ifndef _EXPR_INTERPRETER_H_
#define _EXPR_INTERPRETER_H_

#include "ASTVisitor.h"
#include "ExprParser.h"

class ExprInterpreter : ASTVisitor {
private:
    ExprParser parser;
public:
    ExprInterpreter() {}
    ExprInterpreter(const ExprParser& parser) : parser(parser) {}

    ExprParser getParser() const { return parser; }
    void setParser(const ExprParser& parser) {this->parser = parser; }

    double visitNum(Num* node) { return node->getValue(); }

    double visitUnaryOp(UnaryOp* node) {
        if (node->getToken().getType() == PLUS) {
            return visit(node->getOperands());
        } else if (node->getToken().getType() == MINUS) {
            return -visit(node->getOperands());
        }
        throw Exception("Invalid syntax");
    }

    double visitBinOp(BinOP* node) {
        if (node->getToken().getType() == PLUS) {
            return visit(node->getLeft()) + visit(node->getRight());
        }
        if (node->getToken().getType() == MINUS) {
            return visit(node->getLeft()) - visit(node->getRight());
        }
        if (node->getToken().getType() == MUL) {
            return visit(node->getLeft()) * visit(node->getRight());
        }
        if (node->getToken().getType() == DIV) {
            double num1 = visit(node->getLeft());
            double num2 = visit(node->getRight());
            if (fabs(num2) < EPS)
                throw Exception("dived by 0");
            return num1 / num2;
        }
        if (node->getToken().getType() == POW) {
            return pow(visit(node->getLeft()), visit(node->getRight()));
        }
        throw Exception("Invalid syntax");
    }

    double visit(AST* node) {
        if ("Num" == node->className())
            return visitNum(dynamic_cast<Num*>(node));
        if ("UnaryOp" == node->className())
            return visitUnaryOp(dynamic_cast<UnaryOp*>(node));
        if ("BinOp" == node->className())
            return visitBinOp(dynamic_cast<BinOP*>(node));
        throw Exception("Invalid syntax");
    }

    double interpret() {
        AST* node = parser.expr();
        return visit(node);
    }
};

#endif
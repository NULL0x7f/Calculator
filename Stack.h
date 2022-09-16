/**
 * @file Stack.h
 * @author NULL0x7f
 * @brief #&Ef@i$Lt^on_Y$hw
 * @date 2022-09-16
 */
#ifndef _STACK_H_
#define _STACK_H_

#include <bits/stdc++.h>

template<typename T>
class Stack {
private:
    std::vector<T> stack;
public:
    Stack() {}
    
    void push(const T& x) { stack.emplace_back(x); }
    T top() const { return stack.back(); }
    void pop() { stack.pop_back(); }
    size_t size() const { return stack.size(); }
    bool empty() const { return stack.empty(); }
};

#endif
/**
 * @file Exception.h
 * @author NULL0x7f
 * @brief #&Ef@i$Lt^on_Y$hw
 * @date 2022-09-14
 */
#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_

#include <iostream>
#include <string>

class Exception {
private:
    std::string message;
public:
    Exception(const std::string& message) : message(message) {}
    std::string what() const { return message; }
};

#endif
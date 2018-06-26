//
// Created by maciej on 26.06.18.
//

#ifndef CHECKERS_EXCEPTIONS_H
#define CHECKERS_EXCEPTIONS_H


#include <exception>

class ExceptionCreatingButton: public std::exception {
public:

    const char *what() const noexcept override {
        return "Error while creating button";
    }
}ButtonExcept;


#endif //CHECKERS_EXCEPTIONS_H

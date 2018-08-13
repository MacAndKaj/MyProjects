//
// Created by maciej on 28.06.18.
//

#ifndef CHECKERS_CALLABLE_H
#define CHECKERS_CALLABLE_H


class Callable {
public:
    virtual void callExit() {};
    virtual void callClose() {};
    virtual void callIntro() {};
    virtual void callStart() {};
    virtual void callPause() {};

};


#endif //CHECKERS_CALLABLE_H

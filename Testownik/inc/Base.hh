//
// Created by mkajdak on 16.11.17.
//

#ifndef TESTOWNIK_BAZAPYTAN_HH
#define TESTOWNIK_BAZAPYTAN_HH

#include <vector>
#include <fstream>
#include <boost/filesystem.hpp>



/*
 * Klasa jako Fabryka, bedzie proszona o wydanie pytania
 *
 *
 * Odpowiedzialna za wgranie pytan z bazy, wgranie savea, wydawanie pytan;
 *
 */




//class Question;

namespace fs = boost::filesystem;

class Base {
public:

    static Base* init();

private:
    static Base* s_instance;
    int Amount_of_Questions;
    int QuestionsDone;

//    std::vector<Question> questions;


    Base();
    ~Base() = default;

};

Base* Base::s_instance=nullptr;

#endif //TESTOWNIK_BAZAPYTAN_H

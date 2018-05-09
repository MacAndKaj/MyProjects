//
// Created by maciej on 20.04.18.
//

#ifndef PPRZEPLYWOWY_ZADANIE_H
#define PPRZEPLYWOWY_ZADANIE_H

#include <iostream>
#include <vector>

using namespace std;

class Zadanie {
    int nrZadania;
    std::vector<int> *czasWykonywaniaNaMaszynie;    //czas wykonania na kolejnych maszynach
public:
    Zadanie(int &nr,const std::vector<int> &czasWykonywaniaNaMaszynie);
    virtual ~Zadanie();
    int omega()const;
    void Wypisz()const;
    int CzasWykonywaniaNaMaszynie(int m)const;
};


#endif //PPRZEPLYWOWY_ZADANIE_H

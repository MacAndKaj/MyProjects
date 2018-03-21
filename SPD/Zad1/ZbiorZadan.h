//
// Created by maciej on 28.02.18.
//

#ifndef ZAD1_ZBIORZADAN_H
#define ZAD1_ZBIORZADAN_H

#include "Zadanie.h"
#include <vector>

class ZbiorZadan {
private:
    std::vector<Zadanie> *WektorZadan;
    std::vector<int> *wekS;
    std::vector<int> *wekC;

    Zadanie& GetElementWektora(int) const;
    void SetElementWektora(int&,Zadanie&);
    void S();
    void C();
    int LElem;

    int licznik;
public:
    ZbiorZadan();


    //zadania na SPD***************
    void sortR();
    void alg2opt();
    int fCelu();
    void zamien(int,int);

    int Schrage();
    int findmaxQ();







    //************************
    int getLElem() const;
    void setLElem(int LElem);

    void GenerujWektory();
    void Dodaj(Zadanie);
    void wypisz();
};


#endif //ZAD1_ZBIORZADAN_H

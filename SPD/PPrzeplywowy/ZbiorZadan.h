//
// Created by maciej on 20.04.18.
//

#ifndef PPRZEPLYWOWY_ZBIORZADAN_H
#define PPRZEPLYWOWY_ZBIORZADAN_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "Zadanie.h"
using namespace std;


class ZbiorZadan {
    string nazwa;
    std::vector<Zadanie*> *zbior;
    int iloscMaszyn;


    int Cmax(vector<int>& Perm)const;
public:
    ZbiorZadan(const string &nazwa,int &iloscmaszyn);
    virtual ~ZbiorZadan();

    void DodajZadanie(Zadanie*);
    int ileZadan()const;
    void Wypisz()const;


    const string &getNazwa() const;
    int NEH() const;
    int NEHmod() const;

    int test();
};

#endif //PPRZEPLYWOWY_ZBIORZADAN_H

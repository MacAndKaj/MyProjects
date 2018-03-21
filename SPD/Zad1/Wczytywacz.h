//
// Created by maciej on 02.03.18.
//

#ifndef ZAD1_WCZYTYWACZ_H
#define ZAD1_WCZYTYWACZ_H

#include <string>
#include <list>

#include "Zadanie.h"
#include "ZbiorZadan.h"

using namespace std;

class Info{
    string nazwa;
    unsigned int ilosc;
    unsigned int WynikNieposortowanego;
    // SortR
    unsigned int WynikSortR;
    unsigned int CzasSortR;
    //2opt
    unsigned int Wynik2Opt;
    unsigned int Czas2Opt;
    //oba
    unsigned int WynikOba;
    unsigned int CzasOba;
public:
    Info(
    const string &nazwa,
    unsigned int WynikNieposortowanego,
    unsigned int WynikSortR,
    unsigned int CzasSortR,
    unsigned int Wynik2Opt,
    unsigned int Czas2Opt,
    unsigned int WynikOba,
    unsigned int CzasOba,
    unsigned int ilosc
    );
    friend std::ostream& operator<<(std::ostream& Strm,const Info& klasa);

    unsigned int getIlosc() const;

    unsigned int getWynikNieposortowanego() const;

    unsigned int getWynikSortR() const;

    unsigned int getCzasSortR() const;

    unsigned int getWynik2Opt() const;

    unsigned int getCzas2Opt() const;

    unsigned int getWynikOba() const;

    unsigned int getCzasOba() const;
};


int zadania(string nazwa, ZbiorZadan&);
void DoIT(string nazwapliku,std::list<Info*> &glowa);


#endif //ZAD1_WCZYTYWACZ_H

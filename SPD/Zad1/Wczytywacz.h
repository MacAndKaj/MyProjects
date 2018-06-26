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
enum tryb {Zad1,Zad2};

class Info{
    tryb Wariant;
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
    //Schrage
    unsigned int WynikSchrage;
    unsigned int CzasSchrage;
    //SchragePrmt
    unsigned int WynikPreSchrage;
    unsigned int CzasPreSchrage;
    //Carlier
    unsigned int WynikCarlier;
    unsigned int CzasCarlier;

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

    Info(const string &nazwa, unsigned int ilosc, unsigned int WynikSchrage, unsigned int CzasSchrage,
         unsigned int WynikPreSchrage, unsigned int CzasPreSchrage, unsigned int WynikCarlier,
         unsigned int CzasCarlier);


    friend std::ostream& operator<<(std::ostream& Strm,const Info& klasa);


    /******************     Gettery     ***********************************/
    unsigned int getIlosc() const;
    unsigned int getWynikNieposortowanego() const;
    unsigned int getWynikSortR() const;
    unsigned int getCzasSortR() const;
    unsigned int getWynik2Opt() const;
    unsigned int getCzas2Opt() const;
    unsigned int getWynikOba() const;
    unsigned int getCzasOba() const;

    const string &getNazwa() const;

    unsigned int getWynikSchrage() const;

    unsigned int getCzasSchrage() const;

    unsigned int getWynikPreSchrage() const;

    unsigned int getCzasPreSchrage() const;

    unsigned int getWynikCarlier() const;

    unsigned int getCzasCarlier() const;

    /**********************************************************************/
};




int zadania(string nazwa, ZbiorZadan&);
void DoIT(string nazwapliku,std::list<Info*> &glowa);
void DoIT2(string nazwapliku,std::list<Info*> &glowa);
void DoplikuDlaWykresowZad1(std::list<Info*> &head);
void DoplikuDlaWykresowZad2(std::list<Info*> &head);

#endif //ZAD1_WCZYTYWACZ_H

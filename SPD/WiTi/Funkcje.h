//
// Created by maciej on 12.04.18.
//

#ifndef WITI_FUNKCJE_H
#define WITI_FUNKCJE_H


#include "ZbiorZadan.h"
#include <string>
#include <fstream>


struct Dane{
    int rozmiar;
    TypDanych wejsciowe;
    TypDanych wynikPD;
    double czasPD;
    TypDanych wynikPZ;
    double czasPZ;
    TypDanych wynikSortW;
    double czasSortW;
};

std::vector<std::string> WczytajNazwy(const char *nazwa);
int WczytajZbior(const std::string &nazwa_pliku, ZbiorZadan& zbior);
Dane Testy(ZbiorZadan &ptr,std::string &nazwa);
void DoPliku(Dane& ref,std::fstream &Strm);

#endif //WITI_FUNKCJE_H

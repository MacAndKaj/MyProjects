//
// Created by maciej on 06.04.18.
//

#ifndef WITI_ZBIORZADAN_H
#define WITI_ZBIORZADAN_H

#include <vector>
#include "Zadanie.h"

//Tutaj typ kontenera jakiego uzywamy do przechowywania zadan
typedef std::vector<Zadanie> Kontener;

class ZbiorZadan {
private:
    ///Struktura przechowujaca zadania
    Kontener *Zbior;

    ///Wektor przechowujacy numery zadan, kolejnosc w wektorze oznacza kolejnosc wykonywania
    std::vector<int> *KolejnoscZadan;
public:
    ZbiorZadan();

    virtual ~ZbiorZadan();

    /// Funkcja przelczajaca kryterium optymalizacyjne jakim jest suma WiTi
    /// \return Zwraca sume WiTi lub -1 jesli brak zadan
    TypDanych suma_WiTi() const;

};


#endif //WITI_ZBIORZADAN_H

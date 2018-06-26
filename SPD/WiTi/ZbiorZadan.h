//
// Created by maciej on 06.04.18.
//

#ifndef WITI_ZBIORZADAN_H
#define WITI_ZBIORZADAN_H

#include <vector>
#include "Zadanie.h"

//Tutaj typ kontenera jakiego uzywamy do przechowywania zadan
typedef std::vector<Zadanie> Kontener;




//Zbior ->      [Zad1][Zad2]...[ZadN]
//Kolejnosc ->  [nrZadA][nrZadB]...
//Wektor C ->   [koniec1][koniec2]...[koniecN]


class ZbiorZadan {
private:
    ///Struktura przechowujaca zadania
    Kontener *Zbior;

    ///Wektor przechowujacy numery zadan, kolejnosc w wektorze oznacza kolejnosc wykonywania
    ///
    std::vector<int> *KolejnoscZadan;
    std::vector<int> *PermPD;

    ///Wektor przechowujacy czas zakonczenia kazdego zadania
    std::vector<TypDanych > *WektorKoncaZadan;

    ///Wektor przechowujacy wielkosc spoznienia kazdego zadania
    std::vector<TypDanych > *WektorSpoznienia;

    void Wektor_C();
    void Wektor_T();
public:
    ZbiorZadan();

    virtual ~ZbiorZadan();

    /// Funkcja przelczajaca kryterium optymalizacyjne jakim jest suma WiTi
    /// \return Zwraca sume WiTi lub -1 jesli brak zadan
    TypDanych suma_WiTi();
    int getIlosc() const;

    void Dodaj_Zadanie(Zadanie*);
    void WypiszPermutacje()const;
    void WypiszKolejnosc()const;

    void sortP();
    void sortW();
    void sortD();


    int AlgProgDynamicznego();
    void PD_WypiszPermutacje();
    int PrzegladZupelny();

    void PD_PodmienPermutacje();

};


#endif //WITI_ZBIORZADAN_H

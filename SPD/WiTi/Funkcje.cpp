//
// Created by maciej on 12.04.18.
//

#include "Funkcje.h"




int WczytajZbior(const std::string &nazwa_pliku, ZbiorZadan& zbior){
    std::fstream Strm;
    Zadanie* nowe = nullptr;

    int ilosc;
    TypDanych p,w,d;


    Strm.open(nazwa_pliku);
    if(!Strm.good()) return 1;

    if(!Strm.eof()){
        Strm >> ilosc;
        for (int i = 0; i < ilosc; ++i) {
            Strm >> p;
            Strm >> w;
            Strm >> d;

            nowe = new Zadanie((i), p, w, d);
            zbior.Dodaj_Zadanie(nowe);
        }

    }
    delete nowe;
    Strm.close();
    return 0;
}
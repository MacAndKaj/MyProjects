//
// Created by maciej on 20.04.18.
//

#include "Funkcje.h"
#include <fstream>


int WczytajZbior(std::list<ZbiorZadan*> &Lista){
    std::fstream Strm;
    Zadanie* nowe = nullptr;
    ZbiorZadan *zbior = nullptr;
    std::string nazwa;
    int iloscZadan;
    int iloscMaszyn;

    int nrMaszyny;
    int czas;
    std::vector<int> czasWykonania;

    Strm.open("data.txt",ios::in);
    if(!Strm.good()) return 1;

    while(!Strm.eof()){
        Strm >> nazwa;
        Strm >> iloscZadan;
        Strm >> iloscMaszyn;
        zbior =new ZbiorZadan(nazwa,iloscMaszyn);
        for(int i = 0;i<iloscZadan;++i) {
            czasWykonania.clear();
            for (int j = 1; j <= iloscMaszyn; ++j) {
                Strm >> nrMaszyny;
                Strm >> czas;
                czasWykonania.push_back(czas);
            }
            nowe=new Zadanie(i,czasWykonania);
            zbior->DodajZadanie(nowe);
            nowe = nullptr;
        }
        Lista.push_back(zbior);
    }

    Strm.close();
    return 0;
}

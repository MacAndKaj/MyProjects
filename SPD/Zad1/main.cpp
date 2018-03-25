#include <iostream>
#include <fstream>
#include <sstream>
#include "ZbiorZadan.h"
#include "Wczytywacz.h"

void DoplikuDlaWykresow(std::list<Info*> &head){
    ofstream plik;
    plik.open("PlikZWynikami.txt", ios::out);
    stringstream bufor;
    string linia;
    plik << "Format: Ilosc | Wynik nieposortowanego | Wynik SortR | Czas SortR | Wynik 2Opt | Czas 2Opt | Wynik obu | Czas Obu\n";

    for (auto i = head.begin(); i != head.end(); ++i) {
        bufor.str("");
        linia.clear();
        bufor << i.operator*()->getIlosc();
        linia.append(bufor.str());
        linia.append(" ");
        //*************************
        bufor.str("");
        bufor << i.operator*()->getWynikNieposortowanego();
        linia.append(bufor.str());
        linia.append(" ");
        //*************************
        bufor.str("");
        bufor << i.operator*()->getWynikSortR();
        linia.append(bufor.str());
        linia.append(" ");
        //*************************
        bufor.str("");
        bufor << i.operator*()->getCzasSortR();
        linia.append(bufor.str());
        linia.append(" ");
        //*************************
        bufor.str("");
        bufor << i.operator*()->getWynik2Opt();
        linia.append(bufor.str());
        linia.append(" ");
        //*************************
        bufor.str("");
        bufor << i.operator*()->getCzas2Opt();
        linia.append(bufor.str());
        linia.append(" ");
        //*************************
        bufor.str("");
        bufor << i.operator*()->getWynikOba();
        linia.append(bufor.str());
        linia.append(" ");
        //*************************
        bufor.str("");
        bufor << i.operator*()->getCzasOba();
        linia.append(bufor.str());
        linia.append(" ");

        linia.append("\n");
        plik << linia;

    }

}


int main() {
//    std::list<Info*> head(0);
//    DoIT("NazwyPlikow.txt",head);
//    DoplikuDlaWykresow(head);
    ZbiorZadan zad;
    zadania("in200.txt",zad);

    std::cout << zad.SchragePrmt() << std::endl;

    return 0;
}



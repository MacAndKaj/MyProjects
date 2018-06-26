#include <iostream>
#include <fstream>
#include "ZbiorZadan.h"
#include "Funkcje.h"


int main() {
    auto WekNazw = WczytajNazwy("NazwyPlikow.txt");
    for(auto &i : WekNazw){
        std::cout << i << std::endl;
    }

    std::fstream PlikZwynikami;
    PlikZwynikami.open("PlikZWynikami.txt",std::ios::app);
    if(PlikZwynikami.good()) {
        PlikZwynikami << "Format: Ilosc | WynikSortowania | CzasSortowania | WynikPZ | CzasPZ | WynikPD | CzasPD\n";
        for (auto &i : WekNazw) {
            ZbiorZadan zbior;
            Dane wynik = Testy(zbior, i);
            DoPliku(wynik, PlikZwynikami);
        }

    }
    else{
        std::cerr << "Nie ma pliku z wynikami :(" << std::endl;
    }
    PlikZwynikami.close();
    return 0;
}
#include <iostream>
#include <fstream>

#include "ZbiorZadan.h"
#include "Funkcje.h"


int main() {
    ZbiorZadan zbior;
    int ret = WczytajZbior("data10.txt",zbior);
    zbior.WypiszPermutacje();
    if(ret == 0)std::cout << zbior.suma_WiTi() << std::endl;
    else std::cout << "zle wczytano" << std::endl;
    return 0;
}
#include <iostream>
#include "ZbiorZadan.h"
#include "Wczytywacz.h"


int main() {
    std::list<Info*> head(0);
    DoIT2("NazwyPlikow.txt",head);
    DoplikuDlaWykresowZad2(head);
//    ZbiorZadan zad;
//    zadania("in100.txt",zad);
//
//
//    std::cout << zad.Carlier() << std::endl;
//

    return 0;
}



#include <iostream>
#include <list>
#include "ZbiorZadan.h"
#include "Funkcje.h"
#include <vector>
using namespace std;



int main() {
    std::list<ZbiorZadan*> glowa;
    WczytajZbior(glowa);

    for(auto &i : glowa){
        i->NEH();
    }
    return 0;
}
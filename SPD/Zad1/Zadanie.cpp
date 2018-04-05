//
// Created by maciej on 28.02.18.
//

#include <iostream>
#include "Zadanie.h"



void Zadanie::Pokaz() {
    std::cout << "r = " << this->r << " p = " << this->p << " q = " << this->q << std::endl;

}


Zadanie::Zadanie(const Zadanie& arg){
    this->r=arg.getR();
    this->p=arg.getP();
    this->q=arg.getQ();
}

void Zadanie::setP(unsigned int p) {
    Zadanie::p = p;
}

void Zadanie::setQ(unsigned int q) {
    Zadanie::q = q;
}

void Zadanie::setR(unsigned int r) {
    Zadanie::r = r;
}


Zadanie::Zadanie() = default;

//
// Created by maciej on 06.04.18.
//

#include <iostream>
#include "ZbiorZadan.h"


TypDanych ZbiorZadan::suma_WiTi() {
    if (this->Zbior->empty()) return -1;
    this->Wektor_C();
    this->Wektor_T();
    TypDanych suma = 0;

    for (auto &i : *this->KolejnoscZadan) {
        suma += ((*this->Zbior)[i].getW() * (*this->WektorSpoznienia)[i]);
    }
    return suma;
}

ZbiorZadan::ZbiorZadan() {
    this->Zbior = new Kontener();
    this->KolejnoscZadan = new std::vector<int>();
    this->WektorKoncaZadan = nullptr;
    this->WektorSpoznienia = nullptr;
}

ZbiorZadan::~ZbiorZadan() {
    delete this->KolejnoscZadan;
    delete this->Zbior;
    delete this->WektorKoncaZadan;
}


void ZbiorZadan::Wektor_C() {
    if (this->Zbior->empty()) return;
    delete this->WektorKoncaZadan;
    this->WektorKoncaZadan = new std::vector<TypDanych>(this->Zbior->size());
    TypDanych Czas = 0;

    for (auto &i : *this->KolejnoscZadan) {
        Czas += (*this->Zbior)[i].getP();
        (*this->WektorKoncaZadan)[i] = Czas;
    }
}

void ZbiorZadan::Dodaj_Zadanie(Zadanie *ptr) {
    this->Zbior->push_back(*ptr);
    this->KolejnoscZadan->push_back(ptr->getNumerZadania());
}

void ZbiorZadan::WypiszPermutacje() const {
    for (auto &i : *this->KolejnoscZadan) {
        std::cout << "Zadanie nr: " << i+1 << std::endl;
        std::cout << "\tp: " << (*this->Zbior)[i].getP() << " w: " << (*this->Zbior)[i].getW() << " d: "
                  << (*this->Zbior)[i].getD() << std::endl;
    }
}

void ZbiorZadan::Wektor_T() {
    if (this->Zbior->empty()) return;
    if(this->WektorKoncaZadan == nullptr)this->Wektor_C();
    delete this->WektorSpoznienia;
    this->WektorSpoznienia = new std::vector<TypDanych>(this->Zbior->size());

    for (auto &i : *this->KolejnoscZadan) {
        (*this->WektorSpoznienia)[i] = std::max((*this->WektorKoncaZadan)[i]-(*this->Zbior)[i].getD(),0);
    }

}




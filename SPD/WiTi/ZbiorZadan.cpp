//
// Created by maciej on 06.04.18.
//

#include "ZbiorZadan.h"



TypDanych ZbiorZadan::suma_WiTi() const {
    if(this->Zbior->empty()) return -1;
}

ZbiorZadan::ZbiorZadan(){
    this->Zbior = new Kontener();
    this->KolejnoscZadan = new std::vector<int>();
}

ZbiorZadan::~ZbiorZadan() {
    delete this->KolejnoscZadan;
    delete this->Zbior;
}

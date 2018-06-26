//
// Created by maciej on 06.04.18.
//

#include "Zadanie.h"

Zadanie::Zadanie(int NumerZadania, TypDanych p, TypDanych w, TypDanych d) : NumerZadania(NumerZadania), p(p),
                                                                                     w(w), d(d) {}

Zadanie::~Zadanie() = default;

int Zadanie::getNumerZadania() const {
    return NumerZadania;
}

TypDanych Zadanie::getP() const {
    return p;
}

TypDanych Zadanie::getW() const {
    return w;
}

TypDanych Zadanie::getD() const {
    return d;
}

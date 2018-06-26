//
// Created by maciej on 06.04.18.
//

#ifndef WITI_ZADANIE_H
#define WITI_ZADANIE_H

typedef int TypDanych;


class Zadanie {
private:
    int NumerZadania;
    TypDanych p;
    TypDanych w;
    TypDanych d;

public:
    ///Konstruktor zadania, kazdemu na poczatku trzeba stworzyc numer przy tworzeniu zbioru
    /// \param NumerZadania Unikalny numer zadania w zbiorze, jesli poza zbiorem to -1
    /// \param p Czas wykonania zadania
    /// \param w Wspolczynnik kary
    /// \param d zadany termin zakonczenia
    Zadanie(int NumerZadania, TypDanych p, TypDanych w, TypDanych d);

    ///Default destruktor
    virtual ~Zadanie();

    // ----------------------------- Operatory, gettery i settery ---------------------------
    int getNumerZadania() const;

    TypDanych getP() const;

    TypDanych getW() const;

    TypDanych getD() const;

};


#endif //WITI_ZADANIE_H

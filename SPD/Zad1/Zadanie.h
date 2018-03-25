//
// Created by maciej on 28.02.18.
//

#ifndef ZAD1_ZADANIE_H
#define ZAD1_ZADANIE_H


class Zadanie {

private:
    unsigned int r;     //czas przygotowania
    unsigned int p;     //czas wykonywania
    unsigned int q;     //czas dostarczenia
    //zmienna dla algorytmu Scheage z przerwaniami
    int CzasPrzerwania;     //-1 gdy nie uzywany


public:
    Zadanie();

    Zadanie(unsigned int r, unsigned int p, unsigned int q) : r(r), p(p), q(q) {
        CzasPrzerwania=-1;
    }

    Zadanie(const Zadanie&);

//    Zadanie(Zadanie arg):r(arg.getR()),p(arg.getP()),q(arg.getQ()){}
//    void operator=(Zadanie& arg){this->r=arg.getR();this->p=arg.getP();this->q=arg.getQ();}
    virtual ~Zadanie() = default;

    unsigned int getR() const {
        return r;
    }

    unsigned int getP() const {
        return p;
    }

    unsigned int getQ() const {
        return q;
    }



    void Pokaz();

};



#endif //ZAD1_ZADANIE_H

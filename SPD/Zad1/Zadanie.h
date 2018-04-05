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


public:
    Zadanie();

    Zadanie(unsigned int r, unsigned int p, unsigned int q) : r(r), p(p), q(q) {}

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

    void setR(unsigned int r);

    void setP(unsigned int p);

    void setQ(unsigned int q);
};



#endif //ZAD1_ZADANIE_H

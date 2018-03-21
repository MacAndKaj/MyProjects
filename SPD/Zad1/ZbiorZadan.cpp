//
// Created by maciej on 28.02.18.
//

#include <iostream>
#include <algorithm>
#include "ZbiorZadan.h"

//****************          Konstruktory i destruktory      **************

ZbiorZadan::ZbiorZadan() {
    WektorZadan = new std::vector<Zadanie>;
    wekS = nullptr;
    wekC = nullptr;
    LElem = 0;
    licznik = 0;
}



//************************************************************************





void ZbiorZadan::sortR() {
    int liczbaelementow = this->licznik;
    do {
        for (unsigned long i = 0; i < liczbaelementow - 1; ++i) {
            if (this->WektorZadan->operator[](i).getR() > this->WektorZadan->operator[](i + 1).getR()) {
                this->zamien(i,i+1);
            }
        }
        liczbaelementow -= 1;
    } while (liczbaelementow > 1);
}


void ZbiorZadan::alg2opt() {
    this->GenerujWektory();
    int najlepsze = this->fCelu();
//    this->wypisz();


    int check=0;
    int n=this->licznik;

    for (int i = 0; i < n -1; ++i) {
        for (int j = i+1; j < n; ++j) {

            this->zamien(i, j);
            this->GenerujWektory();
            check = this->fCelu();
            if (check < najlepsze) {
				najlepsze = check;
                i=0;
                j=i+1;
            } else this->zamien(i, j);
        }
    }
//    this->wypisz();
}


int ZbiorZadan::fCelu() {
    //pusty wektor
    if (licznik == 0)return -1;
    //*****************
    int i = 0;
    int Cmax = this->wekC->operator[](i) + this->GetElementWektora(i).getQ();
    int n = this->licznik;
    int temp;
    for (i = 1; i < n; ++i) {
        temp = this->wekC->operator[](i) + this->GetElementWektora(i).getQ();
        if (temp > Cmax)
            Cmax = temp;
    }
    return Cmax;
}


void ZbiorZadan::S() {
    int temp;

    if (this)
        this->wekS = new std::vector<int>(static_cast<unsigned long>(this->licznik));
    this->wekS->operator[](0) = this->WektorZadan->operator[](0).getR();

    for (int i = 1; i < licznik; ++i) {
        temp = this->wekS->operator[](i - 1) + this->WektorZadan->operator[](i - 1).getP();

        if (this->GetElementWektora(i).getR() > temp) {

            this->wekS->operator[](i) = this->GetElementWektora(i).getR();

        } else this->wekS->operator[](i) = temp;
    }
//    for (std::vector<int>::const_iterator j = this->wekS->begin(); j < this->wekS->end(); ++j) {
//        std::cout << j.operator*() << std::endl;
//    }
//    std::cout << std::endl;
}


void ZbiorZadan::C() {
    int n = this->licznik;
    std::vector<Zadanie>::const_iterator it = this->WektorZadan->begin();
    std::vector<int>::const_iterator it2 = this->wekS->begin();

    this->wekC = new std::vector<int>(static_cast<unsigned long>(this->licznik));

    for (int i = 0; i < n; ++i) {
        wekC->operator[](i) = it.operator*().getP() + it2.operator*();
        ++it;
        ++it2;
    }

//    for (std::vector<int>::const_iterator j = this->wekC->begin(); j < this->wekC->end(); ++j) {
//        std::cout << j.operator*() << std::endl;
//    }
}
//************************************************************************************************************************

/*
 *      Getery i setery
 */

void ZbiorZadan::setLElem(int LElem) {
    ZbiorZadan::LElem = LElem;
}

int ZbiorZadan::getLElem() const {
    return LElem;
}

Zadanie &ZbiorZadan::GetElementWektora(int indeks) const {
    return this->WektorZadan->operator[](indeks);
}

void ZbiorZadan::SetElementWektora(int &indeks, Zadanie &arg) {
    this->WektorZadan->operator[](indeks) = arg;
}


/*
 *      Dodaje zadania do zbioru
 */
void ZbiorZadan::Dodaj(Zadanie zadanko) {
    if (licznik != LElem) {
        this->WektorZadan->push_back(zadanko);
        this->licznik += 1;
    }
}


void ZbiorZadan::wypisz() {
    for (int i = 0; i < licznik; ++i) {
        std::cout << "r=" << this->WektorZadan->operator[](i).getR();
        std::cout << " p=" << this->WektorZadan->operator[](i).getP();
        std::cout << " q=" << this->WektorZadan->operator[](i).getQ() << std::endl;
    }
    std::cout << std::endl;

}

void ZbiorZadan::GenerujWektory() {
    if (this->wekS != nullptr) {
        delete this->wekC;
        delete this->wekS;
        this->wekC = nullptr;
        this->wekS = nullptr;
    }
    this->S();
    this->C();
}

void ZbiorZadan::zamien(int i, int j) {
    Zadanie temp(this->WektorZadan->operator[](i));
    this->WektorZadan->operator[](i)=this->WektorZadan->operator[](j);
    this->WektorZadan->operator[](j)=temp;
}

int ZbiorZadan::Schrage() {
    int Cmax=0;
    int t=0;
    int k=0;
    Zadanie temp;
    std::vector<int> PermCzesciowa(this->getLElem());
    auto *G_WekGotowych=new std::vector<Zadanie>();

    this->sortR();
    while(!G_WekGotowych->empty() || !this->WektorZadan->empty()) {

        while(!this->WektorZadan->empty() && this->GetElementWektora(0).getR() <= t){
            if(G_WekGotowych->empty()){
                t=this->GetElementWektora(0).getR();
            }
            temp=this->GetElementWektora(0);
            this->WektorZadan->erase(this->WektorZadan->begin());
            G_WekGotowych->push_back(temp);
        }
        int indeks=0,pom=0;
        int tempQ=this->GetElementWektora(0).getQ();
        if(!G_WekGotowych->empty()) {
            for (auto i = G_WekGotowych->begin() + 1; i != G_WekGotowych->end(); ++i) {
                if (i.operator*().getQ() > tempQ) {
                    tempQ = i.operator*().getQ();
                    indeks = pom;
                }
                ++pom;
            }
        }

        ++k;
        temp=G_WekGotowych->operator[](indeks);
        PermCzesciowa[k]=indeks;
        t+=temp.getP();
        Cmax=std::max(static_cast<unsigned int>(Cmax),t+temp.getQ());
    }

    return Cmax;
}


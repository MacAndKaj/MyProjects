//
// Created by maciej on 06.04.18.
//

#include <iostream>
#include <cmath>
#include <algorithm>
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
    this->PermPD = nullptr;
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
        std::cout << "Zadanie nr: " << i + 1 << std::endl;
        std::cout << "\tp: " << (*this->Zbior)[i].getP() << " w: " << (*this->Zbior)[i].getW() << " d: "
                  << (*this->Zbior)[i].getD() << std::endl;
    }
}

void ZbiorZadan::Wektor_T() {
    if (this->Zbior->empty()) return;
    if (this->WektorKoncaZadan == nullptr)this->Wektor_C();
    delete this->WektorSpoznienia;
    this->WektorSpoznienia = new std::vector<TypDanych>(this->Zbior->size());

    for (auto &i : *this->KolejnoscZadan) {
        (*this->WektorSpoznienia)[i] = std::max((*this->WektorKoncaZadan)[i] - (*this->Zbior)[i].getD(), 0);
    }

}

void ZbiorZadan::sortP() {
    unsigned long n = this->Zbior->size();
    int firstIndex = 0, secondIndex = 0;
    do {
        for (int i = 0; i < n - 1; ++i) {
            firstIndex = (*this->KolejnoscZadan)[i];
            secondIndex = (*this->KolejnoscZadan)[i + 1];
            if ((*this->Zbior)[firstIndex].getP() > (*this->Zbior)[secondIndex].getP()) {
                std::swap((*this->KolejnoscZadan)[i], (*this->KolejnoscZadan)[i + 1]);
            }
        }
        --n;
    } while (n > 1);
}

void ZbiorZadan::sortW() {
    unsigned long n = this->Zbior->size();
    int firstIndex = 0, secondIndex = 0;
    do {
        for (int i = 0; i < n - 1; ++i) {
            firstIndex = (*this->KolejnoscZadan)[i];
            secondIndex = (*this->KolejnoscZadan)[i + 1];
            if ((*this->Zbior)[firstIndex].getW() < (*this->Zbior)[secondIndex].getW()) {
                std::swap((*this->KolejnoscZadan)[i], (*this->KolejnoscZadan)[i + 1]);
            }
        }
        --n;
    } while (n > 1);
}

void ZbiorZadan::sortD() {
    unsigned long n = this->Zbior->size();
    int firstIndex = 0, secondIndex = 0;
    do {
        for (int i = 0; i < n - 1; ++i) {
            firstIndex = (*this->KolejnoscZadan)[i];
            secondIndex = (*this->KolejnoscZadan)[i + 1];
            if ((*this->Zbior)[firstIndex].getD() < (*this->Zbior)[secondIndex].getD()) {
                std::swap((*this->KolejnoscZadan)[i], (*this->KolejnoscZadan)[i + 1]);
            }
        }
        --n;
    } while (n > 1);
}

void ciagi(std::vector<int> &ptr, int &iter, unsigned long liczba) {
    for (auto &i : ptr) {
        i = 0;
    }
    std::vector<int> miejsca;
    int temp = iter;
    int index = 0;
    while (temp != 0) {
        if (temp % 2 == 1)miejsca.push_back(index);
        temp /= 2;
        ++index;
    }


    for (auto &i : miejsca) {
        ptr[i] = 1;
    }
}
//  Zbior zadan  ---->  [Zad1][Zad2][Zad3]...[ZadN]
//  Ciag bitowy  ---->  [boolZad1][boolZad2][boolZad3]...[boolZadN]
//int ZbiorZadan::AlgProgDynamicznego() {
//    unsigned long LiczbaZadan=this->Zbior->size();
//    double liczbaIteracji = pow(2, LiczbaZadan) - 1;
//    TypDanych DoWiti=0;
//    TypDanych Pom=0;
//    TypDanych Max=0;
//    std::vector<TypDanych> DoMin;
//    //pojedynczy ciag
//    std::vector<int> ciag(LiczbaZadan);
//
//    //wektor wszystkich stworzonych ciagow
//    std::vector<std::vector<int>> ZbiorCiagow;
//
//    //wyniki dla poszczegolnych ciagow
//    std::vector<TypDanych> WiTi(static_cast<unsigned long>(liczbaIteracji));
//
//    //wyznaczamy ciagi
//    for(int i=1;i<=liczbaIteracji;++i){
//        ciagi(ciag,i,LiczbaZadan);
//        ZbiorCiagow.push_back(ciag);
//    }
//
//
//    for (int j = 0; j <liczbaIteracji; ++j) {                       //iteracja po kolejnych ciagach
//        ciag = ZbiorCiagow[j];
//
//        Pom=0;
//        Max=0;
//        DoMin.clear();
//        for (int i = 0; i < LiczbaZadan; ++i) {                     //iteracja dla roznych d
//            if(ciag[i]==1){
//                for (int k = 0; k < LiczbaZadan; ++k) {             //iteracja kolejnych p
//                    if(ciag[k]==1) {
//                        Pom += (*this->Zbior)[k].getP();
//                    }
//                }
//                Pom-=(*this->Zbior)[i].getD();
//                Max=std::max(Pom,0);
//                Max*=(*this->Zbior)[i].getW();
//
//                for(int x = 0;x <= i;++x){
//                    auto nr = static_cast<int>(pow(2, x) - 1);
//                    Max+=WiTi[j-nr];
//                }
//            }
//            DoMin.push_back(Max);
//        }
//
//
//        auto it=std::min_element(DoMin.begin(),DoMin.end());
//        DoWiti = *it;
//
//        WiTi[j]=DoWiti;
//    }
//    int index=1;
//    for (auto &i : WiTi){
//        std::cout << "Iteracja nr " <<index<< " Witi: " << i << std::endl;
//        ++index;
//    }
//}


int ZbiorZadan::AlgProgDynamicznego() {
    int cmax, pomoc;
    int iloscZadan = this->Zbior->size();
    int liczbaPermutacji = std::pow(2, iloscZadan);

    auto *F = new int[liczbaPermutacji];
    auto ost = new int[liczbaPermutacji];


    F[0] = 0;

    for (int index = 1; index < liczbaPermutacji; ++index) {
        cmax = 0;
        F[index] = 999999;
        for (int zad = 0, maska = 1; zad < iloscZadan; ++zad, maska *= 2) {
            if (index & maska) cmax += (*this->Zbior)[zad].getP();
        }
        for (int zad = 0, maska = 1; zad < iloscZadan; ++zad, maska *= 2) {
            if (index & maska) {
                if ((pomoc = F[index - maska] +
                             std::max(0, (cmax - (*this->Zbior)[zad].getD()) * (*this->Zbior)[zad].getW())) <
                    F[index]) {
                    F[index] = pomoc;
                    ost[index] = zad + 1;
                }
            }
        }
    }
    this->PermPD = new std::vector<int>(1);
    int problem=liczbaPermutacji-1, zadanie=ost[problem];
    (*this->PermPD)[0]=zadanie;
    for(int i=1; i<iloscZadan; i++)
    {
        problem=problem & (~(1<<(zadanie-1)));
        zadanie=ost[problem];
        this->PermPD->push_back(zadanie);
    }

    return F[liczbaPermutacji - 1];
}

unsigned long silnia(int &liczba) {
    unsigned long temp = 1;
    for (int i = 1; i < liczba + 1; ++i) temp *= i;

    return temp;
}

int ZbiorZadan::PrzegladZupelny() {
    int liczbaZadan = this->Zbior->size();
    unsigned long rozm = silnia(liczbaZadan);
    std::vector<TypDanych> kary(rozm);
    std::vector<int> zadania(liczbaZadan);
    int t = 0, kara = 0, pomoc = 0, minimum = 0;


    for (int i = 0; i < liczbaZadan; ++i)zadania[i] = i;
    do {
        pomoc = 0;
        kara = 0;
        t = 0;
        for (int i = 0; i < liczbaZadan; i++) {
            t += (*this->Zbior)[zadania[i]].getP();
            pomoc = (t - (*this->Zbior)[zadania[i]].getD()) * (*this->Zbior)[zadania[i]].getW();
            if (pomoc > 0) kara += pomoc;
        }
        kary[rozm - 1] = kara;
        --rozm;
    } while (std::next_permutation(zadania.begin(), zadania.end()));
    rozm = silnia(liczbaZadan);

    minimum = *(std::min_element(kary.begin(), kary.end()));
    return minimum;
}

void ZbiorZadan::PD_WypiszPermutacje() {
    if(this->PermPD == nullptr){
        std::cerr << "Brak permutacji" << std::endl;
        return;
    }
    for(auto it = this->PermPD->rbegin() ; it != this->PermPD->rend();++it){
        std::cout << *it << " ";
    }

}

void ZbiorZadan::PD_PodmienPermutacje() {
    int index=0;
    for(auto && i : *this->KolejnoscZadan){
        i=(*this->PermPD)[index];
        ++index;
    }
}

void ZbiorZadan::WypiszKolejnosc() const {
    for (auto i=this->KolejnoscZadan->rbegin();i!=this->KolejnoscZadan->rend();++i){
        std:: cout << *i << " ";
    }

}

int ZbiorZadan::getIlosc() const {
    if(this->Zbior== nullptr)return 0;
    return static_cast<int>(this->Zbior->size());
}



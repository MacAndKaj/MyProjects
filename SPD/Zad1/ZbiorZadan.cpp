//
// Created by maciej on 28.02.18.
//

#include <iostream>
#include <algorithm>
#include "ZbiorZadan.h"


//                              Niezalezne funkcje pomocnicze
/***************************************************************************/

/// \brief Funkcja szukajaca w wektorze zadan takiego z najwiekszym q.
/// \param wek Referencja do wektora z zadaniami
/// \return Zwraca iterator z kopia najwiekszego zadania
std::vector<Zadanie>::iterator Znajdz_Zad_Max_Q(std::vector<Zadanie> &wek) {
    if(wek.size()==1)
        return wek.begin();

    auto temp = wek.begin();
    for(auto it=wek.begin()+1;it != wek.end();++it){
        if((*temp).getQ()<(*it).getQ()){
            temp=it;
        }
    }

    return temp;
}

/// \brief Funkcja zwracajaca indeks elementu wektora - zadania z najwiekszym q.
/// \param wek Referencja do wektora z zadaniami.
/// \return Indeks elementu.
int Iterator_Zad_Max_Q(std::vector<Zadanie> &wek) {
    if(wek.size()==1) return 0;
    auto temp = wek.begin();
    int indeks=0,loc=0;
    for(auto it=wek.begin();it != wek.end();++it){
        std::cout << "Porownuje: " << it->getQ() << " z " << temp->getQ() << std::endl;
        if((*temp).getQ()<(*it).getQ()){

            temp=it;
            indeks=loc;
        }
        ++loc;
    }
    std::cout << "indeks: " << indeks << std::endl;
    return indeks;
}
void swapElements(std::vector<Zadanie> &wek,int i, int j) {
    Zadanie temp(wek.operator[](i));
    wek.operator[](i)=wek.operator[](j);
    wek.operator[](j)=temp;
}
void sortmax(std::vector<Zadanie> &wek){
    int liczbaelementow = static_cast<int>(wek.size());
    do {
        for (unsigned long i = 0; i < liczbaelementow - 1; ++i) {
            if (wek.operator[](i).getQ() < wek.operator[](i + 1).getQ()) {
                swapElements(wek,i,i+1);
            }
        }
        liczbaelementow -= 1;
    } while (liczbaelementow > 1);
}



//****************          Konstruktory i destruktory      **************

ZbiorZadan::ZbiorZadan() {
    WektorZadan = new std::vector<Zadanie>;
    wekS = nullptr;
    wekC = nullptr;
    LElem = 0;
    licznik = 0;
}

ZbiorZadan::~ZbiorZadan() {
    delete this->WektorZadan;
    if(this->wekS != nullptr){
        delete this->wekS;
        delete this->wekC;
    }
}

//************************************************************************


//                          Algorytmy


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

int ZbiorZadan::Schrage() {
    //TODO ogarnac!!!
    /**************************     Inicjalizacja potrzebnych zmiennych i struktur      ****************************/
    this->sortR();      //
    std::vector<Zadanie>::iterator iter;
    //perm czesciowa zawiera indeksy kolejnych zadan, jest gotowy po skonczeniu dzialania algorutmy
    std::vector<Zadanie> PermutacjaCzesciowa;
    std::vector<Zadanie> Uporzadkowane;

    std::vector<Zadanie> Nieuporzadkowane;
    for (auto &i : *this->WektorZadan) {
        Nieuporzadkowane.push_back(i);
    }
    unsigned int t=0;
    unsigned int Cmax=0;

    while(!Nieuporzadkowane.empty() || !Uporzadkowane.empty()){

        pusteG:
        while (!Nieuporzadkowane.empty() && (Nieuporzadkowane.begin()->getR() <= t)) {
            Uporzadkowane.push_back(*Nieuporzadkowane.begin());
            Nieuporzadkowane.erase(Nieuporzadkowane.begin());
        }
        if(Uporzadkowane.empty()){
            t=Nieuporzadkowane.begin()->getR();
            goto pusteG;
        }

        sortmax(Uporzadkowane);                                 //Szukamy zadania z najwiekszym q
        std::cout << "*************************************************" << std::endl;
        for (auto &i : Uporzadkowane) {
            i.Pokaz();
        }
        std::cout << "**************************************************" << std::endl << std::endl;

        PermutacjaCzesciowa.push_back(*Uporzadkowane.begin());
        Uporzadkowane.erase(Uporzadkowane.begin());

        t = t + (PermutacjaCzesciowa.back().getP());

        Cmax=std::max(Cmax,t+PermutacjaCzesciowa.begin()->getQ());

    }

    std::cout << "Czas" << t<<  ". Permutacja:" << std::endl;

    delete this->WektorZadan;
    this->WektorZadan=new std::vector<Zadanie>();
    for (auto &i : PermutacjaCzesciowa) {
        i.Pokaz();
        this->WektorZadan->push_back(i);
    }

    return Cmax;
}

int ZbiorZadan::SchragePrmt() {
/**************************     Inicjalizacja potrzebnych zmiennych i struktur      ****************************/
    this->sortR();      //
    std::vector<Zadanie>::iterator iter;
    //perm czesciowa zawiera indeksy kolejnych zadan, jest gotowy po skonczeniu dzialania algorutmy
    std::vector<Zadanie> PermutacjaCzesciowa;
    std::vector<Zadanie> Uporzadkowane;

    std::vector<Zadanie> Nieuporzadkowane;
    for (auto &i : *this->WektorZadan) {
        Nieuporzadkowane.push_back(i);
    }
    Zadanie* l= nullptr;


    unsigned int t=0;
    unsigned int Cmax=0;

    while(!Nieuporzadkowane.empty() || !Uporzadkowane.empty()){

        pusteG:
        while (!Nieuporzadkowane.empty() && (Nieuporzadkowane.begin()->getR() <= t)) {
            Uporzadkowane.push_back(*Nieuporzadkowane.begin());
            Nieuporzadkowane.erase(Nieuporzadkowane.begin());
            if(Uporzadkowane.begin()->getQ() > )

        }
        if(Uporzadkowane.empty()){
            t=Nieuporzadkowane.begin()->getR();
            goto pusteG;
        }

        sortmax(Uporzadkowane);                                 //Szukamy zadania z najwiekszym q

        l=&(*Uporzadkowane.begin());
        t=t+Uporzadkowane.begin()->getP();
        Cmax=std::max(Cmax,t+Uporzadkowane.begin()->getQ());

        Uporzadkowane.erase(Uporzadkowane.begin());

    }

    std::cout << "Czas" << t<<  ". Permutacja:" << std::endl;

    delete this->WektorZadan;
    this->WektorZadan=new std::vector<Zadanie>();
    for (auto &i : PermutacjaCzesciowa) {
        i.Pokaz();
        this->WektorZadan->push_back(i);
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

int ZbiorZadan::fCelu() {
    //pusty wektor
    if (licznik == 0)return -1;
    //*****************
    this->GenerujWektory();
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

void ZbiorZadan::setWektorZadan(std::vector<Zadanie> *WektorZadan) {
    ZbiorZadan::WektorZadan = WektorZadan;
    this->LElem = this->licznik = static_cast<int>(WektorZadan->size());
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


/*
 *      Wypisuje w zadowalajacym formacie
 */
void ZbiorZadan::wypisz() {
    for (int i = 0; i < licznik; ++i) {
        std::cout << "r=" << this->WektorZadan->operator[](i).getR();
        std::cout << " p=" << this->WektorZadan->operator[](i).getP();
        std::cout << " q=" << this->WektorZadan->operator[](i).getQ() << std::endl;
    }
    std::cout << std::endl;

}


/*
 *      Swap dla mojego zadania
 */
void ZbiorZadan::zamien(int i, int j) {
    Zadanie temp(this->WektorZadan->operator[](i));
    this->WektorZadan->operator[](i)=this->WektorZadan->operator[](j);
    this->WektorZadan->operator[](j)=temp;
}





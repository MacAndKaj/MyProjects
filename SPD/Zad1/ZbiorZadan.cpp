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
    if (wek.size() == 1)
        return wek.begin();

    auto temp = wek.begin();
    for (auto it = wek.begin() + 1; it != wek.end(); ++it) {
        if ((*temp).getQ() < (*it).getQ()) {
            temp = it;
        }
    }

    return temp;
}

/// \brief Funkcja zwracajaca indeks elementu wektora - zadania z najwiekszym q.
/// \param wek Referencja do wektora z zadaniami.
/// \return Indeks elementu.
int Iterator_Zad_Max_Q(std::vector<Zadanie> &wek) {
    if (wek.size() == 1) return 0;
    auto temp = wek.begin();
    int indeks = 0, loc = 0;
    for (auto it = wek.begin(); it != wek.end(); ++it) {
        if ((*temp).getQ() < (*it).getQ()) {

            temp = it;
            indeks = loc;
        }
        ++loc;
    }
    return indeks;
}


/// Funkcja zamieniajaca miejscami elementy wektora
/// \param wek Referencja do wektora w ktorym maja byc zamienione elementy
/// \param i indeks pierwszego elementu
/// \param j indeks drugiego elementu
void swapElements(std::vector<Zadanie> &wek, int i, int j) {
    Zadanie temp(wek.operator[](i));
    wek.operator[](i) = wek.operator[](j);
    wek.operator[](j) = temp;
}

/// Algorytm sortowania babelkowego od najwiekszego q do najmniejszego
/// \param wek Wektor do sortowania.
void sortmax(std::vector<Zadanie> &wek) {
    auto liczbaelementow = static_cast<int>(wek.size());
    do {
        for (unsigned long i = 0; i < liczbaelementow - 1; ++i) {
            if (wek.operator[](i).getQ() < wek.operator[](i + 1).getQ()) {
                swapElements(wek, i, i + 1);
            }
        }
        liczbaelementow -= 1;
    } while (liczbaelementow > 1);
}

int CzasZakonczeniaZadania(std::vector<Zadanie> &wek,int i){
    if(wek.empty()) return 0;
    std::vector<int> S, C;
    S.push_back(wek.begin()->getR());
    C.push_back(*S.begin() + wek.begin()->getP());

    for (auto i = ++wek.begin(); i != wek.end(); ++i) {
        S.push_back((int &&) std::max(i->getR(), S.back() + (i - 1)->getP()));
        C.push_back(S.back() + i->getP());
    }

    return C[i];
}

/// Uogolnienie wyliczania Cmax dla kazdego wektora zadan
/// \param wek Wektor z zadaniami.
/// \return Cmax wektora
int CmaxWek(std::vector<Zadanie> &wek) {
    if(wek.empty()) return 0;
    std::vector<int> S, C;
    S.push_back(wek.begin()->getR());
    C.push_back(*S.begin() + wek.begin()->getP());

    for (auto i = ++wek.begin(); i != wek.end(); ++i) {
        S.push_back((int &&) std::max(i->getR(), S.back() + (i - 1)->getP()));
        C.push_back(S.back() + i->getP());
    }
    int i = 0;
    int Cmax = C[i] + wek[i].getQ();
    int n = static_cast<int>(wek.size());
    int temp;
    for (i = 1; i < n; ++i) {
        temp = C[i] + wek[i].getQ();
        if (temp > Cmax)
            Cmax = temp;
    }

    return Cmax;
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
    if (this->wekS != nullptr) {
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
                this->zamien(i, i + 1);
            }
        }
        liczbaelementow -= 1;
    } while (liczbaelementow > 1);
}

void ZbiorZadan::alg2opt() {
    this->GenerujWektory();
    int najlepsze = this->fCelu();
//    this->wypisz();


    int check = 0;
    int n = this->licznik;

    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {

            this->zamien(i, j);
            this->GenerujWektory();
            check = this->fCelu();
            if (check < najlepsze) {
                najlepsze = check;
                i = 0;
                j = i + 1;
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
    std::vector<Zadanie> Gotowe;

    std::vector<Zadanie> Nieuporzadkowane;
    for (auto &i : *this->WektorZadan) {
        Nieuporzadkowane.push_back(i);
    }
    unsigned int t = 0;
    unsigned int Cmax = 0;

    while (!Nieuporzadkowane.empty() || !Gotowe.empty()) {

        pusteG:
        while (!Nieuporzadkowane.empty() && (Nieuporzadkowane.begin()->getR() <= t)) {
            Gotowe.push_back(*Nieuporzadkowane.begin());
            Nieuporzadkowane.erase(Nieuporzadkowane.begin());
        }
        if (Gotowe.empty()) {
            t = Nieuporzadkowane.begin()->getR();
            goto pusteG;
        }

        sortmax(Gotowe);                                 //Szukamy zadania z najwiekszym q

        PermutacjaCzesciowa.push_back(*Gotowe.begin());
        Gotowe.erase(Gotowe.begin());

        t = t + (PermutacjaCzesciowa.back().getP());

        Cmax = std::max(Cmax, t + PermutacjaCzesciowa.back().getQ());

    }


    delete this->WektorZadan;
    this->WektorZadan = new std::vector<Zadanie>();
    for (auto &i : PermutacjaCzesciowa) {
        this->WektorZadan->push_back(i);
    }

    return CmaxWek(PermutacjaCzesciowa);
}

int ZbiorZadan::Schrage(std::vector<Zadanie> &wek) {
    /**************************     Inicjalizacja potrzebnych zmiennych i struktur      ****************************/
//    int liczbaelementow = static_cast<int>(wek.size());
//    do {
//        for (unsigned long i = 0; i < liczbaelementow - 1; ++i) {
//            if (wek.operator[](i).getR() > wek.operator[](i + 1).getR()) {
//                this->zamien(i, i + 1);
//            }
//        }
//        liczbaelementow -= 1;
//    } while (liczbaelementow > 1);      //


    //perm czesciowa zawiera indeksy kolejnych zadan, jest gotowy po skonczeniu dzialania algorutmy
    std::vector<Zadanie> PermutacjaCzesciowa;
    std::vector<Zadanie> Uporzadkowane;
    std::vector<Zadanie> Nieuporzadkowane;

    std::vector<Zadanie>::iterator e;
    for (auto &i : wek) {
        Nieuporzadkowane.push_back(i);
    }
    unsigned int t = 0;
    unsigned int Cmax = 0;

    while (!Nieuporzadkowane.empty() || !Uporzadkowane.empty()) {
        int MinRwN=0;
        for(int i=0;i<Nieuporzadkowane.size();++i){
            if (Nieuporzadkowane[i].getR()<Nieuporzadkowane[MinRwN].getR())MinRwN=i;
        }
        PusteG:
        while (!Nieuporzadkowane.empty() && (Nieuporzadkowane[MinRwN].getR() <= t)) {

            e=Nieuporzadkowane.begin()+MinRwN;
            Uporzadkowane.push_back(*e);
            Nieuporzadkowane.erase(e);
            MinRwN=0;
            for(int i=0;i<Nieuporzadkowane.size();++i){
                if (Nieuporzadkowane[i].getR()<Nieuporzadkowane[MinRwN].getR())MinRwN=i;
            }
        }
        if (Uporzadkowane.empty()) {
            int tmp=0;
            for(int i=0;i<Nieuporzadkowane.size();++i){
                if (Nieuporzadkowane[i].getR()<Nieuporzadkowane[tmp].getR())tmp=i;
            }
            t = Nieuporzadkowane[tmp].getR();
            goto PusteG;
        }

        int tmp=0;
        for(int i=0;i<Uporzadkowane.size();++i){
            if(Uporzadkowane[i].getQ() > Uporzadkowane[tmp].getQ()) tmp=i;
        }
        e=Uporzadkowane.begin()+tmp;

        PermutacjaCzesciowa.push_back(*e);
        Uporzadkowane.erase(e);

        t = t + (PermutacjaCzesciowa.back().getP());

        Cmax = std::max(Cmax, t + PermutacjaCzesciowa.back().getQ());

    }
    wek.clear();
    for(auto &i : PermutacjaCzesciowa){
        wek.push_back(i);
//        i.Pokaz();
    }

    return CmaxWek(PermutacjaCzesciowa);

}

int ZbiorZadan::SchragePrmt() {
/**************************     Inicjalizacja potrzebnych zmiennych i struktur      ****************************/
    this->sortR();      //
    std::vector<Zadanie> Gotowe_Do_Realizacji;
    std::vector<Zadanie> Nieuszeregowane;

    //Algorytm bedzie dzialal na kopii
    for (auto &i : *this->WektorZadan) {
        Nieuszeregowane.push_back(i);

    }
    Zadanie l(0, 0, 99999);

    unsigned int t = 0;
    unsigned int Cmax = 0;

    while (!Nieuszeregowane.empty() || !Gotowe_Do_Realizacji.empty()) {

        pusteG:
        while (!Nieuszeregowane.empty() && (Nieuszeregowane.begin()->getR() <= t)) {
            Gotowe_Do_Realizacji.push_back(*Nieuszeregowane.begin());
            if (Gotowe_Do_Realizacji.crbegin()->getQ() > l.getQ()) {
                l.setP(t - Gotowe_Do_Realizacji.crbegin()->getR());
                t = Gotowe_Do_Realizacji.crbegin()->getR();
                if (l.getP() > 0) {
                    Gotowe_Do_Realizacji.push_back(l);
                }
            }
            Nieuszeregowane.erase(Nieuszeregowane.begin());
        }
        if (Gotowe_Do_Realizacji.empty()) {
            t = Nieuszeregowane.begin()->getR();
            goto pusteG;
        }
        sortmax(Gotowe_Do_Realizacji);  //Szukamy zadania z najwiekszym q
        l = *Gotowe_Do_Realizacji.begin();
        Gotowe_Do_Realizacji.erase(Gotowe_Do_Realizacji.begin());
        t = t + l.getP();
        Cmax = std::max(Cmax, t + l.getQ());
    }

    return Cmax;
}

int ZbiorZadan::SchragePrmt(std::vector<Zadanie> &wek) {

    int liczbaelementow = static_cast<int>(wek.size());
    do {
        for (unsigned long i = 0; i < liczbaelementow - 1; ++i) {
            if (wek.operator[](i).getR() > wek.operator[](i + 1).getR()) {
                this->zamien(i, i + 1);
            }
        }
        liczbaelementow -= 1;
    } while (liczbaelementow > 1);      //

    std::vector<Zadanie> Gotowe_Do_Realizacji;
    std::vector<Zadanie> Nieuszeregowane;

    //Algorytm bedzie dzialal na kopii
    for (auto &i : wek) {
        Nieuszeregowane.push_back(i);

    }
    Zadanie l(0, 0, 99999);

    unsigned int t = 0;
    unsigned int Cmax = 0;

    while (!Nieuszeregowane.empty() || !Gotowe_Do_Realizacji.empty()) {

        pusteG:
        while (!Nieuszeregowane.empty() && (Nieuszeregowane.begin()->getR() <= t)) {
            Gotowe_Do_Realizacji.push_back(*Nieuszeregowane.begin());
            if (Gotowe_Do_Realizacji.crbegin()->getQ() > l.getQ()) {
                l.setP(t - Gotowe_Do_Realizacji.crbegin()->getR());
                t = Gotowe_Do_Realizacji.crbegin()->getR();
                if (l.getP() > 0) {
                    Gotowe_Do_Realizacji.push_back(l);
                }
            }
            Nieuszeregowane.erase(Nieuszeregowane.begin());
        }
        if (Gotowe_Do_Realizacji.empty()) {
            t = Nieuszeregowane.begin()->getR();
            goto pusteG;
        }
        sortmax(Gotowe_Do_Realizacji);  //Szukamy zadania z najwiekszym q
        l = *Gotowe_Do_Realizacji.begin();
        Gotowe_Do_Realizacji.erase(Gotowe_Do_Realizacji.begin());
        t = t + l.getP();
        Cmax = std::max(Cmax, t + l.getQ());
    }

    return Cmax;
}

int ZbiorZadan::Carlier() {
    //----------struktury pomocnicze--------------
    std::vector<Zadanie> VECTORrpq;
    std::vector<Zadanie> *Permutacja = new std::vector<Zadanie>();
    std::vector<Zadanie> *PermOpt = new std::vector<Zadanie>();
    //--------------------------------------------
    for (auto &i : *this->WektorZadan) {
        VECTORrpq.push_back(i);
        Permutacja->push_back(i);
    }
    int UB = CmaxWek(*Permutacja);

    int CmaxRet = CmaxWek(*this->DoCarlier(VECTORrpq, Permutacja, PermOpt, UB));

    delete this->WektorZadan;
    this->WektorZadan=PermOpt;
    delete Permutacja;

    return CmaxRet;
}


std::vector<Zadanie> * ZbiorZadan::DoCarlier(std::vector<Zadanie> &wekRPQ, std::vector<Zadanie> *Perm, std::vector<Zadanie> *PermOpt,
                      int &UB) {
    int CmaxPI=0;
    unsigned int rPRIM=0, pPRIM=0, qPRIM=0;
    unsigned int rDoOdtworzenia=0,qDoOdtworzenia=0;
    std::vector<Zadanie>::iterator a,b,c;
    int U = this->Schrage(*Perm);
    int LB = 0;


    if (U < UB) {
        UB = U;
        if (PermOpt != nullptr)delete PermOpt;
        PermOpt = new std::vector<Zadanie>();
        for (auto &i : *Perm) {
            PermOpt->push_back(i);
        }
    }

    //------------------------------------Wyznaczanie bloku (a,b) oraz zadania c ----------------------------
    CmaxPI=CmaxWek(*Perm);
    int iter= static_cast<int>(Perm->size());
    bool found = false;
    while(!found && iter >= 0){
        if(CmaxPI == (CzasZakonczeniaZadania(*Perm,iter)+(Perm->operator[](iter).getQ())))
            found=true;
        else --iter;
    }
    int IterB=iter;
    b=(Perm->begin()+IterB);

    found = false;
    iter = 0;
    while(!found && iter < IterB){
        int suma=0;
        for(int s=iter;s<=IterB;++s){
            suma+=Perm->operator[](s).getP();
        }
        if((Perm->operator[](iter).getR()+suma+(Perm->operator[](IterB).getQ())) == CmaxPI)
            found=true;
        else ++iter;
    }
    int IterA=iter;
    a=(Perm->begin()+IterA);

    int IterC=-1;
    for (int i = IterA; i <= IterB; ++i) {
        if (Perm->operator[](i).getQ() < Perm->operator[](IterB).getQ()) IterC=i;
    }
    if (IterC == -1) return Perm;
    else c = (Perm->begin()+IterC);
    //---------------------------------------------------------------------------------------------------------
    //----------------------Wyznaczamy rPrim,pPrim,qPrim-------------------------------------------------------
    rPRIM=9999;
    for (int j = IterC+1; j <= IterB; ++j) {
        if(Perm->operator[](j).getR() < rPRIM) rPRIM=Perm->operator[](j).getR();
    }
    qPRIM=9999;
    for (int k = IterC+1; k <= IterB; ++k) {
        if(Perm->operator[](k).getQ() < qPRIM) qPRIM=Perm->operator[](k).getQ();
    }
    pPRIM=0;
    for (int l = IterC+1; l <= IterB; ++l) {
        pPRIM+=Perm->operator[](l).getP();
    }


    rDoOdtworzenia=c->getR();
    c->setR(std::max(c->getR(),rPRIM+pPRIM));

    LB = this->SchragePrmt(*Perm);
    if (LB < UB) {
        this->DoCarlier(wekRPQ, Perm, PermOpt, UB);
    }

    c->setR(rDoOdtworzenia);


    qDoOdtworzenia=c->getQ();
    c->setQ(std::max(c->getQ(),qPRIM+pPRIM));

    LB = this->SchragePrmt(*Perm);
    if (LB < UB) {
        this->DoCarlier(wekRPQ, Perm, PermOpt, UB);
    }
    c->setQ(qDoOdtworzenia);
    return PermOpt;
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
    this->WektorZadan->operator[](i) = this->WektorZadan->operator[](j);
    this->WektorZadan->operator[](j) = temp;
}

//int ZbiorZadan::test() {
//    return this->Schrage(*this->WektorZadan);
//}





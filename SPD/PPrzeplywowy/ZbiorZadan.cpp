//
// Created by maciej on 20.04.18.
//

#include "ZbiorZadan.h"

ZbiorZadan::~ZbiorZadan() {
    delete this->zbior;
}

ZbiorZadan::ZbiorZadan(const string &nazwa, int &iloscmaszyn) : nazwa(nazwa), iloscMaszyn(iloscmaszyn) {
    this->zbior = new vector<Zadanie *>();
}

void ZbiorZadan::DodajZadanie(Zadanie *ptr) {
    if (ptr != nullptr) this->zbior->push_back(ptr);
}


int ZbiorZadan::ileZadan() const {
    if (this->zbior == nullptr)return 0;
    else return static_cast<int>(this->zbior->size());
}

const string &ZbiorZadan::getNazwa() const {
    return nazwa;
}


int ZbiorZadan::NEH() const {
    if (this->zbior->empty()) return 0;

    vector<int> omega, kolejnosc, C, Perm;
    vector<pair<int, int>> Ctemp; //para:Ctymczasowe,indeks
    int kolej = 0;
    for (auto &i : *this->zbior) {
        omega.push_back(i->omega());
        kolejnosc.push_back(kolej);
        ++kolej;
    }

    auto n = static_cast<int>(omega.size());
    do {
        for (int i = 0; i < n - 1; ++i) {
            if (omega[kolejnosc[i]] < omega[kolejnosc[i + 1]])
                iter_swap(kolejnosc.begin() + i, kolejnosc.begin() + i + 1);
        }
        --n;
    } while (n > 1);

    for (int j = 0; j < this->zbior->size(); ++j) {              //iteracja po kolejnych zadaniach

        for (int k = 0; k < Perm.size() + 1; ++k) {        //wsadzanie na k-te miejsce najwiekszego zadania
//            cout << "k = " << k << endl;
            if (Perm.empty()) Perm.push_back(kolejnosc[j]);
            else Perm.insert(Perm.begin() + k, kolejnosc[j]);
//            for(auto &i : Perm){
//                cout << i << " ";
//            }
//            cout << endl << "-----------" << endl;
            int testC = this->Cmax(Perm);
            pair<int, int> temp{testC, k};
            Ctemp.push_back(temp);
            Perm.erase(Perm.begin() + k);
        }
        int min = 0;
        for (int x = 0; x < Ctemp.size(); ++x) {

            if (Ctemp[x].first < Ctemp[min].first) min = x;
        }
        C.push_back(Ctemp[min].first);
        Perm.insert(Perm.begin() + Ctemp[min].second, kolejnosc[j]);
//        for(auto &i : Perm){
//            cout << i+1 << " ";
//        }    cout << endl;
        Ctemp.clear();
    }
    cout << this->nazwa << " Cmax dla permutacji: ";
    for (auto &i : Perm) {
        cout << i + 1 << " ";
    }
    cout << "wynosi: " << this->Cmax(Perm) << endl;
}

void ZbiorZadan::Wypisz() const {
    for (auto &i : *this->zbior) {
        i->Wypisz();
    }
}

int ZbiorZadan::Cmax(vector<int> &Perm) const {

    if (Perm.empty()) return 0;

    int m = this->iloscMaszyn, n = static_cast<int>(Perm.size());

    vector<vector<int>> C(n);

    for (int i = 0; i < n; ++i) {           //iteracja po ZADANIACH
        vector<int> czasyC_Zadania;
        if (i == 0)czasyC_Zadania.push_back((*this->zbior)[Perm[i]]->CzasWykonywaniaNaMaszynie(0));
        else czasyC_Zadania.push_back((*this->zbior)[Perm[i]]->CzasWykonywaniaNaMaszynie(0) + C[i - 1][0]);


        for (int j = 1; j < m; ++j) {           //iteracja PO MASZYNACH
            if (i == 0 || czasyC_Zadania[j - 1] > C[i - 1][j])
                czasyC_Zadania.push_back((*this->zbior)[Perm[i]]->CzasWykonywaniaNaMaszynie(j) +
                                         czasyC_Zadania[j - 1]);
            else
                czasyC_Zadania.push_back(C[i - 1][j] +
                                         (*this->zbior)[Perm[i]]->CzasWykonywaniaNaMaszynie(j));


        }
        C[i] = czasyC_Zadania;
//        for(auto &i : czasyC_Zadania){
//            std::cout << i << "   \t";
//        }
//        std::cout << std::endl;
    }


    return C[n - 1][m - 1];
}

int ZbiorZadan::test() {
    vector<int> kolejnosc;
    for (int i = 0; i < this->zbior->size(); ++i) {
        kolejnosc.push_back(i);
    }

    return this->Cmax(kolejnosc);
}

int ZbiorZadan::NEHmod() const {
    if (this->zbior->empty()) return 0;

    vector<int> omega, kolejnosc, C, Perm;
    vector<pair<int, int>> Ctemp; //para:Ctymczasowe,indeks
    int kolej = 0;
    for (auto &i : *this->zbior) {
        omega.push_back(i->omega());
        kolejnosc.push_back(kolej);
        ++kolej;
    }

    auto n = static_cast<int>(omega.size());
    do {
        for (int i = 0; i < n - 1; ++i) {
            if (omega[kolejnosc[i]] < omega[kolejnosc[i + 1]])
                iter_swap(kolejnosc.begin() + i, kolejnosc.begin() + i + 1);
        }
        --n;
    } while (n > 1);

    for (int j = 0; j < this->zbior->size(); ++j) {              //iteracja po kolejnych zadaniach

        for (int k = 0; k < Perm.size() + 1; ++k) {        //wsadzanie na k-te miejsce najwiekszego zadania
//            cout << "k = " << k << endl;
            if (Perm.empty()) Perm.push_back(kolejnosc[j]);
            else Perm.insert(Perm.begin() + k, kolejnosc[j]);
//            for(auto &i : Perm){
//                cout << i << " ";
//            }
//            cout << endl << "-----------" << endl;
            int testC = this->Cmax(Perm);
            pair<int, int> temp{testC, k};
            Ctemp.push_back(temp);
            Perm.erase(Perm.begin() + k);
        }
        int min = 0;
        for (int x = 0; x < Ctemp.size(); ++x) {

            if (Ctemp[x].first < Ctemp[min].first) min = x;
        }
        C.push_back(Ctemp[min].first);
        Perm.insert(Perm.begin() + Ctemp[min].second, kolejnosc[j]);
//        for(auto &i : Perm){
//            cout << i+1 << " ";
//        }    cout << endl;
        Ctemp.clear();

        for(int x = 0; x < Perm.size(); ++x){
            
        }



    }
    cout << this->nazwa << " Cmax dla permutacji: ";
    for (auto &i : Perm) {
        cout << i + 1 << " ";
    }
    cout << "wynosi: " << this->Cmax(Perm) << endl;

}






//
// Created by maciej on 20.04.18.
//

#include "Zadanie.h"

Zadanie::Zadanie(int &nr,const std::vector<int> &czasWykonywaniaNaMaszynie) :nrZadania(nr){
    this->czasWykonywaniaNaMaszynie = new std::vector<int>();
    for (auto &i : czasWykonywaniaNaMaszynie){
        this->czasWykonywaniaNaMaszynie->push_back(i);
    }
}

Zadanie::~Zadanie() {
    delete this->czasWykonywaniaNaMaszynie;
}

int Zadanie::omega() const {
    int ret=0;
    for(auto &i :*this->czasWykonywaniaNaMaszynie){
        ret+=i;
    }
    return ret;
}

void Zadanie::Wypisz() const {
    for(int i =0;i<this->czasWykonywaniaNaMaszynie->size();++i){
        if((*this->czasWykonywaniaNaMaszynie)[i]>9)cout << i+1 << " " << (*this->czasWykonywaniaNaMaszynie)[i] << "\t";
        else cout << i+1 << "  " << (*this->czasWykonywaniaNaMaszynie)[i] << "\t";
    }
    cout << "Koniec" << endl;

}

int Zadanie::CzasWykonywaniaNaMaszynie(int m) const {
    if(m>this->czasWykonywaniaNaMaszynie->size() || m < 0)return 0;
    else return (*this->czasWykonywaniaNaMaszynie)[m];
}

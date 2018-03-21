//
// Created by maciej on 02.03.18.
//

#include "Wczytywacz.h"

#include <fstream>
#include <iostream>

using namespace std;
int zadania(string nazwa, ZbiorZadan &zbior) {
    fstream plik;
    string bufor;
    int licznik;
    Zadanie *nowe;

    unsigned long b;
    unsigned long a;
    unsigned long spacja1, spacja2,tab1,tab2;
    string *llinii, *r, *p, *q;

    plik.open(nazwa, ios::in);
    if (!plik.good()) {
        return 1;
    }


    if (!plik.eof()) {
        licznik = 0;
        getline(plik, bufor);
//        spacja=bufor.find(' ');


//        llinii=new string(bufor,0,spacja);
        zbior.setLElem(atoi(bufor.c_str()));
//        cout << zbior.getLElem() << endl;

        for (int i = 0; i < zbior.getLElem(); ++i) {
            getline(plik, bufor);


            a = bufor.find_first_not_of(' ');
            spacja1 = bufor.find_first_of(' ', a);
            tab1 = bufor.find_first_of('\t',a);

            if(tab1 == string::npos) {

                b = bufor.find_first_not_of(' ', spacja1);
                spacja2 = bufor.find_first_of(' ', b);

                r = new string(bufor, a, spacja1);
                p = new string(bufor, b, spacja2);
                q = new string(bufor, spacja2);
            }
            else{
                b = bufor.find_first_not_of('\t', tab1);
                tab2=bufor.find_first_of('\t',b);

                r = new string(bufor, a, tab1);
                p = new string(bufor, b, tab2);
                q = new string(bufor, tab2);
            }
//            std::cout << "r: " << *r << " p: " << *p << " q: " << *q << std::endl;
            nowe = new Zadanie(atoi(r->c_str()), atoi(p->c_str()), atoi(q->c_str()));
            zbior.Dodaj(*nowe);
//            nowe->Pokaz();

        }


    }
    plik.close();
    return 0;
}


void DoIT(string nazwapliku,std::list<Info*> &glowa) {
    ifstream plik;                      //strumien z pliku
    string bufor;                       //bufor na linie

    int wynik1,wynik2;
    unsigned int wynik3,wynik4;           //do wynikow algorytmow

    unsigned int start,stop;

    unsigned int czas2,czas3,czas4;      //do pomiaru czasu


    plik.open(nazwapliku, ios::in);
    if (!plik.good()) return;

    while (!plik.eof()) {

        getline(plik,bufor);
        if(bufor[0]=='i') {
            ZbiorZadan pierwszy, drugi, trzeci;

//        std::cout << "Wczytuje zadania" << std::endl;
            int ret1 = 0, ret2 = 0, ret3 = 0;
            try {
                ret1 = zadania(bufor, pierwszy);
                ret2 = zadania(bufor, drugi);
                ret3 = zadania(bufor, trzeci);
            } catch (const std::exception &except) {
                std::cout << except.what() << std::endl;
            }


            if (!ret1 || !ret2 || !ret3) {}
            else {
                std::cout << "blad" << std::endl;
                return;
            }


            pierwszy.GenerujWektory();
            wynik1 = pierwszy.fCelu();


            //TODO pomiar czasu sortu

            start = clock();
            drugi.sortR();
            stop = clock();
            czas2 =(stop-start)*CLOCKS_PER_SEC/1000000.;

            drugi.GenerujWektory();
            wynik2 = drugi.fCelu();

            //TODO pomiar czasu 2opt
            start = clock();
            trzeci.alg2opt();
            stop = clock();

            czas3 = (stop-start)*CLOCKS_PER_SEC/1000000.;
            trzeci.GenerujWektory();
            wynik3 = trzeci.fCelu();



            start = clock();
            drugi.alg2opt();
            stop = clock();

            czas4 = (difftime(stop,start)*CLOCKS_PER_SEC/1000000.);
            czas4+=czas2;
            drugi.GenerujWektory();
            wynik4 = drugi.fCelu();


            glowa.push_back(new Info(bufor, wynik1, wynik2, czas2,
                                     wynik3, czas3, wynik4, czas4,
                                     static_cast<unsigned int>(pierwszy.getLElem())));
            std::cout << *glowa.back();
        }
    }
    plik.close();
    
}

Info::Info(const string &nazwa, unsigned int WynikNieposortowanego, unsigned int WynikSortR, unsigned int CzasSortR,
           unsigned int Wynik2Opt, unsigned int Czas2Opt, unsigned int WynikOba, unsigned int CzasOba, unsigned int ilosc) : nazwa(nazwa), WynikNieposortowanego(WynikNieposortowanego),
                                                            WynikSortR(WynikSortR), CzasSortR(CzasSortR),
                                                            Wynik2Opt(Wynik2Opt), Czas2Opt(Czas2Opt),
                                                            WynikOba(WynikOba),CzasOba(CzasOba),ilosc(ilosc){}

ostream& operator<<(std::ostream &Strm, const Info& klasa) {
    Strm << "*******************************************************************" << endl;
    Strm << "Plik:  " << klasa.nazwa << ", ilosc: " << klasa.ilosc << endl;
    Strm << "Wynik algorytmu(12345): " << klasa.WynikNieposortowanego <<endl;
    Strm << "Wynik algorytmu(sortR): " << klasa.WynikSortR << " Czas: " << klasa.CzasSortR <<endl;
    Strm << "Wynik algorytmu(2opt): " << klasa.Wynik2Opt << " Czas: " << klasa.Czas2Opt <<endl;
    Strm << "Wynik algorytmu(SortR -> 2opt): " << klasa.WynikOba << " Czas: " << klasa.CzasOba << endl;
    Strm << "*******************************************************************" << endl;

    return Strm;
}

unsigned int Info::getIlosc() const {
    return ilosc;
}

unsigned int Info::getWynikNieposortowanego() const {
    return WynikNieposortowanego;
}

unsigned int Info::getWynikSortR() const {
    return WynikSortR;
}

unsigned int Info::getCzasSortR() const {
    return CzasSortR;
}

unsigned int Info::getWynik2Opt() const {
    return Wynik2Opt;
}

unsigned int Info::getCzas2Opt() const {
    return Czas2Opt;
}

unsigned int Info::getWynikOba() const {
    return WynikOba;
}

unsigned int Info::getCzasOba() const {
    return CzasOba;
}

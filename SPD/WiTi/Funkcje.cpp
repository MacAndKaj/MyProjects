//
// Created by maciej on 12.04.18.
//

#include <iostream>
#include <sstream>
#include "Funkcje.h"




int WczytajZbior(const std::string &nazwa_pliku, ZbiorZadan& zbior){
    std::cout << "Wczytuje zbior" << std::endl;

    std::fstream Strm;
    Zadanie* nowe = nullptr;

    int ilosc;
    TypDanych p,w,d;


    Strm.open(nazwa_pliku);
    if(!Strm.good()) return 1;

    if(!Strm.eof()){
        Strm >> ilosc;
        for (int i = 0; i < ilosc; ++i) {
            Strm >> p;
            Strm >> w;
            Strm >> d;

            nowe = new Zadanie((i), p, w, d);
            zbior.Dodaj_Zadanie(nowe);
        }

    }
    delete nowe;
    Strm.close();
    return 0;
}

Dane Testy(ZbiorZadan &ptr,std::string &nazwapliku){
    std::cout << "Testuje" << std::endl;

    struct Dane DoPliku{};
    clock_t start,end;
    double wynik=0;
    std::cout << nazwapliku << std::endl;
    int ret = WczytajZbior(nazwapliku,ptr);
    if(ret!=0){
        std::cerr << "Cos sie stalo!" << std::endl;
        DoPliku.rozmiar=0;
        return DoPliku;
    }

    DoPliku.rozmiar=ptr.getIlosc();

    DoPliku.wejsciowe=ptr.suma_WiTi();
    std::cout << "******************************************************************************************************" << std::endl;
    std::cout << "Dla kolejnosci wejsciowej pliku \""<<nazwapliku<<"\" suma WiTi wynosi " << DoPliku.wejsciowe <<std::endl;


    //---------------- sort ----------------
    start = clock();
    ptr.sortW();
    end = clock();
    wynik = static_cast<double>(end-start)/CLOCKS_PER_SEC*1000.0;
    DoPliku.wynikSortW=ptr.suma_WiTi();
    DoPliku.czasSortW=wynik;
    std::cout << "\nWynik algorytmu sortowania wzgledem w wynosi: " << DoPliku.wynikSortW << " w czasie " << DoPliku.czasSortW;

    //--------------------- przeglad -----------------
    std::cout << "\nWynik algorytmu przegladu zupelnego wynosi ";
    if(ptr.getIlosc()>12){
        DoPliku.czasPZ=0;
        DoPliku.wynikPZ=0;
        std::cout << " nie wiadomo ile bo za dlugo liczy" << std::endl;
    }
    else{
        start=clock();
        DoPliku.wynikPZ=ptr.PrzegladZupelny();
        end=clock();
        wynik = static_cast<double>(end-start)/CLOCKS_PER_SEC*1000.0;
        DoPliku.czasPZ = wynik;
        std::cout << DoPliku.wynikPZ << ", znaleziony w czasie " << DoPliku.czasPZ << "s" << std::endl;
    }

    //--------------- Programowanie dynamiczne -------------------
    std::cout << "\nWynik algorytmu programowania dynamicznego wynosi ";
    start=clock();
    DoPliku.wynikPD = ptr.AlgProgDynamicznego();
    end=clock();
    wynik=static_cast<double>(end-start)/CLOCKS_PER_SEC*1000.0;
    DoPliku.czasPD = wynik;
    std::cout << DoPliku.wynikPD << ", znaleziony w czasie " << DoPliku.czasPD ;

    std::cout << "\n------------------------------------------------------------------------------------------------------" << std::endl;

}

std::vector<std::string> WczytajNazwy(const char *nazwa) {
    std::cout << "Wczytuje nazwy" << std::endl;
    std::fstream Strm;
    std::string bufor;
    std::vector<std::string> WektorNazw;
    Strm.open(nazwa,std::ios::in);
    if(!Strm.good()) {
        std::cerr << "Nie wczytano nazw" << std::endl;
        return WektorNazw;
    }

    while(!Strm.eof()){
        getline(Strm,bufor);
        if(bufor[0]=='d'){
            WektorNazw.push_back(bufor);
        }
    }
    Strm.close();
    for(auto &i : WektorNazw){
        std::cout << i << std::endl;
    }
    return WektorNazw;
}

void DoPliku(Dane &ref,std::fstream &Strm) {
    std::cout << "Wrzucam do pliku" << std::endl;
    std::stringstream bufor;
    std::string linia;
    bufor.str("");
    bufor  << ref.rozmiar;
    linia.append(bufor.str());
    linia.append(" ");
    //**************************************************
    bufor.str("");
    bufor << ref.wynikSortW;
    linia.append(bufor.str());
    linia.append(" ");
    //*************************
    bufor.str("");
    bufor << ref.czasSortW;
    linia.append(bufor.str());
    linia.append(" ");
    //*************************
    bufor.str("");
    bufor <<ref.wynikPZ;
    linia.append(bufor.str());
    linia.append(" ");
    //*************************
    bufor.str("");
    bufor <<ref.czasPZ;
    linia.append(bufor.str());
    linia.append(" ");
    //*************************
    bufor.str("");
    bufor <<ref.wynikPD;
    linia.append(bufor.str());
    linia.append(" ");
    //*************************
    bufor.str("");
    bufor << ref.czasPD;
    linia.append(bufor.str());
    linia.append(" ");

    linia.append("\n");
    Strm << linia;
}


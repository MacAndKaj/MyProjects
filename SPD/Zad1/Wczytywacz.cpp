//
// Created by maciej on 02.03.18.
//

#include "Wczytywacz.h"

#include <fstream>
#include <iostream>

using namespace std;



//***************************** Funkcje ogolne ***********************************************************************/
/// \brief Funkcja do wczytania zadan.
/// \param nazwa Format - nazwaplikuzzadaniem.txt, czyli plik z czasami dla zadania.
/// \param zbior Referencja do struktury zbioru zadan w ktorej zapisywane jest kazde wczytane zadanie.
/// \return Zwraca 0 gdy wczytywanie zadania sie powiodlo,1 gdy nie udalo sie.
int zadania(string nazwa, ZbiorZadan &zbior) {
    fstream plik;
    int licznik;
    Zadanie *nowe;

    int r, p, q;

    int tempLiczba;
    plik.open(nazwa, ios::in);
    if (!plik.good()) {
        return 1;
    }


    if (!plik.eof()) {

        plik >> tempLiczba;
        zbior.setLElem(tempLiczba);
        //smiec
        plik >> tempLiczba;
        for (int i = 0; i < zbior.getLElem(); ++i) {
            plik >> tempLiczba;
            r = tempLiczba;
            plik >> tempLiczba;
            p = tempLiczba;
            plik >> tempLiczba;
            q = tempLiczba;
            nowe = new Zadanie(r, p, q);
            zbior.Dodaj(*nowe);
//            nowe->Pokaz();

        }
    }
    plik.close();
    return 0;
}

/// \brief Funkcja obliczajaca wszystkie rzeczy.
///
/// Funkcja odpowiada za zrobienie wszystkiego czego oczekuje prowadzacy czyli wczytanie, testowanie,mierzenie czasu.
/// \param nazwapliku   Format - nazwapliku.txt, czyli plik z odpowiednio formatowanymi liczbami.
/// \param glowa        Referencja do listy w ktorej beda przechowywane wyniki kolejnych zadan.
void DoIT(string nazwapliku, std::list<Info *> &glowa) {
    ifstream plik;                      //strumien z pliku
    string bufor;                       //bufor na linie

    int wynik1, wynik2;
    unsigned int wynik3, wynik4;           //do wynikow algorytmow

    unsigned int start, stop;

    unsigned int czas2, czas3, czas4;      //do pomiaru czasu


    plik.open(nazwapliku, ios::in);
    if (!plik.good()) return;

    while (!plik.eof()) {

        getline(plik, bufor);
        if (bufor[0] == 'i') {
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


            wynik1 = pierwszy.fCelu();


            //TODO pomiar czasu sortu

            start = clock();
            drugi.sortR();
            stop = clock();
            czas2 = (stop - start) * CLOCKS_PER_SEC / 1000000.;

            wynik2 = drugi.fCelu();

            //TODO pomiar czasu 2opt
            start = clock();
            trzeci.alg2opt();
            stop = clock();

            czas3 = (stop - start) * CLOCKS_PER_SEC / 1000000.;
            wynik3 = trzeci.fCelu();


            start = clock();
            drugi.alg2opt();
            stop = clock();

            czas4 = (difftime(stop, start) * CLOCKS_PER_SEC / 1000000.);
            czas4 += czas2;
            wynik4 = drugi.fCelu();


            glowa.push_back(new Info(bufor, wynik1, wynik2, czas2,
                                     wynik3, czas3, wynik4, czas4,
                                     static_cast<unsigned int>(pierwszy.getLElem())));
            std::cout << *glowa.back();
        }
    }
    plik.close();

}



//*********************************************************************************************************************/




///
/// \param nazwa    Nazwa pliku z zadaniami
/// \param WynikNieposortowanego    Wynik funkcji celu
/// \param WynikSortR   Wynik funkcji celu po posortowaniu
/// \param CzasSortR    Zmierzony czas sortowania w mikrosekundach
/// \param Wynik2Opt    Wynik funkcji celu po uzyciu algorytmu 2 opt
/// \param Czas2Opt     Zmierzony czas dzialania algorytmu
/// \param WynikOba     Wynik funkcji celu po uzyciu algorytmu 2 opt oraz sortR
/// \param CzasOba      Zmierzony czas dzialania obu algorytmow razem(mikrosekundy)
/// \param ilosc        Liczba zadan w pliku
Info::Info(const string &nazwa, unsigned int WynikNieposortowanego, unsigned int WynikSortR, unsigned int CzasSortR,
           unsigned int Wynik2Opt, unsigned int Czas2Opt, unsigned int WynikOba, unsigned int CzasOba,
           unsigned int ilosc) : nazwa(nazwa), WynikNieposortowanego(WynikNieposortowanego),
                                 WynikSortR(WynikSortR), CzasSortR(CzasSortR),
                                 Wynik2Opt(Wynik2Opt), Czas2Opt(Czas2Opt),
                                 WynikOba(WynikOba), CzasOba(CzasOba), ilosc(ilosc) {}

///
/// \param Strm Referencja do strumienia wyjsciowego
/// \param klasa Referencja do obiektu w ktorym zapisane sa informacje ktore czytamy
/// \return Zwraca strumien z informacjami do wyswietlenia
ostream &operator<<(std::ostream &Strm, const Info &klasa) {
    Strm << "*******************************************************************" << endl;
    Strm << "Plik:  " << klasa.nazwa << ", ilosc: " << klasa.ilosc << endl;
    Strm << "Wynik algorytmu(12345): " << klasa.WynikNieposortowanego << endl;
    Strm << "Wynik algorytmu(sortR): " << klasa.WynikSortR << " Czas: " << klasa.CzasSortR << endl;
    Strm << "Wynik algorytmu(2opt): " << klasa.Wynik2Opt << " Czas: " << klasa.Czas2Opt << endl;
    Strm << "Wynik algorytmu(SortR -> 2opt): " << klasa.WynikOba << " Czas: " << klasa.CzasOba << endl;
    Strm << "*******************************************************************" << endl;

    return Strm;
}




//              Getery
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

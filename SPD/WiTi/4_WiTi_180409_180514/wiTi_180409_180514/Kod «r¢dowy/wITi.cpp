// wITi.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include<cmath>			// Do potegowania
#include <iostream>		
#include <fstream>		// Do obslugi plikow
#include <Windows.h>

#define MAX 99999999	// Duza liczba do porownan

using namespace std;


char *nazwa_wej = "wiTi_input.txt";		// Do przechowywania nazwy aktualnego pliku wejsciowego
char *nazwa_wyj = "wiTi_output.txt";		// Do przechowywania nazwy aktualnego pliku wyjsciowego

int liczba_zadan;			// Zmienna okreslajaca liczbe zadan

long int liczba_permutacji;			// Zmienna okreslajaca liczbe permutacji
long int tab_obliczen[33554444][3];	// Tablica zawierajaca ponad 2^25 wierszy


int main()
{
	fstream plik_in;	// Plik wejsciowy
	fstream plik_out;	// Plik wyjsciowy
	
	double base = 2;	// Podstawa do potegowania	
	
	long int temp_r;
	long int mini;
	long int mini_2 = -1;
	
	long int **tab_zadan = new long int * [25]; // Tablica przechowujaca dane na temat zadan
    for (int j = 0; j < 25; j++)
    {
     tab_zadan[j] = new long int[3];
    }
    
    long int **tab_poteg = new long int * [26]; // Tablica zawierajaca w 1 kolumnie wartosci minimalne i czasy w drugiej
    for (int j = 0; j < 26; j++)
    {
     tab_poteg[j] = new long int[2];
    }


	
	plik_in.open(nazwa_wej, fstream::in);	// Otwarcie pliku wejsciowego
	plik_out.open(nazwa_wyj, fstream::out);	// Otwarcie pliku do zapisu
	
	// Sprawdzenie poprawnosci otwarcia pliku do odczytu
	if (!plik_in.good())
	{	// W przypadku niepowodzenia wyswietlany jest komunikat o bledzie i program konczy prace
		cout << "Blad otwarcia pliku do odczytu!";
		exit(-1);
	}
	// Sprawdzenie poprawnosci otwarcia pliku do zapisu
	if (!plik_out.good())
	{	// W przypadku niepowodzenia wyswietlany jest komunikat o bledzie i program konczy prace
		cout << "Blad otwarcia pliku do zapisu!";
		exit(-1);
	}



	// Glowna petla wykonujaca sie tyle razy, ile instancji jest do przeliczenia
	for(int k = 0; k < 16; k++)	// Liczbe plikow zapisujemy na sztywno na 16
	{
		// Wczytanie z pliku wejsciowego informacji o liczbie zadan
		plik_in >> liczba_zadan;
		// Wczytanie informacji o zadaniach
		for(int i = 0; i < liczba_zadan; i++)
		{
  			for(int j = 0; j < 3; j++)
			{
				plik_in >> tab_zadan[i][j];
			}
		}
		
  		liczba_permutacji = pow(base,liczba_zadan);			// Wyliczenie liczby permutacji
	    tab_poteg[liczba_zadan-1][0] = liczba_permutacji/2;	// Wpisanie informacji do tablicy poteg
		liczba_permutacji--;								// Liczba permutacji jest teraz mniejsza

		// Wyliczenie wartosci w tablicy poteg
		for(int i = liczba_zadan-2; i >= 0; i--)
		{
    		tab_poteg[i][0] = tab_poteg[i+1][0]/2;
    		tab_poteg[i][1] = tab_poteg[i][0];
    		tab_poteg[i+1][1] = liczba_permutacji-tab_poteg[i+1][0];
		}
		// Uzupelnienie pozostalych pol tablicy poteg
		tab_poteg[0][0] = 1;
		tab_poteg[0][1] = liczba_permutacji-1;
		tab_poteg[liczba_zadan][0] = MAX;
    
		for(int i = 1; i <= liczba_permutacji; i++)
		{
			int j = 0;

			mini = MAX;
			mini_2 = -1;

			while(tab_poteg[j][0] <= i)
			{	
				temp_r = (tab_zadan[j][0] + tab_obliczen[tab_poteg[j][1]&i][1] - tab_zadan[j][2]) * tab_zadan[j][1];
				if(temp_r < 0)
				{
					temp_r = 0;
				}
				temp_r = temp_r + tab_obliczen[tab_poteg[j][1]&i][0];	
				if(temp_r < mini)
				{
					mini = temp_r;
					mini_2 = j;
				}		
				j++;
			}
			if(mini_2 >= 0)
			{	
				tab_obliczen[i][0] = mini;
				tab_obliczen[i][1] = tab_obliczen[tab_poteg[mini_2][1]&i][1] + tab_zadan[mini_2][0];
				tab_obliczen[i][2] = tab_poteg[mini_2][1]&i;
			}
			tab_obliczen[i+1][0] = MAX;
			tab_obliczen[i+1][1] = MAX;
		}
		plik_out << tab_obliczen[liczba_permutacji][0] << "\n";	// Zapisanie wartosci funkcji celu do pliku wyjsciowego	
		mini = liczba_permutacji;								// Zapisanie pozycji minimalnej
		
		int i = 1;

		while(mini != 0)
		{
			tab_zadan[liczba_zadan-i][0] = mini;
			mini = tab_obliczen[mini][2];
			i++;
		}
		liczba_permutacji = 0;
		
		// Wypisanie permutacji do pliku wyjsciowego
		for(int i = 0; i < liczba_zadan; i++)
		{
			for(int j = 0; j < liczba_zadan; j++)
			{
				if((tab_poteg[j][0]|liczba_permutacji) == tab_zadan[i][0])
				{
					plik_out << j+1 << " ";
					liczba_permutacji = liczba_permutacji|tab_poteg[j][0];
					j = liczba_zadan;
				}
			}
		}
		plik_out << "\n\n";
	}
	// Zamkniecie plikow wejsciowego i wyjsciowego
	plik_in.close();
	plik_out.close();
	
	for (int j = 0; j < 25; j++)
    {
     delete [] tab_zadan[j];
    }
    for (int j = 0; j < 25; j++)
    {
     delete [] tab_poteg[j];
    }
    delete [] tab_poteg;
    delete [] tab_zadan;
	system("pause");
	exit(0);
}

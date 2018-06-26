from matplotlib import pyplot as wykres

import os, subprocess, pathlib
import tkinter

# wymagania
# python3 (sudo apt-get install python3)
# matplotlib(sudo apt-get install python3-matplotlib)
# tkinter (sudo apt-get install python3-tk)
# cmake (sudo apt-get install cmake)


os.system("rm Zad1")
nazwa = []
# najpierw trzeba przygotowac plik zeby program poszedl
mojplik = os.path.isfile("NazwyPlikow.txt")  # sprawdzamy czy jest juz plik
if not mojplik:
    os.system("find in* > NazwyPlikow.txt")

uchwyt = open("NazwyPlikow.txt", "r+")

licczba = len(uchwyt.readlines())

if licczba == 0:
    os.system("find in* > NazwyPlikow.txt")

cmake = subprocess.call(["cmake", '.'])

make = subprocess.call("make")

# teraz wykonamy program ktory da nam plik z potrzebnymi liczbami
programPath = os.getcwd()
programPath += "/Zad1"
print(programPath + "/Zad1")
prog = subprocess.Popen(programPath)
prog.wait()

uchwyt.close()

DoNazw = open("NazwyPlikow.txt", 'r').readlines()
j = 0
for x in DoNazw:
    nazwa.append(x)

# uchwyt = open("PlikZWynikamiZad1.txt", 'r').readlines()
uchwyt = open("PlikZWynikamiZad2.txt", 'r').readlines()

# do wyswietlania na wykresach
ilosc = []
temp = []
# -------zad1---------
# wynik12345=[]
# wynikSortR=[]
# czasSortR=[]
# wynik2opt=[]
# czas2opt=[]
# wynikOba=[]
# czasOba=[]
# -------zad2--------
wynikSchrage = []
wynikPreSchrage = []
wynikCarlier = []
czasSchrage = []
czasPreSchrage = []
czasCarlier = []
# -------------------




# for line in uchwyt:
#     if not line[0] == "F":
#         for val in line.split():
#             temp.append(int(val))
#         ilosc.append(temp[0])
#         wynik12345.append(temp[1])
#         wynikSortR.append(temp[2])
#         czasSortR.append(temp[3])
#         wynik2opt.append(temp[4])
#         czas2opt.append(temp[5])
#         wynikOba.append(temp[6])
#         czasOba.append(temp[7])
#
#     temp.clear()

for line in uchwyt:
    if not line[0] == "F":
        for val in line.split():
            temp.append(int(val))
        ilosc.append(temp[0])
        wynikSchrage.append(temp[1])
        czasSchrage.append(temp[2])
        wynikPreSchrage.append(temp[3])
        czasPreSchrage.append(temp[4])
        wynikCarlier.append(temp[5])
        czasCarlier.append(temp[6])

    temp.clear()

algorytmy = ["Schrage", "PreSchrage", "Carlier"]

kolory = ['b', 'g', 'r', 'c', 'm', 'y', 'k']

# for i in range(0,len(ilosc)):
#     if ilosc[i] <100:
#         wykres.figure(1)
#         wykres.plot(algorytmy,[wynik12345[i],wynikSortR[i],wynik2opt[i],wynikOba[i]],kolory[i%len(kolory)]+'-o',label = nazwa[i])
#     else:
#         wykres.figure(2)
#         wykres.plot(algorytmy,[wynik12345[i],wynikSortR[i],wynik2opt[i],wynikOba[i]],kolory[i%len(kolory)]+'-o',label = nazwa[i])

for i in range(0, len(ilosc)):
    if ilosc[i] < 100:
        wykres.figure(1)
        wykres.plot(algorytmy, [wynikSchrage[i], wynikPreSchrage[i], wynikCarlier[i]], kolory[i % len(kolory)] + '-o',
                    label=nazwa[i])
    else:
        wykres.figure(2)
        wykres.plot(algorytmy, [wynikSchrage[i], wynikPreSchrage[i], wynikCarlier[i]], kolory[i % len(kolory)] + '-o',
                    label=nazwa[i])

wykres.figure(1)
wykres.legend(loc="center left", bbox_to_anchor=(1.0, 0.5))
wykres.title('Wykres wynikow funkcji celu dla ilosci <100')
wykres.xlabel('Algorytm')
wykres.ylabel('Wynik funkcji celu')
wykres.grid(True)
wykres.semilogy()
wykres.tight_layout()

wykres.figure(2)
wykres.legend(loc="center left", bbox_to_anchor=(1.0, 0.5))
wykres.title('Wykres wynikow funkcji celu dla ilosci >100')
wykres.xlabel('Algorytm')
wykres.ylabel('Wynik funkcji celu')
wykres.grid(True)
wykres.semilogy()
wykres.tight_layout()

# for i in range(0, len(ilosc)):
#     if ilosc[i] < 100:
#         wykres.figure(3)
#         wykres.plot(algorytmy, [czasSchrage[i], czasPreSchrage[i], czasCarlier[i]], kolory[i % len(kolory)] + '-o',
#                     label=nazwa[i])
#     else:
#         wykres.figure(4)
#         wykres.plot(algorytmy, [czasSchrage[i], czasPreSchrage[i], czasCarlier[i]], kolory[i % len(kolory)] + '-o',
#                     label=nazwa[i])
#
# wykres.figure(3)
# wykres.legend(loc="center left", bbox_to_anchor=(1.0, 0.5))
# wykres.title('Wykres pomiarow czasu dla ilosci <100')
# # wykres.title('Wykres pomiarow czasu')
# wykres.xlabel('Algorytm')
# wykres.ylabel('Wynik pomiaru czasu')
# wykres.grid(True)
# wykres.semilogy()
# wykres.tight_layout()
#
# wykres.figure(4)
# wykres.legend(loc="center left", bbox_to_anchor=(1.0, 0.5))
# wykres.title('Wykres pomiarow czasu dla ilosci >100')
# wykres.xlabel('Algorytm')
# wykres.ylabel('Wynik pomiaru czasu')
# wykres.grid(True)
# wykres.semilogy()
# wykres.tight_layout()
#
# wykres.show()

iloscZad2 = [6, 10, 20, 50, 100, 200, 500]
sredniCzasSchrage = [0, 0, 0, 0, 0, 0, 0]
sredniCzasPreSchrage = [0, 0, 0, 0, 0, 0, 0]
sredniCzasCarlier = [0, 0, 0, 0, 0, 0, 0]
LiczbaPowtorzen = [0, 0, 0, 0, 0, 0, 0]
for i in range(0, len(ilosc)):
    for x in range(0, len(iloscZad2)):
        if ilosc[i] == iloscZad2[x]:
            LiczbaPowtorzen[x] += 1
            sredniCzasSchrage[x] += czasSchrage[i]
            sredniCzasPreSchrage[x] += czasPreSchrage[i]
            sredniCzasCarlier[x] += czasCarlier[i]

for i in range(0,len(LiczbaPowtorzen)):
    sredniCzasSchrage[i]=sredniCzasSchrage[i]/LiczbaPowtorzen[i]
    sredniCzasPreSchrage[i]=sredniCzasPreSchrage[i]/LiczbaPowtorzen[i]
    sredniCzasCarlier[i]=sredniCzasCarlier[i]/LiczbaPowtorzen[i]

wykres.figure(3)
for i in range(0, len(iloscZad2)):
    wykres.plot(algorytmy, [sredniCzasSchrage[i], sredniCzasPreSchrage[i], sredniCzasCarlier[i]], kolory[i % len(kolory)] + '-o',
                    label=iloscZad2[i])



wykres.figure(3)
wykres.legend(loc="center left", bbox_to_anchor=(1.0, 0.5))
# wykres.title('Wykres pomiarow czasu dla ilosci <100')
wykres.title('Wykres pomiarow czasu')
wykres.xlabel('Algorytm')
wykres.ylabel('Wynik pomiaru czasu')
wykres.grid(True)
wykres.semilogy()
wykres.tight_layout()

wykres.show()
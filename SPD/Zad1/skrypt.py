from matplotlib import pyplot as wykres

import os, subprocess, pathlib
import tkinter

#wymagania
# python3 (sudo apt-get install python3)
# matplotlib(sudo apt-get install python3-matplotlib)
# tkinter (sudo apt-get install python3-tk)
# cmake (sudo apt-get install cmake)


os.system("rm Zad1")
nazwa=[]
# najpierw trzeba przygotowac plik zeby program poszedl
mojplik = os.path.isfile("NazwyPlikow.txt")  # sprawdzamy czy jest juz plik
if not mojplik:
    os.system("find in* > NazwyPlikow.txt")

uchwyt = open("NazwyPlikow.txt", "r+")

licczba = len(uchwyt.readlines())


if licczba == 0:
    os.system("find in* > NazwyPlikow.txt")



cmake=subprocess.call(["cmake",'.'])



make=subprocess.call("make")

# teraz wykonamy program ktory da nam plik z potrzebnymi liczbami
programPath = os.getcwd()
programPath += "/Zad1"
print(programPath + "/Zad1")
prog = subprocess.Popen(programPath)
prog.wait()

uchwyt.close()

DoNazw=open("NazwyPlikow.txt",'r').readlines()
j=0
for x in DoNazw:
    nazwa.append(x)

uchwyt = open("PlikZWynikami.txt", 'r').readlines()




#do wyswietlania na wykresach
ilosc=[]
wynik12345=[]
wynikSortR=[]
czasSortR=[]
wynik2opt=[]
czas2opt=[]
wynikOba=[]
czasOba=[]
temp=[]



for line in uchwyt:
    if not line[0] == "F":
        for val in line.split():
            temp.append(int(val))
        ilosc.append(temp[0])
        wynik12345.append(temp[1])
        wynikSortR.append(temp[2])
        czasSortR.append(temp[3])
        wynik2opt.append(temp[4])
        czas2opt.append(temp[5])
        wynikOba.append(temp[6])
        czasOba.append(temp[7])

    temp.clear()

algorytmy=["12345","SortR","2opt","SortR+2opt"]

kolory=['b', 'g', 'r', 'c', 'm', 'y', 'k']

for i in range(0,len(ilosc)):
    if ilosc[i] <100:
        wykres.figure(1)
        wykres.plot(algorytmy,[wynik12345[i],wynikSortR[i],wynik2opt[i],wynikOba[i]],kolory[i%len(kolory)]+'-o',label = nazwa[i])
    else:
        wykres.figure(2)
        wykres.plot(algorytmy,[wynik12345[i],wynikSortR[i],wynik2opt[i],wynikOba[i]],kolory[i%len(kolory)]+'-o',label = nazwa[i])

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

algorytmy.pop(0)
for i in range(0,len(ilosc)):
    if ilosc[i] <100:
        wykres.figure(3)
        wykres.plot(algorytmy,[czasSortR[i],czas2opt[i],czasOba[i]],kolory[i%len(kolory)]+'-o',label = nazwa[i])
    else:
        wykres.figure(4)
        wykres.plot(algorytmy,[czasSortR[i],czas2opt[i],czasOba[i]],kolory[i%len(kolory)]+'-o',label = nazwa[i])


wykres.figure(3)
wykres.legend(loc="center left", bbox_to_anchor=(1.0, 0.5))
wykres.title('Wykres pomiarow czasu dla ilosci <100')
wykres.xlabel('Algorytm')
wykres.ylabel('Wynik pomiaru czasu')
wykres.grid(True)
wykres.semilogy()
wykres.tight_layout()



wykres.figure(4)
wykres.legend(loc="center left", bbox_to_anchor=(1.0, 0.5))
wykres.title('Wykres pomiarow czasu dla ilosci >100')
wykres.xlabel('Algorytm')
wykres.ylabel('Wynik pomiaru czasu')
wykres.grid(True)
wykres.semilogy()
wykres.tight_layout()


wykres.show()



from matplotlib import pyplot as wykres

import os, subprocess, pathlib

# wymagania
# python3 (sudo apt-get install python3)
# matplotlib(sudo apt-get install python3-matplotlib)
# tkinter (sudo apt-get install python3-tk)
# cmake (sudo apt-get install cmake)


os.system("rm WiTi NazwyPlikow.txt PlikZWynikami.txt")

nazwa = []
# najpierw trzeba przygotowac plik zeby program poszedl
mojplik = os.path.isfile("NazwyPlikow.txt")  # sprawdzamy czy jest juz plik
if not mojplik:
    os.system("find data* > NazwyPlikow.txt")

uchwyt = open("NazwyPlikow.txt", "r+")

licczba = len(uchwyt.readlines())

if licczba == 0:
    os.system("find data* > NazwyPlikow.txt")

cmake = subprocess.call(["cmake", '.'])

make = subprocess.call("make")

# teraz wykonamy program ktory da nam plik z potrzebnymi liczbami
programPath = os.getcwd()
programPath += "/WiTi"
print(programPath + "/WiTi")
prog = subprocess.Popen(programPath)
prog.wait()

uchwyt.close()

DoNazw = open("NazwyPlikow.txt", 'r').readlines()
j = 0
for x in DoNazw:
    nazwa.append(x)

# do wyswietlania na wykresach
ilosc = []
temp = []
wynik12345 = []
wynikSortW = []
czasSortW = []
wynikPZ = []
czasPZ = []
wynikPD = []
czasPD = []

uchwyt = open("PlikZWynikami.txt", 'r').readlines()

for line in uchwyt:
    if not line[0] == "F":
        for val in line.split():
            temp.append(float(val))
        ilosc.append(temp[0])
        wynikSortW.append(temp[1])
        czasSortW.append(temp[2])
        wynikPZ.append(temp[3])
        czasPZ.append(temp[4])
        wynikPD.append(temp[5])
        czasPD.append(temp[6])

    temp.clear()

index = 0
while czasPZ[index]!=0:
    index+=1


czasPZ_krotki=[]
ilosc_krotka=[]
for it in range(0,index):
    czasPZ_krotki.append(czasPZ[it])
    ilosc_krotka.append(ilosc[it])

print()

algorytmy = ["SortW", "PZ ekstrapolowane", "P. Dynamiczne", "Przeglad zupelny"]

kolory = ['b', 'g', 'r', 'c', 'm', 'y', 'k']

wykres.figure(1)
wykres.plot(ilosc, czasSortW, kolory[0] + '-o', label=algorytmy[0])
wykres.plot(ilosc, czasPD, kolory[1] + '-o', label=algorytmy[2])

wykres.plot(ilosc_krotka, czasPZ_krotki, kolory[2] + '--o', label=algorytmy[3])

wykres.legend(loc="center left", bbox_to_anchor=(1.0, 0.5))
wykres.title('Wykres zaleznosci czasu od wielkosci instancji dla algorytmow')
wykres.xlabel('Algorytm')
wykres.ylabel('Wynik mierzenia czasu algorytmow')
wykres.grid(True)
wykres.semilogy()
wykres.tight_layout()

wykres.show()

uchwyt = open("PlikZWynikami.txt","r").readlines()

optima = open("Optima.txt","r").readlines()

temp=[]
ilosci=[]
sorty=[]
for line in uchwyt:
    if not line[0] == "F":
        for val in line.split():
            try:
                temp.append(int(val))
            except:
                pass
        ilosci.append(temp[0])
        sorty.append(temp[1])
    temp.clear()

opt=[]
for line in optima:
    for val in line.split():
        opt.append(int(val))
nowy = open("dotexa.txt","w")
for i in range(0,len(sorty)):
    sorty[i]=100*(sorty[i]-opt[i])/opt[i]
    nowy.write(str(ilosci[i]) + " & " + str(opt[i]) + " & " + str(sorty[i])+"\n")
nowy.close()
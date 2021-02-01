serie = []
f1 = 0
f2 = 1
serie.append(f1)
serie.append(f2)
for i in range(50000):
    f1, f2 = f2, (2*f2)+f1
    serie.append(f2)


while True:
    try:
        a = input()
        ban = False
        if(a == '\n'):
            break
        a = int(a)
        if (serie[a] % 2 == 0):
            print("Pell's number", a, "is divisible by", 2)
            ban = True
        if (serie[a] % 3 == 0):
            print("Pell's number", a, "is divisible by", 3)
            ban = True
        if (serie[a] % 4 == 0):
            print("Pell's number", a, "is divisible by", 4)
            ban = True
        if (serie[a] % 7 == 0):
            print("Pell's number", a, "is divisible by", 7)
            ban = True
        if (serie[a] % 13 == 0):
            print("Pell's number", a, "is divisible by", 13)
            ban = True
        if ban == False:
            print(-1)

    except:
        break

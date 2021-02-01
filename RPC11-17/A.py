notas = ["DO", "DO#", "RE", "RE#", "MI",
         "FA", "FA#", "SOL", "SOL#","LA", "LA#", "SI"]
pos, clave = input().split()
pos = int(pos)
for indice in range(len(notas)):
    if(clave == notas[indice]):
        print(notas[indice - pos])
        break
dg = [0]*10
pos = valor = 999999
s = input()
for i in range(len(s)):
    dg[ord(s[i])-48] += 1
for i in range(1,10):
    if(dg[i]<valor):
        pos = i
        valor = dg[i]
if(dg[0]<valor):
    print(10**(dg[0]+1))
else:
    print(str(pos)*(valor+1))
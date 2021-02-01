n = int(input())
while True:
    p = (((n*(n+1))//2)*3)-n
    if(p%4 ==0):
        break
    n +=1

print(n)
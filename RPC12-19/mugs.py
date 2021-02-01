import fileinput
def D(a):print(a)
def main():
    N=0
    s=""
    z=0
    for l in fileinput.input():
        z+=1
        if(z<2):
            N=int(l)
            continue
        s=l
    L=[10000000]*(1<<20)
    L[0]=-1
    B=0
    X=0
    for i in range(N):
        B^=1<<(ord(s[i])-97)
        X=max(X,i-L[B])
        for j in range(20):
            X=max(X,i-L[B^1<<j])
        L[B]=min(L[B],i)
    D(X)
main()

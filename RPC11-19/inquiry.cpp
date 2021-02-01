#include <bits/stdc++.h>
using namespace std;
unsigned long long s1[1000001];
unsigned long long s2[1000001];
int main(){
    s1[0] = 0;
    s2[0] = 0;
    int t, x;
    scanf("%d",&t);
    for(int i = 1; i<=t; i++){
        scanf("%d",&x);
        s1[i] = s1[i-1] + (x*x);
        s2[i] = s2[i-1] + x;
    }
    unsigned long long maximo = 0;
    for(int i=1; i<=t; i++){
        unsigned long long val = s1[i]*(s2[t]-s2[i]);
        maximo = val > maximo ? val : maximo;
    }
    printf("%llu\n",maximo);
}
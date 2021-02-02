#include<bits/stdc++.h>
#define MAXN 1000001
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    int t;
    ull n, res;
    scanf("%d", &t);
    while(t--){
        scanf("%llu", &n);
        res = n*(n+1)*(n+2)/6;
        printf("%llu\n",res);
    }
    return 0;   
}

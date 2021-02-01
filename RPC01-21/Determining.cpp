#include<bits/stdc++.h>
#define MAXN 1000001
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    ll MOD = (1LL<<31)-1LL;
    ll fib[10001];
    unordered_set <ll> s_fib; 
    fib[0]=0LL; fib[1]=1LL;
    s_fib.insert(0); s_fib.insert(1);
    for(int i=2; i<=10000; i++){
        fib[i] = (fib[i-1] + fib[i-2])%MOD;
        s_fib.insert(fib[i]);
    }
    int T, n, m;
    cin>>T;
    while(T--){
        cin>>n;
        if(s_fib.find(n) != s_fib.end()){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
    
    return 0;   
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    /*#ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin); 
        freopen("error.txt", "w", stderr); 
        freopen("output.txt", "w", stdout); 
    #endif */
    ll a, b;
    while(cin>>a >>b && (a|b)){
        ll res = b%4;
        if(res==0) cout<<a;
        else if(res==1) cout<<a<<"i";
        else if(res == 2) cout<<(-1LL*a);
        else if(res == 3) cout<<(-1LL*a)<<"i";
        cout<<'\n';
        
    }
    //cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0;   
}
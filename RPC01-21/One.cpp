#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int T, P, E;
    cin>>T;
    while(T--){
        cin>>P >>E;
        if((P-E)>= 10){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
    
    return 0;   
}

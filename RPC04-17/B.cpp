#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, p, pi, sum, integrant;
    while(true){
        cin>>n>>p;
        sum=0;
        if(n==0 && p==0) break;
        for(int i=0;i<n; i++){
            cin>>pi;
            sum+=pi;
        }
        integrant=p/sum;
        cout<<integrant<<endl;


    }

    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, d, t;
    cin>>n;
    int v[n];
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    int maxx = 100;
    
    for (int i = 0; i < n-2; i++)
    {
        if(max(v[i],v[i+2])< maxx){
            maxx = max(v[i], v[i+2]);
            d = i;
        }
    }
    
    cout<< d+1 << " "<< maxx<<'\n';
    
    return 0;
}
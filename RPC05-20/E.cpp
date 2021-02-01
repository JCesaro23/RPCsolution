#include <bits/stdc++.h>
using namespace std;
int main(){
    int v[101];
    v[0] = 0;
    for(int i=1; i<=100; i++)
        v[i]=v[i-1]+i;
    int c=0, c1=0, c2=0;
    int sum = 0;
    int n;
    cin>>n;
    for(int i=0;i+n<=100;i++){
        sum = v[i+n] - v[i];
        //cout<<sum<<endl;
        if((sum&1)==0)  c2++;
        else c1++;
        c++;
    }
    if(c == c1) cout<<"Odd"<<endl;
    else if(c == c2) cout<<"Even"<<endl;
    else cout<<"Either"<<endl;
    return 0;
}
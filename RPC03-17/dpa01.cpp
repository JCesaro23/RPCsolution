#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t, n, i, sum;
    cin>>t;
    while(t--){
        sum = 0;
        cin>>n;
        for(i=1;i<=n/2;i++){
            if(n%i == 0)
                sum+=i;
        }
        if(sum==n)
            cout<<"perfect"<<endl;
        else if(sum>n)
            cout<<"abundant"<<endl;
        else
            cout<<"deficient"<<endl;
    }

    return 0;
}

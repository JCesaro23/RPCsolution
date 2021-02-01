#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, dc;
    vector<int>v;
    cin>>n;
    for(int i=0; i<n;i++){
        cin>>dc;
        v.push_back(dc);
    }
    double ans=1.0;
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        if(v[i]>i+1){
            cout<<"imposible"<<endl;
            return 0;
        }else{
            ans = min(ans, v[i]/(i+1.0));
        }
    }
    printf("%.10lf\n",ans);
    return 0;
}
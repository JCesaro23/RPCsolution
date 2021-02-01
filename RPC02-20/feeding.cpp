#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  int n;
  long long m, wi;
  int res=0;
  vector <long long> v;
  cin>>n >> m;
  for(int i=0; i<n; i++){
      cin>>wi;
      v.push_back(wi);
  }
  sort(v.begin(), v.end());
  int i=v.size()-1;
  int j = 0;
    while(i>j){
        if(v[j]> (m-v[i])){
            res++;
            i--;
        }else{
            res++;
            i--;
            j++;
        }
    }

    if(i == j) res++;
  cout<<res<<endl;
}

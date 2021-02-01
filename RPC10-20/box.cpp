#include<bits/stdc++.h>
using namespace std;
int main(){
  int base[102];
  int b, r, h, v, c, i, j;
  memset(base, 0,sizeof(base));
  cin>>b>>r;
  int may = 0;
  while(r--){
    may = 0;
    cin>>h>>v>>c;
    j = c+h-1;
    for(i=c; i<=j;i++)
      may = max(may,base[i]);
    for(i=c; i<=j; i++)
      base[i]=may+v;
  }
  may = 0;
  for(i=1;i<=b;i++)
    may = max(may, base[i]);
  cout<<may<<'\n';
  return 0;
}

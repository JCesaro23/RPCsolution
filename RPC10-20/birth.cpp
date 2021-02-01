#include<bits/stdc++.h>
#include <string>
using namespace std;
int main(){
  int n;
  string s;
  set<string> ss;
  cin>>n;
  while (n--) {
    cin>>s;
    ss.insert(s);
  }
  int ans = ss.size();
  cout<<ans<<'\n';
  return 0;
}

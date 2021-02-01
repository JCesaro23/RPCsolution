#include <bits/stdc++.h> 
using namespace std; 
void solve(); 
int main() 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
  
#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("error.txt", "w", stderr); 
    freopen("output.txt", "w", stdout); 
#endif 
  
    int t = 1; 
    /*is Single Test case?*/// cin >> t; 
    while (t--) { 
        solve(); 
        cout << "\n"; 
    } 
  
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
} 
void solve() 
{ 
    stack<int> p, w;
    p.push(3);
    p.push(4);
    p.push(23);
    p.push(33);
    cout<<p.size()<<endl;
    p.swap(w);
    cout<<p.size();
}
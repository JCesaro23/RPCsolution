#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, ta, da, tb, db;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>n;
    cin>>ta >>da;
    int speed = 0;
    while(n-- != 1){
        cin>> tb>> db;
         speed = max((db-da)/(tb-ta), speed);
         ta =tb;
         da = db;
    }
    cout<<speed<<endl;
    return 0;
}
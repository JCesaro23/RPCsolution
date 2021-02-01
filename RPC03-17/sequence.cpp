#include <bits/stdc++.h>
#define MAX 1000000000
using namespace std;
vector<long int> dp;

void precalculo(){
    dp.push_back(0);
    dp.push_back(3);
    long int c=5;
    for(int i=2; i<=MAX; i++){
        dp.push_back(dp[i-1]+c);
        c+=2;
    }

}

int main(){
    precalculo();
    cout<<dp[200]<<endl;
    cout<<dp[725]<<endl;
    cout<<dp[1333]<<endl;
    return 0;
}

/*******************************************************
Name Problem:Rating Problems
Problem Category:adhoc
Problem Tester: Julio Cesar Mamani Villena.
Email: mamanivillenajc@gmail.com
*******************************************************/
#include<bits/stdc++.h>
#define PI 2*acos(0.0)
#define MOD 1000000007
#define EPS 1e-9
#define all(x) x.begin(),x.end()
#define fast(); ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
using namespace std;
void solve(){
    int n, k;
    float r, ans=0.0f;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; ++i)
    {
    	scanf("%f", &r);
    	ans += r;
    }
    printf("%.4f ", (ans+(-3*(n-k)))/n);
    printf("%.4f\n", (ans+(3*(n-k)))/n);
}
int main(){
    fast();
    solve();
    return 0;
}
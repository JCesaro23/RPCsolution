/*******************************************************
Name Problem:Divvying
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
typedef long long ll;

void solve(){
    ll n, wn, ans, dist;
    scanf("%lld", &n);
    ans = 0LL;
    for (int i = 0; i < n; ++i)
    {
    	scanf("%lld", &wn);
    	ans += wn;
    }
    dist = ans / 3LL;
    if (ans == (dist*3LL))
    	printf("yes\n");
    else
    	printf("no\n");
}
int main(){
    fast();
    solve();
    return 0;
}
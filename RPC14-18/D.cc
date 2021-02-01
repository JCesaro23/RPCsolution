#include <bits/stdc++.h>
using namespace std;
#define forr(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=(int)(n-1);i>=0;i--)
#define pb push_back
#define fst first
#define snd second
#define db(v) cerr << #v << " = " << v << endl
#define sz(v) ((int)v.size())
typedef long long ll;

ll r,p;

ll calc(ll r, ll p) {
	return r*p + max(r-p, p-r);
}

int main() {
	//~ freopen("A.in", "r",stdin);
	while(scanf("%lld %lld", &r, &p)>=2) {
		ll y2 = calc(r+1, p);
		ll y3 = calc(r, p+1);
		
		if(y2 == y3) {
			printf("Either\n");
		} else if(y2 > y3) {
			printf("Technical\n");
		} else {
			printf("Interpersonal\n");
		}
	}
	return 0;
}

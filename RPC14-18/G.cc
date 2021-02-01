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
const int MAXN = 500005;

ll n,m;
ll r[MAXN], sum[MAXN];

int main() {
	//~ freopen("H.in", "r",stdin);
	while(scanf("%lld %lld", &n, &m) >= 2) {
		memset(r,0,sizeof(r));
		memset(sum,0,sizeof(sum));

		forn(i,n) {
			ll q,x,y;
			scanf("%lld %lld %lld", &q, &x, &y);
			r[x] += q;
			r[y+1] -= q;
		}

		ll msum=-1e9;
		int mi=0;
		ll ac=0;
		forn(i, MAXN) {
			ac += r[i];
			if(msum < (i-m) * ac) {
				msum = (i-m) * ac;
				mi = i;
			}
		}
		
		printf("%d\n", mi);
	}

	return 0;
}

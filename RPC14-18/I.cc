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

int n;
ll t;

int main() {
	//~ freopen("A.in", "r",stdin);
	while(scanf("%d", &n) >= 1){
		t = ((ll)n*(n-1)/2 + 1)/2;
		ll val = n-1, acum = 0; int p = 0;
		while(acum < t){
			p++; acum += val;
			val--;
			//~ printf("En el paso %d llevo %lld\n", p, acum);
		}
		printf("%d\n", p);
	}
	return 0;
}

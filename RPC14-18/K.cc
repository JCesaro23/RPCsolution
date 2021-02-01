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

double C[6], av, ans;

int main() {
	//~ freopen("M.in", "r",stdin);
	av = 0; ans = 1e9;
	forn(i, 6){
		scanf("%lf", &C[i]);
		av += (i+1)*C[i];
	}
	//~ printf("%.9lf\n", av);
	forn(i, 6){
		double nav = av - (i+1)*C[i];
		double nval = (3.5-nav)/C[i];
		//~ printf("nval = %.9lf\n", nval);
		ans = min(abs(nval-(i+1)), ans);
	}
	printf("%.3f\n", ans);
	return 0;
}

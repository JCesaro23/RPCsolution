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
typedef pair<int, int> ii;

struct cand{ int l, r, val; } ans;

int n;
string IN;
vector<ii> V;
set<ii> S;

bool sup(ii l, ii r){
	if(r.fst - l.fst != ans.val) return r.fst - l.fst > ans.val;
	if(l.snd+1 != ans.l) return (l.snd+1) < ans.l;
	return r.snd < ans.r;
}

bool sup(cand a, cand b){
	if(a.val != b.val) return ans.val > b.val;
	if(a.l != b.l) return a.l < b.l;
	return a.r < b.r;
}

cand solve(){
	n = sz(IN);
	V.clear(); S = {{0, 0}};
	int r = 0, b = 0;
	forn(i, n){
		if(IN[i] == 'R')r++;
		else b++;
		V.pb({r-b, i+1});
		S.insert({r-b, i+1});
	}
	
	//~ forn(i, n)printf("Hata %d hay %d\n", i+1, V[i].fst);
	
	ans = {-1, -1, -1};
	dforn(i, n){
		S.erase(V[i]);
		ii L = *S.begin();
		ii R = V[i];
		//~ printf("%d %d es candidato con %d\n", L.snd+1, R.snd, R.fst-L.fst);
		if(sup(L, R)){
			ans = {L.snd+1, R.snd, R.fst - L.fst};
		}
	}
	return ans;
}

int main() {
	//~ freopen("A.in", "r",stdin);
	while(cin >> IN){
		cand ans =  solve();
		forn(i, sz(IN)){
			if(IN[i] == 'B')IN[i] = 'R';
			else IN[i] = 'B';
		}
		cand ans2 = solve();
		if(sup(ans2, ans))ans = ans2;
		printf("%d %d\n", ans.l, ans.r);
	}
	return 0;
}

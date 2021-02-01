#include <bits/stdc++.h>
using namespace std;
#define forr(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=(int)(n-1);i>=0;i--)
#define pb push_back
#define fst first
#define snd second
#define mp make_pair
#define db(v) cerr << #v << " = " << v << endl
#define sz(v) ((int)v.size())
typedef long long ll;
typedef pair<int,int> ii;

int s;
int main() {
	//~ freopen("A.in", "r",stdin);
	while(scanf("%d", &s)>=1) {
		vector<ii> ans;
		forr(i, 2, s) {
			int q = 2*i-1;
			int r = ((int)s/q)*q;
			if(r==s) {
				ans.pb(mp(i,i-1));
				continue;
			}
			
			if(r && r+i == s) {
				ans.pb(mp(i,i-1));
				continue;
			}
		}

		forr(i, 2, s) {
			int q = 2*i;
			int r = ((int)s/q)*q;
			if(r==s) {
				ans.pb(mp(i,i));
				continue;
			}
			
			if(r && r+i == s) {
				ans.pb(mp(i,i));
				continue;
			}
		}

		sort(ans.begin(), ans.end());
		printf("%d:\n",s);
		for(auto it:ans) {
			printf("%d,%d\n",it.fst,it.snd);
		}
	}
	return 0;
}

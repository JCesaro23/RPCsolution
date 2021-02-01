#include <bits/stdc++.h>
using namespace std;
#define forr(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(ll i=(ll)(n-1);i>=0;i--)
#define pb push_back
#define fst first
#define snd second
#define db(v) cerr << #v << " = " << v << endl
#define sz(v) ((ll)v.size())
typedef long long ll;
const ll MAXN=10050;

ll b,s,A[MAXN],sz[MAXN],coste[MAXN];
ll id[MAXN],idn;
vector<ll> tt[MAXN],g[MAXN];
bool used[MAXN];

int main() {
	//~ freopen("E.in", "r",stdin);
	while(scanf("%lld%lld",&b,&s)>=1){
		idn=0;
		memset(used,false,sizeof(used));
		forn(i,MAXN){
			tt[i].clear();
			g[i].clear();
		}
		memset(coste,0,sizeof(coste));
		memset(sz,0,sizeof(sz));
		memset(A,0,sizeof(A));
		
		forn(i,b){
			ll t;
			scanf("%lld%lld%lld",&A[i],&sz[i],&t);
			id[idn++]=A[i];
			forn(j,t){
				ll v;scanf("%lld",&v);
				if(v)tt[i].pb(v);
			}
		}
		sort(id,id+idn);
		forn(i,b){
			A[i]=lower_bound(id,id+idn,A[i])-id;
			forn(j,sz(tt[i])){
				g[A[i]].pb(lower_bound(id,id+idn,tt[i][j])-id);
			}
		}
		//~ forn(i,b){
			//~ printf("Node %d:\n",i);
			//~ forn(j,sz(g[i])){
				//~ printf("--> %d\n",g[i][j]);
			//~ }
		//~ }
		forn(i,b){
			coste[A[i]]=sz[i];
		}
		queue<ll> Q;
		forn(i,s){
			ll t;
			scanf("%lld",&t);
			t=lower_bound(id,id+idn,t)-id;
			Q.push(t);used[t]=true;
		}
		while(!Q.empty()){
			ll v=Q.front();Q.pop();
			forn(i,sz(g[v])){
				ll w=g[v][i];
				if(used[w]) continue;
				used[w]=true;Q.push(w);
			}
		}
		ll ans=0;
		forn(i,b){
			if(!used[i]){
				ans+=coste[i];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

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
const int MAXN=5050;
const ll INF=(ll)1e18;

int n,s,f,A[MAXN],bm[MAXN],BM[MAXN],nc;
vector<int> g[MAXN];
ll C[MAXN],memo[MAXN][1<<11];
int color[MAXN];

void dfs(int u, int p, int c){
	color[u]=c;
	for(int v:g[u])if(v!=p){
		if(color[v]==0){
			dfs(v,u,c);
		}
	}
}

ll dp(int pos, int bm){
	if(pos==nc){
		return (bm==((1<<s)-1)) ? 0 : INF;
	}
	ll &ret=memo[pos][bm];
	if(ret!=-1)return ret;
	ret=min(dp(pos+1,bm),dp(pos+1,bm|BM[pos])+C[pos]);
	return ret;
}

int main() {
	//~ freopen("F.in", "r",stdin);
	while(scanf("%d%d%d",&n,&s,&f)>=1){
		forn(i,MAXN)g[i].clear();
		memset(bm,0,sizeof(bm));
		memset(BM,0,sizeof(BM));
		memset(color,0,sizeof(color));
		memset(C,0,sizeof(C));
		memset(memo,-1,sizeof(memo));
		nc=0;
		
		forn(i,n){
			scanf("%d",&A[i]);
		}
		forn(i,f){
			int a,b;
			scanf("%d%d",&a,&b);
			g[a].pb(b);
			g[b].pb(a);
		}
		forn(i,s){
			int q;scanf("%d",&q);
			forn(j,q){
				int v;scanf("%d",&v);
				bm[v]|=(1<<i);
			}
		}
		
		forn(i,n){
			if(color[i]==0){
				dfs(i,-1,nc);
				nc++;
			}
		}
		
		forn(i,n){
			BM[color[i]]|=bm[i];
			C[color[i]]+=A[i];
		}
		
		printf("%lld\n",dp(0,0));
	}
	return 0;
}

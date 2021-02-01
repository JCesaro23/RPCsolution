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
const int MAXN=1024;

int TC,n,k,A[MAXN];
bool used[MAXN];

int main() {
	//~ freopen("A.in", "r",stdin);
	scanf("%d",&TC);
	forn(tc,TC){
		memset(used,false,sizeof(used));
		scanf("%d%d",&n,&k);
		forn(i,n-1){
			scanf("%d",&A[i]);
		}
		
		sort(A,A+n-1);
		int top=k+A[n-2],ans=1;
		used[n-2]=true;
		dforn(i,n-1){
			if(used[i]) continue;
			int best=-1;
			forn(j,n-1){
				if(used[j]) continue;
				if(A[i]+A[j]<top){
					best=j;
				}
			}
			if(best==-1){
				ans++;
				forn(j,i){
					if(!used[i])best=j;
				}
			}
			used[i]=true;
			used[best]=true;
		}
		printf("%d\n",ans);
	}
	return 0;
}

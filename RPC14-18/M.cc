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

string N;

bool all9(){
	forn(i, sz(N))if(N[i] != '9')return false;
	return true;
	
}

int main() {
	//~ freopen("A.in", "r",stdin);
	while(cin >> N){
		if(all9()){
			forn(i, sz(N))N[i] = '1';
			N.pb('1');
		}
		else{
			dforn(i, sz(N)){
				if(N[i] == '9')N[i] = '1';
				else {N[i]++; break;}
			}
		}
		cout << N << endl;
	}
	return 0;
}

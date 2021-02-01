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
int grid[40][40];
bool v[40];
int main() {
	//~ freopen("H.in", "r",stdin);
	ios::sync_with_stdio(false);
	while(cin >> n) {
		forn(i,n) {
			string s;
			cin >> s;
			forn(j,n) {
				if('0' <= s[j] && s[j] <= '9') {
					grid[i][j] = s[j]-'0';
				} else {
					grid[i][j] = s[j]-'A'+10;
				}
			}
		}
		
		bool is_latin_square = true;
		forn(i,n) {
			memset(v, false, sizeof(v));
			forn(j,n) {
				v[grid[i][j]] = true;
			}
			forn(j,n) {
				if(!v[j]) {
					is_latin_square = false;
					break;
				}
			}
			if(!is_latin_square) break;
		}

		forn(i,n) {
			memset(v, false, sizeof(v));
			forn(j,n) {
				v[grid[j][i]] = true;
			}
			forn(j,n) {
				if(!v[j]) {
					is_latin_square = false;
					break;
				}
			}
			if(!is_latin_square) break;
		}
		
		if(!is_latin_square) {
			printf("No\n");
			continue;
		}
		
		bool reduced = true;
		forn(i,n) {
			if(grid[0][i] != i) {
				reduced = false;
				break;
			}
		}
		
		forn(i,n) {
			if(grid[i][0] != i) {
				reduced = false;
				break;
			}
		}
		
		if(reduced) {
			printf("Reduced\n");
		} else {
			printf("Not Reduced\n");
		}
	}
	return 0;
}

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
const int MAXN = 50 * 100050;

int trie[MAXN][26], nxt, t;
bool terminal[MAXN];
string s, m;
vector<string> ans;

void insert(const string &s){
	int i = 0, v = 0;
	while(i < sz(s)){
		int ch = s[i] - 'a';
		if(trie[v][ch] == -1){
			v = trie[v][ch] = ++nxt;
		} else {
			v = trie[v][ch];
		}
		i++;
	}
	terminal[v] = true;
}

bool check(const string &s){
	int i = 0, v = 0;
	while(i < sz(s)){
		int ch = s[i] - 'a';
		if(trie[v][ch] == -1){
			return false;
		} else {
			v = trie[v][ch];
		}
		i++;
	}
	return terminal[v];
}

void readstring(string &s){
	char ss[55];
	scanf(" %s", ss);
	s = ss;
}

void bf(int pos, int dif, int node){
	//~ printf("[%d, %d, %d] :: %s\n", pos, dif, node, m.c_str());
	if(pos == sz(s)){
		if(terminal[node]){
			ans.pb(m);
		}
		if(dif < 2){
			forn(ch, 26){
				int w = trie[node][ch];
				if(w == -1) continue;
				
				// insert
				m.pb(ch + 'a');
				bf(pos, dif + 1, w);
				m.pop_back();
			}
		}
		return;
	}
	if(dif < 2){
		//~ printf("[%d, %d, %d] -> [%d, %d, %d]\n", pos, dif, node, pos + 1, dif + 1, node);
		bf(pos + 1, dif + 1, node); // <-- delete character
		forn(ch, 26){
			int w = trie[node][ch];
			if(w == -1) continue;
			
			// replace
			//~ printf("[%d, %d, %d] -> [%d, %d, %d]\n", pos, dif, node, pos + 1, dif + 1, w);
			m.pb(ch + 'a');
			bf(pos + 1, dif + 1, w);
			m.pop_back();
			
			// insert
			//~ printf("[%d, %d, %d] -> [%d, %d, %d]\n", pos, dif, node, pos, dif + 1, w);
			m.pb(ch + 'a');
			bf(pos, dif + 1, w);
			m.pop_back();
		}
	}
	
	// normal
	int w = trie[node][s[pos] - 'a'];
	if(w != -1){
		//~ printf("[%d, %d, %d] -> [%d, %d, %d]\n", pos, dif, node, pos + 1, dif, w);
		m.pb(s[pos]);
		bf(pos + 1, dif, w);
		m.pop_back();
	}
}

int main() {
	//~ freopen("A.in", "r",stdin);
	while(scanf("%d",&t)>=1){
		nxt = 0;
		memset(trie, -1, sizeof(trie));
		
		forn(i, t){
			readstring(s);
			insert(s);
		}
		
		scanf("%d", &t);
		
		forn(i, t){
			readstring(s);
			if(check(s)){
				printf("%s\n", s.c_str());
			} else {
				ans.clear();
				bf(0, 0, 0);
				sort(ans.begin(), ans.end());
				ans.erase(unique(ans.begin(), ans.end()), ans.end());
				forn(i, sz(ans)){
					if(i) printf(" ");
					printf("%s", ans[i].c_str());
				}
				puts("");
			}
		}
	}
	return 0;
}

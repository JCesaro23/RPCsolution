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
typedef long double ld;

const ld EPS = 1e-8;

struct dot{
	ld x, y, z;
	dot(ld x = 0., ld y = 0., ld z = 0.): x(x), y(y), z(z){}
	dot operator+(dot a){ return dot(x + a.x, y + a.y, z + a.z);}
	dot operator-(dot a){ return dot(x - a.x, y - a.y, z - a.z);}
	dot operator*(ld a){ return dot(x*a, y*a, z*a);}
	dot operator/(ld a){ return dot(x/a, y/a, z/a);}
	ld operator*(dot a){ return x*a.x + y*a.y + z*a.z; }
	dot operator^(dot a){ return dot(y*a.z - z*a.y, z*a.x - x*a.z, x*a.y - y*a.x); }
	ld norm2(){ return x*x + y*y + z*z; }
	ld norm(){ return sqrt(norm2()); }
};
bool operator<(dot a, dot b){
	if(a.x != b.x) return a.x < b.x;
	if(a.y != b.y) return a.y < b.y;
	return a.z < b.z;
}

struct ln{
	dot p, pq;
	ln(dot p, dot q): p(p), pq(q-p){}
	dot proj(dot r){ return p + pq*((r-p)*pq/pq.norm2()); }
};

dot C;
vector<pair<int, dot>> V;

int main() {
	//~ freopen("C.in", "r",stdin);
	int p; dot T;
	while(cin >> p >> T.x >> T.y >> T.z){
		V.clear();
		
		if(p == 6) C = T;
		else V.pb({p, T});
		forn(i, 4){
			cin >> p >> T.x >> T.y >> T.z;
			if(p == 6) C = T;
			else V.pb({p, T});
		}
		sort(V.begin(), V.end());
		assert(sz(V) == 4);
		
		bool CRASH = false;
		forn(i, 3){
			if(V[i].fst == V[i+1].fst){
				printf("No chiral centre\n");
				CRASH = true;
				break;
			}
		}
		if(CRASH)continue;
		
		dot A = V[3].snd - C, B = V[2].snd - C, E = V[0].snd - C;
		
		ln L(dot(0, 0, 0), E);
		dot PA = A - L.proj(A), PB = B - L.proj(B);
		//~ printf("PA: (%.6Lf, %.6Lf, %.6Lf)\n", PA.x, PA.y, PA.z);
		//~ printf("PB: (%.6Lf, %.6Lf, %.6Lf)\n", PB.x, PB.y, PB.z);
		if(PA.norm() < EPS || PB.norm() < EPS){ printf("No chiral centre\n"); continue; }
		dot N = PA^PB;
		if(N.norm() < EPS){ printf("No chiral centre\n"); continue; }
		//~ printf("N: (%.6Lf, %.6Lf, %.6Lf)\n", N.x, N.y, N.z);
		//~ printf("E: (%.6Lf, %.6Lf, %.6Lf)\n", E.x, E.y, E.z);
		//~ printf("%.20Lf\n", (N^E).norm2());
		//~ assert((N^E).norm() < EPS);
		ld val = N*E;
		//~ printf("%.20Lf\n", val);
		if(abs(val) < EPS)printf("No chiral centre\n");
		else printf("%s\n", (val < 0 ? "Rectus" : "Sinister"));
	}
	return 0;
}

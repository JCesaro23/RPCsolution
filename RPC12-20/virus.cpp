#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define deb(x)	cout<<#x<<" = { "<<x<<" }\n"
#define fastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define forn(i, n) for (int i = 0; i < n; i++)
#define forr(i, n) for (int i = n; i >= 0; i--)
#define forne(i, x, n) for (int i = x; i < n; i++)
#define forre(i, x, n) for (int i = n; i >= x; i--)
#define all(a) (a).begin(), (a).end()
#define MOD 1000000007

int main() {
    int g, p, t;
    cin>> g>>p >>t;
    int individual = g*p;
    int grupal = g+(p*t);
    if(individual<grupal) {
	cout<<1<<endl;
    }else if(individual > grupal) {
	cout<<2<<endl;
    }else {
	cout<<0<<endl;
    }
    return 0;
}


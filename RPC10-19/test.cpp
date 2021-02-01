#include<bits/stdc++.h>
using namespace std;
#define SORT(v) sort(v.begin(),v.end())
#define si(n) scanf("%d",&n)
#define sii(n,m) scanf("%d %d",&n,&m)
#define sl(n) scanf("%lld",&n)
#define sll(n,m) scanf("%lld %lld",&n,&m)
#define ss(cad) scanf("%s",cad)
#define PB push_back
#define fst first
#define scn second
#define DBG(x) cerr<< #x << "=" << (x) <<endl
#define M 1000000007
#define N_MAX 1000010

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<pi> vp;

ll a,b;
int x;
ll vec[10];
char cad[20];
void leer()
{
	ss(cad);
	bool sw=true;
	a=0;
	b=0;
	x=0;
	for(int i=0;cad[i]!='\0';i++)
	{
		if(cad[i]=='.')
			sw=false;
		else if(sw)
			a = a*10 + (cad[i]-'0');
		else
		{
			x++;
			b = b*10 + (cad[i]-'0');
		}
	}
    printf("%lld -- %lld\n",a,b);
}

ll base( int n)
{
	ll aux=1;
	while(n>0)
	{
		aux*=10;
		n--;
	}
	return aux;
}

ll gcd(ll a,ll b)
{
	if(b==0)
		return a;
	return gcd(b, a%b);
}

pll frac(int pos, ll va, ll vb)
{
	vec[pos] = va/vb;
	if(pos<7)
	{
		pll aux = frac(pos+1 , vb , va%vb);
		//ll val = gcd(aux.first , aux.second);
		//aux.first /= val;
		//aux.second /= val;
		//cout<<vec[pos]<<" -> "<<aux.second<<"/"<<aux.first<<endl;
		return {vec[pos]*aux.first + aux.second, aux.first};
	}
	return {vec[pos],1};
}


int main()
{
	int n;
	si(n);
	while(n--)
	{
		leer();
		vec[0]=a;
		ll aux = base(x);
		pll resp = frac(1 , aux , b);
        printf("%lld *** %lld\n",resp.first, resp.second);
		ll num = vec[0]*resp.first + resp.second;
		ll den = resp.first;
	/*	ll val=gcd(num,den);
		num/=val;
		den/=val;*/
		printf("%lld", vec[0]);
		for(int i = 1 ; i < 8 ; i++)
			printf(" %lld", vec[i]);
		printf("\n%lld/%lld\n", num, den);
	}
	
	return 0;
}
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
#define M (__int128)4300000013
#define N_MAX 1000010

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<pi> vp;

__int128 expo( __int128 a, ll b)
{
	if(b == 0)
		return 1;
	__int128 aux = expo(a,b>>1);

	aux=aux*aux;
	aux%=M;

	if( (b & 1) != 1)
		return aux;
	return (a*aux)%M;
}

__int128 inv(ll a)
{
	return expo(a%M,M-2);
}


int data[100010];
int QR,QL;
int pos_u;
int val_u;
int n;
__int128 tot;
int tam;

map <int,int> mapa;

struct node
{
	int val;
	node(int a=0)
	{
		val=0;
	}

	void initLeaf(int val)
	{
		this->val = val;
	}

	void merge(node a, node b)
	{
		this->val = a.val+b.val;
	}
};

node tree[262144];

ll query(int pos,int left, int right)
{
	if(QL <= left && right <=QR)
		return tree[pos].val;
	else
	{
		int mid= (left+right)>>1;
		int A = pos <<1;

		if(	QR <= mid)
			return query(A,left,mid);
		else if(QL>mid)
			return query(A|1, mid+1, right);
		else
			return query(A,left,mid) + query(A|1, mid+1, right);
	}
}

void update(int pos, int left, int right)
{
	if(left==right)
	{
		if(data[left]==0)
		{
			tam++;
			mapa[val_u]++;
			//tot= (tot*tam)/mapa[val_u];
			tot = (tot*tam);
			tot%=M;
			__int128 inver=inv(mapa[val_u]);
			//cout<<"inverso  de : "<<mapa[val_u]<<" = "<<inver<<endl;
			tot*=inver;
			tot%=M;
		}
		else
		{
			tot = tot * mapa[data[left]];
			tot%=M;
			mapa[data[left]]--;
			mapa[data[left]+val_u]++;
			//tot = tot / mapa[data[left]+val_u];
			__int128 inver=inv(mapa[data[left]+val_u]);
			//cout<<"inverso  de : "<<mapa[data[left]+val_u]<<" = "<<inver<<endl;
			tot*=inver;
			tot%=M;
		}

		data[left]+= val_u;
		tree[pos].initLeaf(data[left]);
	}
	else
	{
		int mid= (left+right)>>1;
		int A = pos <<1;

		if(pos_u <= mid)
			update(A,left,mid);
		else
			update(A|1, mid+1, right);

		tree[pos].merge(tree[A],tree[A|1]);
	}
}

int main()
{
	int test;
	si(test);

	while(test--)
	{
		si(n);
		int m;
		si(m);

		memset(data,0,sizeof(int)*(n+1));
		memset(tree,0,sizeof tree);
		mapa.clear();
		tot=1;
		tam=0; // Cantidad de elementos

		while(m--)
		{
			char op;
			scanf(" %c",&op);

			if(op=='Q')
			{
				sii(QL,QR);
				QL--;
				QR--;

				ll resp=query(1,0,n-1);
				printf("%lld\n",resp);
			}
			else if(op=='U')
			{
			//	if(tot==0)
			//		tot=1;
				sii(pos_u,val_u);
				pos_u--;
				update(1,0,n-1);
			}
			else
			{
				printf("%lld\n", (ll)tot);
			}
		}

	}

	return 0;
}
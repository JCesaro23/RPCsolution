#include <bits/stdc++.h>
#define MAXN 10001
int HULAM[MAXN];
void pre_calculo()
{
	HULAM[1]=1;
	HULAM[2]=2;
	HULAM[3]=4;
	for(int i=4; i<= MAXN; i++)
	{
		HULAM[i]=HULAM[i-1]+3;
	}
}
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	pre_calculo();
	int n,pos;
	cin >>n;
	while(n>0)
	{
		cin >>pos;
		cout << HULAM[pos] << endl;
		--n;
	}
	return 0;
}
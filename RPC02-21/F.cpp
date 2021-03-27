/*******************************************************
Name Problem:Musical Chairs
Problem Category:adhoc
Problem Tester: Julio Cesar Mamani Villena.
Email: mamanivillenajc@gmail.com
*******************************************************/
#include<bits/stdc++.h>
#define PI 2*acos(0.0)
#define MOD 1000000007
#define EPS 1e-9
#define all(x) x.begin(),x.end()
#define fast(); ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
#define MAXN 10000
using namespace std;
void solve(){
    int nprofs;
    int profs[MAXN];
    int opus[MAXN];
    scanf("%d", &nprofs);
    for (int i = 0; i < nprofs; i++)
    {
    	scanf("%d", &opus[i]);
    	profs[i]=i+1;
    }
    int cur = 0;
    while(nprofs>1){
    	int nextOut = (cur+opus[cur]-1)%nprofs;
    	for (int i = nextOut+1; i < nprofs; i++)
    	{
    		profs[i-1] = profs[i];
    		opus[i-1]=opus[i];
    	}
    	nprofs--;
    	cur = nextOut % nprofs;
    }
    printf("%d\n", profs[0]);

}
int main(){
    fast();
    solve();
    return 0;
}
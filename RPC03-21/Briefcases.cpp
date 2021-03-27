/*******************************************************
Name Problem:Briefcases
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
using namespace std;
void solve(){
    int s[6];
    int mon[] = {1, 5, 10, 20, 50, 100};
    int mayor = 0; int min_billetes = 500000;
    for (int i = 0; i < 6; ++i)
    {
    	scanf("%d", &s[i]);
    	mayor = max(mayor, s[i]*mon[i]);
    }
    for (int i = 0; i < 6; ++i)
    {
    	if(mayor == (s[i]*mon[i])){
    		min_billetes = min(min_billetes, s[i]);
    	}
    }

    printf("%d\n", mayor / min_billetes);

}
int main(){
    fast();
    solve();
    return 0;
}
/*******************************************************
Name Problem:Moderate Pace
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

int mediana(int a, int b, int c){
	if(a>b){
		if(a>c){
			if(b>c)
				return b;
			else
				return c;
		}else{
			return a;
		}
	}else{
		if(b>c){
			if(a>c)
				return a;
			else
				return c;
		}else{
			return b;
		}
	}
}

void solve(){
    int mat[3][1001];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 3; ++i)
    {
    	for (int j = 0; j < n; ++j)
    	{
    		scanf("%d", &mat[i][j]);
    	}
    }

    printf("%d", mediana(mat[0][0], mat[1][0], mat[2][0]));

    for (int i = 1; i < n; ++i)
    {
    	printf(" %d", mediana(mat[0][i], mat[1][i], mat[2][i]));
    }

    printf("\n");

}
int main(){
    fast();
    solve();
    return 0;
}
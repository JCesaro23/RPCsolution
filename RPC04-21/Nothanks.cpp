/*******************************************************
Name Problem:problem
Problem Category:category
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
    int n, card;
    vector<int> cards;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
    	scanf("%d", &card);
    	cards.push_back(card);
    }
    sort(all(cards));
    int ans = 0;
    int aux = 0;
    bool ban = false;
    for (int i = 0; i < cards.size()-1; ++i)
    {
    	if(cards[i]==(cards[i+1]-1)){
    		if(ban == false){
    			aux = cards[i];
    			ban = true;
    		}
    	}else{
    		if(aux>0){
    			ans+=aux;
    		}else{
    			ans+=cards[i];
    		}
    		aux = 0;
    		ban = false;
    	}
    }
    if(aux>0){
		ans+=aux;
	}else{
		ans+=cards[n-1];
	}
	printf("%d\n", ans);

}
int main(){
    fast();
    solve();
    return 0;
}
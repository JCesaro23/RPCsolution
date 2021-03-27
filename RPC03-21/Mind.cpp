/*******************************************************
Name Problem:A Game Called Mind
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
    int player, n_target, card;
    vector<int> cards;
    map<int, char> mp;
    scanf("%d", &player);
    int c=65;
    for (int i = 0; i < player; ++i)
    {
    	scanf("%d", &n_target);
    	for (int j = 0; j < n_target; ++j)
    	{
    		scanf("%d", &card);
    		cards.push_back(card);
    		mp[card] = c;
    	}
    	c++;
    }
    sort(all(cards));
    for(int it:cards){
    	printf("%c", mp[it]);
    }
    printf("\n");
}
int main(){
    fast();
    solve();
    return 0;
}
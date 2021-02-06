/*******************************************************
Name Problem:Queries on the Stack
Problem Category:STL
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
    int T, Q, q, val;
    scanf("%d", &T);
    while(T--){
        stack<int> stk;
        stack<pair<int,int>> pstk;
       
        scanf("%d", &Q);
        while(Q--){
            scanf("%d", &q);

            if(q == 1){
                scanf("%d", &val);
                if(stk.empty()){
                    pstk.push(make_pair(val,val));
                }else{
                    pstk.push( make_pair( max(val, pstk.top().first),min(val, pstk.top().second) ) );
                }
                stk.push(val);
            }else if(q == 2){
                if(!stk.empty()){
                    stk.pop();
                    pstk.pop();
                }
            }else if(q == 3){
                if(stk.empty()){
                    printf("Empty!\n");
                }else{
                    pair<int, int> tope = pstk.top();
                    printf("%d\n", abs(tope.first - tope.second));
                }
            }
        }
    }
}
int main(){
    fast();
    solve();
    return 0;
}
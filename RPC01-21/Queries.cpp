#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    /*#ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin); 
        freopen("error.txt", "w", stderr); 
        freopen("output.txt", "w", stdout); 
    #endif */
    int T, Q, q, val, valMAX, valMIN;
    
    
    multiset<int>:: iterator b;
    multiset<int>:: iterator rb;
    scanf("%d", &T);
    while(T--){
        stack<int> p;
        multiset<int> mt;
        scanf("%d", &Q);
        
        while(Q--){
            scanf("%d", &q);
            if(q==1){
                scanf("%d", &val);
                p.push(val);
                mt.insert(val);
            }else if(q==2){
                if(!p.empty()){
                    mt.erase(mt.find(p.top()));
                    p.pop();
                }
            }else if(q==3){
                if(p.empty()){
                    cout<<"Empty!\n";
                }else{
                    b = mt.begin();
                    valMIN = *b;
                    int endd = mt.size() - 1;
                    advance(b, endd);
                    valMAX = *b;
                    printf("%d\n",abs(valMIN-valMAX));
                    
                }
            }
        }
    }
    
    return 0;   
}

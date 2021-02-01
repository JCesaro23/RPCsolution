#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int T, Q, q, val, valMAX, valMIN;
    
    scanf("%d", &T);
    while(T--){
        stack<int> p;
        scanf("%d", &Q);
        valMIN = 100000; valMAX = -99999;
        while(Q--){
            scanf("%d", &q);
            if(q==1){
                scanf("%d", &val);
                p.push(val);
            }else if(q==2){
                if(!p.empty()){
                    p.pop();
                }
            }else if(q==3){
                if(p.empty()){
                    cout<<"Empty!\n";
                }else{
                    valMIN = 100000; valMAX = -99999;
                    stack<int> aux;
                    while(!p.empty()){
                        valMAX = max(valMAX, p.top());
                        valMIN = min(valMIN, p.top());
                        aux.push(p.top());
                        p.pop();
                    }
                    printf("%d\n",abs(valMIN-valMAX));
                    p.swap(aux);
                }
            }
        }
    }
    
    return 0;   
}

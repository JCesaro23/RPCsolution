#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int days;
ll prevs = 1<<30;
ll money = 100;
ll cur;
int main(){
    scanf("%d", &days);
    for(int i=0; i<days; i++){
        scanf("%lld", &cur);
        if(cur > prevs) 
            money += min((money/prevs), 100000LL) * (cur-prevs);
        prevs = cur;
    }
    printf("%lld\n",money);
    return 0;
}
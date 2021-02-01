#include<bits/stdc++.h>
using namespace std;
int main(){
    int N, i;
    long Min, Max, bi;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N;
    Min=9999999999;
    Max=0;
    for(i=0; i<N; i++){
        cin>>bi;
        Min=min(bi,Min);
        Max=max(bi,Max);
        printf("%d\n",Min+Max);
    }

    return 0;
}
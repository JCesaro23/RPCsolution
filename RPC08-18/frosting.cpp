#include <bits/stdc++.h>
using namespace std;
long long A[3];
long long B[3];
int N, dato;
int main(){
    scanf("%d",&N);
    for(int i=2; i<=N+1; i++){
        scanf("%d",&dato);
        A[i%3] += dato;
    }
    for(int i=2; i<=N+1; i++){
        scanf("%d",&dato);
        B[i%3] += dato;
    }
    printf("%lld %lld %lld\n", B [2]* A [0]+ B [0]* A [2]+ B [1]* A [1] ,
                        B [2]* A [1]+ B [0]* A [0]+ B [1]* A [2] ,
                        B [2]* A [2]+ B [0]* A [1]+ B [1]* A [0]);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int W, L, N, wi, li, area;
int main(){
    area = 0;
    scanf("%d\n%d", &W, &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &wi, &li);
        area += (wi*li);
    }
    L = (area/W);
    printf("%d\n", L);
    return 0;
}
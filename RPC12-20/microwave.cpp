#include<bits/stdc++.h>
#include <cstdio>
using namespace std;
int main() {
    int m, s, a, b;
    scanf("%d:%d", &m, &s);
    a = (m*60)+s;
    b = (m*3600)+(s*60);
    int ans = b-a;
    int H= ans/3600;
    ans = ans%3600;
    int M = ans/60;
    ans = ans % 60;
    int S = ans;

    printf("%02d:%02d:%02d\n", H, M, S);
}

#include <bits/stdc++.h>
#define MAX 100000001
using namespace std;
typedef long long int lli;


int main()
{
    
    int t_casos;
    lli s;
    scanf("%d", &t_casos);
    while (t_casos--)
    {
        scanf("%lld", &s);
        lli ans = (s*(s+1))+s;
        printf("%lld\n", ans);
    }
    return 0;
}
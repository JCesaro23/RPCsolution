#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t_casos, x;
    scanf("%d", &t_casos);
    while (t_casos--)
    {
        scanf("%d", &x);
        int ans = 1;
        for(int i=2; i<x; i++){
            if(x%i==0)
                ans += i;
        }
        //cout<<"test = "<<ans<<endl;
        if (ans == x)
            printf("perfect\n");
        else if (ans < x)
            printf("deficient\n");
        else if (ans > x)
            printf("abundant\n");
    }

    return 0;
}
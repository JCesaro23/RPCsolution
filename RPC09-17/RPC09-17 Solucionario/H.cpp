#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, val;
    long long s;
    map<long long, int> pref;

    while(scanf("%d %lld", &n, &s) != EOF)
    {
        pref.clear();
        long long soma = 0;
        bool achou = 0;

        pref[0] = 0;

        for(int i = 0; i < n; i++)
        {
            scanf("%d", &val);
            if(achou) continue;

            soma += val;
            if(pref.count(soma - s))
            {
                printf("%d %d\n", pref[soma - s]+1, i+1);
                achou = 1;
            }
            pref[soma] = i+1;
        }

        if(!achou) printf("-1\n");
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

bool has(long long m, long long mask)
{
    while(m >= mask)
    {
        if((m & mask) == mask)
            return 1;
        m >>= 1;
    }
    return 0;
}

int main()
{
    long long m, k;

    while(scanf("%lld %lld", &m, &k) != EOF)
    {
        long long mask = (1LL << k) - 1;

        if(has(m, mask))   printf("%lld\n", m);
        else
        {
            m |= mask;
            mask <<= 1;
            int i = 0;

            while((m & mask) == mask)
                m &= ~(1LL << i), i++, mask <<= 1;

            printf("%lld\n", m);
        }
    }

    return 0;
}

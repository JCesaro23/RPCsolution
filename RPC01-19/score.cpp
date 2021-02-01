#include <bits/stdc++.h>
#define POWS(a) ((a)*(a))
#define MIN(a,b,c) (7*min(min((a),(b)),(c)))
#define MAX(a,b,c) (max(max((a),(b)),(c)))
using namespace std;
unsigned long long dp[7][4];
int main()
{
    int n;
    unsigned long long read;
    unsigned long long a,b,c,temp;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        for(int k=0; k<4; k++)
        {
            scanf("%llu",&read);
            dp[i][k]=read;
        }
    }
    for(int i=0; i<n; i++)
    {
        temp=dp[i][0]+dp[i][3];
        a = POWS(temp) + POWS(dp[i][1]) + POWS(dp[i][2]) + MIN(temp,dp[i][1],dp[i][2]);
        temp=dp[i][1]+dp[i][3];
        b = POWS(dp[i][0]) + POWS(temp) + POWS(dp[i][2]) + MIN(dp[i][0],temp,dp[i][2]);
        temp=dp[i][2]+dp[i][3];
        c = POWS(dp[i][0]) + POWS(dp[i][1]) + POWS(temp) + MIN(dp[i][0],dp[i][1],temp);
        cout<<MAX(a,b,c)<<'\n';
    }

    return 0;
}


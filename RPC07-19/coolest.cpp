#include<iostream>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstdio>
#define inf 0x3f3f3f3f
#include<vector>
using std::pair;
typedef pair<int,int> s;

using namespace std;
vector<s> mapp[1005];

int vis[1005];
int flag[1005];
int dis[1005];
int sum,maxx;
int n,m;

void dfs(int a)
{
    for(int i=0;i<mapp[a].size();i++)
    {
        if(dis[mapp[a][i].first]<dis[a]+mapp[a][i].second)
        {
            //vis[i]=1;
            //sum+=mapp[a][i];
            //cout<<mapp[a][i].first<<"  "<<a<<"  "<<mapp[a][i].second<<endl;
            dis[mapp[a][i].first]=dis[a]+mapp[a][i].second;
            //cout<<"  "<<dis[mapp[a][i].first]<<endl;
            dfs(mapp[a][i].first);
            //maxx=max(sum,maxx);
            //cout<<maxx<<endl;
            //vis[i]=0;
            //sum-=mapp[a][i];
        }
    }
}

int main()
{
    cin>>n>>m;
    memset(flag,0,sizeof(flag));
    memset(dis,0,sizeof(dis));
    for(int i=0;i<n;i++)
        mapp[i].clear();
    int s,t,c;
    for(int i=0;i<m;i++)
    {
        cin>>s>>t>>c;
        flag[t]=1;
        mapp[s].push_back(make_pair(t,c));
    }
    for(int i=1;i<=n;i++)
    {
        if(flag[i]==0)
        {
            //sum=0;
            dfs(i);
            //memset(vis,0,sizeof(vis));
        }
    }
    maxx=0;
    for(int i=1;i<=n;i++)
        //cout<<dis[i]<<endl;
        maxx=max(maxx,dis[i]);
    cout<<maxx<<endl;
    return 0;
}
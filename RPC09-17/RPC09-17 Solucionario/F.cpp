#include <bits/stdc++.h>
using namespace std;

#define MAXN 500000

vector<int> g[MAXN];
map<string,int> m;
int n;

bool v[MAXN];
pair<int, pair<int, string> > resp[MAXN];

#define level first
#define depen second.first
#define nome second.second

void dfs(int a)
{
    if(v[a]) return;
    v[a] = 1;

    resp[a].level = 1;
    resp[a].depen = g[a].size();

    for(int i = 0; i < (int)g[a].size(); i++)
    {
        int j = g[a][i];
        dfs(j);
        resp[a].level = max(resp[a].level, resp[j].level + 1);
    }
}

int id(char *s)
{
    if(m.count(s)) return m[s];
    resp[n].nome = s;
    m[s] = n;
    return n++;
}

int main()
{
    char s1[100], s2[100];
    int arestas;

    while(scanf("%d", &arestas) != EOF)
    {
        for(int i = 0; i < min(MAXN, 2*arestas); i++)
            g[i].clear();

        m.clear();
        n = 0;

        while(arestas--)
        {
            scanf("%s %s", s1, s2);
            g[id(s2)].push_back(id(s1));
        }

        fill(v, v + n, 0);
        for(int i = 0; i < n; i++)
            if(!v[i])
                dfs(i);

        sort(resp, resp + n);

        for(int i = 0; i < n; i++)
            printf("%d.%d %s\n", resp[i].level, resp[i].depen, resp[i].nome.c_str());
    }

    return 0;
}

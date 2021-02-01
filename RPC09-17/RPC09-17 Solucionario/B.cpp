#include <bits/stdc++.h>
using namespace std;

#define MAXN 500000

int grau[MAXN];
int prufer[MAXN];

pair<int,int> arestas[MAXN];

int main()
{
    int n;

    while(scanf("%d", &n) != EOF)
    {
        for(int i = 0; i < n; i++) grau[i] = 1;

        for(int i = 0; i < n-2; i++)
            scanf("%d", &prufer[i]), grau[--prufer[i]]++;

        priority_queue<int, vector<int>, greater<int> > folhas;

        for(int i = 0; i < n; i++)
            if(grau[i] == 1)
                folhas.push(i);

        for(int i = 0; i < n-2; i++)
        {
            arestas[i] = make_pair(prufer[i], folhas.top());
            folhas.pop();

            if(--grau[prufer[i]] == 1)
                folhas.push(prufer[i]);
        }

        arestas[n-2].first = folhas.top(); folhas.pop();
        arestas[n-2].second = folhas.top();

        for(int i = 0; i < n-1; i++)
            if(arestas[i].first > arestas[i].second)
                swap(arestas[i].first, arestas[i].second);

        sort(arestas, arestas + n-1);

        for(int i = 0; i < n-1; i++)
            printf("%d %d\n", arestas[i].first + 1, arestas[i].second + 1);
    }

    return 0;
}

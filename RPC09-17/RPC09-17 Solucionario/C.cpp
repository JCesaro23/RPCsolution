#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000

char mapa[MAXN+2][MAXN+2];
int n, m;

int cont_casas[(MAXN+2) * (MAXN+2) + 5];
int v[MAXN+2][MAXN+2];

set< pair<int,int> > fronteira;

void ffill(int i, int j, int id)
{
    queue< pair<int,int> > f;
    int cont = 0;

    f.push(make_pair(i, j));
    v[i][j] = id;

    while(!f.empty())
    {
        i = f.front().first;
        j = f.front().second;
        f.pop();

        cont += mapa[i][j] == '#';

        for(int a = -1; a <= 1; a++)
        {
            for(int b = -1; b <= 1; b++)
            {
                int ii = i + a, jj = j + b;
                if(ii < 0 || jj < 0 || ii >= n || jj >= m) continue;

                if(id == 0 && mapa[ii][jj] == '*')
                    fronteira.insert(make_pair(ii, jj));

                if(v[ii][jj] == -1 && (mapa[ii][jj] == '.' || mapa[ii][jj] == '#'))
                {
                    v[ii][jj] = id;
                    f.push(make_pair(ii, jj));
                }
            }
        }
    }

    cont_casas[id] = cont;
}

int main()
{
    while(scanf("%d %d", &n, &m) != EOF)
    {
        for(int i = 0; i < n+2; i++) mapa[i][0] = mapa[i][m+1] = '.';
        for(int i = 0; i < m+2; i++) mapa[0][i] = mapa[n+1][i] = '.';
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                scanf(" %c", &mapa[i][j]);
        n += 2;
        m += 2;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                v[i][j] = -1;

        int id = 0;
        fronteira.clear();

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(v[i][j] == -1 && (mapa[i][j] == '.' || mapa[i][j] == '#'))
                    ffill(i, j, id++);

        int resp = cont_casas[0];

        for(auto i : fronteira)
        {
            set<int> ss;
            ss.insert(0);

            for(int a = -1; a <= 1; a++)
            {
                for(int b = -1; b <= 1; b++)
                {
                    int ii = i.first + a, jj = i.second + b;
                    if(ii < 0 || jj < 0 || ii >= n || jj >= m) continue;

                    if(v[ii][jj] != -1)
                        ss.insert(v[ii][jj]);
                }
            }

            int aqui = 0;
            for(auto i : ss)
                aqui += cont_casas[i];

            resp = max(resp, aqui);
        }

        printf("%d\n", resp);
    }

    return 0;
}

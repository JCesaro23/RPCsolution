#include <bits/stdc++.h>
using namespace std;

bool vogal(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main()
{
    int n;
    char linha[101];

    scanf("%d", &n);
    getchar();

    while(n--)
    {
        gets(linha);

        for(int i = 0; linha[i]; i++)
        {
            if(vogal(linha[i])) printf("%cp%c", linha[i], linha[i]);
            else                printf("%c", linha[i]);
        }

        printf("\n");
    }

    return 0;
}

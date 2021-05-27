/*******************************************************
Name Problem:Missing Number
Problem Category:adhoc
Problem Tester: Julio Cesar Mamani Villena.
Email: mamanivillenajc@gmail.com
*******************************************************/
#include <bits/stdc++.h>
#define PI 2 * acos(0.0)
#define MOD 1000000007
#define EPS 1e-9
#define all(x) x.begin(), x.end()
#define fast()                        \
    ;                                 \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;
void solve()
{
    int n, pos;
    string sn, rd;
    rd = "12345678910111213141516171819202122232425262728293031323334353637383940";
    rd += "41424344454647484950515253545556575859606162636465666768697071727374757677787980";
    rd += "81828384858687888990919293949596979899100";
    cin >> n >> sn;
    int lmt = sn.size();
    bool ban = false;
    for (pos = 0; pos < lmt; pos++)
    {
        if (rd[pos] != sn[pos])
        {
            if (pos < 10)
                cout << rd[pos] << endl;
            else
                cout << rd[pos + 1] << rd[pos] << endl;
            ban = true;
            break;
        }
    }
    if (!ban)
    {
        cout << n << endl;
    }
}
int main()
{
    fast();
    solve();
    return 0;
}
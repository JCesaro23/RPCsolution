#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[2010];
ll b[2010];
ll n, m;
multiset <ll> st;
int main(){

    scanf("%lld",&n);
    scanf("%lld",&m);
    for(ll i=0; i<n; i++)
        scanf("%lld",&a[i]);
    for(ll i=0; i<m; i++)
        scanf("%lld",&b[i]);
    st.clear();
    for(ll i=0; i<n; i++){
        for (ll j = 0; j < m; j++)
        {
            if(b[j]>=a[i])
                st.insert(b[j]-a[i]);
        }
    }

    multiset <ll>::iterator it;
    ll x = -1;
    ll k = 0;
    ll y = 0;
    ll sum = -1;
    for(it= st.begin(); it!=st.end(); it++){
        if((*it) == x) k++;
        else if((*it)!=x){
            if(k>sum){
                sum = k;
                y = x;
            }
            x = (*it);
            k = 1;
        }
    }
    printf("%lld\n", y);

    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main() {
    int est, elec, v1, v2, E, M, e1, e2, m1, m2;
    cin>>est;
    e1 = e2 = m1 = m2 = 0;
    while(est--) {
	cin>>elec >>v1 >>v2;
	m1 += v1;
	m2 += v2;
	if(v1 > v2) {
	    e1 += elec;
	}
	else if(v1 < v2)e2 += elec;
    }
    E = M = 0;
    if(e1>e2) E = 1;
    else if(e1 < e2) E = 2;
    
    if(m1>m2) M = 1;
    else if(m1 < m2)M = 2;

    
    if(E==1 && M==1) cout<<1<<endl;
    else if(E==2 && M==2)cout<<2<<endl;
    else cout<<0<<endl;
    return 0;
}

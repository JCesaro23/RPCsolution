#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m, xi;
    int enem[300000];
    int muertos[300000];
    scanf("%d %d",&n, &m);

    for(int i=0; i<n; i++){
        scanf("%d",&xi);
        enem[i]=xi;
    }
    for(int i=m; i<n; i++){
        muertos[i]=max(muertos[i-1], muertos[i-m]+enem[i]);
    }
    printf("%d\n",muertos[n-1]);


    return 0;
}

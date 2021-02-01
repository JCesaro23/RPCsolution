#include<bits/stdc++.h>
using namespace std;
int pos,i,j,m,n;
int menor(int caje[]){
    m=1000000;
    for (i=1; i<=n; i++){
        if(caje[i]<m){
            pos=i;
            m=caje[i];
        }
    }

    return pos;
}
int main(){
    int c,dato,posi;

    scanf("%d",&n);
    int caje[n+1];
    scanf("%d",&c);
    for (i=1;i<=n;i++){
        scanf("%d",&dato);
        caje[i]=dato;
        if(i==c){
            printf("%d\n",i);
        }
        else printf("%d ",i);
    }

    for(j=n+1;j<=c;j++){
        scanf("%d",&dato);
        posi=menor(caje);
        caje[posi]+=dato;
        if(j==c){
            printf("%d\n",posi);
        }
        else printf("%d ",posi);

    }
    return 0;
}

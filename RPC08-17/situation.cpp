#include<bits/stdc++.h>
using namespace std;
int main(){
    int i,j,k,n,x;
    bool z=false;
    scanf("%d",&n);
    int vec[n+1];
    for(i=0;i<n;i++){
        scanf("%d",&x);
        vec[i]=x;
    }
    for(i=0;i<n-2;i++){
        for(j=i+1;j<n-1;j++){
            for(k=j+1;k<n;k++){
                if(vec[i]+vec[j]>vec[k]&&abs(vec[i]-vec[j])<vec[k]){
                    printf("possible\n");
                    z=true;
                    break;
                }
            }
            if(z)break;
        }
        if(z)break;
    }
    if(z==false)printf("impossible\n");

    return 0;
}

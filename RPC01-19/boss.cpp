#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while((scanf("%d",&n)!=EOF)){
        if(n<=3){
            printf("1\n");
        }else{
            printf("%d\n",n-2);
        }
    }
    return 0;
}

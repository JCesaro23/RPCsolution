#include<bits/stdc++.h>
#define MAX_N 100001
using namespace std;
int cols[MAX_N], n, i, montain;
bool sw = true;
string a, b;
int main(){
    scanf("%d",&n);
    for(i=0; i<n; i++){
        scanf("%d",&cols[i]);
        sw = cols[i]!=0 ? false:sw;
    }
    montain = 0;
    if(sw){
        printf("0\n");
    }else if(n == 2){
        printf("1\n");
    }else{
        sw = true;
        a = "up";
        for(i=1; i<n; i++){
            if(cols[i-1]!=cols[i]){
                b = cols[i-1]<cols[i] ? "up":"down";
            }else{
                b = a;
            }
            if(b=="down" && a=="up"){
                ++montain;
                sw = false;
            }
            a = b;
        }
        if(sw){
        printf("1\n");
        }else{
            if(cols[i-2]<cols[i-1])
                printf("%d\n",++montain);
            else
                printf("%d\n",montain);
        }
    }
    
    return 0;
}
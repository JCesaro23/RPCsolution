#include <bits/stdc++.h>
#define MAX 1000001
#define SQRT 1000
using namespace std;
bitset<MAX> marked;
int n;

void criba(){
    marked[0]=marked[1]=true;
    int i=2;
    for(; i<=SQRT;i++){
        if(!marked[i]){
            for(int j=i*i; j<=MAX; j+=i)
                marked[j]=true;
        }
    }
    
}
int main(){
    criba();
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
vector <int> xi;
double median;
int n, x, i;
int main(){
    while(scanf("%d",&n), n!=0){
        xi.clear();
        median = 0;
        i = n;
        if(n <= 2){
            while(i--){
                scanf("%d",&x);
                median += x;
            }
            printf("%.1lf\n",median/n);
        }else{
            while(i--){
                scanf("%d", &x);
                xi.push_back(x);
            }
            sort(xi.begin(), xi.end());
            if((n & 1) == 1)
                median = xi[n/2];
            else
                median = (double) (xi[n/2] + xi[(n/2)-1])/2;     
            printf("%.1lf\n", median);               
        }
    }

    return 0;
}
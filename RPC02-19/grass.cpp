#include <bits/stdc++.h>
using namespace std;
double precio, costTotal, wi, li, area;
int L;

int main(){
    scanf("%lf\n%d", &precio, &L);
    area = 0;
    while(L--){
        scanf("%lf %lf", &wi, &li);
        area += (wi*li);
    }
    costTotal = precio*area;
    printf("%.7lf",costTotal);
    return 0;
}
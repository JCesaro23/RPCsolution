#include <bits/stdc++.h>
using namespace std;
int main(){
	double ans = 2 + sqrt(2)+sqrt(6);
	double a;
	scanf("%lf",&a);
	double l = a*ans;
	double res = l*l;
	printf("%.5lf\n",res);
	return 0;
}

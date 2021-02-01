#include<bits/stdc++.h>
using namespace std;
int main(){
	int a, b, c;
	set<int>p;
	scanf("%d %d %d", &a, &b, &c);
	for(int i=b; i<a; i+=b){
		p.insert(i);
	}
	for(int i=c; i<a; i+=c){
		p.insert(i);
	}
	int ans = p.size();
	printf("%d\n", ans);
	return 0;
}

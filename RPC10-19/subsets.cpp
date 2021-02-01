#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int V[1000010];

int main(){
	cin.tie(0);
	cout.tie(0);
	int n,q,a,ind;
	long long sum=0;
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>V[i];
	}
	sort(V,V+n);
	while(q--){
		cin>>a;
		sum=0;
		for(int i=n-1;i>=0;i--){
			ind=upper_bound(V,V+n,(a-V[i])) -V-1;
			ind=min(ind,i-1);
			
			if(ind<0) continue;
			sum=sum+ind+1;
		}
		cout<<sum<<'\n';
	}
	return 0;
}
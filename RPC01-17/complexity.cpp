#include<bits/stdc++.h>
#define MAXN 101
using namespace std;
vector<int>frec(30);
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	char s;	
	int i=0;
	while((s=getchar() ) !='\n'){
		++frec[s-'a'];	
		
	}
	sort(frec.rbegin(),frec.rend());
	vector<int>:: iterator it;
	int sum=0;
	for(it=frec.begin(); it!=frec.end(); it++ ){
		if(i>1 && *it!=0) sum += *it;
		if(*it == 0) break;
		++i;
	}
	cout<<sum<<endl;
	return 0;
}

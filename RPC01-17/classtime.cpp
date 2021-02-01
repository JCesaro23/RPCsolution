#include <bits/stdc++.h>
using namespace std;
string MAT[100][2];
string AUX[100][2];
int n;
set<string>ape;
void ordenar(){
	set<string>:: iterator it;
	int pos=0;
	for(it=ape.begin(); it!=ape.end(); it++ ){
		set<string>names;
		for(int i=0; i<n; i++){
			if(MAT[i][1].compare(*it) == 0 ){
				names.insert(MAT[i][0] );
			}
		}
		set<string>:: iterator itr;
		for(itr=names.begin(); itr!=names.end(); itr++ ){
			AUX[pos][0]=*itr;
			AUX[pos][1]=*it;
			++pos;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	string x;
	getline(cin,x);
	n = atoi(x.c_str());
	for(int i=0; i<n; i++){
		cin>>MAT[i][0]>>MAT[i][1];
		ape.insert(MAT[i][1]);
	}
	ordenar();
	for(int i=0; i<n; i++){
		cout<<AUX[i][0]<<" "<<AUX[i][1]<<endl;
	}	
	return 0;
}


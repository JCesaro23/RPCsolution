#include <iostream>

using namespace std;

string V[200];
int main(){
	V[1]="1";
	V[2]="2";
	V[3]="2";
	V[4]="2";
	V[5]="6";
	V[6]="8";
	V[7]="10";
	V[8]="18";
	V[9]="20";
	V[10]="20";
	V[11]="28";
	V[12]="68";
	V[13]="88";
	V[14]="108";
	V[15]="188";
	V[16]="200";
	V[17]="208";
	V[18]="288";
	V[19]="688";
	V[20]="888";
	for(int i=21;i<=130;i++){
		V[i]=V[i-7]+'8';
	}
	int q,a;
	cin>>q;
	while(q--){
		cin>>a;
		cout<<V[a]<<endl;
	}
	return 0;
}
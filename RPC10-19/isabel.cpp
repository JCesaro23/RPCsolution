#include<bits/stdc++.h>
using namespace std;

string vec[134];
void isabel(){
    int i,j;
    string c="8";
    vec[1]="1";
    vec[2]="2";
    vec[3]="2";
    vec[4]="2";
    vec[5]="6";
    vec[6]="8";
    vec[7]="10";
    vec[8]="18";
    vec[9]="20";
    vec[10]="20";
    vec[11]="28";
    vec[12]="68";
    vec[13]="88";
    vec[14]="108";
    vec[15]="188";
    vec[16]="200";
    vec[17]="208";
    vec[18]="288";
    vec[19]="688";
    vec[20]="888";
    for(i=21;i<133;i+=7){
        for(j=0;j<7;j++){

            vec[i+j]=vec[14+j]+c;
        }
        c+="8";
    }
}
int main(){
    int t,x;
    scanf("%d",&t);
    isabel();
    while(t--){
        scanf("%d",&x);
        printf("%s\n",vec[x].c_str());
    }
    return 0;
}

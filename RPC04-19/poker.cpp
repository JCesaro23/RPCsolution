
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s,z;
    int n=0,m,c;
    int vec[14];
    memset(vec,0,sizeof(vec));
    getline(cin,s);
    m=13;
    for(int i=0;i<m;i+=3){
        c=s[i]-48;
        if(c==1){

            i++;
            vec[10]++;
            m++;
        }
        else{

            if(c<11){
                ++vec[c];
            }

            else{
                if(s[i]=='A')vec[1]++;
                else if(s[i]=='J')vec[11]++;
                else if(s[i]=='Q')vec[12]++;
                else vec[13]++;
            }
        }

    }
    for(int j=1;j<14;j++){
        if(vec[j]>n)n=vec[j];

    }
    printf("%d\n",n);
    return 0;
}

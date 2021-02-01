#include <bits/stdc++.h>
using namespace std;
int character[123];
void inicialize(){
    for(int i=0; i<=122; i++)
        character[i]=0;
}
int main(){
    char c, ini='*';
    string s="";
    set<char> cadena;
    int par=0,impar=0, len=0, pos;
    while((c=getchar())!=EOF){
        if(c=='\n') break;
        ++character[c];
        cadena.insert(c);
    }
    len = cadena.size();
    set<char>::iterator it;
    for(it=cadena.begin(); it!=cadena.end();it++){
        pos = *it;
        if((character[pos] & 1) == 0)
            ++par;
        else
            ++impar;
    }

    if(par == len)
        cout<<"0"<<endl;
    else if(impar == len)
        cout<<"1"<<endl;
    else
        cout<<"2"<<endl;

    return 0;
}

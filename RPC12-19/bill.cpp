#include<bits/stdc++.h>
#define cerveza 42
#define fast_io ios::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
int suma, precio, i, cant, residuo;
string s1, s2;
int main(){
    fast_io
    while(cin>>s1){
        if(s1[0] == '|') { suma += (cerveza * s1.size()); } 
        else {
            for(i=0; i<s1.size(); i++){
                if(isdigit(s1[i])) s2 += s1[i];
                else break;
            }
            precio = stoi(s2);
            cant = s1.size() - (i+2);
            if(cant == 0) suma += precio;
            else suma += (precio * cant);
        }
        s2 = s1 = "";
        cant = 0;
    }
    residuo = suma % 10;
    if( residuo != 0) suma += (10 - residuo);
    printf("%d,-\n",suma);
   
    return 0;
}

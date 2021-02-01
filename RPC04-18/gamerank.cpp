#include <bits/stdc++.h>
using namespace std;
int ranked = 25;
int z = 0;
int c = 0;
string s;
int main(){
    cin >> s;
    for(int i=0; i<s.size(); i++){
        if(s[i] == 'W'){
            z++;
            c++;
            if(z>=3 && (ranked >= 6 && ranked <=25)) c++;
            if(ranked >= 21 && ranked<=25 && c > 2) { ranked--; c-=2; }
            if(ranked >= 16 && ranked<=20 && c > 3) { ranked--; c-=3; }
            if(ranked >= 11 && ranked<=15 && c > 4) { ranked--; c-=4; }
            if(ranked >= 1 && ranked<=10 && c > 5) { ranked--; c-=5; }
            if(ranked == 0){ printf("Legend\n"); break; }

        }else{
            z = 0;
            if(ranked >= 1 && ranked <=20) c--;
            if(ranked == 20 && c < 0) c = 0;
            if(ranked <= 10 && c < 0) {ranked++; c = 4; if(ranked == 11) c = 3;}
            if(ranked <= 15 && c < 0) {ranked++; c = 3; if(ranked == 16) c = 2;}
            if(ranked <= 20 && c < 0) {ranked++; c = 2;}
        }
    }
    if(ranked != 0) printf("%d\n", ranked);
    return 0;
}
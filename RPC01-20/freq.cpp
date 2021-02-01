#include<bits/stdc++.h>
using namespace std;
int ch[26];
void pre_calculo(string s) {
  for (int i = 0; i < s.length(); i++){
      if(isalpha(s[i])){
          ch[toupper(s[i]) - 'A']++;
      }
  }
}
void test(){
    set<int> val;
    for (int i=0; i<26; i++)
        if(ch[i]!=0)
            val.insert(ch[i]);
    set<int>::reverse_iterator i;
    for(i=val.rbegin(); i!=val.rend(); i++){
        set<char> key;
        for(int m =0; m<26; m++)
            if(ch[m]!=0 && ch[m]==(*i))
                key.insert(m+'a');
        set<char>::iterator it;
        for(it = key.begin(); it!=key.end(); it++){
            for(int k=0; k<(*i); k++){
                printf("%c",(*it));
            }
        }
    }
    printf("\n");
}
int main(){
    memset(ch,0,sizeof(ch));
    string ss;
    getline(cin, ss);
    pre_calculo(ss);
    test();
    return 0;
}

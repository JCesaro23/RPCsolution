#include<bits/stdc++.h>
using namespace std;
int main(){
    int A, B;
    //while(cin>>A>>B){
        cin>>A>>B;
        int c=0;
        while(A!=B){
            if(A>B){
                if((A&1)==0){
                    A/=2;
                }else{
                    A++;
                }
            }else{
                A++;
            }
            c++;
        }
        cout<<c<<endl;
    //}
    return 0;
}
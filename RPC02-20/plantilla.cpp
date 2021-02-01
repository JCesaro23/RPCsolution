#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0);
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
/*  
    g++ -std=c++11 plantilla.cpp -o t
    ./t <a.in >a.out 
*/
int main(){
    fast
    double f =( 379/100);
    printf("%.0lf\n",f);
    return 0;
}
/*
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0);
using namespace std;
typedef pair<int,int> pii;
typedef vector<long> vl;
typedef vector<pii> vii;
/*  
    g++ -std=c++11 plantilla.cpp -o t
    ./t <a.in >a.out 
*/
/*int main(){
    fast
    int n;
    long c, wi;
    vl cu;
    cin >>n >>c;
    for(int i=0; i<n; i++){
        cin>>wi;
        cu.push_back(wi);
    }
    sort(cu.rbegin(), cu.rend());

    vl::iterator it;
    for(it=cu.begin(); it!=cu.end(); it++){
        cout<<(*it)<<"  ";
    }
    cout<<'\n';
    int p=0;
    long wg=0;
    while(!cu.empty()){
        wg = cu.front();
        cu.erase(cu.begin());
        for(int i=0; i<cu.size(); i++){
            if(wg+cu[i] <= c){
               // cout<<cu[i]<<'\n';
                it = find(cu.begin(), cu.end(), cu[i]);
                cu.erase(it);
                break;
            }
        }
        p++;
    }
    cout << p<<'\n';
    return 0;
}

*/
#include <bits/stdc++.h>
#include <cstdio>
#define N 100000
using namespace std;
int tree[4*N];
int v[N];

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a%b);
}

void build(int id, int L, int R){
  if(L==R){
    tree[id] = v[L];
    return;
  }
  int mid = (L+R)/2;
  build(2*id, L, mid);
  build(2*id+1, mid+1, R);
  tree[id] = gcd(tree[2*id], tree[2*id+1]);
}

void update(int id, int L, int R, int pos, int val){
  if(L == R){
    tree[id] = val;
    return;
  }
  int mid = (L+R)/2;
  if(pos <= mid){
    update(2*id, L, mid, pos, val);
  }else{
    update(2*id+1, mid+1, R, pos, val);
  }
  tree[id] = gcd(tree[2*id], tree[2*id+1]);
}

int query(int id, int L, int R, int l, int r){
  if(L==l && R==r){
    return tree[id];
  }
  int mid = (L+R)/2;
  
  if(r <= mid){
    return query(2*id, L, mid, l, r);
  }
  if(mid < l){
    return query(2*id+1, mid+1, R, l, r);
  }

  return gcd(query(2*id, L, mid, l, mid), query(2*id+1, mid+1, R, mid+1, r));

}

int main(){
  int n, q, a, b;
  char c;
  cin>>n;
  
  for(int it=0; it<n; it++)
    cin>>v[it];
  build(1, 0, n-1);

  cin>>q;
  while(q--){
    cin>> c >> a >> b;
    if(c == 'Q'){
      printf("Gcd de %d al %d es %d\n", a, b, query(1, 0, n-1, a, b));     
    }else{
      update(1,0,n-1,a,b);


    }

  }
  
  return 0;
}

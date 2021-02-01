#include<bits/stdc++.h>
#include <cstdio>
using namespace std;
int main(){
  int a, b, dg, ct, res, i, j, k, l;
  bool ban = false;
  scanf("%d %d %d\n", &a, &b, &dg);
  l= a%10; a/=10;
  k = a%10; a/=10;
  j = a%10; a/=10;
  i = a;
  ct = res = 0;
  for(;i<10;i++){
    for(;j<10;j++){
      for(;k<10; k++){
	for(;l<10;l++){
	  if(i==dg)ct++; if(j==dg)ct++;
	  if(k==dg)ct++; if(l==dg)ct++;
	  res = (i*1000)+(j*100)+(k*10)+l;
	  if(res == b){
	    ban = true;
	    break;
	  }
	}l=0;
	if(ban)break;
      }k=0;
      if(ban)break;
    }j=0;
    if(ban)break;
  }i=0;
  cout<<ct<<'\n';
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define MAX_D 10000000
long long ki[10], a, b, temp, bi;
int t, idx, x;
double r=0;
char cad[20];

void leer()
{
	scanf("%s",cad);
	bool sw=true;
	a=0;
	b=0;
	x=0;
	for(int i=0;cad[i]!='\0';i++)
	{
		if(cad[i]=='.')
			sw=false;
		else if(sw)
			a = a*10 + (cad[i]-'0');
		else
		{
			x++;
			b = b*10 + (cad[i]-'0');
		}
	}
    
}

long long calculo(){
    bi = a/b;
    a = a % b;
    temp = a;
    a = b; 
    b = temp;
    return bi;
}


long long base( int n)
{
	long long aux=1;
	while(n>0)
	{
		aux*=10;
		n--;
	}
	return aux;
}

int main(){
    scanf("%d",&t);
    while(t--){
        leer();
        ki[0] = a;
        long long aux = base(x);
        a = aux;
        idx = 1;
        while (b != 0 && idx < 8)
        {
            ki[idx] = calculo();
            idx++;
        }
        printf("%lld",ki[0]);
        for(int i=1; i < 8; i++)
            printf(" %lld",ki[i]);
        a = 1;
        b = ki[7];
        for(int i=7; i>0; i--){
            a = a + (ki[i-1] * b);
            temp = a;
            a = b;
            b = temp;
        }
        
        temp = a;
        a = b;
        b = temp;    
        printf("\n%lld/%lld\n", a, b);
    }
    return 0;
}

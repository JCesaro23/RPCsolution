#include <bits/stdc++.h>
using namespace std;
int n_casos, x, y;
long long puntos, altura, ld;

void calcular_eje_Y_positivo(){
    if(x>0)
        altura = (x+y)*2;
    else
        altura = (-x+y)*2;

    puntos = altura * altura;
    puntos -= (altura-(x+1));
    
}

void  calcular_eje_Y_negativo(){
    int base = (-y*2);
    if(x >=0){
        if(x <= base){
            altura = base + 1;
            puntos = altura * altura;
            puntos -= (altura+(x-1));
        } 
        else{
            altura = (x+y)*2;
            puntos = altura * altura;
            puntos  -= ((altura-1)-x);
            
        }  
    }
    else{
        if(-x <= base){
            altura = (-y*2)+1;
            puntos = altura * altura;
            puntos -= (altura-1)+x;
        }else{
            ld = (-x+y)*2;
            altura = ld-1;
            puntos = altura * altura;
            puntos += (ld + x);
        }
    }
}

int main(){
    
    scanf("%d",&n_casos);
    while(n_casos--){
        puntos = 0;
        altura = 0;
        scanf("%d %d", &x, &y);
        if(x==0 && y==0){
            printf("1\n");
        }
        else if(y>=0){
            calcular_eje_Y_positivo();
            printf("%lld\n",puntos);
        }
        else{
            calcular_eje_Y_negativo();
            printf("%lld\n",puntos);
        }
        
    }
    
    
    return 0;
}
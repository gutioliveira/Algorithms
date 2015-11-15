#include <bits/stdc++.h>
   
using namespace std;
  
struct pedra{
  
    char tipo;
    int d;
  
};
  
int main(){
   
    int teste;
  
    int distancia;
  
    int n;
  
    char tipo, aux;
  
    int distancia_pedra;
  
    int max = 0;
  
    int salto;
  
    pedra p[100];
  
    scanf("%d", &teste);
  
    for ( int test = 1; test <= teste ; test++ ){
  
        scanf("%d %d", &n, &distancia);
  
        for ( int i = 0 ; i < n ; i++ ){
  
            cin.ignore();
            cin >> tipo >> aux >> distancia_pedra;
              
            p[i].tipo = tipo;
            p[i].d = distancia_pedra;
  
        }
  
        int i = -1;
  
        while ( i < n ){
  
            if ( i == -1 ){
                salto = p[0].d;
                i++;
  
                if ( salto > max )
                    max = salto;
            }else if ( p[i].tipo == 'S' ){
  
                p[i].tipo = 'X';
  
                if ( i + 1 == n ){
  
                    salto = distancia - p[i].d;
  
// printf("yto na pedrinha %d , salto = %d\n", i , salto );
  
                    if ( salto > max )
                        max = salto;
                    break;
                }else{
  
  
                    if ( p[i+1].tipo == 'B' ){
                        salto = p[i+1].d - p[i].d;
                        i = i + 1;
                        if ( salto > max )
                             max = salto;
                    }
                    else if ( i + 2 == n ){
                        salto = distancia - p[i].d;
                        i = i + 2;
  
                        if ( salto > max )
                             max = salto;
                    }else{
                        salto = p[i+2].d - p[i].d;
                        i = i + 2;
  
                        if ( salto > max )
                            max = salto;                        
                    }
  
// printf("xto na pedrinha %d , salto = %d\n", i , salto );
                      
                }
  
            }else if ( p[i].tipo == 'B' ){
  
                if ( i + 1 == n ){
  
                    salto = distancia - p[i].d;
  
// printf("zto na pedrinha %d , salto = %d\n", i , salto );
  
                    if ( salto > max )
                        max = salto;
                    break;                    
                }else{
  
                    salto = p[i+1].d - p[i].d;
  
// printf("to na pedrinha %d , salto = %d\n", i , salto );
                    i++;
  
                     if ( salto > max )
                        max = salto;
                }
            }
  
            if ( salto > max )
                max = salto;
  
        }
  
        i = n;
  
        int ultimo_salto = distancia;
  
        while ( i != -1 ){
 
            if ( i - 1 == -1 ){
  
                salto = ultimo_salto;
 
                if ( p[0].tipo != 'X')
                    salto = p[0].d;
// printf("bto na pedrinha %d , salto = %d\n", i , salto );
                if ( salto > max )
                    max = salto;
  
                break;
            }
  
            if ( p[i-1].tipo == 'B' || p[i-1].tipo == 'S' ){
  
                salto = abs(ultimo_salto - p[i-1].d);
                ultimo_salto = p[i-1].d;
// printf("Ato na pedrinha %d , salto = %d\n", i , salto );
                i--;
            }else if ( p[i-1].tipo == 'X' ){
  
                i--;
            }
  
            if ( salto > max )
                max = salto;
  
        }
  
        printf("Case %d:", test);
        printf(" %d\n", max);
  
        max = 0;
  
    }
   
    return 0;
}
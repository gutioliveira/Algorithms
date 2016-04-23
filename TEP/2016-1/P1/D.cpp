#include <bits/stdc++.h>

using namespace std;

#define MAX 55

int campo[MAX][MAX];
int visitado[MAX][MAX];

int n,m,p;

void vertical(int i, int j, int valor, int valor_inicial){

    queue < pair<int,int> > q;
    
    q.push(make_pair(i,j));
    
    pair<int,int> atual;
    
    int a,b;
    
    while ( !q.empty() ){
    
            atual = q.front();
            q.pop();
            a = atual.first;
            b = atual.second;
            
            campo[a][b] = valor;
            visitado[a][b] = 1;
            
            if ( a+1 <= n )
                if ( campo[a+1][b] == valor_inicial && !visitado[a+1][b] ){
                    q.push(make_pair(a+1,b));
                    visitado[a+1][b] = 1;
                }
            
            if ( a-1 >= 1 )
                if ( campo[a-1][b] == valor_inicial && !visitado[a-1][b] ){
                    q.push(make_pair(a-1,b));
                    visitado[a-1][b] = 1;
                }
         
    }   
}

void horizontal(int i, int j, int valor, int valor_inicial){

    queue < pair<int,int> > q;
    
    q.push(make_pair(i,j));
    
    pair<int,int> atual;
    
    int a,b;
    
    while ( !q.empty() ){
    
            atual = q.front();
            a = atual.first;
            b = atual.second;
            q.pop();
            
            campo[a][b] = valor;
            visitado[a][b] = 1;
            
            if ( b+1 <= m )
                if ( campo[a][b+1] == valor_inicial && !visitado[a][b+1] ){
                    q.push(make_pair(a,b+1));
                    visitado[a][b+1] = 1;
                }
            
            if ( b-1 >= 1 )
                if ( campo[a][b-1] == valor_inicial && !visitado[a][b-1] ){
                    q.push(make_pair(a,b-1));
                    visitado[a][b-1] = 1;
                }
         
    }
}

void diagonal(int i, int j, int valor, int valor_inicial){

    queue < pair<int,int> > q;
    
    q.push(make_pair(i,j));
    
    pair<int,int> atual;
    
    int a, b;
    
    while ( !q.empty() ){
    
            atual = q.front();
            a = atual.first;
            b = atual.second;
            q.pop();
            
            //printf("k\n");
            
            campo[a][b] = valor;
            visitado[a][b] = 1;
            
                if ( a-1 >= 1 && b+1 <= m )
                    if ( campo[a-1][b+1] == valor_inicial && !visitado[a-1][b+1] ){
                        q.push(make_pair(a-1,b+1));
                        visitado[a-1][b+1] = 1;
                    }
                
                if ( a+1 <= n && b+1 <= m )
                    if ( campo[a+1][b+1] == valor_inicial && !visitado[a+1][b+1] ){
                        q.push(make_pair(a+1,b+1));
                        visitado[a+1][b+1] = 1;
                    }
                
                if ( a+1 <= n && b-1 >= 1 )
                    if ( campo[a+1][b-1] == valor_inicial && !visitado[a+1][b-1] ){
                        q.push(make_pair(a+1,b-1));
                        visitado[a+1][b-1] = 1;
                    }
                
                if ( a-1 >= 1 && b-1 >= 1 )
                    if ( campo[a-1][b-1] == valor_inicial && !visitado[a-1][b-1] ){
                        q.push(make_pair(a-1,b-1));
                        visitado[a-1][b-1] = 1;
                    }
                  
    }
}

bool pula = false;

int main(){

    int T;
    
    scanf("%d", &T);    
    
    int c;
    
    for ( int t = 1; t <= T; t++ ){
    
        if ( pula )
            printf("\n");
    
        memset(campo, 0, sizeof campo);
        
        
        scanf("%d %d %d", &n, &m, &p);
        
        scanf("%d", &c);
        
        for ( int i = 1; i <= n; i++ )
            for ( int j = 1; j <= m; j++ )
                campo[i][j] = 1;
        
        int i,j;
        
        char comando;
        
        int valor;
        
        for ( int x = 0; x < c; x++ ){
        
            scanf(" %c %d %d %d", &comando, &i, &j, &valor);
            
            if ( comando == 'V' )
                vertical(i,j,valor,campo[i][j]);
            else if ( comando == 'H' )
                horizontal(i,j,valor,campo[i][j]);
            else if ( comando == 'D' )
                diagonal(i,j, valor, campo[i][j]);
                
            memset(visitado,0, sizeof visitado);
        }
        
        printf("Mosaico %d:\n", t);
        
        for ( int x = 1; x <= n; x++ ){
            for ( int y = 1; y <= m; y++ ){
                printf("%3.d", campo[x][y]);
            }
            printf("\n");
        }
        
        pula = true;
    
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define MAX 100005

int visitado[MAX];

vector<int> grupos;

vector<vector<int>> v;

int bfs( int n){

    queue <int> q;
    queue <int> aux;
    
    int conectados = 1;
    
    q.push(n);
    
    int atual;
    
    while( !q.empty() ){
    
        atual = q.front();
        q.pop();
        
        visitado[atual] = 1;
        
        for ( int i = 0; i < v[atual].size(); i++ ){
        
            if ( !visitado[ v[atual][i] ] ){
                q.push(v[atual][i]);
                conectados++;
            }
        }
    }
    
    return conectados;

}

int main(){

    int T;
    
    int n,m;
    
    int aux;
    
    int p;
    
    scanf("%d", &T);
    
    for ( int t = 1; t <= T; t++ ){
    
        //vector<int> v[MAX];
        
        memset(visitado, 0, sizeof visitado);
    
        map < int, string > nome;
        map < string , int > id;
    
        scanf("%d %d", &n, &m);
        
        v.push_back({});
        for ( int i = 1; i <= m; i++ )
            v.push_back({});
        
        for ( int i = 0; i < n; i++ ){
        
            scanf("%d", &aux);
            grupos.push_back(aux);
        }

//cout << "w222aht\n";
        scanf("%d", &p);
        
        char aux1, aux2;
        int p1, p2;
       
        
        for ( int i = 1; i <= p; i++ ){
            
            scanf(" %c%d  %c%d", &aux1, &p1, &aux2, &p2);
            
            //printf("%d %d\n", p1,p2);
            
            v[p1].push_back(p2);
            v[p2].push_back(p1);
            
//printf("%c%d %c%d\n", aux1, p1, aux2, p2);
        }
        
        int contador = 0;
        
        vector<int> conectados;
        
        for ( int i = 1; i <= m; i++ ){
        
            if ( !visitado[i] ){
            
               conectados.push_back(bfs(i));
            }
        }
        
        sort(grupos.begin(), grupos.end());
        sort(conectados.begin(), conectados.end());
        
        //for ( int i = 0; i < conectados.size(); i++ )
          //  printf("%d\n", conectados[i] );
        
        for ( int i = 0; i < grupos.size(); i++ ){
        
            for ( int j = 0; j < conectados.size(); j++ ){
            
                if (  grupos[i] <= conectados[j] ){
                
                    conectados[j] = -1;
                    contador++;
                    break;
                } 
            }
        }
        
        printf("Caso #%d: %d grupo(s)\n", t, contador);
     
        conectados.clear();
        grupos.clear();
        v.clear();
        
    }

    return 0;
}

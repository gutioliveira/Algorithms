#include <bits/stdc++.h>

using namespace std;

#define MAX 1005

int visited[MAX];
int dist[MAX];

//int adj[MAX][MAX];

int bfs(vector <int> v[], int p, int c){

    queue <int> q;
    
    q.push(p);
    
    int atual;
    
    //printf("hue\n");
    
    while ( !q.empty() ){
    
        //visitado[atual] = 1;
        
        atual = q.front();
        q.pop();
        
        for ( int i = 0; i < v[atual].size(); i++ ){
        
            //printf("caraca\n");
            
            if ( !visited[ v[atual][i] ] ){
                
                visited[ v[atual][i] ] = 1;
                dist[ v[atual][i] ] = dist[atual] + 1;
            
                if ( v[atual][i] == c )
                    return dist[ v[atual][i] ];
                    
                q.push(v[atual][i]);
            
            }
            
        }
    
    }
    
    return -1;
    
}

int main(){

    int n,m;
    
    int p,c;

    while ( scanf("%d %d", &n, &m) != EOF ){
    
        vector < int > v[MAX];
        
        memset(visited,0, sizeof visited);
        memset(dist, 0, sizeof dist);
        
        int a,b, D;
    
        for ( int i = 1; i <= m; i++ ){
        
            scanf("%d %d", &a, &b);
            v[a].push_back(b);
        }
        
        scanf("%d %d", &p, &c);
        
        D = bfs(v, p, c);
        
        if ( D == -1 ){
        
            printf("Nao ha rotas de %d para %d\n", p, c );
        }else if ( D == 1 ){
        
            printf("Existe um voo direto de %d para %d\n", p, c);
        }else{
        
            printf("Rota minima: %d escalas\n", D - 1);
        }
        
    }

    return 0;
}

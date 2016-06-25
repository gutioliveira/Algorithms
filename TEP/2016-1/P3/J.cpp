#include <bits/stdc++.h>
#define MAX 10000
using namespace std;

bool t;

int vertices[MAX];

void dfs(vector <int> v[], int u, int color){

    vertices[u] = color;
    
    if ( not t )
        return;
        
    for ( int i = 0; i < v[u].size(); i++ ){
    
        if ( vertices[ v[u][i] ] == -1 )
            dfs(v, v[u][i], 1 - color );
        else if ( vertices[u] == vertices[v[u][i]] ){
        
            t = false;
            break;
        }
    }
    
}

int main(){

    int n,m;
    int a,b;
    
    int teste = 1;
    
    while ( scanf("%d %d", &n, &m) != EOF ){
    
        vector < int > v[MAX];
        
        memset(vertices, -1, sizeof vertices);
        
        t = true;
    
        for ( int i = 0; i < m; i++ ){
        
            scanf("%d %d", &a, &b);
            
            v[a].push_back(b);
            v[b].push_back(a);
        }
        
        for ( int i = 1; i <= n; i++ ){
        
            if ( vertices[i] == -1 ){
                // printf("kk%d\n", i);
                dfs(v, i, 1);
            }
        }
        
        printf("Mapa %d: %s\n",teste, t ? "nao atende" : "atende" );
        
        teste++;
    
    }
    
    
    return 0;
}

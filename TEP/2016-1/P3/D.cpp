#include <bits/stdc++.h>

#define MAX 1010
#define INF 50000000

using namespace std;

using ii = pair<int,int>;

int dist[MAX];

priority_queue< ii , vector <ii> , greater<ii>> pq;

int dijkstra(int o, int n, vector<int> v[]){
    
    for ( int i = 1; i < MAX; i++ )
        dist[i] = INF;
        
    dist[o] = 0;
    
    pq.push(ii(dist[o], o));
    
    while ( not pq.empty() ){
    
        auto p = pq.top();
        pq.pop();
        
        int d = p.first;
        int x = p.second;
        
        if ( d > dist[x] )
            continue;
            
        for ( int i = 0; i < v[x].size(); i++ ){
        
            if ( dist[ x ] + 1 < dist[ v[x][i] ] ){

                dist[ v[x][i] ] = dist[x] + 1;
                pq.push(ii(dist[ v[x][i] ], v[x][i]));
            }
        }
    }
    
    
    return dist[n];
}

int main(){

    int n,m,t;
    
    char nome[50];
    char nome2[50];
    
    map <string, int> id;
    
    while( scanf("%d", &n) , n ){
    
        vector <int> v[MAX];
        
        int mini = INF;
    
        for ( int i = 1; i <= n; i++ ){
        
            scanf("%s", nome);
            
            id[nome] = i;
        }
        
        
        scanf("%d", &m);
        
        for ( int i = 1; i <= m; i++ ){
        
            scanf("%s %s", nome, nome2);
            
            v[id[nome]].push_back(id[nome2]);
            v[id[nome2]].push_back(id[nome]);
        }
        
        scanf("%d", &t);
        
        for ( int i = 1; i <= t; i++ ){
        
            scanf("%s", nome);
            
            mini = min(mini, dijkstra(1, id[nome], v) -1 );
        }
        
        if ( mini == INF -1 )
            printf("-1\n");
        else
            printf("%d\n", mini);
    }
    
    
    return 0;
}

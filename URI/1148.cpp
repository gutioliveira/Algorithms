#include <bits/stdc++.h>
#define MAX 1010
#define INF 2147483647
using namespace std;
using ii = pair < int, int >;
using iii = pair < int , ii >;
int grid[MAX][MAX];
int peso[MAX][MAX];
int edges[MAX];
int dist[MAX];
// distance, coordenates
priority_queue < ii, vector<ii> , greater<ii> > pq;

int dijkstra(int n, int N){
	for ( int i = 0; i < MAX; i++ )
		dist[i] = INF;
	dist[n] = 0;
	pq.push(ii(dist[n], n));
	while( not pq.empty() ){
		auto p = pq.top();
		pq.pop();
		int d = p.first;
		int x = p.second;
		if ( d > dist[x] )
			continue;
		for ( int i = 0; i < edges[x]; i++ ){
			if ( dist[ x ] + peso[x][i] < dist[ grid[x][i] ] ){
				dist[ grid[x][i] ] = dist[ x ] + peso[x][i];
				pq.push(ii(dist[ grid[x][i] ], grid[x][i]));
			}
		}
	}
	return dist[N];
}
int main(){
	int N, E;
	while ( scanf("%d %d", &N, &E) , N | E ){
		int x,y,h;
		int o,d;
		int k;
		set < int > s[MAX];
		memset(edges, 0, sizeof edges);
		memset(peso, 0, sizeof peso);
		for ( int i = 0; i < E; i++ ){
			scanf("%d %d %d", &x, &y, &h);
			grid[x][edges[x]++] = y;
			peso[x][edges[x]-1] = h;
		}
			for ( int i = 1; i <= N; i++ )
				for ( int j = 0; j < edges[i]; j++ )
					for ( int k = 0; k < edges[grid[i][j]]; k++ )
						if ( grid[ grid[i][j] ][k] == i ){

							peso[grid[i][j]][ k ] = 0;
						}

		scanf("%d", &k);
		for ( int i = 0; i < k; i++ ){
			scanf("%d %d", &o, &d);
			if ( dijkstra(o,d) == INF )
				printf("Nao e possivel entregar a carta\n");
			else
				printf("%d\n", dist[d]);
		}
		printf("\n");
	}
	return 0;
}

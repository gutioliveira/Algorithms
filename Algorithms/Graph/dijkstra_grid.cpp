#include <bits/stdc++.h>

#define MAX 1010

#define INF 2147483647

using namespace std;

using ii = pair < int, int >;

using iii = pair < int , ii >;

int grid[MAX][MAX];
int weight[MAX][MAX];
int edges[MAX];
int dist[MAX];

// distance, coordenates
priority_queue < ii, vector<ii> , greater<ii> > pq;

int dijkstra(int n, int N){ // n to N

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

			if ( dist[ x ] + weight[x][i] < dist[ grid[x][i] ] ){

				dist[ grid[x][i] ] = dist[ x ] + weight[x][i];
				pq.push(ii(dist[ grid[x][i] ], grid[x][i]));
			}
		}
	}

	return dist[N];

}

int main(){

	int N, E;

	while ( scanf("%d %d", &N, &E) , N | E ){

		int x,y,h; // x -> y, h is the weight

		memset(edges, 0, sizeof edges);
		memset(weight, 0, sizeof weight);

		for ( int i = 0; i < E; i++ ){

			scanf("%d %d %d", &x, &y, &h);

			grid[x][edges[x]++] = y;
			weight[x][edges[x]-1] = h;
		}

	}
	
	return 0;
}
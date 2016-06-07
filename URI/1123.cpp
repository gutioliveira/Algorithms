#include <bits/stdc++.h>

#define MAX 300

#define INF 100000

using namespace std;

int pesos[MAX][MAX];

using ii = pair < int, int >;

using iii = pair < int , ii >;

int dist[MAX];

// distance, coordenates
// priority_queue < ii, vector<ii> , greater<ii> > pq;

priority_queue <ii> pq;

int dijkstra(int n, int N, vector <int> v[], int c){

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

		if ( x < c ){
// printf("cara\n");
			for ( int i = x; i < c; i++ ){
// printf("dist %d peso %d %d\n", dist[i], pesos[i][i+1], dist[ i+ 1]);
				if ( dist[i] + pesos[i][i+1] < dist [ i+1 ] ){
// printf("hue\n");
					dist[ i + 1 ] = dist[i] + pesos[i][i+1];
					pq.push(ii(dist[i+1],i+1));
				}
			}
		}else{

			for ( int i = 0; i < v[x].size(); i++ ){

				if ( dist[x] + pesos[x][ v[x][i] ] < dist[ v[x][i] ] ){

					dist[ v[x][i] ] = dist[ x ] + pesos[x][ v[x][i] ];
					pq.push(ii(dist[ v[x][i] ], v[x][i]));
				}
			}
		}
	}

	return dist[N];
}

int main(){

	int n,m,c,k; // c cidades da rota, k lugar onde foi concertado.
	int u,v,p;

	while ( scanf("%d %d %d %d", &n, &m, &c, &k) , (n+m+c+k) ){

		vector < int > rotas[MAX];

		priority_queue <int> distances;

		for ( int i = 0; i < m; i++ ){

			scanf("%d %d %d", &u, &v, &p);

			pesos[u][v] = p;
			pesos[v][u] = p;
			rotas[u].push_back(v);
			rotas[v].push_back(u);
		}

		printf("%d\n", dijkstra(k,c-1,rotas,c));





	}
	
	return 0;
}
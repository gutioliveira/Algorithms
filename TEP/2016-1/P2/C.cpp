#include <bits/stdc++.h>
#define INF 100000000
#define MAX 10005

using namespace std;

using ii = pair < int , int >;

using transporte = pair < int, ii >;

priority_queue <ii> pq;

int matrix[MAX];
int visited[MAX];

int dist[MAX];

bool sim;

int dijkstra(int n, int N, vector<int> v[]){

	for ( int i = 0; i < MAX; i++ )
		dist[i] = INF;

	dist[n] = 0;

	pq.push(ii(0,n));

	while( !pq.empty() ){

		auto p = pq.top();
		pq.pop();

		int custo = p.first;
		int destino = p.second;

		if ( custo > dist[destino] )
			continue;

		for ( int i = 0; i < v[destino].size(); i++ ){

			if ( dist[destino] + 1 < dist[ v[destino][i] ] ){

				dist[ v[destino][i] ] = dist[destino] + 1;
				pq.push(ii(dist[ v[destino][i] ], v[destino][i]));
			}
		}
	}

	return dist[N];
}

int main(){

	int N;

	int s,d;

	int c;

	int n, aux;

	int teste = 1;

	int max_c;

	while( scanf("%d", &N) != EOF ){

		vector < int > v[MAX];

		scanf("%d %d", &s, &d);

		for ( int i = 1; i <= N; i++ ){

			scanf("%d %d", &c, &n);

			for ( int j = 0; j < n; j++ ){

				scanf("%d", &aux);

				v[c].push_back(aux);
			}
		}

		scanf("%d", &max_c);

		printf("Caso #%d: ", teste);

		dijkstra(s,d,v);

		if ( dist[d] == INF )
			printf("arquivada\n");
		else if ( dist[d] + 1 <= max_c )
			printf("aceita com %d carimbos\n", dist[d]+1);
		else
			printf("devolvida\n");

		teste++;
	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define INF 2147483647

using namespace std;

using ii = pair < int, int >;

using iii = pair < int , ii >;

int dist[24];

// distance, coordenates
priority_queue < ii, vector<ii> , greater<ii> > pq;

int dijkstra(int n, int N, vector <int> v[]){

	for ( int i = 0; i < 24; i++ )
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

		for ( int i = 0; i < v[x].size(); i++ ){

			if ( dist[x] + 1 < dist[ v[x][i] ] ){

				dist[ v[x][i] ] = dist[ x ] + 1;
				pq.push(ii(dist[ v[x][i] ], v[x][i]));
			}
		}
	}

	return dist[N];

}

int main(){

	int teste = 1;

	while ( 1 ){

		vector < int > v[24];

		int n;

		int N;

		int a,b;

		for ( int i = 1; i <= 19; i++ ){

			if ( scanf("%d", &n) == EOF )
				goto out;

			for ( int j = 0; j < n; j++ ){
				scanf("%d", &a);

				v[i].push_back(a);
				v[a].push_back(i);
			}
		}

		printf("Test Set #%d\n", teste);

		scanf("%d",&N);

		for ( int i = 1; i <= N; i++ ){

			scanf("%d %d", &a, &b);

			printf("%2.d to %2.d: %1.d\n", a, b, dijkstra(a,b,v) );
		}

		printf("\n");

		teste++;

	}

	out:;

	return 0;
}
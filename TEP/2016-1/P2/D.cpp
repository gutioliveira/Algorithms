#include <bits/stdc++.h>
#define INF 92233720368547758
#define MAX 1005

using namespace std;

using ii = pair < int , string >;

using transporte = pair < int, ii >;

priority_queue <transporte, vector<transporte>, greater<transporte> > pq;

int matrix[MAX];
int visited[MAX];

long long int dist[MAX];

bool sim;

long long int dijkstra(int n, int N, vector<transporte> v[] ,set<string> pode){

	for ( int i = 0; i < MAX; i++ )
		dist[i] = INF;

	dist[n] = 0;

	pq.push(transporte(dist[n], ii(n,"")));

	while( !pq.empty() ){

		auto p = pq.top();
		pq.pop();

		int custo = p.first;
		int destino = p.second.first;
		string tran = p.second.second;

		if ( custo > dist[destino] )
			continue;

		for ( int i = 0; i < v[destino].size(); i++ ){

			if ( pode.count(v[destino][i].second.second) >= 1 ){

				if ( dist[destino] + v[destino][i].first < dist[ v[destino][i].second.first ] ){

					dist[ v[destino][i].second.first ] = dist[destino] + v[destino][i].first;
					pq.push(transporte(dist[ v[destino][i].second.first ], ii(v[destino][i].second.first, v[destino][i].second.second)));
				}
			}
		}
	}

	return dist[N];
}

int main(){

	int n,m;

	int a,b,c;

	string t;

	int q;

	scanf("%d %d", &n, &m);

	vector < transporte > v[MAX];

	for ( int i = 0; i < m; i++ ){

		scanf("%d %d %d", &a, &b, &c);

		cin >> t;

		v[a].push_back(transporte(c, ii(b, t)));
		v[b].push_back(transporte(c, ii(a, t)));
	}

	scanf("%d", &q);

	for ( int i = 1; i <= q; i++ ){

		set < string > pode;

		scanf("%d %d %d", &a, &b, &c);

		while(c--){

			cin >> t;

			pode.insert(t);
		}

		long long int resultado = dijkstra(a,b,v,pode);

		if ( resultado == INF )
			resultado = -1;

		printf("Solicitacao #%d: %lld\n", i, resultado);
	}	

	return 0;
}
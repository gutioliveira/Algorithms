#include <bits/stdc++.h>

#define MAX 1010
#define INF 10*10*10*10*10

using namespace std;

using ii = pair<int,int>;
using edge = pair<double, ii>;
using vi = vector<int>;

vector<ii> already;

int nois = 0;

class UFDS{

	int m_count;
	vi m_parents, m_rank;

public:

	UFDS(int V) : m_count(V), m_parents(V + 1, 0), m_rank(V + 1, 0){

		for ( int i = 1; i <= V; ++i )
			m_parents[i] = i;
		for ( int i = 0; i < already.size(); i++ )
			union_set(already[i].first, already[i].second);

	}

		int find_set(int u){
			return m_parents[u] == u ? u : (m_parents[u] = find_set(m_parents[u]));
		}

		bool same_set(int u, int v){ return find_set(u) == find_set(v); }

		void union_set( int u, int v ){

			if ( same_set(u,v) )
				return;
			int p = find_set(u);
			int q = find_set(v);

			if ( m_rank[p] >= m_rank[q] )
				m_parents[q] = p;
			else
				m_parents[p] = q;

			if ( m_rank[p] == m_rank[q] ) ++m_rank[p];
				--m_count;
		}

		int count() const { return m_count; }
	
};

priority_queue<edge> pq2;

int dist[MAX];
int aux[MAX];
int pesos[MAX][MAX];

priority_queue < ii, vector<ii> , greater<ii> > pq;

int bfs(int n, int m, vector<int> novas[]){

	if ( n == m )
		return 0;

	int visitado[MAX];
	int parents[MAX];
	queue <int> q;
	memset(visitado, 0, sizeof visitado);

	q.push(n);

	while ( !q.empty() ){

		int topo = q.front();
		q.pop();

		visitado[topo] = 1;

		for ( int i = 0; i < novas[topo].size(); i++ ){

			if ( !visitado[ novas[topo][i] ] ){

				parents[ novas[topo][i] ] = topo;
				q.push(novas[topo][i]);
			}
		}
	}

	int aux = m;
	int minimo = -INF;

	while ( aux != n ){

		// printf("%d %d -> %d\n", aux, parents[aux], pesos[aux][parents[aux]]);
		minimo = max(minimo, pesos[aux][parents[aux]]);
		aux = parents[aux];
	}

	return minimo;

}

int dijkstra(int n, int N, vector <int> v[]){

	memset(aux, -1, sizeof aux);

	for ( int i = 0; i < MAX; i++ )
		dist[i] = INF;

	aux[n] = n;

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

			if ( dist[x] + pesos[x][ v[x][i] ] < dist[ v[x][i] ] ){

				aux[ v[x][i] ] = x; // guarda o anterior

				dist[ v[x][i] ] = dist[ x ] + pesos[x][ v[x][i] ];
				pq.push(ii(dist[ v[x][i] ], v[x][i]));
			}
		}
	}

	return dist[N];
}

int kruskall(int V, vector <int> novas[]){

	UFDS ufds(V);

	int d = 0;

	while ( not pq2.empty() ){

		auto e = pq2.top();
		pq2.pop();

		int w = e.first;
		int u = e.second.first;
		int v = e.second.second;

		if ( not ufds.same_set(u,v) ){
			nois++;
			ufds.union_set(u,v);
			novas[u].push_back(v);
			novas[v].push_back(u);

			// printf("rotas %d -> %d\n", u, v);
			d += w;
		}
	}

	return d;
}

int main(){

	int n, m, k;
	int a,b;
	int I, J, H;

	int teste = 1;

	while ( scanf("%d %d", &n, &m), (n+m) ){

		vector < int > rotas[MAX];

		vector < int > novas[MAX];

		for ( int i = 0; i < m; i++ ){
			scanf("%d %d %d", &I, &J, &H);

// printf("%d %d %d\n", I,J,H);

			rotas[I].push_back(J);
			rotas[J].push_back(I);
			pesos[I][J] = H;
			pesos[J][I] = H;

			pq2.push(edge(-H, ii(I,J)));
		}

		scanf("%d", &k);

		kruskall(n, novas);

		printf("Instancia %d\n", teste);

		teste++;

		for ( int i = 0; i < k; i++ ){

			vector < int > resultados;

			scanf("%d %d", &a, &b);

			// dijkstra(a,b,novas);

			// int x = b;

			// while ( x != a ){

			// 	// printf("%d %d\n", x, aux[x]);

			// 	if ( aux[x] == -1 )
			// 		break;

			// 	resultados.push_back(pesos[x][aux[x]]);
			// 	x = aux[x];
			// }

			// sort(resultados.begin(), resultados.end(), greater<int>());


			printf("%d\n", bfs(a,b,novas) );
			// for ( auto y : resultados )
			// printf("%d\n", y);
		}

		printf("\n");


	}
	
	return 0;
}
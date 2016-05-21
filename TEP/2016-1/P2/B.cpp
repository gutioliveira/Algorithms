#include <bits/stdc++.h>

#define MAX 500005

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

priority_queue<edge> pq;

double kruskall(int V){

	UFDS ufds(V);

	double d = 0;

	while ( not pq.empty() ){

		auto e = pq.top();
		pq.pop();

		double w = e.first;
		int u = e.second.first;
		int v = e.second.second;

		if ( not ufds.same_set(u,v) ){
			nois++;
			ufds.union_set(u,v);
			d += w;
		}
	}

	return d;
}


int main(){

	int T, n;

	scanf("%d", &T);

	int a,b,c;

	int I;

	double l;

	for ( int t = 1; t <= T; t++ ){

		// vector < edge > concessoes[MAX];

		edge concessoes[MAX];

		nois = 0;

		scanf("%d", &n);

		for ( int i = 1; i <= n*(n-1)/2; i++ ){

			scanf("%d %d %d %lf", &I, &a, &b, &l);

			concessoes[I] = edge(l, ii(a,b));

			pq.push(edge(l, ii(a,b)));

			// concessoes[I].push_back(edge(l, ii(a,b)));
		}

		scanf("%d", &c);

		int aux;

		double calculo = 0;

		for ( int i = 0; i < c; i++ ){

			scanf("%d", &aux);

			already.push_back(ii(concessoes[aux].second.first, concessoes[aux].second.second));

			calculo += concessoes[aux].first;
		}

		calculo = calculo + kruskall(n);

		printf("Caso #%d: %d -> R$ %.2lf\n", t, nois, calculo);

		already.clear();
	}
	
	return 0;
}
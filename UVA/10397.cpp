#include <bits/stdc++.h>

#define MAX 10005

using namespace std;
using ii = pair<int, int>;
using edge = pair<double, ii>;
using vi = vector<int>;

vector<ii> already;

class UFDS {
    int m_count;
    vi m_parents, m_rank;
    
public:
    UFDS(int V) : m_count(V), m_parents(V + 1, 0), m_rank(V + 1, 0) {
        for (int i = 1; i <= V; ++i)
            m_parents[i] = i;

        for (int i = 0; i < already.size();i++)
        	union_set(already[i].first, already[i].second);
    }

    int find_set(int u) { return m_parents[u] == u ? u : (m_parents[u] = find_set(m_parents[u])); }

    bool same_set(int u, int v) { return find_set(u) == find_set(v); }

    void union_set(int u, int v) {
        if (same_set(u, v))
            return;

        int p = find_set(u);
        int q = find_set(v);

        if (m_rank[p] >= m_rank[q])
            m_parents[q] = p;
        else
            m_parents[p] = q;

        if (m_rank[p] == m_rank[q]) ++m_rank[p];
        --m_count;
    }

    int count() const { return m_count; }
};

priority_queue<edge> pq;

double kruskall(int V)
{
    UFDS ufds(V);
    double D = 0;
    
    while (not pq.empty())
    {
        auto e = pq.top();
        pq.pop();
        
        double w = -e.first;
        int u = e.second.first;
        int v = e.second.second;

        if (not ufds.same_set(u, v))
        {
            ufds.union_set(u, v);
            D += w;
        }
    }

    return D;
}

int main(){

	int N,M;

	int x, y;

	int a, b;

	while ( scanf("%d", &N) != EOF ){

		vector < ii > pares;

		double distance = 0;

		pares.push_back(ii(0,0));

		for ( int i = 0; i < N; i++ ){
			scanf("%d %d", &x, &y);

			pares.push_back(ii(x,y));
		}

		scanf("%d", &M);

		for ( int i = 0; i < M; i++ ){

			scanf("%d %d", &a, &b);

			already.push_back(ii(a,b));

			double dA = sqrt( (pares[a].first - pares[b].first)*(pares[a].first - pares[b].first) );
			double dB = sqrt( (pares[a].second - pares[b].second)*(pares[a].second - pares[b].second) );
		}

		for ( int i = 1; i < pares.size(); i++ )
			for ( int j = i + 1; j < pares.size(); j++ ){

				double dA = sqrt( (pares[i].first - pares[j].first)*(pares[i].first - pares[j].first) );
				double dB = sqrt( (pares[i].second - pares[j].second)*(pares[i].second - pares[j].second) );

				pq.push(edge(-hypot(dA, dB), ii(i, j)));
			}

		distance = kruskall(N);

		printf("%.2lf\n", distance);

		already.clear();
	}

	return 0;
}
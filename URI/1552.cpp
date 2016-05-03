#include <bits/stdc++.h>

using namespace std;

using ii = pair < int, int >;
using edge = pair < double , ii > ;
using vi = vector < int >;

priority_queue <edge> pq;

class UFDS {
    int m_count;
    vi m_parents, m_rank;
    
public:
    UFDS(int V) : m_count(V), m_parents(V + 1, 0), m_rank(V + 1, 0) {
        for (int i = 1; i <= V; ++i)
            m_parents[i] = i;
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

double kruskall(int V)
{
    UFDS ufds(V);
    double D = 0.0;
    
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

	int c;

	int n;

	scanf("%d", &c);

	int a,b;

	while(c--){

		vector < vector < double > > v;

		vector < pair<int,int> > aux;

		scanf("%d", &n);

		for ( int i = 0; i < n; i++ ){

			scanf("%d %d", &a, &b);

			v.push_back({});
			aux.push_back(make_pair(a,b));
		}

		for ( int i = 0; i < n; i++ )
			for ( int j = i+1; j < n; j++ ){

				// if ( i != j )
					pq.push(edge(- hypot((double)aux[i].first - aux[j].first , (double)aux[i].second - aux[j].second),ii(i,j)));
			}


		printf("%.2lf\n", kruskall(n*n)/100);

	}
	

	return 0;
}
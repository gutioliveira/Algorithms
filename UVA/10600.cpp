#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;
using edge = pair<int, ii>;
using vi = vector<int>;

priority_queue <edge> pq;
set <edge> seta;
priority_queue <edge> pq2;

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

int kruskall_vector(int V, vector < edge > vetor){

    UFDS ufds(V);
    int D = 0;
    
    // while (not pq.empty())
    // {
    
    for ( int i = 0; i < vetor.size(); i++ ){
        
        int w = -vetor[i].first;
        int u = vetor[i].second.first;
        int v = vetor[i].second.second;

        if (not ufds.same_set(u, v))
        {
            ufds.union_set(u, v);
            D += w;
        }
    }
    // }

    // printf("---\n");

    return D;
}

int kruskall(int V)
{
    UFDS ufds(V);
    int D = 0;
    
    while (not pq.empty())
    {
        auto e = pq.top();
        pq.pop();
        int w = -e.first;
        int u = e.second.first;
        int v = e.second.second;

        if (not ufds.same_set(u, v))
        {
            seta.insert(edge(-w, ii(u,v)));

            // printf("seta %d %d %d\n", -w, u, v);
            // pq2.push(edge(-w, ii(u,v)));
            ufds.union_set(u, v);
            D += w;
        }
    }

    // printf("---\n");

    return D;
}

// priority_queue <edge> pq2;



int main(){

	int T;

	int N,M;

	scanf("%d", &T);

	int a,b,c;

	while(T--){

        vector < edge > v;

        vector < int > resultados;

		scanf("%d %d", &N, &M);

		for ( int i = 0; i < M; i++ ){

			scanf("%d %d %d", &a, &b, &c);

			pq.push(edge(-c, ii(a,b)));
            v.push_back(edge(-c, ii(a,b)));
		}

        // edge aux = edge(-2, ii(0,0));

        // edge aux2 = edge(-2, ii(0,0));

        // if ( aux == aux2 )
        //     printf("enois\n");

        sort(v.begin(), v.end(), greater<edge>());

        int resultado = kruskall(N);

        for ( int i = 0; i < v.size(); i++ ){

            vector < edge > aux = v;

            // printf("hue\n");

            // printf("%d-%d-%d\n", v[i].first, v[i].second.first, v[i].second.second);

            if ( seta.count( v[i] ) >= 1 ){

                // printf("waath\n");

                aux[i].first = -800000000;

                sort(aux.begin(), aux.end(), greater<edge>());

                resultados.push_back(kruskall_vector(N, aux));
            }
        }

        // printf("hue2\n");

        sort(resultados.begin(), resultados.end());

		printf("%d %d\n", resultado, resultados[0]);

        seta.clear();
	}

	return 0;
}

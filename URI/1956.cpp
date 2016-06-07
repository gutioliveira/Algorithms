#include <bits/stdc++.h>

#define MAX 10*10*10*10 + 5

using namespace std;
using ii = pair<int, int>;
using edge = pair<int, ii>;
using vi = vector<int>;

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

priority_queue<edge> pq;

int visited[MAX];

long long kruskall(int V)
{
    UFDS ufds(V);
    long long D = 0;
    
    while (not pq.empty())
    {
        auto e = pq.top();
        pq.pop();
        
        int w = -e.first;
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

void dfs(int x, vector <int> v[]){

    visited[x] = 1;

    for ( int i = 0; i < v[x].size(); i++ )
        if ( !visited[ v[x][i] ] )
            dfs(v[x][i],v);
}

int main(){

	int n;

    scanf("%d", &n);

    vector < int > v[MAX];

    int par;

    int a,b;

    int familias = 0;

    memset(visited, 0, sizeof visited);

    for ( int i = 1; i < n; i++ ){

        scanf("%d", &par);

        for ( int j = 0; j < par; j++ ){

            scanf("%d %d", &a, &b);

            v[i].push_back(a);
            v[a].push_back(i);

            pq.push(edge(-b, ii(i,a)));
        }
    }

    for ( int i = 1; i <= n; i++ )
        if ( !visited[i] ){
            familias++;
            dfs(i, v);
        }

    printf("%d %lld\n", familias,  kruskall(n));
    
	return 0;
}
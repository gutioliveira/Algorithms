#include <iostream>
#include <queue>
#include <vector>

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
            ufds.union_set(u, v);
            D += w;
        }
    }

    return D;
}

int main()
{
    int m, n;

    while (scanf("%d %d", &m, &n), m | n)
    {
        int total = 0;

        while (n--)
        {
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);

            total += z;
            pq.push(edge(-z, ii(x, y)));
        }

        int D = kruskall(m);

        printf("%d\n", total - D);
    }

    return 0;
}
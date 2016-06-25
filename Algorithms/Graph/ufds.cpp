#include <bits/stdc++.h>

using namespace std;

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

int main(){
	
	return 0;
}
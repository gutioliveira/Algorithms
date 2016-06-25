#include <bits/stdc++.h>

#define MAX 300

using namespace std;
using ii = pair<int, int>;
using edge = pair<int, ii>;

int n, m, v, h, max_edge;
vector<ii> graph[MAX];
unsigned dist_table[MAX][MAX];

class union_find {
	int size;
	vector<int> parents, rank;

public:
	union_find(int v) : size(v), parents(v + 1, 0), rank(v + 1, 0) {
		for(int i = 1; i <= v; ++i) {
			parents[i] = i;
		}
	}

	int find_set(int u) {
		return u == parents[u] ? u : (parents[u] = find_set(parents[u]));
	}

	bool same_set(int u, int v) {
		return find_set(u) == find_set(v);
	}

	void union_set(int u, int v) {
		if(same_set(u, v))
			return;

		int p = find_set(u);
		int q = find_set(v);

		if(rank[p] >= rank[q])
			parents[q] = p;
		else
			parents[p] = q;

		if(rank[p] == rank[q])
			rank[p]++;

		--size;
	}

	int get_size() {
		return size;
	}
};

priority_queue<edge, vector<edge>, greater<edge>> pq;
void kruskall(int n) {
	union_find ufds(n);

	int dist = 0;
	while(not pq.empty()) {
		auto e = pq.top();
		int w = e.first, u = e.second.first, v = e.second.second;
		pq.pop();
		if(not ufds.same_set(u, v)) {
			ufds.union_set(u, v);
			graph[u].push_back(ii(w, v));
			graph[v].push_back(ii(w, u));
			dist_table[u][v] = dist_table[v][u] = w;
		}
	}
}

void dijkstra(int source, int destiny) {
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	unsigned dist[MAX], parents[MAX];
	for(int u = 1; u <= n; ++u) { dist[u] = -1; parents[u] = 0; }
	dist[source] = max_edge = 0;
	pq.push(ii(dist[source], source));
	while(not pq.empty()) {
		auto current = pq.top();
		pq.pop();

		int u = current.second, current_dist = current.first;
		
		if(current_dist > dist[u]) continue;

		for(auto& e : graph[u]) {
			int v = e.second, w = e.first;
			if(dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				pq.push(ii(dist[v], v));
				parents[v] = u;
			}
		}
	}

	int aux = destiny;
	while(parents[aux]) {
		max_edge = max(max_edge, (int) dist_table[parents[aux]][aux]);
		aux = parents[aux];
	}
}

int main(void) {
	while(scanf("%d %d", &n, &m) != EOF) {
		memset(dist_table, -1, sizeof dist_table);
		for(int i = 0; i < m; ++i) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			pq.push(edge(w, ii(u, v)));
		}

		kruskall(n);
		scanf("%d %d", &v, &h);
		for(int tc = 1; tc <= v; ++tc) {
			int source, destiny;
			scanf("%d %d", &source, &destiny);

			if(tc > 1)
				printf("\n");

			dijkstra(source, destiny);
			printf("Viagem %d: %d\nCarlos: %s!\n", tc, max_edge, max_edge <= h ? "Vou" : "Nao Vou");
		}

		for(int u = 1; u <= n; ++u)
			graph[u].clear();
	}

	return 0;
}

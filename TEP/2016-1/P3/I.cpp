#include <bits/stdc++.h>

#define MAX 300

using namespace std;
using ii = pair<int, int>;
using edge = pair<int, ii>;

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

int kruskall(int n, priority_queue<edge, vector<edge>, greater<edge>>& pq) {
	union_find ufds(n);

	int dist = 0;
	while(not pq.empty()) {
		auto e = pq.top();
		int w = e.first, u = e.second.first, v = e.second.second;
		pq.pop();
		if(not ufds.same_set(u, v)) {
			ufds.union_set(u, v);
			dist += w;
		}
	}

	return dist;
}

int main(void) {
	int n, tc = 0;
	while(scanf("%d", &n), n) {
		int m = n * (n - 1) / 2;
		priority_queue<edge, vector<edge>, greater<edge>> cost_pq, time_pq;
		for(int i = 0; i < m; ++i) {
			int u, v, p, c = 0, t = 0;
			scanf("%d %d %d", &u, &v, &p);
			if(p < 100) {
				scanf("%d %d", &c, &t);
			}

			cost_pq.push(edge(c, ii(u, v)));
			time_pq.push(edge(t, ii(u, v)));
		}

		int min_cost = kruskall(n, cost_pq);
		int min_time = kruskall(n, time_pq);

		if(tc) printf("\n");

		printf("Caso %d:", ++tc);
		if(min_cost && min_time) {
			printf("\n%d reais\n%d dia(s)\n", min_cost, min_time);
		} else {
			printf(" imediata\n");
		}
	}

	return 0;
}

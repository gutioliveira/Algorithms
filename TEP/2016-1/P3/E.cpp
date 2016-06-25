#include <bits/stdc++.h>
using namespace std;

#define MAX 301
vector<int> adj[MAX];
bool visited[MAX];

int cobertura(int root, int N) {
	for(int i=0; i<N; i++)
		visited[i] = false;
			
	int count = -1;
	queue<int> q;
	q.push(root);
	while(not q.empty()) {
		int next = q.front();
		q.pop();
		
		if(visited[next]) continue;
		visited[next] = true;
		count++;
		
		for(auto i : adj[next])
			if(not visited[i])
				q.push(i);
	}
	
	return count;
}

int main() {
	int N, E;
	cin >> N >> E;
	for(int i=0; i<E; i++) {
		int a, b;
		cin >> a >> b;
		adj[a-1].push_back(b-1);
	}

	int total=0;
		for(int i=0; i<N; i++)
			total += cobertura(i,N);
	int max = N*(N-1);
	
	double ans = 100.0*(double(total))/(double(max));
	printf("%.2lf%%\n",ans);

	return 0;
}


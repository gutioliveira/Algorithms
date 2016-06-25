#include <bits/stdc++.h>
using namespace std;

#define MAX 101
map<string,int> dream_map;
string dream[MAX];
vector<int> adj[MAX];
bool visited[MAX];
int out_degree[MAX];

int main() {
	int T;
	cin >> T;
	for(int t=1; t<=T; t++) {
		int N, M, K;
		cin >> N >> M >> K;
//cout << "NMK: " << N << " " << M << " " << K << endl;

		for(int i=0; i<N; i++) {
			adj[i].clear();
			visited[i] = false;
		}
		dream_map.clear();
		
		getchar();
		for(int i=0; i<N; i++) {
			string aux;
			getline(cin,aux);
			dream[i] = aux;
			dream_map[dream[i]] = i;
			out_degree[i] = 0;
//cout << dream[i] << endl;
		}
		
		for(int i=0; i<M; i++) {
			string a, b;
			getline(cin,a);
			getline(cin,b);
			adj[dream_map[b]].push_back(dream_map[a]);
			out_degree[dream_map[a]]++;
		}
//cout << endl;

		cout << "Cenario " << t << ":" << endl;
		vector<string> out;
		bool impossible = false;
		for(int i=0; i<K; i++) {
			int without_deps=0;
			while(without_deps < N && out_degree[without_deps] != 0)
				without_deps++;
			if(without_deps == N) {
				impossible = true;
				break;
			}
			out_degree[without_deps]--;
			out.push_back(dream[without_deps]);
			for(auto u : adj[without_deps])
				out_degree[u]--;
		}
		if(impossible) cout << "Impossivel\n";
		else {
			int c=1;
			for(auto i : out)
				cout << c++ << ". " << i << endl;
		}
		if(t<T) cout << endl;
	}
	
	return 0;
}


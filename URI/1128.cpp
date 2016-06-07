#include <bits/stdc++.h>

#define MAX 2005

using namespace std;

int visited[MAX];

stack <int> S; // stack containing all of the vertices

void dfsutil(int u, vector <int> v[]){

	visited[u] = 1;

	for ( int i = 0; i < v[u].size(); i++ ){

		int vertice = v[u][i];

		if ( !visited[ vertice ] )
			dfsutil(vertice, v);

	}

	S.push(u);
}

vector<int> l; // stores every strongly connected vertices


// aply the dfsreverse on the reverse graph and add it to 'l'
void dfsreverse(int u, vector<int> v[]){

	visited[u] = 1;

	l.push_back(u);

	for ( int i = 0; i < v[u].size(); i++ ){

		int vertice = v[u][i];

		if ( !visited[ vertice ] )
			dfsreverse(vertice, v);
	}
}



int main(){

	int n,m;

	int c,w,p;

	while( scanf("%d %d", &n, &m) , n | m ){

		vector < int > v[MAX];
		vector < int > v_i[MAX];

		vector < vector < int > > result;

		memset(visited, 0, sizeof visited);
		l.clear();

		for ( int i = 0; i < m; i++ ){
			
			scanf("%d %d %d", &c, &w, &p);

			v[c].push_back(w);
			v_i[w].push_back(c);

			if ( p == 2 ){

				v[w].push_back(c);
				v_i[c].push_back(w);
			}
		}

		for ( int i = 1; i <= n; i++ ){

			if ( !visited[i] ){

				dfsutil(i, v);
			}
		}

		memset(visited, 0, sizeof visited);

		while ( !S.empty() ){

			if ( !visited[S.top()] ){

				l.clear();

				dfsreverse(S.top(), v_i);

				result.push_back(l);

				S.pop();
			}else
				S.pop();
		}

		if ( result.size() == 1 )
			printf("1\n");
		else
			printf("0\n");
	}
	

	return 0;
}
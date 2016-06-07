#include <bits/stdc++.h>

#define MAX 1300

using namespace std;

// vector < vector < int > > v; // graph

int visited[MAX];
int num[MAX];
int low[MAX];
int parents[MAX];
int times = 0;

vector < pair<int,int> > points;

void dfs(int u, vector < int > v[]){

	int children_count = 0;
	visited[u] = 1;
	num[u] = low[u] = times++;

	for ( int i = 0; i < v[u].size(); i++ ){

		if ( !visited[ v[u][i] ] ){

			parents[ v[u][i] ] = u;
			dfs( v[u][i], v );

			low[u] = min(low[u], low[ v[u][i] ]);

			if ( low[ v[u][i] ] > num[u] ){
				points.push_back( make_pair( v[u][i],num[u] ) );
				printf("%d %d p\n", v[u][i], u);
			}

		}else if ( v[u][i] != parents[u] )
			low[u] = min(low[u],num[ v[u][i] ]);
		
	}

}


int main(){
	
	int c,p;

	while ( scanf("%d %d", &c, &p) != EOF ){

		memset(visited, 0, sizeof visited);
		memset(parents, -1, sizeof parents);
		memset(low, -1, sizeof low);
		memset(num, -1, sizeof num);
		
		times = 0;

		vector < int > v[MAX];

		int a,b;

		for ( int i = 0; i < p; i++ ){

			scanf("%d %d", &a, &b);
			v[a].push_back(b);
			v[b].push_back(a);
		}

		dfs(1,v);

		cout << points.size() << endl;

		points.clear();

	}

	// memset(visited, 0, sizeof visited);

	return 0;
}
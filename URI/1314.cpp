#include <bits/stdc++.h>

#define MAX 10005

using namespace std;

vector < pair < int, int > > points;

int visited[MAX];
int num[MAX];
int low[MAX];
int parents[MAX];
int times = 0;

void dfs(int u, vector < int > v[], vector< int > s[]){

	int children_count = 0;
	visited[u] = 1;
	num[u] = low[u] = times++;

	for ( int i = 0; i < v[u].size(); i++ ){

		if ( !visited[ v[u][i] ] ){

			parents[ v[u][i] ] = u;
			dfs( v[u][i], v , s );

			low[u] = min(low[u], low[ v[u][i] ]);

			if ( low[ v[u][i] ] > num[u] ){
				points.push_back( make_pair( v[u][i],num[u] ) );
				// printf("kk %d %d\n", v[u][i],  u);
				s[v[u][i]].push_back(u);
				s[u].push_back(v[u][i]);
			}

		}else if ( v[u][i] != parents[u] )
			low[u] = min(low[u],num[ v[u][i] ]);
		
	}
}

int bfs(int first, int final, vector <int> s[]){

	queue<int> q;

	q.push(first);

	int atual;

	while(!q.empty()){

		atual = q.front();
		q.pop();

		if ( atual == final )
			return 1;

		visited[atual] = 1;

		for ( int i = 0; i < s[atual].size(); i++ ){

			if ( !visited[ s[atual][i] ] ){
				// printf("hue %d\n",  s[atual][i]);
				q.push( s[atual][i] );
			}
		}
	}

	return 0;
}

int main(){

	int r,c,q;

	while ( scanf("%d %d %d", &r, &c, &q) , ( r + c + q) ){

		vector < int > v[MAX];

		vector < int > s[MAX];

		// for ( int i = 0; i <= r; i++ )
		// 	s[i].clear();

		memset(visited,0,sizeof visited);
		memset(parents, -1, sizeof parents);
		memset(low, -1, sizeof low);
		memset(num, -1, sizeof num);
		times = 0;

		int a,b;

		for ( int i = 0; i < c; i++ ){

			scanf("%d %d", &a, &b);

			v[a].push_back(b);
			v[b].push_back(a);
		}

		for ( int i = 1; i <= r; i++ )
			dfs(i,v,s);

		for ( int i = 0; i < q; i++ ){

			memset(visited,0,sizeof visited);

			scanf("%d %d", &a, &b);

			if ( bfs(a,b,s) )
				printf("Y\n");
			else
				printf("N\n");
		}

		printf("-\n");
	}
	

	return 0;
}
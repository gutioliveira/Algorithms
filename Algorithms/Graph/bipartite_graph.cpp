#include <bits/stdc++.h>
#define MAX 105 // number of vertices

using namespace std;

bool bipartite = true;

int vertices[MAX];

// graph must be connected.
void dfs( vector < int > v[], int u, int color ){ // u = initial vertex , color = flag 1 or 0.

	vertices[u] = color;

	if ( not bipartite )
		return;

	for ( int i = 0; i < v[u].size(); i++ ){

		if ( vertices[ v[u][i] ] == -1 ){

			dfs(v, v[u][i], 1 - color); // swap color 1,0
		}else if( vertices[u] == vertices[ v[u][i] ] ){

			bipartite = false;
			break;
		}
	}
}

int main(){

	vector <int> v[MAX]; // representation of the graph

	memset(matrix, -1, sizeof matrix);
	
	return 0;
}
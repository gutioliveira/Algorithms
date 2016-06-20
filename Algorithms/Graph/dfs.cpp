#include <bits/stdc++.h>

#define MAX 100002 // number of vertices

using namespace std;

vector< vector<int> > v; // representation of the graph
bool visited[MAX]; // checks if a vertex has been visited

int dfs(int a){

	for ( int i = 0 ; i < v[a].size() ; i++ ){

		if ( !visited[v[a][i]] ){

			visited[v[a][i]] = 1;

			dfs(v[a][i]);
		}
	}

	return -1;
}

int main(){

	memset( visited , 0 , sizeof visited );

	return 0;
}
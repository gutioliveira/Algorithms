#include <bits/stdc++.h>

#define MAX 100002 // number of vertices

using namespace std;

vector< vector<int> > v; // representation of the graph
bool visited[MAX]; // checks if a vertex has been visited
int dist[MAX]; // distance from the origin to a vertex

int bfs(int origin, int destination){

	queue < int > q;

	q.push(origin);

	while ( !q.empty() ){

		int current = q.front();

		q.pop();

		for ( int i = 0 ; i < v[current].size() ; i++ ){

			if ( !visited[ v[current][i] ] ){

				visited[ v[current][i] ] = true;

				dist[  v[current][i] ] = dist[current] + 1;

				if ( v[current][i] == destination ) // checks if the current vertex is your destination
					return dist[ v[current][i] ];

				q.push( v[current][i] );
			}
		}
	}

	return -1;
}

int main(){

	memset( visited , 0 , sizeof visited );

	memset( dist , 0 , sizeof dist );

	return 0;
}
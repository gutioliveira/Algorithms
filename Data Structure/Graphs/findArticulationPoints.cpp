#include <bits/stdc++.h>
#define MAX 110

using namespace std;

int times = 0;

int visited[MAX];
int parent[MAX];
int num[MAX]; // dfs num
int low[MAX]; // dfs low

vector < int > v[MAX]; // GRAPH

vector < int > points; // all the articulation points

int glo;

void dfs(int vertex){

	visited[vertex] = 1;
	num[vertex] = times;
	low[vertex] = times;
	bool is_articulated_point = false;

// cout << " vertex " << vertex << " times " << times << endl; 

	times++;

	int child_count = 0;

	for ( int i = 0; i < v[vertex].size(); i++ ){

		if ( parent[ v[vertex][i] ] == vertex ){
// cout << " is_parent " << vertex << " = " << parent[vertex] << endl; 
			continue;
		}

		if ( !visited[ v[vertex][i] ] ){

// cout << "parent " << v[vertex][i] << " = " << vertex << endl;

			parent[ v[vertex][i] ] = vertex;
			child_count++;
			dfs(v[vertex][i]);

			if ( num[vertex] <= low[ v[vertex][i] ] ){

				is_articulated_point = true;
			}else{

				low[vertex] = min( low[ v[vertex][i] ], low[vertex] );
			}
		}else{
// printf(" already visited %d\n", v[vertex][i]);
			low[vertex] = min(num[ v[vertex][i] ], low[vertex]);
		}
	}

	if ( parent[vertex] == -1 && child_count >= 2 || parent[vertex] > -1 && is_articulated_point ){

		points.push_back(vertex);
	}
}

int main(){

	/*
		uses the Graph ( vector v )	
		v[i] , stores all the connections with i
	*/
	
	return 0;
}
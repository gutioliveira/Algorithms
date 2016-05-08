#include <bits/stdc++.h>

#define MAX 100

using namespace std;

int visited[MAX];

stack <int> s; // stack containing all of the vertices

void dfsutil(int u, vector <int> v[]){

	visited[u] = 1;

	for ( int i = 0; i < v[u].size(); i++ ){

		int vertice = v[u][i];

		if ( !visited[ vertice ] )
			dfsutil(vertice, v);

	}

	s.push(u);
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

	vector < int > v[MAX]; // graph

	vector < int > v_inverted[MAX]; // inverted graph

	memset(visited,0,sizeof visited);


	// edges
	v[1].push_back(2);
	v_inverted[2].push_back(1);
	v[2].push_back(3);
	v_inverted[3].push_back(2);
	v[3].push_back(1);
	v_inverted[1].push_back(3);
	v[3].push_back(5);
	v_inverted[5].push_back(3);
	v[5].push_back(6);
	v_inverted[6].push_back(5);
	v[6].push_back(4);
	v_inverted[4].push_back(6);
	v[4].push_back(5);
	v_inverted[5].push_back(4);
	v[7].push_back(6);
	v_inverted[6].push_back(7);

	/*
		this graph.
		/ 1 <     / 4 <
		<    \    <    \
		2 -> 3 -> 5 -> 6 <- 7

	*/


	// goes through every vertex
	for ( int i = 1; i <= 7; i++ )
		if ( !visited[i] )
			dfsutil(i,v);

	vector < vector < int > > result;

	memset(visited, 0, sizeof visited);

	// goes through the stack.
	while ( not s.empty() ){

		if ( !visited[ s.top() ] ){

			l.clear();

			dfsreverse(s.top(), v_inverted);

			s.pop();

			result.push_back(l);
		}else{

			s.pop();
		}
	}
	// print each strongly connected component into a line
	for ( int i = 0; i < result.size(); i++ ){

		for ( int j = 0; j < result[i].size(); j++ )
			printf(" %d", result[i][j]);

		printf("\n");
	}
	return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#define MAX 10005
using namespace std;

int visited[MAX];

int dfs(vector<int> v[MAX], int n){

	for ( int i = 0; i < v[n].size(); i++ ){

		if ( !visited[ v[n][i] ]){

			visited[ v[n][i] ] = 1;
			dfs(v, v[n][i]);
		}
	}
}

int main(){

	int n, m;

	cin >> n;

	memset(visited, 0, sizeof visited);

	vector < int > v[MAX];

	for ( int i = 0; i < n; i++ ){

		cin >> m;

		v[i+1].push_back(m);
		v[m].push_back(i+1);
	}

	int number = 0;

	for ( int i = 0; i < n; i++ ){

		if ( !visited[i+1] ){

			number++;
			dfs(v, i+1);
		}
	}
	
	printf("%d\n", number);

	return 0;
}
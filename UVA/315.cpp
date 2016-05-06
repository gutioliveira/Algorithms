#include <bits/stdc++.h>
#define MAX 100

using namespace std;

int times = 0;

int visited[MAX];
int parent[MAX];
int num[MAX];
int low[MAX];

vector < int > v[MAX];

vector < int > points;

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
// printf(" ja visitei %d\n", v[vertex][i]);
			low[vertex] = min(num[ v[vertex][i] ], low[vertex]);
		}

	}

	if ( parent[vertex] == -1 && child_count >= 2 || parent[vertex] > -1 && is_articulated_point ){

		points.push_back(vertex);
	}
}

int main(){

	int n;

	string line;

	while( scanf("%d", &n) , n != 0 ){

		memset(visited,0, sizeof visited);
		memset(parent, -1, sizeof parent);

		while(1){

			int firsts;
		
			cin >> firsts;

			if ( firsts == 0 )
				break;

			cin.ignore();

			getline(cin, line);

			int aux;

			istringstream s(line);

			while ( s >> aux ){

				v[firsts].push_back(aux);
				v[aux].push_back(firsts);
			}

			// dfs(firsts);

		}

		dfs(1);

		cout << points.size() << endl;

		points.clear();

		for ( int i = 0; i < MAX; i++ )
			v[i].clear();




	}
	
	return 0;
}
#include <bits/stdc++.h>

#define MAX 100

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

	bool blank = false;

	vector < int > v[MAX];

	vector < int > v_inverted[MAX];

	int teste = 0;

	while( scanf("%d %d", &n , &m) , n | m ){

		if ( blank )
			printf("\n");

		blank = true;

		map < string , int > ids;
		map < int , string > names;

		vector < int > v[MAX];
		vector < int > v_inverted[MAX];

		int id = 1;

		string f, s;

		memset(visited, 0, sizeof visited);

		// S.clear();

		for ( int i = 1; i <= m; i++ ){

			cin >> f >> s;

			if ( ids[f] == 0 ){
// cout << f << " " << id << endl;
				ids[f] = id;
				names[id] = f;

				id++;
			}

			if ( ids[s] == 0 ){
// cout << s << " " << id << endl;
				ids[s] = id;
				names[id] = s;

				id++;
			}

			v[ ids[f] ].push_back( ids[s] );
			v_inverted[ ids[s] ].push_back( ids[f] ); 
		}

		for ( auto i : ids ){

			if ( i.second == 0 )
				continue;
			if ( !visited[ i.second ] ){

				dfsutil(i.second, v);
			}
		}

		printf("Calling circles for data set %d:\n", ++teste);

		memset(visited, 0, sizeof visited);

		while ( !S.empty() ){

			if ( !visited[ S.top() ] ){

				l.clear();

				dfsreverse(S.top(), v_inverted);

				S.pop();

				for ( int i = 0; i < l.size(); i++ ){

					if ( i )
						printf(", ");
					cout << names[l[i]];
				}

				cout << endl;

			}else
				S.pop();
		}
	}

	return 0;
}
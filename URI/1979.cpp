#include <bits/stdc++.h>
#define MAX 105
using namespace std;

bool sim = true;

int matrix[MAX];

void dfs( vector < int > v[], int u, int color ){

	matrix[u] = color;

	if ( not sim )
		return;

	for ( int i = 0; i < v[u].size(); i++ ){

		if ( matrix[ v[u][i] ] == -1 ){
			dfs(v, v[u][i], 1 - color);
		}else if( matrix[u] == matrix[ v[u][i] ] ){
			sim = false;
			break;
		}
	}
}

int main(){

	int n;

	int aux;
	int aux2;

	while( scanf("%d", &n) , n != 0 ){

		vector <int> v[MAX];

		memset(matrix, -1, sizeof matrix);

		sim = true;

		string line;

		for ( int i = 1; i <= n; i++ ){

			scanf("%d", &aux);

			cin.ignore();

			getline(cin, line);

			istringstream s(line);

			while ( s >> aux2 ){
				v[aux].push_back(aux2);
				v[aux2].push_back(aux);
			}

		}

			dfs(v, 1, 0);

			if ( sim )
				printf("SIM\n");
			else
				printf("NAO\n");
	}

	return 0;
}
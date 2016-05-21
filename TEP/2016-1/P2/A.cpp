#include <bits/stdc++.h>

#define MAX 100005

using namespace std;

using ii = pair<int, int>;

int matrix[MAX];
int visited[MAX];

bool sim;

void dfs(vector <int> v[], int u, int color){

	matrix[u] = color;

	visited[u] = 1;

	for ( int i = 0; i < v[u].size(); i++ ){

		if ( matrix[ v[u][i] ] == -1 ){

			dfs(v, v[u][i], 1 - color);
		}else if ( matrix[u] == matrix[ v[u][i] ] ){

			sim = false;
		}
	}
}

int main(){

	int n,m;

	int a,b;

	int p,s;

	int teste = 1;

	while ( scanf("%d %d", &n, &m), (n+m) ){

		vector < int > v[MAX];

		vector < ii > colors;

		sim = true;

		memset( matrix, -1, sizeof matrix );
		memset( visited, 0, sizeof visited );

		for ( int i = 0; i < m; i++ ){

			scanf("%d %d", &a, &b);

			v[a].push_back(b);
			v[b].push_back(a);
		}

		scanf("%d", &p);

		int aux;

		int p_aux[MAX];
		// int s_aux[MAX];

		memset(p_aux, -1, sizeof p_aux);
		// memset(s_aux, -1, sizeof s_aux);

		for ( int i = 0; i < p; i++ ){

			scanf("%d", &aux);

			matrix[aux] = 1;
			p_aux[aux] = 1;

			colors.push_back(ii(aux, 1));
		}

		scanf("%d", &s);

		for ( int i = 0; i < s; i++ ){

			scanf("%d", &aux);

			matrix[aux] = 0;
			p_aux[aux] = 0;

			colors.push_back(ii(aux, 0));
		}

		printf("Cenario #%d: ", teste);

		teste++;

		// cout << colors.size() << endl;

		for ( int i = 0; i < colors.size(); i++ ){

			if ( !visited[ colors[i].first ] ){

				dfs( v, colors[i].first, colors[i].second );
			}
		}

		for ( int i = 1; i <= n; i++ ){

			if ( !visited[i] and p_aux[i] == -1 ){
					dfs(v, i, 1);
			}
		}

		if ( sim )
			printf("sim\n");
		else
			printf("nao\n");

	}
	
	return 0;
}
#include <bits/stdc++.h>

#define MAX 550
#define INF 1000000000

using namespace std;

int dist[MAX][MAX];
int aux[MAX];
char grid[MAX][MAX];

using ii = pair < int, int >;

using iii = pair < int , ii >;

priority_queue < iii, vector<iii> , greater<iii> > pq;

// priority_queue<iii> pq;

int dijkstra(ii n, ii N){

	for ( int i = 0; i < MAX; i++ )
		for ( int j = 0; j < MAX; j++ )
			dist[i][j] = INF;

	dist[n.first][n.second] = 0;

	pq.push(iii(dist[n.first][n.second], n));

	while( not pq.empty() ){

		auto p = pq.top();
		pq.pop();

		int d = p.first;
		int x = p.second.first;
		int y = p.second.second;

		if ( d > dist[x][y] )
			continue;

		// printf("%d\n",d);

		// cima e baixo
		for ( int i = -1; i <= 1; i += 2 )
			if ( grid[x+i][y] != '#' ){

				int distancia;

				if ( grid[x+i][y] == '.' || grid[x+i][y] == 'E' )
					distancia = 0;
				else{
					distancia = grid[x+i][y] - 48;
				}

				if ( dist[x][y] + distancia < dist[x+i][y] ){

					dist[x+i][y] = dist[x][y] + distancia;
					pq.push(iii(dist[x+i][y], ii(x+i,y)));
				}
			}

		// lado e outro
		for ( int i = -1; i <= 1; i += 2 )
			if ( grid[x][y+i] != '#' ){

				int distancia;

				if ( grid[x][y+i] == '.' || grid[x][y+i] == 'E' )
					distancia = 0;
				else{
					distancia = grid[x][y+i] - 48;

					// printf("%d\n", distancia);
				}

				if ( dist[x][y] + distancia < dist[x][y+i] ){

					dist[x][y+i] = dist[x][y] + distancia;
					pq.push(iii(dist[x][y+i], ii(x,y+i)));
				}
			}
	}

	return dist[N.first][N.second];
}

int main(){

	int n,m;

	ii h,e;

	scanf("%d %d", &n, &m);

	string line;

	memset(grid, '#', sizeof grid);

	for ( int i = 1; i <= n; i++ )
	{

		cin >> line;

		for ( int j = 1; j <= m; j++ ){

			grid[i][j] = line[j-1];

			if ( grid[i][j] == 'H' )
				h = ii(i,j);
			else if ( grid[i][j] == 'E' )
				e = ii(i,j);
		}
	}

	int resultado = dijkstra(h,e);

	if ( resultado == INF )
		printf("ARTSKJID\n");
	else	
		printf("%d\n", resultado);
	
	return 0;
}
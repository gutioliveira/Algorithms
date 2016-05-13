#include <bits/stdc++.h>

#define MAX 1010

#define INF 2147483647

using namespace std;

using ii = pair < int, int >;

using iii = pair < int , ii >;

int grid[MAX][MAX];

int dist[MAX][MAX];

// distance, coordenates
priority_queue < iii, vector<iii> , greater<iii> > pq;

int dijkstra(int N, int M){

	memset(dist, 1, sizeof dist);

	dist[1][1] = 0;

	pq.push(iii(dist[1][1], ii(1,1)));

	while( not pq.empty() ){

		auto p = pq.top();
		pq.pop();

		int d = p.first;
		int x = p.second.first;
		int y = p.second.second;

		if ( d > dist[x][y] )
			continue;

		for ( int i = -1; i <= 1; i += 2 )
			if ( grid[x+i][y] != -1 and dist[x][y] + grid[x+i][y] < dist[x+i][y] ){

				dist[x+i][y] = dist[x][y] + grid[x+i][y];
				pq.push(iii(dist[x+i][y], ii(x+i,y)));
			}

		for ( int i = -1; i <= 1; i += 2 )
			if ( grid[x][y+i] != -1 and dist[x][y] + grid[x][y+i] < dist[x][y+i] ){

				dist[x][y+i] = dist[x][y] + grid[x][y+i];
				pq.push(iii(dist[x][y+i], ii(x,y+i)));
			}

	}

	return dist[N][M];

}

int main(){

	int T;

	scanf("%d", &T);

	int x,y;

	while(T--){

		memset(grid, -1, sizeof grid);

		scanf("%d", &x);
		scanf("%d", &y);

		for ( int i = 1; i <= x; i++ )
			for ( int j = 1; j <= y; j++ )
				scanf("%d", &grid[i][j]);


		printf("%d\n", dijkstra(x,y) + grid[1][1]);

	}
	
	return 0;
}
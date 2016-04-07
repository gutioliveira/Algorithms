#include <bits/stdc++.h>

/*
	Créé par Gustavo Cavalcante, Université de Brasilia.
	exercice nombre 1621 URI.
*/

#define MAX 510

using namespace std;

int max_dist = -1;

char champ[MAX][MAX];
int visite[MAX][MAX];
int distance_[MAX][MAX];

pair < int, int > position;

void bfs(pair <int,int> p){

	memset(visite, 0, sizeof(visite[0][0]) * MAX * MAX);

	memset(distance_, 0, sizeof(distance_[0][0]) * MAX * MAX);

	queue < pair < int, int > > q;

	q.push(p);

	pair <int,int> actual;

	int aux;

	while(!q.empty()){

		actual = q.front();

		q.pop();

		visite[actual.first][actual.second] = 1;

		aux = max_dist;

		max_dist = max(max_dist, distance_[actual.first][actual.second]);

		if ( max_dist > aux )
			position = make_pair(actual.first, actual.second);

		if ( !visite[actual.first-1][actual.second] &&  champ[actual.first-1][actual.second] == '.' ){

			q.push(make_pair(actual.first-1, actual.second));

			distance_[actual.first-1][actual.second] = 1 + distance_[actual.first][actual.second];
		}
		if ( !visite[actual.first+1][actual.second] &&  champ[actual.first+1][actual.second] == '.' ){

			q.push(make_pair(actual.first+1, actual.second));

			distance_[actual.first+1][actual.second] = 1 + distance_[actual.first][actual.second];
		}
		if ( !visite[actual.first][actual.second-1] &&  champ[actual.first][actual.second-1] == '.' ){

			q.push(make_pair(actual.first, actual.second-1));

			distance_[actual.first][actual.second-1] = 1 + distance_[actual.first][actual.second];
		}
		if ( !visite[actual.first][actual.second+1] &&  champ[actual.first][actual.second+1] == '.' ){

			q.push(make_pair(actual.first, actual.second+1));

			distance_[actual.first][actual.second+1] = 1 + distance_[actual.first][actual.second];
		}

	}

}

int main(){

	int n,m;

	while(scanf("%d %d", &n, &m) && ( n || m )){

		memset(champ, 0, sizeof(champ[0][0]) * MAX * MAX);

		// remplir le champ
		for ( int i = 1 ; i <= n ; i++ ){

			for ( int j = 1 ; j <= m ; j++ ){
				scanf(" %c", &champ[i][j]);
			}
		}

		int a,b;

		// primier cas
		for ( int i = 1 ; i <= n ; i++ )
			for ( int j = 1 ; j <= m ; j++ )
				if ( champ[i][j] == '.' ){
					a = i;
					b = j;
					goto flag;
				}

		flag:

		// printf("- --  %c -- \n", champ[1][1]);

		bfs(make_pair(a,b));
		max_dist = -1;
		bfs(position);
		printf("%d\n", max_dist );
		max_dist = -1;

		// for ( int i = 1 ; i <= n ; i++ )
		// 	for ( int j = 1 ; j <= m ; j++ )
		// 		printf("%d %d = %d\n", i, j , distance_[i][j]);
	}

	return 0;
}
#include <bits/stdc++.h>

#define INF 10000

using namespace std;

using ii = pair<int,int>;

int main(){

	char l1, l2;
	int a1, a2;
	int b1, b2;

	map < ii , int > mapa;

	int aux = 1;

	for ( int i = 1; i <= 8; i++ )
		for ( int j = 1; j <= 8; j++ ){
			mapa[ii(i,j)] = aux;
			aux++;
		}

	int peso[65][65];

	for ( int i = 1; i <= 64; i++ )
			for ( int j = 1; j <= 64; j++ )
				peso[i][j] = INF;

	for ( int i = 1; i <= 8; i++ )
			for ( int j = 1; j <= 8; j++ ){

				if ( i + 2 <= 8 and j + 1 <= 8 )
					peso[mapa[ii(i,j)]][mapa[ii(i+2,j+1)]] = 1;

				if ( i + 1 <= 8 and j + 2 <= 8 )
					peso[mapa[ii(i,j)]][mapa[ii(i+1,j+2)]] = 1;

				if ( i - 1 >= 1 and j + 2 <= 8 )
					peso[mapa[ii(i,j)]][mapa[ii(i-1,j+2)]] = 1;

				if ( i - 2 >= 1 and j + 1 <= 8 )
					peso[mapa[ii(i,j)]][mapa[ii(i-2,j+1)]] = 1;

				if ( i - 2 >= 1 and j - 1 >= 1 )
					peso[mapa[ii(i,j)]][mapa[ii(i-2,j-1)]] = 1;

				if ( i - 1 >= 1 and j - 2 >= 1 )
					peso[mapa[ii(i,j)]][mapa[ii(i-1,j-2)]] = 1;

				if ( i + 1 <= 8 and j - 2 >= 1 )
					peso[mapa[ii(i,j)]][mapa[ii(i+1,j-2)]] = 1;

				if ( i + 2 <= 8 and j - 1 >= 1 )
					peso[mapa[ii(i,j)]][mapa[ii(i+2,j-1)]] = 1;
			}

	for ( int k = 1; k <= 64; k++ )
			for ( int i = 1; i <= 64; i++ )
				for ( int j = 1; j <= 64; j++ )
					peso[i][j] = min(peso[i][j], peso[i][k] + peso[k][j]);

	while ( scanf(" %c%d %c%d", &l1, &a1, &l2, &a2) != EOF ){

		aux = 1;

		b1 = l1 - 96;
		b2 = l2 - 96;

		printf("To get from %c%d to %c%d takes %d knight moves.\n", l1,a1, l2,a2, b1 == b2 && a1 == a2 ? 0 : peso[mapa[ii(a1,b1)]][mapa[ii(a2,b2)]] );
	}

	return 0;
}
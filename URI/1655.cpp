#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int a,b;

	int x,y;

	double z;

	while ( scanf("%d", &a), a ){

		scanf("%d", &b);

		double peso[105][105];

		for ( int i = 0; i <= 100; i++ )
			for ( int j = 0; j <= 100; j++ )
				peso[i][j] = 0;

		for ( int i = 0; i < b; i++ ){

			scanf("%d %d %lf", &x, &y, &z);

			peso[x][y] = z/100;
			peso[y][x] = z/100;
		}

		for ( int k = 1; k <= 100; k++ )
			for ( int i = 1; i <= 100; i++ )
				for ( int j = 1; j <= 100; j++ )
					if ( peso[i][k] * peso[k][j] > peso[i][j] )
						peso[i][j] = peso[i][k] * peso[k][j];

		printf("%.6lf percent\n", peso[1][a]*100);

	}

	return 0;
}
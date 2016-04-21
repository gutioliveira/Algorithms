#include <bits/stdc++.h>

using namespace std;

#define MAX 105

char space[MAX][MAX];

int stars;

bool is_star;

int n;

void star(int a, int b){

	space[a][b] = '.';

	for ( int i = -1; i <= 1; i++ )
		for ( int j = -1; j <= 1; j++ ){

			if ( space[a+i][b+j] == '*' ){
				is_star = false;
				star(a+i,b+j);
			}
		}

}

int main(){

	int r,c;

	while( scanf("%d %d", &r, &c) , r | c ){

		memset(space, '.', sizeof space);

		stars = 0;

		is_star = true	;

		for ( int i = 1; i <= r; i++ ){
			scanf("%s", &space[i][1]);
		}

		// for ( int i = 1; i <= r; i++ ){
		// 	for ( int j = 1; j <=c; j++ ){
		// 		printf("%c", space[i][j]);
		// 	}
		// 	printf("\n");
		// }

		for ( int i = 1; i <= r; i++ ){
			for ( int j = 1; j <=c; j++ ){
				if ( space[i][j] == '*' ){

					star(i,j);

					if ( is_star )
						stars++;
				}

				is_star = true;
			}
		}

		printf("%d\n", stars);




	}	

	return 0;
			
}
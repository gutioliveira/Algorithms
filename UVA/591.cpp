#include <bits/stdc++.h>

using namespace std;

int main(){

	int n;

	int bricks[50];

	int media;

	int moves;

	int test = 1;

	while(1){

		scanf("%d", &n);

		media = 0;

		moves = 0;

		if ( n == 0 )
			break;

		for ( int i = 0 ; i < n ; i++ ){

			scanf("%d", &bricks[i]);
			media = media + bricks[i];

		}

		media = media/n;

		for ( int i = 0 ; i < n ; i++ ){

			if ( bricks[i] > media )
				moves = bricks[i] - media + moves;

		}

		printf("Set #%d\nThe minimum number of moves is %d.\n\n", test , moves);

		test++;

	}
	
	return 0;
}
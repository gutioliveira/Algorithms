#include <bits/stdc++.h>

using namespace std;

int main(){

	int t , n;

	int walls[50];

	int low = 0;

	int high = 0;

	scanf("%d", &t);

	for ( int test = 1 ; test <= t ; test++ ){

		scanf("%d", &n);

		for ( int i = 0 ; i < n ; i++ ){

			scanf("%d", &walls[i]);

		}

		for ( int i = 0 ; i < n - 1 ; i++ ){

			if ( walls[i+1] > walls[i] )
				high++;

			if ( walls[i+1] < walls[i] )
				low++;

		}

		printf("Case %d: %d %d\n", test , high , low);

		high = 0;
		low = 0;

	}
	
	return 0;
}
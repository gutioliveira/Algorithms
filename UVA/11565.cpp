#include <bits/stdc++.h>

using namespace std;

int main(){

	int a,b,c;

	int flag = 1;

	int t;

	scanf("%d", &t);

	while(t--){

		scanf("%d %d %d", &a, &b, &c);

		flag = 1;

		for ( int i = -100; i <= 100; i++ ){

			for ( int j = -100; j <= 100; j++ ){

				for ( int k = -100; k <= 100; k++ ){

					if ( i != j && j != k && k != i && i+j+k == a && i*j*k == b && i*i + j*j + k*k == c ){

						flag = 0;
						a = i;
						b = j;
						c = k;
						break;
					}
				}
			}
		}

		if ( flag )
			printf("No solution.\n");
		else
			printf("%d %d %d\n", a,b,c);
	}

	return 0;
}
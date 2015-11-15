#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){

    return b == 0 ? a : gcd(b, a % b);
}

int main(){

	int n;

	long long g;

	while(1){

		scanf("%d", &n);

		if ( n == 0 )
			break;

		g = 0;

		for( int i = 1 ; i < n ; i++ )
			for( int j = i + 1 ; j <= n ; j++ )
				g += gcd(i,j);

		printf("%lld\n", g);



	}
	
	return 0;
}
#include <bits/stdc++.h>
#define MOD 1000000

using namespace std;

int main(){

	int n, m;

	while( scanf("%d %d", &n , &m ) != EOF )
		if ( n == 1 && m == 1 )
			printf("0\n");
		else
			printf("%d\n", (n*m - 1) );

	return 0;
}
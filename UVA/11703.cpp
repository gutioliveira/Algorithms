#include <bits/stdc++.h>
#define MOD 1000000

using namespace std;

int mapa[MOD+1];

long long x(int i){

	if ( mapa[i] != 0 )
		return mapa[i];

	if ( i <= 0 )
		return 1;
	else
		mapa[i] = ( x(i - sqrt(i)) + x(log(i)) + x(i*sin(i)*sin(i)) ) % MOD ;
	
	return mapa[i];
}

int main(){

	memset(mapa, 0 , sizeof mapa);

	int n;

	while(1){

		scanf("%d", &n);

		if ( n == -1 )
			break;

		printf("%lld\n", x(n));

	}

	return 0;
}
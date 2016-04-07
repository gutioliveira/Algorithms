#include <bits/stdc++.h>

using namespace std;

#define MAX 1025

map < int, long long > mapa;

unsigned long long fibo(int n){

	if ( n == 0 )
		return 0;

	if ( n == 1 )
		return 1;

	if ( mapa[n] != 0 )
		return mapa[n];

	mapa[n] = fibo(n-1) + fibo(n-2);

}

int main(){

	int t;

	int aux;

	scanf("%d", &t);

	while(t--){

		scanf("%d", &aux);

		printf("Fib(%d) = %lld\n", aux, fibo(aux));

	}

	return 0;
}
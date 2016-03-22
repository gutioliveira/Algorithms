#include <bits/stdc++.h>

using namespace std;

int global = 0;
int global2 = 0;

int fibo(int n){

	global2++;

	if ( n <= 0 ){

		global++;
		return 0;
	}

	if ( n == 1 ){

		global++;
		return 1;
	}

	return fibo(n-2) + fibo(n-1);
}

int main(){

	int fibos[40];

	fibos[0] = 1;
	fibos[1] = 1;

	int n;

	for ( int i = 2 ; i <= 39 ; i++ )
		fibos[i] = fibos[i-1] + fibos [i-2];

	scanf("%d", &n);

	int j;

	for ( int i = 0 ; i < n ; i++ ){

		scanf("%d", &j);

		int x = fibo(j);

		printf("fib(%d) = %d calls = %d\n", j , global2 - 1, x);

		global = 0;
		global2 = 0;
	}



	return 0;
}
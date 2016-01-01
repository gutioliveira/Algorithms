#include <bits/stdc++.h>

using namespace std;

int main(){

	int t;

	scanf("%d", &t);

	char a[10000];

	char b[10000];

	int operacoes = 0;

	for ( int i = 0 ; i < t ; i++ ){

		operacoes = 0;

		scanf("%s %s", &a, &b);

		for ( int j = 0 ; j < strlen(a) ; j++ ){

			if ( b[j] - a[j] >= 0 )
				operacoes = operacoes + b[j] - a[j];
			else
				operacoes = operacoes + b[j] - a[j] + 26;
		}

		printf("%d\n", operacoes);

	}

	return 0;
}
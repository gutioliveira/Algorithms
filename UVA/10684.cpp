#include <bits/stdc++.h>
#define MAX 10005
using namespace std;

int main(){

	int n;

	int vetor[MAX];

	int soma;

	int negativos;

	int maximo = -1;

	while ( 1 ){

		scanf("%d", &n);

		if ( n == 0 )
			break;

		negativos = 0;

		maximo = -1;

		soma = 0;

		for ( int i = 0 ; i < n ; i++ ){

			scanf("%d", &vetor[i]);

			if ( vetor[i] < 0 )
				negativos++;

		}

		if ( negativos == n )
			printf("Losing streak.\n");
		else{

			for ( int i = 0 ; i < n ; i++ ){

				soma = soma + vetor[i];

				if ( soma < 0 )
					soma = 0;

				maximo = max(maximo, soma);
			}

			if ( maximo == 0 )
				printf("Losing streak.\n");
			else
				printf("The maximum winning streak is %d.\n", maximo);
		}

		memset( vetor , 0 , sizeof vetor );

	}

	return 0;
}
#include <bits/stdc++.h>
#define MAX 1000000

using namespace std;

int recebe_lis( int alturas[] ,  int lis[] ,  int tamanho ){

	memset ( lis , 0 , sizeof lis );

	int maior = 0;

	lis[0] = 1;

	for ( int i = 1 ; i < tamanho ; i++ ){

		lis[i] = 1;

		for ( int j = 0 ; j < i ; j++ ){

			if ( alturas[i] <= alturas[j] ){
				
				if ( lis[j] >= lis[i] ){
					lis[i]++;
					maior = max(maior, lis[i]);
				}
				
			}

		}
	}

	if ( maior == 0 )
		maior = 1;

	return maior;
}

int main(){

	int alturas[MAX];

	int lis[MAX];

	int aux;

	int caso = 1;

	int aux2;

	int i = 0;

	while(1){

		scanf("%d", &alturas[i]);

		if ( alturas[i] == -1 ){

			memset ( lis , 0 , sizeof lis );

			if ( caso != 1 )
				printf("\n");

			printf("Test #%d:\n  maximum possible interceptions: %d\n", caso, recebe_lis(alturas, lis, i));

			caso++;

			scanf("%d", &aux2);

			if ( aux2 == -1 )
				break;
			else{
				i = 0;
				alturas[i] = aux2;
			}
		}

		i++;

	}
	
	return 0;
}
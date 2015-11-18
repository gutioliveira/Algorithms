#include <bits/stdc++.h>
#define MAX 1005

using namespace std;

int max_gastos(int lucro[] , int tamanho , int custo){

	int max = -2000;

	int soma;

	for ( int i = 0 ; i < tamanho ; i++ ){

		soma = 0;

		for ( int j = i ; j < tamanho ; j++ ){

			soma = soma + lucro[j] - custo;

			if ( soma > max )
				max = soma;
			else
				continue;
		}

	}

	if ( max < 0 )
		max = 0;

	return max;


}

int main(){

	int receitas;

	int custo;

	int lucro[MAX];

	while ( scanf("%d", &receitas) != EOF ){

		scanf("%d", &custo);

		for ( int t = 0 ; t < receitas ; t++ )
			scanf("%d", &lucro[t]);

		printf("%d\n", max_gastos(lucro,receitas,custo));

		/*

		custo por dia 20

		18
		35
		6
		80
		15
		21

		6
		15
		18
		21
		35
		80
 
		*/

	}

	return 0;
}
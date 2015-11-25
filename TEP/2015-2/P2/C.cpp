#include <bits/stdc++.h>

#define MAX 10005

using namespace std;

/*

	1000 5 VALOR MÁXIMO A SER EMPRESTADO

	-150 -75 -320

	100 -250 75 -320 1000

	saldo = 100

	divida = 150

	saldo = 75

	diviida = 150 + (320-75)



*/

int main(){

	int maximo;

	int eventos;

	int saldo;

	int valores[MAX];

	int divida;

	while (1){

		saldo = 0;

		divida = 0;

		scanf("%d %d", &maximo, &eventos);

		if ( maximo == 0 && eventos == 0 )
			break;

		for ( int i = 0 ; i < eventos ; i++ )
			scanf("%d", &valores[i]);


		for ( int i = 0 ; i < eventos ; i++ ){

			if ( valores[i] < 0 && abs(valores[i]) > saldo ){

				divida = abs(valores[i] + saldo) + divida;

				saldo = 0;
			}else{

				saldo = saldo + valores[i];
			}

		}

		if ( divida > maximo )
			printf("-1\n");
		else
			printf("%d\n", divida);

	}

		

	return 0;
}
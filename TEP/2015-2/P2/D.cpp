#include <bits/stdc++.h>
#define MAX 10*10*10*10*10 + 3

using namespace std;

int temperaturas[MAX];

long long temp[MAX];

void update(int i, int valor, int tamanho){

	if ( i > tamanho )
		return;

	temp[i] = temp[i] + valor;

	i = i + ( i & (-i) );

	update(i, valor, tamanho);

}

long long sum(int i){

	long long soma = 0;

	while( i > 0 ){

		soma = soma + temp[i];
		i = i - ( i & (-i) );

	}

	return soma;

}

int main(){

	int teste;

	scanf("%d", &teste);

	int n;

	int comandos;

	int intervalo;

	char tipo;

	int a, b, t;

	double media;

	int cont = 0;

	for ( int test = 1; test <= teste ; test++ ){

		cont = 0;

		if ( test != 1 )
			printf("\n");

		scanf("%d", &n);

		for ( int i = 1 ; i <= n ; i++ ){
			scanf("%d", &temperaturas[i]);
			update(i, temperaturas[i] , n);
		}

		scanf("%d", &comandos);

		for ( int i = 0 ; i < comandos ; i++ ){

			scanf(" %c", &tipo);

			if ( tipo == 'Q' ){

				scanf("%d %d", &a, &b);

				intervalo = b-a + 1;

				if ( sum(a-1) < 0 )
					media = double((sum(b) - sum(a-1))) / double( intervalo );
				else
					media = double((sum(b) - sum(a-1))) / double( intervalo );


				cont++;

				printf("Query %d: %.2lf\n", cont, media);

			}else{

				scanf("%d %d", &a, &t);

				int new_temp = t;

				update(a, new_temp, n);

			}

		}

		memset(temp, 0, sizeof temp);

	}
	
	return 0;
}
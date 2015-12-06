#include <bits/stdc++.h>

using namespace std;

class Casa{

public:
	int pessoas;
	int consumo;

};

int main(){

	map < int, int > mapa;

	Casa aux;

	int teste = 1;

	int n;

	int consumo;

	int total;

	while(1){

		consumo = 0;

		total = 0;

		scanf("%d", &n);

		if ( n == 0 )
			break;

		if ( teste != 1 )
			printf("\n");

		for ( int i = 0 ; i < n ; i++ ){

			cin >> aux.pessoas >> aux.consumo;

			total = aux.pessoas + total;

			consumo = consumo + aux.consumo;

			mapa[(int)aux.consumo/(int)aux.pessoas] = mapa[(int)aux.consumo/(int)aux.pessoas] + aux.pessoas;
		}

		printf("Cidade# %d:\n", teste );

		for ( auto it = mapa.begin() ; it != mapa.end() ; it++ ){
		
			if ( it != mapa.begin() )
				printf(" ");

			printf("%d-%d", it->second, it->first);

		}

		printf("\nConsumo medio: %.2lf m3.\n", (double)consumo/(double)total -0.0049999999);

		mapa.clear();

		teste++;

	}
	
	return 0;
}
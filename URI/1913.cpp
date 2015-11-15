#include <bits/stdc++.h>
#define MAX 100

using namespace std;

class cilindro{

public:
	int altura;
	int raio;
	string cor;

};

bool comparator(const cilindro &a, const cilindro &b){
 
	 return a.raio > b.raio;
}

int main(){

	int n;

	int soma;

	int maior;

	cilindro aux;

	vector < cilindro > cilindros;

	vector < cilindro > somas;

	while(1){

		soma = 0;

		maior = 0;

		scanf("%d", &n);

		if ( n == 0 )
			break;

		for ( int i = 0 ; i < n ; i++ ){

			cin >> aux.altura >> aux.raio >> aux.cor;

			cilindros.push_back(aux);
		}

		sort(cilindros.begin(), cilindros.end(), &comparator);

		somas = cilindros;

		for ( int i = 1 ; i < cilindros.size() ; i++ ){
			
			int maior_parcial = 0;

			for ( int j = i ; j > 0 ; j-- ){

			if ( cilindros[i].raio < cilindros[j-1].raio )
				if ( cilindros[i].cor == "VERMELHO" ){

					if ( cilindros[j-1].cor != "LARANJA"){

						maior_parcial = max(maior_parcial, somas[j-1].altura );

					}else if ( cilindros.size() == 2 ){

						maior = max(cilindros[0].altura, cilindros[1].altura);
					}

				}else if ( cilindros[i].cor == "LARANJA" ){

					if ( cilindros[j-1].cor != "AZUL" ){

						maior_parcial = max(maior_parcial, somas[j-1].altura );

					}else if ( cilindros.size() == 2 ){

						maior = max(cilindros[0].altura, cilindros[1].altura);
					}

				}else if ( cilindros[i].cor == "AZUL" ){

					if ( cilindros[j-1].cor != "VERDE" ){

						maior_parcial = max(maior_parcial, somas[j-1].altura );

					}else if ( cilindros.size() == 2 ){

						maior = max(cilindros[0].altura, cilindros[1].altura);
					}

				}else if ( cilindros[i].cor == "VERDE" ){

					if ( cilindros[j-1].cor != "VERMELHO" ){

						maior_parcial = max(maior_parcial, somas[j-1].altura );

					}else if ( cilindros.size() == 2 ){

						maior = max(cilindros[0].altura, cilindros[1].altura);
					}

				}

			}

			somas[i].altura = somas[i].altura + maior_parcial;

			maior = max(maior , somas[i].altura);
		}

		if ( cilindros.size() == 1 )
			maior = cilindros[0].altura;

		printf("%d centimetro(s)\n", maior);

		cilindros.clear();
		somas.clear();

	}

	return 0;
}
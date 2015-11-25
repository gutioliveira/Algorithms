#include <bits/stdc++.h>

using namespace std;

/*

	
naipes = H, D, S, C
cartas = A,T, J, Q, R



*/

int main(){

	int teste;

	vector < string > cartas;

	string aux;

	int auxzinho;

	map < char , int > mapa;

	mapa['K'] = 10; 
	mapa['Q'] = 10;
	mapa['A'] = 1;
	mapa['J'] = 10;
	mapa['T'] = 10;
	mapa['1'] = 1;
	mapa['2'] = 2;
	mapa['3'] = 3;
	mapa['4'] = 4;
	mapa['5'] = 5;
	mapa['6'] = 6;
	mapa['7'] = 7;
	mapa['8'] = 8;
	mapa['9'] = 9;

	scanf("%d", &teste);

	for ( int test = 1; test <= teste ; test++ ){

		int soma = 0;

		for ( int i = 0 ; i < 52 ; i++ ){

			cin >> aux;

			cartas.push_back(aux);
		}

		for ( int i = 0 ; i < 52 ; i++ ){

			// cout << cartas[i] << endl;

			if ( (mapa[cartas[i][0]] + soma) > 21 ){

				break;
			}else{

				soma = mapa[cartas[i][0]] + soma;
			}

		}

		printf("Case #%d: %d pontos\n", test, soma);

		cartas.clear();

	}
	

	return 0;
}
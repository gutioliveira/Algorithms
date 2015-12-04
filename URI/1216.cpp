#include <bits/stdc++.h>

using namespace std;

int main(){

	string nome;

	string sobrenome;

	int contador = 0;

	int distancia;

	double media = 0;

	cin.ignore();

	while ( getline(cin, nome) ){

		cin >> distancia;

		cin.ignore();
		
		media = distancia + media;

		contador++;

	}

	printf("%.1lf\n", media/contador );

	return 0;
}
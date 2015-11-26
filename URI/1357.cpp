#include <bits/stdc++.h>

using namespace std;

int main(){

	map < string , int > mapa;

mapa[".***.."] = 0;
mapa["*....."] = 1;
mapa["*.*..."] = 2;
mapa["**...."] = 3;
mapa["**.*.."] = 4;
mapa["*..*.."] = 5;
mapa["***..."] = 6;
mapa["****.."] = 7;
mapa["*.**.."] = 8;
mapa[".**..."] = 9;

	map < int , string > mapa_au_contraire;

mapa_au_contraire[0] = ".***..";
mapa_au_contraire[1] = "*.....";
mapa_au_contraire[2] = "*.*...";
mapa_au_contraire[3] = "**....";
mapa_au_contraire[4] = "**.*..";
mapa_au_contraire[5] = "*..*..";
mapa_au_contraire[6] = "***...";
mapa_au_contraire[7] = "****..";
mapa_au_contraire[8] = "*.**..";
mapa_au_contraire[9] = ".**...";

	int n;

	char tipo;

	string vetor[101];

	string aux;

	while(1){

		scanf("%d", &n);

		if ( n == 0 )
			break;

		scanf(" %c", &tipo);

		if ( tipo == 'B' ){

			for ( int i = 0 ; i < n ; i++ ){

				cin >> aux;

				vetor[i] = vetor[i] + aux;

			}

			for ( int i = 0 ; i < n ; i++ ){

				cin >> aux;

				vetor[i] = vetor[i] + aux;

			}

			for ( int i = 0 ; i < n ; i++ ){

				cin >> aux;

				vetor[i] = vetor[i] + aux;

			}

			for ( int i = 0 ; i < n ; i++ ){
				printf("%d", mapa[vetor[i]] );
				vetor[i] = "";
			}

			printf("\n");

		}else{

			cin >> aux;

			int size_ = aux.size();

			for ( int i = 0 ; i < size_ ; i++ ){

					cout << mapa_au_contraire[aux[i] - 48][0] << mapa_au_contraire[aux[i] - 48][1];
					
					if ( i != size_ - 1 )
						cout << ' ';
					else
						cout << '\n';
			}

			for ( int i = 0 ; i < size_ ; i++ ){

					cout << mapa_au_contraire[aux[i] - 48][2] << mapa_au_contraire[aux[i] - 48][3];
					
					if ( i != size_ - 1 )
						cout << ' ';
					else
						cout << '\n';
			}

			for ( int i = 0 ; i < size_ ; i++ ){

					cout << mapa_au_contraire[aux[i] - 48][4] << mapa_au_contraire[aux[i] - 48][5];
					
					if ( i != size_ - 1 )
						cout << ' ';
					else
						cout << '\n';
			}

		}

	}

	return 0;
}
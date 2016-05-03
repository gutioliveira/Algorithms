#include <bits/stdc++.h>
#define MAX 105
using namespace std;

map < int , string > mapa;


int main(){

	mapa[61] = "Brasilia";
	mapa[71] = "Salvador";
	mapa[11] = "Sao Paulo";
	mapa[21] = "Rio de Janeiro";
	mapa[32] = "Juiz de Fora";
	mapa[19] = "Campinas";
	mapa[27] = "Vitoria";
	mapa[31] = "Belo Horizonte";
	
	int x;

	scanf("%d", &x);

	if ( mapa[x].size() >= 3 )
		cout << mapa[x] << endl;
	else
		cout << "DDD nao cadastrado" << endl;

	return 0;
}
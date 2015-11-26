#include <bits/stdc++.h>

using namespace std;

int main(){

	int n , aux;

	map <int, int> mapa;

	scanf("%d", &n);

	for ( int i = 0 ; i < n ; i++ ){
		scanf("%d", &aux);
		mapa[aux]++;
	}

	for ( auto it = mapa.begin() ; it != mapa.end() ; it++ ){

		printf("%d aparece %d vez(es)\n", it->first, it->second );
	}

	return 0;
}
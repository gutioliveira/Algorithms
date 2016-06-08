#include <bits/stdc++.h>

#define MAX 100005

using namespace std;

int main(){

	long long a, aux;

	while ( scanf("%lld", &a), a ){

		map < long long , long long > mapa;

		for ( long long i = 0; i < a; i++ ){

			scanf("%lld", &aux);

			mapa[aux]++;
		}

		for ( auto it = mapa.begin(); it != mapa.end(); it++ ){

			if ( it->second % 2 == 1 ){

				cout << it->first << endl;
				break;
			}
		}
	}

	return 0;
}
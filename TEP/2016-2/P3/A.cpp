#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

	long long numero;

	int teste = 1;

	const double pi = acos(-1);

	long long a = 1;
	long long b = 1;
	long long fib = 0;

	vector < double > termos;

	termos.push_back(pi*0.5);
	termos.push_back(pi*0.5 + termos[termos.size()-1]);

	while(1){

		fib = a + b;
		a = b;
		b = fib;

		if ( fib > 20000000000 )
			break;

		termos.push_back(pi*fib*0.5 + termos[termos.size()-1]);
	}

	while(scanf("%lld", &numero), numero){

		int comprimento = 0;

		for ( int i = 0; i < termos.size(); i++ ){

			if ( termos[i] >= numero ){

				comprimento = i + 1;
				break;
			}
		}

		printf("Caso %d: %d\n", teste++, comprimento);
	}

	return 0;
}
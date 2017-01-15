#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int testa_primo(int primo){

	if ( primo == 2 )
		return 1;
	if ( primo == 3 )
		return 1;
	if ( primo % 2 == 0 )
		return 0;
	if ( primo % 3 == 0 )
		return 0;

	int i = 5;
	int j = 2;

	while ( i * i <= primo ){

		if ( primo % i == 0 )
			return 0;

		i += j;
		j = 6 - j;
	}

	return 1;
}

int main(){

	int n;

	cin >> n;

	for ( int i = 1; i < 10*10*10; i++ ){

		if ( !testa_primo(n * i + 1) ){

			printf("%d\n", i);
			return 0;
		}
	}

	return 0;
}
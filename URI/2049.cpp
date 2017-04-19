#include <iostream>
#include <map>
#include <cstring>
#include <string>

using namespace std;

int main(){

	int t = 0;

	string s, x;

	while ( cin >> s >> x, s != "0" ){

		if ( t )
			printf("\n");

		printf("Instancia %d\n", ++t);
		printf("%s\n", x.find(s) == string::npos ? "falsa" : "verdadeira" );

	}

	return 0;
}
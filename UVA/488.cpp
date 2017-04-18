#include <iostream>
#include <map>
using namespace std;

int main(){

	int t, f, a;

	cin >> t;

	map < int , string > m;
	m[0] = "";
	m[1] = "1";
	m[2] = "22";
	m[3] = "333";
	m[4] = "4444";
	m[5] = "55555";
	m[6] = "666666";
	m[7] = "7777777";
	m[8] = "88888888";
	m[9] = "999999999";


	for ( int j = 0; j < t; j++ ){

		cin >> a >> f;

		if ( j )
			printf("\n");

		string x = "";

		for ( int i = 1; i <= a; i++ ){

			x += m[i] + "\n";
		}

		for ( int i = a-1; i > 0; i-- ){

			x += m[i] + "\n";
		}

		for ( int i = 0; i < f; i++ ){

			if ( i )
				printf("\n");

			printf("%s", x.c_str());
		}
	}

	return 0;
}
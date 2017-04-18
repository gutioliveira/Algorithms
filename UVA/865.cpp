#include <iostream>
#include <map>
#include <cstring>

using namespace std;

int main(){

	int t;

	string a,b,line;

	scanf("%d\n", &t);

	for ( int i = 0; i < t; i++ ){

		// cin.ignore();

		map < char, char > mapa;

		for ( int i = 0; i < 250; i++ )
			mapa[i] = i;

		getline(cin, a);
		getline(cin, b);

		if ( i )
			printf("\n");

		cout << b << endl;
		cout << a << endl;

		for ( int i = 0; i < a.size(); i++ )
			mapa[a[i]] = b[i];

		while( getline(cin, line), line != "" ){

			for ( int i = 0; i < line.size(); i++ )
				printf("%c", mapa[line[i]]);

			printf("\n");

			line = "";
		}
	}

	return 0;
}
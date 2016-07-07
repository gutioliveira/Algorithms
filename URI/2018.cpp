#include <bits/stdc++.h>

using namespace std;

int main(){

	string aux;

	string aux2;

	string biggest = "";

	while(1){

		getline(cin, aux);

		istringstream s(aux);

		if ( aux == "0" )
			break;

		bool checa = false;

		while( s >> aux ){

			if (checa)
				cout << "-";

			cout << aux.size();

			if ( aux.size() >= biggest.size() )
				biggest = aux;

			checa = true;
		}

		cout << endl;

	}

	cout << "\nThe biggest word: " << biggest << endl;

	return 0;
}
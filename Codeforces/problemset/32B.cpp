#include <iostream>

using namespace std;

int main(){

	string s;

	cin >> s;

	string aux = "";

	for ( int i = 0; i < s.size(); i++ ){

		aux += s[i];

		if ( aux == "." ){

			cout << "0";
			aux = "";
		}else if ( aux == "-." ){

			cout << "1";
			aux = "";
		}else if ( aux == "--" ){

			cout << "2";
			aux = "";
		}
	}

	cout << endl;

	return 0;
}
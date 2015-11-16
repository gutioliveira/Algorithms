#include <bits/stdc++.h>

using namespace std;

string decimal_hexadecilam(int decimal){

	stringstream ss;

	ss << hex << decimal;
	
	string result = ss.str();

	for ( int i = 0 ; i < result.size() ; i++ ){

		if ( result[i] >= 97 )
			result[i] = result[i] - 32;

	}

	return result;
}


int main(){

	string numero;

	int decimal;

	int tamanho;

	while(1){

		cin >> numero;

		if ( numero[0] == '-' )
			break;

		if ( numero[0] == '0' && numero[1] == 'x' ){

			numero.erase(numero.begin());
			numero.erase(numero.begin());

			int number = (int)strtol(numero.c_str(), NULL, 16);

			cout << number << endl;

		}else{

			decimal = atoi( numero.c_str() );

			printf("0x");

			cout << decimal_hexadecilam(decimal) << endl;

		}

	}

	return 0;
}
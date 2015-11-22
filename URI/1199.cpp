#include <bits/stdc++.h>

using namespace std;

long long binary_to_decimal(string bin){

	int size_b = bin.size();

	long long soma = 0;

	int j, i;

	for ( i = size_b - 1 , j = 0 ; i >= 0 ; i-- , j++ ){

		if ( bin[j] == '1' )
			soma = soma + pow(2, i);

	}

	return soma;
}

string decimal_to_hex(long long decimal){

	string hex = "";

	int aux , aux2;

	map < int , char > mapa;

	mapa[0] = '0';
	mapa[1] = '1';
	mapa[2] = '2';
	mapa[3] = '3';
	mapa[4] = '4';
	mapa[5] = '5';
	mapa[6] = '6';
	mapa[7] = '7';
	mapa[8] = '8';
	mapa[9] = '9';
	mapa[10] = 'A';
	mapa[11] = 'B';
	mapa[12] = 'C';
	mapa[13] = 'D';
	mapa[14] = 'E';
	mapa[15]= 'F';

	if ( decimal > 15 ){

		while ( decimal > 15 ){

			aux = decimal / 16;

			aux2 = aux;

			aux = decimal - aux * 16;

			decimal = aux2;

			hex = hex + mapa[aux];

		}

		hex = hex + mapa[decimal];

	}else
		hex = mapa[decimal];

	reverse(hex.begin(), hex.end());

	return hex;

}

long long hex_to_decimal(string hex){

	int size_b = hex.size();

	long long soma = 0;

	int j, i;

	for ( i = size_b - 1 , j = 0 ; i >= 0 ; i-- , j++ ){


		if ( hex[j] >= 97 )
			soma = soma + ( ( hex[j] - 	87 ) )*pow(16, i);
		else
			soma = soma + ( ( hex[j] - 	48 ) )*pow(16, i);

	}

	return soma;

}

void ConvertToBinary(long long n)
{
    if (n / 2 != 0) {
        ConvertToBinary(n / 2);
    }
    printf("%lld", n % 2);
}

int main(){

	int n;

	string base;

	string numero;

	while(1){

		cin >> numero;

		if ( numero[0] == '-' )
			break;

		if ( numero[0] == '0' && numero[1] == 'x' ){

			numero.erase(numero.begin());
			numero.erase(numero.begin());

			cout << hex_to_decimal(numero) << endl;

		}else{

			printf("0x");
			cout << decimal_to_hex(atoi(numero.c_str())) << endl;
		}

		

	}

	return 0;
}
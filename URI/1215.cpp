#include <bits/stdc++.h>
 
using namespace std;

int main(){

	char a;
	
	string aux = "";	
	
	map<string,int> mapa;
	
	while ( scanf("%c", &a) != EOF ){
		
		string s(1, tolower(a));
		
		if ( isalpha(a) ){
		
			aux = aux + s;
		}else{
			mapa[aux] = 1;
			aux = "";			
		}
	}
	
	for ( auto it = mapa.begin(); it != mapa.end(); it++ ){
		if ( it->first != "" )
			cout << it->first << endl;
	}

	return 0;
}
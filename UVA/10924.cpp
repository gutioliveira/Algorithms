#include <bits/stdc++.h>
#define MOD 1000000

using namespace std;

bool is_prime(int n){

    if( n <= 2 ) 
    	return true;

    if( n % 2 == 0 ) 
    	return false;
    
    for( int i = 3 ; i <= n/i ; i = i+ 2 )
        if( n % i == 0 ) 
        	return false;
    
    return true;
}

int soma(string word){

	int soma = 0;

	for ( int i = 0 ; i < word.size() ; i++ ){

		if ( word[i] >= 'a' )
			soma = soma + word[i] - 'a' + 1;
		else
			soma = soma + word[i] - 38;
		
	}

	return soma;
}

int main(){

	string word;

	while( cin >> word ){

		if ( is_prime(soma(word)) )
			printf("It is a prime word.\n");
		else
			printf("It is not a prime word.\n");

	}

	return 0;
}
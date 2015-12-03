#include <stdio.h>
#define false 0
#define true 1

int is_prime(int n){

    if( n <= 2 ) 
    	return true;

    if( n % 2 == 0 ) 
    	return false;
    
    for( int i = 3 ; i <= n/i ; i = i+ 2 )
        if( n % i == 0 ) 
        	return false;
    
    return true;
}

int next_prime(int primo){

	int numero = primo + 1;

	while( !is_prime(numero) ){

		numero++;
	}

	return numero;

}

long long maior_fator(long long number){

	long long numero = number;

	int next = next_prime(1);

	while(1){

		if ( numero % next == 0 ){

			numero = numero/next;
		}else if ( numero == 1 ){

			return next;
		}else{

			next = next_prime(next);
		}
	}

}

int main(){

	/*
The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143 ?
	*/

	printf("%lld\n", maior_fator(600851475143) );

	return 0;
}
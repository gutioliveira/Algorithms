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

long long sum_primes(int n){

	long long sum = 0;

	for ( int i = next_prime(1) ; i < n ; i = next_prime(i) )
		sum = sum + i;

	return sum;

}

int main(){

	/*
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
Find the sum of all the primes below two million.
	*/

	printf("%lld\n", sum_primes(2000000) );

	return 0;
}
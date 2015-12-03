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

long long nth_prime(int n){

	int i = 1;

	int j = 1;
	
	while(1){

		i = next_prime(i);

		if ( j == n )
			break;

		j++;
	}

	return i;

}

int main(){

	/*
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
What is the 10 001st prime number?
	*/

	printf("%lld\n", nth_prime(10001) );

	return 0;
}
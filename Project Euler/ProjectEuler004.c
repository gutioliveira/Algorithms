#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *convert_int_string(int n){

	char *numero;

	numero = (char*) malloc ( 8*sizeof(char) );

	sprintf(numero, "%d", n);

	return numero;

}

int is_palindrome(char *numero, int a, int b){

	if ( a == b || a == strlen(numero)/2 )
		return 1;

	if ( numero[a] == numero[b] )
		return is_palindrome(numero, a+1, b-1);
	else
		return 0;

}

int product(){

	int maior = 0;

	for ( int i = 1 ; i < 1000 ; i++ ){
		for ( int j = 1 ; j < 1000 ; j++ ){
			if ( is_palindrome(convert_int_string(i*j), 0 , strlen(convert_int_string(i*j)) - 1) ){
				if ( i*j > maior ){
					maior = i*j;
				}
			}
		}
	}

	return maior;

}

int main(){

	/*
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
Find the largest palindrome made from the product of two 3-digit numbers.
	*/

	printf("%d\n", product());

	return 0;
}
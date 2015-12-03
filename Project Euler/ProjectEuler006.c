#include <stdio.h>
#include <math.h>

int sum_of_the_squares(int n){

	int sum = 0;

	for ( int i = 1 ; i <= n ; i++ )
		sum = i*i + sum;

	return sum;
}

int square_of_the_sum(int n){

	int sum = 0;

	for ( int i = 1 ; i <= n ; i++ )
		sum = i + sum;

	return sum*sum;
}


int main(){

	/*
The sum of the squares of the first ten natural numbers is,
12 + 22 + ... + 102 = 385
The square of the sum of the first ten natural numbers is,
(1 + 2 + ... + 10)2 = 552 = 3025
Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.	
Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
	*/

	printf("%d\n", square_of_the_sum(100) - sum_of_the_squares(100));

	return 0;
}
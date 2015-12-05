#include <stdio.h>

long long smalles_multiple(int n){
	
	int number = 2;

	int counter = 2;

	while(1){

		for ( int i = 3 ; i <= n ; i++ ){

			if ( number % i == 0 )
				counter++;
			else
				break;
		}

		if ( counter == n )
			return number;

		counter = 2;

		number = number + 2;

	}

}

int main(){
	
	/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
	*/	

	printf("%lld\n", smalles_multiple(20));

	return 0;
}
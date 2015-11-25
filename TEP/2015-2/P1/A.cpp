#include <iostream>
#include <stdio.h>
#include <stack>

using namespace std;

int main(){

	int n;

	int total = 0;

	int numero;

	stack<int> pilha;

	while ( scanf("%d", &n) != EOF ){

		for ( int i = 0 ; i < n ; i++ ){

			scanf("%d", &numero);

			if ( pilha.size() == 0 ){

				pilha.push(numero);

				total = total + numero;
			}else if ( numero <= pilha.top() && pilha.size() < 6 ){

				pilha.push(numero);
				total = total + numero;
			}
		}

		while ( pilha.size() != 0 ){

			pilha.pop();
		}

		printf("Massa empilhada: %d kg\n", total);

		total = 0;
	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define MAX 1025

int campo[MAX][MAX];

int A,B;

void bfs( int a, int b ){

	queue < pair<int,int> >q;

	q.push(make_pair(a,b));

	pair <int,int> atual;

	while(!q.empty()){

		atual = q.front();

		q.pop();

		if ( atual.first - 1 > 0 && campo[atual.first-1][atual.second] != 1 ){

			campo[atual.first-1][atual.second] = 1;
			q.push(make_pair(atual.first-1, atual.second));
		}

		if ( atual.first + 1 <= A  && campo[atual.first+1][atual.second] != 1 ){

			campo[atual.first+1][atual.second] = 1;
			q.push(make_pair(atual.first+1, atual.second));
		}

		if ( atual.second - 1 > 0  && campo[atual.first][atual.second-1] != 1 ){

			campo[atual.first][atual.second-1] = 1;
			q.push(make_pair(atual.first, atual.second-1));
		}

		if ( atual.second + 1 <= B  && campo[atual.first][atual.second+1] != 1 ){

			campo[atual.first][atual.second+1] = 1;
			q.push(make_pair(atual.first, atual.second+1));
		}

	}

}

int main(){

	int a,b;

	scanf("%d %d", &A, &B);

	char aux;

	int conta = 0;

	memset(campo, 0, sizeof(campo[0][0]) * MAX * MAX);

	// for ( int i = 1 ; i <= A ; i++ ){

	// 	printf("\n");
	// 	for ( int j = 1 ; j <= B ; j++ ){
			
	// 		printf("%d", campo[i][j]);
	// 	}
	// }


	for ( int i = 1 ; i <= A ; i++ ){
		for ( int j = 1 ; j <= B ; j++ ){
			cin >> aux;
			if ( aux == 'o' ){

				campo[i][j] = 1;
			}
		}
	}

	for ( int i = 1 ; i <= A ; i++ ){
		for ( int j = 1 ; j <= B ; j++ ){
			
			if ( campo[i][j] == 0 ){
				campo[i][j] = 1;



				bfs(i,j);
				conta++;
			}
		}
	}

	// for ( int i = 1 ; i <= A ; i++ ){

	// 	printf("\n");
	// 	for ( int j = 1 ; j <= B ; j++ ){
			
	// 		printf("%d", campo[i][j]);
	// 	}
	// }



	printf("%d\n", conta);

	return 0;
}
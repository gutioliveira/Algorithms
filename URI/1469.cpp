#include <bits/stdc++.h>

using namespace std;

#define MAX 510

#define INF 420000

vector < vector<int> > v;

vector < int > indexxx;

int minu = INF;

int visited[MAX*MAX];

void fill(){

	v.push_back({});

	for ( int i = 0 ; i < MAX ; i++ )
		v.push_back({});
}

void clear(){

	for ( int i = 0 ; i < MAX ; i++ )
		v[i].clear();
}

int dfs(int a){

	if ( v[a].size() == 0 )
		return 0;

	for ( int i = 0 ; i < v[a].size() ; i++ ){

		if ( !visited[v[a][i]] ){

			// printf("estou no %d, valor %d\n", v[a][i] , indexxx[v[a][i]] );

			minu = min(minu, indexxx[v[a][i]] );

			visited[v[a][i]] = 1;

			dfs(v[a][i]);
		}
	}

	return -1;

}

int main(){

	fill();

	int N,M,I;

	int aux;

	while( scanf("%d %d %d", &N, &M, &I) != EOF ){

		indexxx.push_back(-1);

		for ( int i = 0 ; i < N ; i++ ){

			scanf("%d", &aux);

			indexxx.push_back(aux);
		}

		int a,b;

		for ( int i = 0 ; i < M ; i++ ){

			scanf("%d %d", &a, &b);

			v[b].push_back(a);
		}

		char cmd;

		for ( int i = 0 ; i < I ; i++ ){

			scanf(" %c", &cmd);

			memset(visited, 0, sizeof visited);

			if ( cmd == 'T' ){

				int c,d;

				int e,f;

				scanf("%d %d", &c, &d);

				// e = indexxx[c];

				// indexxx[c] = indexxx[d];

				// indexxx[d] = e;

				vector < int > aux;

				// for ( int i = 1 ; i < indexxx.size() ; i++ ){

				// 	printf("vetor[%d]", i);

				// 	for ( int j = 0 ; j < v[i].size() ; j++ ){

				// 		printf(" %d,", v[i][j]);
				// 	}

				// 	printf("\n");
				// }

				aux = v[c];

				v[c] = v[d];

				v[d] = aux;

				// for ( int i = 1 ; i < indexxx.size() ; i++ ){

				// printf("vetor[%d]", i);

				// for ( int j = 0 ; j < v[i].size() ; j++ ){

				// 	printf(" %d,", v[i][j]);
				// }

				// printf("\n");
				// }

				for ( int i = 1 ; i <= indexxx.size() ; i++ ){

					for ( int j = 0 ; j < v[i].size() ; j++ ){

						if ( v[i][j] == c )
							v[i][j] = d;
						else if ( v[i][j] == d)
							v[i][j] = c;
					}
				}


			}else{

				int x;

				scanf("%d", &x);

				dfs(x);

				if ( minu == INF )
					printf("*\n");
				else
					printf("%d\n", minu);

				minu = INF;
			}

			// for ( int i = 1 ; i < indexxx.size() ; i++ ){

			// 	printf("vetor[%d]", i);

			// 	for ( int j = 0 ; j < v[i].size() ; j++ ){

			// 		printf(" %d,", v[i][j]);
			// 	}

			// 	printf("\n");
			// }
		}

		indexxx.clear();

		clear();

		// finaliza o resto do código., atualiza as variaveis.

	}

	return 0;
}



































// #include <bits/stdc++.h>

// using namespace std;

// #define MAX 510

// int idades[MAX];
// int visited[MAX];

// int ficticio[MAX];

// struct lig{

// 	vector < int > ligacoes;
// };

// struct lig liga[MAX];

// struct lig toma[MAX];

// int menor = 21000000;

// void dfs(int a){

// 	if ( toma[a].ligacoes.size() == 0 )
// 		return;

// 	for ( int i = 0 ; i < toma[a].ligacoes.size() ; i++ ){

// 		if ( !visited[toma[a].ligacoes[i]] ){

// 			// eprintf("visitou %d \n", ficticio[toma[a].ligacoes[i]]);

// 			visited[ficticio[toma[a].ligacoes[i]]] = 1;
// 			menor = min(menor, idades[toma[a].ligacoes[i]]);

// 			printf("menor %d \n", menor);

// 			dfs(toma[a].ligacoes[i]);
// 		}

// 	}

// }


// int main(){

// 	int N, M, I;

// 	char action;

// 	int a, b;

// 	while( scanf("%d %d %d", &N, &M, &I) != EOF ){

// 		for ( int i = 1; i <= N; i++ ){
// 			scanf("%d", &idades[i]);
// 			// ficticio[i] = i;
// 		}
		

// 		for ( int i = 0; i < M; i++ ){

// 			// printf("i = %d\n", i);

// 			scanf("%d %d", &a, &b);

// 			liga[a].ligacoes.push_back(b);
// 			toma[b].ligacoes.push_back(a);
// 		}


// 		for ( int i = 0; i < I; i++ ){
// 			scanf(" %c", &action);

// 			memset(visited, 0, sizeof visited);

// 			if ( action == 'T' ){

// 				int aux;

// 				struct lig aux2;

// 				int aux3;

// 				scanf("%d %d", &a, &b);

// 				// aux = ficticio[a];

// 				// ficticio[ficticio[a]] = ficticio[ficticio[b]];

// 				// ficticio[a] = ficticio[b];

// 				// ficticio[b] = aux;

// 				// swap(idades[a], idades[b]);

// 				// swap(visited[a], visited[b]);

// 				//swap(toma[a], toma[b]);



// 				// aux3 = visited[a];
// 				// visited[a] = visited[b];
// 				// visited[b] = aux3;

// 				// aux2 = toma[a];
// 				// toma[a] = toma[b];
// 				// toma[b] = aux2;


// 			}else{
// 				scanf("%d", &a);

// 				// printf("fic %d\n", ficticio[a] );

// 				dfs(ficticio[a]);

// 				if ( menor == 21000000 )
// 					printf("*\n");
// 				else
// 					printf("%d\n", menor);
// 			}

// 			menor = 21000000;

// 		}

// 	}

// 	return 0;
// }
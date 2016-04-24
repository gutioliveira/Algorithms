#include <bits/stdc++.h>

using namespace std;

#define MAX 1005

char cidades[MAX];
vector < vector <int> > ligacoes;

char inverte(char l){

	if ( l == 'A' )
		return 'B';
	else
		return 'A';

}

int count2 = 0;

int visitado[MAX];

bool acertoo = true;

// void bfs(int a){

// 	int cont = 0;

// 	for ( int i = 0; i < ligacoes[a].size(); i++ ){

// 		if ( cidades[ligacoes[a][i]] == 'B' )
// 			cont++;
// 	}

// 	if ( cont % 2 == 1 ){
// 		printf("cont == %d\n", cont);
// 		acertoo = false;
// 	}

// }

int bfs(int a){

	queue <int> q;

	q.push(a);

	int atual;

	int cont = 0;

	if ( cidades[a] == 'B' ){
		// printf("hue\n");
		cont++;
	}

	while (!q.empty()){

		atual = q.front();

		q.pop();

		visitado[atual] = 1;

		for ( int i = 0; i < ligacoes[atual].size(); i++ ){

			if ( !visitado[ligacoes[atual][i]] ){
				q.push(ligacoes[atual][i]);
				if ( cidades[ligacoes[atual][i]] == 'B' ){
					cidades[ligacoes[atual][i]] = 'A';
					cont++;
				}
			}
		}
	}

	// printf("encontrou %d\n", cont);

	return cont;

}

int main(){
	
	int n,m;

	int a,b;

	while( scanf("%d %d", &n, &m) != EOF ){

		count2 = 0;

		memset(visitado,0,sizeof visitado);

		acertoo = true;

		ligacoes.push_back({});
		for ( int i = 1; i <= n; i++ ){
			//scanf(" %c", &cidades[i]);
			cin >> cidades[i];
			ligacoes.push_back({});
		}

		for ( int i = 1; i <= m; i++ ){
			scanf("%d %d", &a, &b);

			ligacoes[a].push_back(b);
			ligacoes[b].push_back(a);
		}

		for ( int i = 1; i <= n; i++ ){
			if ( !visitado[i] ){
				// printf("entrou\n");
				if ( bfs(i) % 2 != 0 ){
					acertoo = false;
					break;
				}
			}
		}

		// bfs(1);

		// bool achou = true;

		// for ( int i = 1; i <= n; i++ ){
		// 	if ( cidades[i] == 'B' ){
		// 		achou = false;
		// 		break;
		// 	}
		// }

		if ( acertoo )
			printf("Y\n");
		else
			printf("N\n");

		ligacoes.clear();

	}

	return 0;
}
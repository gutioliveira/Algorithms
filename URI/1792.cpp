#include <bits/stdc++.h>

#define MAX 10005

using namespace std;
using ii = pair<int,int>;

int in[MAX];
int out[MAX];
int inimigos[MAX];
int refens[MAX];
int visitado[MAX];
int soldados;


class T{
public:
	int index;
	int enemies;

	bool operator < ( const T& t ) const{

		if ( t.enemies < enemies )
			return true;
		else
			return false;
	}

};

int main(){

	int n,m,s;

	while( scanf("%d %d %d", &n, &m, &s), n | m | s ){

		vector<int> v[MAX];

		soldados = s;

		int contador = 0;

		memset(in, 0, sizeof in);
		memset(visitado, 0, sizeof visitado);

		priority_queue <T> pq;

		int a,b;

		for ( int i = 1; i <= n; i++ )
			scanf("%d", &inimigos[i]);
		for ( int i = 1; i <= n; i++ )
			scanf("%d", &refens[i]);

		for ( int i = 1; i <= m; i++ ){
			scanf("%d %d", &a, &b);
			v[a].push_back(b);

			// printf("%d ->> %d %d\n",a,b,);
			out[a]++;
			in[b]++;
		}


		for ( int i = 1; i <= n; i++ ){

			if ( in[i] == 0 ){
// printf("colocou na pq %d\n", i);
				T t;
				t.index = i;
				t.enemies = inimigos[i];

				pq.push(t);
				visitado[i] = 1;
			}
		}

		priority_queue<ii> pq2;

		// pq2 = pq;

		// while ( !pq2.empty() ){

		// 	printf("index %d e enemies %d\n", pq.top().first, pq.top().second);
		// 	pq2.pop();
		// }

		while ( !pq.empty() ){

			int index = pq.top().index;
			int enemies = pq.top().enemies;

			pq.pop();

			if ( enemies >= soldados ){
				// printf("soldados < enemies\n");
				break;
			}else{

				soldados += refens[index];
				contador++;

				// printf("%d size %lu\n", index, v[index].size());

				for ( int i = 0; i < v[index].size(); i++ ){

					in[v[index][i]]--;

					// printf("in %d\n", in[v[index][i]] );

					if ( in[v[index][i]] == 0 && !visitado[v[index][i]] ){

						// printf("faz sentdido\n");

						T t;
						t.index = v[index][i];
						t.enemies = inimigos[v[index][i]];

						pq.push(t);
						visitado[v[index][i]] = 1;
					}
				}
			}
		}

		if ( contador == n )
			printf("possivel\n");
		else
			printf("impossivel\n");




	}

	return 0;
}
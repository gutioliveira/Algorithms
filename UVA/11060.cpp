#include <bits/stdc++.h>

using namespace std;

#define MAX 110

// 

int adj[MAX][MAX];

int in[MAX];

int out[MAX];

int main(){

	int N;

	int teste = 1;

	while( scanf("%d", &N) != EOF ){

		map <string,int> ids;
		map <int, string> names;

		memset(in, 0, sizeof in);
		memset(out, 0, sizeof out);
		memset(adj, 0, sizeof adj);

		for ( int id = 1 ; id <= N ; ++id ){

			char name[60];
			scanf("%s", name);

			ids[name] = id;
			names[id] = name;
		}

		int M;

		vector < string > v;

		scanf("%d", &M);

		for ( int i = 0; i < M; i++){

			char aux1[60];
			char aux2[60];

			scanf("%s %s", aux1, aux2);

			adj[ ids[aux1] ][ out[ids[aux1]]++ ] = ids[aux2];

			in[ids[aux2]]++;
		}

		while ( v.size() != N ){

			for ( int i = 1; i <= N; i++ ){

				if ( in[i] == 0 ){

					v.push_back(names[i]);
					in[i] = -1;

					for ( int j = 0; j < out[i]; j++ ){

						in[adj[i][j]]--;
					}

					break;
				}
			}

		}

		printf("Case #%d: Dilbert should drink beverages in this order:", teste);

		for ( int i = 0; i < v.size(); i++ )
			printf(" %s", v[i].c_str());

		printf(".\n\n");

		teste++;
		ids.clear();
		names.clear();
		v.clear();


	}
	
	return 0;	
}
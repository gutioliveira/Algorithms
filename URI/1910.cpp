#include <bits/stdc++.h>

using namespace std;

#define MAX 100002

#define CANAL 100000

bool visited[MAX];
int dist[MAX];

map <int, bool> mapa;

vector< vector<int> > v;

void fill(){

	v.push_back({});

	for ( int i = 1 ; i <= 100000 ; i++ ){

		v.push_back({});

		if ( i < CANAL )
			v[i].push_back(i+1);

		if ( i > 1 )
			v[i].push_back(i-1);

		if ( i*2 <= CANAL )
			v[i].push_back(i*2);

		if ( i*3 <= CANAL )
			v[i].push_back(i*3);

		if ( i % 2 == 0 )
			v[i].push_back(i/2);
	}
}

int bfs(int o, int d){

	queue < int > q;

	q.push(o);

	while ( !q.empty() ){

		int atual = q.front();

		q.pop();

		for ( int i = 0 ; i < v[atual].size() ; i++ ){

			// printf("v = %d\n", v[atual][i]);

			if ( !visited[ v[atual][i] ] ){

				visited[ v[atual][i] ] = true;

				dist[  v[atual][i] ] = dist[atual] + 1;

				if ( v[atual][i] == d )
					return dist[ v[atual][i] ];

				q.push( v[atual][i] );
			}
		}
	}

	return -1;
}

int main(){

	fill();

	int o,d,k;

	int k1;

	// for ( int i = 0 ; i < v[12].size() ; i++ )
	// 	printf(" %d,",v[12][i]);

	// printf("\n");

	while( 1 ){

		scanf("%d %d %d", &o, &d, &k);

		memset( visited , 0 , sizeof visited );

		memset( dist , 0 , sizeof dist );

		if ( o == 0 && d == 0 && k == 0 )
			break;

		for ( int i = 0 ; i < k ; i++ ){

			scanf("%d", &k1);

			visited[k1] = true;

			mapa[k1] = true;
		}

		printf("%d\n", bfs(o,d));

		mapa.clear();
	}

	return 0;
}
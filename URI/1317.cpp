#include <bits/stdc++.h>

#define MAX 50005

using namespace std;

struct e{

	int a1, a2;
	string p1;
	string p2;
	string p3;

};

vector < vector < int > >v;

vector < vector < string > > s;

vector < struct e > e;

int n;

void bfs(int enviador, struct e E, int sizeee){

	int visited[30];

	memset( visited , 0 , sizeof visited );

	queue < int >  q;

	q.push(enviador);

	int atual;

	while(!q.empty()){

		atual = q.front();

		q.pop();

		if ( !visited[atual] )
			if ( v[atual].size() < E.a1 ){

				s[atual].push_back(E.p1);
			}else if ( v[atual].size() < E.a2 ){

				s[atual].push_back(E.p2);
			}else{

				s[atual].push_back(E.p3);
			}

		visited[atual] = 1;

		for ( int i = 0 ; i < v[atual].size() ; i++ ){

			if ( !visited[ v[atual][i] ] ){

				q.push( v[atual][i] );
			}

		}
	}

	for ( int i = 1 ; i <= n ; i++ ){

		if ( s[i].size() < sizeee + 1 )
			s[i].push_back(E.p1);
	}

}

int main(){
	int caso = 0;

	int x = 21;

	int aux;

	int a1, a2;

	string p1;
	string p2;
	string p3;

	while(x--){
		v.push_back({});
		s.push_back({});
	}

	while( scanf("%d", &n) && n != 0 ){

		vector < int > VETOR;

		for ( int i = 1 ; i <= n ; i++ ){

			while ( scanf("%d", &aux) && aux != 0 )
				v[i].push_back(aux);

		}

		while( scanf("%d", &aux) && aux != 0 ){

			VETOR.push_back(aux);
			//scanf("%d %d %s %s %s", &a1, &a2, p1, p2, p3 );
			cin >> a1 >> a2 >> p1 >> p2 >> p3;
			struct e y;

			y.a1 = a1;
			y.a2 = a2;
			y.p1 = p1;
			y.p2 = p2;
			y.p3 = p3;

			e.push_back(y);
		}

		for ( int i = 1 ; i <= n ; i++ ){

			cin >> p1;

			p1 = p1+":";

			s[i].push_back(p1);
		}

		
		for ( int i = 0 ; i < e.size() ; i++ ){

			bfs(VETOR[i], e[i], i+1);
		}

		// if ( !caso ){
		// 	printf("\n");
		// 	caso = 1;
		// }

		for ( int i = 1 ; i <= n; i++ ){

			if ( i != 1 )
				cout << endl;

			for ( int j = 0 ; j < s[i].size() ; j++ ){

				cout << s[i][j] << " ";
			}
		}


		printf("\n");

		e.clear();

		for ( int i = 0 ; i < 21 ; i++ ){

			v[i].clear();
			s[i].clear();
		}

		// printf("final\n");

	}

	return 0;
}
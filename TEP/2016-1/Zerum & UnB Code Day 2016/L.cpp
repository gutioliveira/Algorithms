#include <bits/stdc++.h>

using namespace std;

class ordenar{

public:

	int mes, ano;
	string profissao;

	ordenar(int m, int a, string p){

		mes = m;
		ano = a;
		profissao = p;
	}

	bool operator < ( const ordenar& o ) const{

		if ( ano == o.ano )
			return mes < o.mes;
		else
			return ano < o.ano;
	}

};

int main(){

	int T;

	bool pula = false;

	scanf("%d", &T);

	for ( int t = 1; t <= T; t++ ){

		int c, n;

		string profissao;

		scanf("%d", &c);

		map < string , int > id;

		getchar();

		for ( int i = 0; i < c; i++ ){

			getline(cin, profissao);

			id[profissao] = i;
		}

		scanf("%d", &n);

		int mes, ano;

		vector < ordenar > v;

		for ( int i = 0; i < n; i++ ){

			scanf("%d %d", &mes, &ano);

			getchar();

			getline(cin, profissao);

			ordenar o(mes, ano, profissao);

			v.push_back(o);
		}

		sort(v.begin(), v.end());

		map < int , vector < ordenar > > mapa;

		int sizes[1020];

		for ( int i = 0; i < v.size(); i++ ){
			sizes[i] = 1;
			mapa[i].push_back(v[i]);
		}

		int target = 0;
		int value = 0;

		for ( int i = 1; i < v.size(); i++ )
			for ( int j = 0; j < i; j++ ){

				if ( id[v[i].profissao] > id[v[j].profissao] ){
					if ( sizes[j]+1 > sizes[i] ){
						mapa[i].push_back(v[j]);
						sizes[i] = sizes[j]+1;
					}
				}
			}

		for ( int i = 0; i < v.size(); i++ ){

			if ( sizes[i] > value )
				target = i;
		}

		if ( pula )
			cout << endl;

		pula = true;

		printf("Curriculo %d:\n", t);

		sort(mapa[target].begin(), mapa[target].end());

		for ( int i = 0; i < mapa[target].size(); i++ )
			cout << ( mapa[target][i].mes < 10 ? "0" : "" ) << mapa[target][i].mes << "/" << mapa[target][i].ano << " - " << mapa[target][i].profissao << endl;

	}

	return 0;
}
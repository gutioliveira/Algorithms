#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

class aluno{

public:

	string nome;
	int fluxo;
	char situacao;
	int inscricao;

	bool operator < ( const aluno& a )const {

		if ( situacao == a.situacao ){

			if ( fluxo == a.fluxo ){

				return inscricao < a.inscricao;

			}else{

				return fluxo > a.fluxo;
			}

		}else{

			if ( situacao == 'C' ){

				return true;
			}else{

				return false;
			}
		}

	}	

};

int main(){

	int vagas, alunos;

	scanf("%d", &vagas);

	scanf("%d", &alunos);

	aluno aux;

	vector <aluno> vetor;

	for ( int i = 0 ; i < alunos ; i++ ){

		cin >> aux.nome >> aux.fluxo >> aux.situacao;
		aux.inscricao = i;

		vetor.push_back(aux);
	}

	if ( alunos <= vagas ){

		printf("Todos foram matriculados\n");
	}else{

		sort( vetor.begin() , vetor.end());

		cout << vetor[vagas].nome << endl;
	}


	return 0;
}
#include <bits/stdc++.h>

using namespace std;

using ss = pair<string,string>;

map < string , ss > grafo;

bool checa = false;

map < string , int > visitado;

void dfs(string topo){

	if ( checa )
		cout << " ";
	cout << topo;

	checa = true;

	visitado[topo] = 1;

	if ( visitado[ grafo[topo].first ] != 1 && grafo[topo].first != "" ){

		dfs(grafo[topo].first);
	}

	if ( visitado[ grafo[topo].second ] != 1 && grafo[topo].second != "" ){

		dfs(grafo[topo].second);
	}
}

void posfixa(string topo){

	// cout << " k " << topo << endl;

	string anterior;

	if ( visitado[ grafo[topo].first ] != 1 && grafo[topo].first != "" ){

		anterior = topo;
		posfixa(grafo[topo].first);
	}
	
	if ( visitado[ grafo[topo].second ] != 1 && grafo[topo].second != "" ){

		anterior = topo;
		posfixa(grafo[topo].second);
	}

	if ( checa )
		cout << " ";

	checa = true;
	cout << topo;

}

int main(){
    
    string comando;
    
    string primeira_letra;
    
    cin >> comando >> primeira_letra;
    
    string inserir;

    vector < string > v;
    
	v.push_back(primeira_letra);

    while ( cin >> comando ){
    
        string aux = primeira_letra;
    
        if ( comando == "I" ){
        
            cin >> inserir;

            v.push_back(inserir);
            	
            while ( 1 ) {
            
                if ( inserir < aux ){
                
                    if ( grafo[aux].first == "" ){
                        grafo[aux].first = inserir;
                        
                        break;    
                    }
                    else
                        aux = grafo[aux].first;   
                }else{
                    
                    if ( grafo[aux].second == "" ){
                        grafo[aux].second = inserir;
                        
                        break;   
                    }
                    else
                        aux = grafo[aux].second;
                }    
            }
        }

        if ( comando == "PREFIXA" ){

        	visitado.clear();
        	checa = false;
        	dfs(primeira_letra);

        	printf("\n");
        }

        if ( comando == "INFIXA" ){

        	checa = false;

        	sort(v.begin(), v.end());

        	for ( int i = 0; i < v.size(); i++ ){
        		if ( i )
        			cout << " ";
        		cout << v[i];
        	}

        	printf("\n");
        }

        if ( comando == "P" ){
        	cin >> aux;

        	for ( int i = 0; i < v.size(); i++ )
        		if ( v[i] == aux ){
        			cout << aux << " existe" << endl;
        			goto tag;
        		}

        	cout << aux << " nao existe" << endl;
        }

        tag:;

        if ( comando == "POSFIXA" ){

        	visitado.clear();
        	checa = false;
        	posfixa(primeira_letra);
        	cout << endl;
        }
    }   
    
    return 0;
}
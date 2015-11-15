#include <bits/stdc++.h>
  
using namespace std;
  
int soma(vector<int> numeros){
  
    int sizev = numeros.size();
  
    int soma = 0;
  
    for ( int i = 0 ; i < sizev - 1 ; i++ ){
  
        soma = soma + abs(numeros[i] - numeros[i+1]);
    }
  
    return soma;
  
}
 
int caso_maior_lista(vector<int> numeros){
 
    list<int> lista;
 
    list<int> aux;
 
    aux.push_back(numeros[0]);
 
    for ( int i = 1 ; i < numeros.size() ; i++ )
        lista.push_back(numeros[i]);
 
    int fim = 1;
 
    auto it = lista.end();
    auto it2 = lista.end();
 
    int aux2;
 
    while ( lista.size() != 0 ){
 
        if ( fim ){
 
            it = next(lista.begin(), lista.size() - 1);
            it2 = next(lista.begin(), lista.size() - 2);
 
            aux.push_front(*it);
            aux.push_back(*it2);
 
            lista.pop_back();
            lista.pop_back();
 
            fim = 0;
            // cout << it << endl;
        }else{
 
            it = lista.begin();
            it2 = next(lista.begin(), 1);
 
            aux.push_front(*it);
            aux.push_back(*it2);
 
            lista.pop_front();
            lista.pop_front();
 
            fim = 1;
        }
 
    }
 
    int soma2 = 0;
 
    numeros.clear();

    for ( it = aux.begin() ; it != aux.end() ; it++ ){
 
        soma2 = soma2 + *it;
 
        numeros.push_back(*it);
    }
 
    return soma(numeros);
 
}
 
int caso_menor_lista(vector<int> numeros){
 
    list<int> lista;
 
    list<int> aux;
 
    aux.push_back(numeros[numeros.size() - 1]);
 
    numeros.pop_back();
 
    for ( int i = 0 ; i <= numeros.size() -1 ; i++ )
        lista.push_back(numeros[i]);
 
    int inicio = 1;
 
    auto it = lista.end();
    auto it2 = lista.end();
 
    int aux2;
 
    while ( lista.size() != 0 ){
 
        if ( inicio ){
 
            it = lista.begin();
            it2 = next(lista.begin(), 1);
 
            aux.push_front(*it);
            aux.push_back(*it2);
 
            lista.pop_front();
            lista.pop_front();
 
            inicio = 0;

        }else{
 
            it = next(lista.begin(), lista.size() - 1);
            it2 = next(lista.begin(), lista.size() - 2);
 
            aux.push_front(*it);
            aux.push_back(*it2);
 
            lista.pop_back();
            lista.pop_back();
 
            inicio = 1;
        }
 
    }
 
    int soma2 = 0;
 
    numeros.clear();
 
    for ( it = aux.begin() ; it != aux.end() ; it++ ){
 
        soma2 = soma2 + *it;
 
        numeros.push_back(*it);
    }
 
    return soma(numeros);
 
}
  
int caso_maior(vector<int> numeros){
  
    vector <int> a;
  
    vector <int> b;
 
    list <int> lista;
  
    for ( int i = numeros.size() - 1 ; i >= 1 ; i-- ){
  
        if ( i % 2 == 0 )
            a.push_back(numeros[i]);
        else
            b.push_back(numeros[i]);
    }
  
    sort(b.begin(), b.end(), greater<int>());
  
    vector<int> c = b;
  
    c.push_back(numeros[0]);
  
    for ( int i = 0 ; i < a.size() ; i++ )
        c.push_back(a[i]);
  
    return soma(c);
}
  
int caso_menor(vector<int> numeros){
  
    vector <int> a;
  
    vector <int> b;
  
    int sizev = numeros.size();
  
    for ( int i = 0 ; i < sizev - 1 ; i++ ){
  
        if ( i % 2 == 0 )
            a.push_back(numeros[i]);
        else
            b.push_back(numeros[i]);
    }
  
    sort(b.begin(), b.end());
  
    vector<int> c = b;
  
    c.push_back(numeros[sizev - 1]);
  
    for ( int i = 0 ; i < a.size() ; i++ )
        c.push_back(a[i]);
  
    return soma(c);
}
  
int main(){
  
    vector <int> numeros;
  
    vector <int> novo;
  
    int teste;
  
    int cont = 1;
  
    int aux;
  
    int numeros_teste;
  
    scanf("%d", &numeros_teste);
  
    for ( int w = 0 ; w < numeros_teste ; w++ ){
        scanf("%d", &teste);
  
        for ( int i = 1 ; i <= teste ; i++ ){
  
            scanf("%d", &aux);
  
            numeros.push_back(aux);
  
        }
  
        int size2 = numeros.size();
  
        sort(numeros.begin(), numeros.end(), greater<int>());
  
        if ( teste == 1 ){
            printf("Case %d: 0\n", cont);
            cont++;
        }else if ( size2 % 2 == 0 ){
            for ( int i = numeros.size()/2 ; i >= 1 ; i-- ){
                novo.push_back(numeros[i-1]);
                novo.push_back(numeros[i - 1 + size2/2]);
            }
            int soma = 0;
  
            for ( int i = 0 ; i < teste - 1 ; i++ ){
  
                soma = soma + abs(novo[i] - novo[i+1]);
            }
  
            printf("Case %d: %d\n", cont , soma);
  
            cont++;
  
            soma = 0;
        }else{
  
            //caso_maior(numeros);
            //caso_menor(numeros);
  
            for ( int i = (int)numeros.size()/2 ; i >= 1 ; i-- ){
                novo.push_back(numeros[i-1]);
                novo.push_back(numeros[i - 1 + (int)size2/2]);
            }
            int soma = 0;
  
            int lastone = novo[teste-2];
  
            novo.pop_back();
  
            novo.push_back(numeros[teste-1]);
  
            novo.push_back(lastone);
  
            for ( int i = 0 ; i < teste - 1 ; i++ ){
  
                soma = soma + abs(novo[i] - novo[i+1]);
            }
  
            vector < int > maior_resultado;
             
            maior_resultado.push_back(caso_maior_lista(numeros));
            maior_resultado.push_back(caso_menor_lista(numeros));
            maior_resultado.push_back(soma);
            maior_resultado.push_back(caso_maior(numeros));
            maior_resultado.push_back(caso_menor(numeros));
  
            sort(maior_resultado.begin(), maior_resultado.end());
  
            printf("Case %d: %d\n", cont , maior_resultado[4]);
  
            cont++;
  
            soma = 0;
        }
  
        novo.clear();
        numeros.clear();
    }
  
    return 0;
}
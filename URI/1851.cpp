#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
 
class pq{
 
public:
    int dia;
    int multa;
 
    bool operator < (const pq& str) const
    {
         
        if ( dia*str.multa > multa*str.dia )
            return true;
        else
            return false;
         
    }
 
};
 
 
using namespace std;
 
int main(){
 
    std::ios::sync_with_stdio(false);
 
    pq aux;
 
    long long multa = 0;
 
    vector <pq> vetor;
 
    priority_queue <pq> filaprioridade;
 
    long long agregado = 0;
 
    pq top;
 
    int dias_restantes;
 
    cin >> top.dia >> top.multa;
 
    dias_restantes = top.dia;
 
    while( cin >> aux.dia >> aux.multa ){
 
        if ( dias_restantes == 0 ){
 
            top = filaprioridade.top();
 
            dias_restantes = top.dia;
 
            agregado = agregado - top.multa;
 
            multa = agregado*top.dia + multa;
 
            filaprioridade.pop();
        }
 
        agregado = aux.multa + agregado;
 
        dias_restantes--;
 
        multa = dias_restantes * aux.multa + multa;
 
        filaprioridade.push(aux);
 
    }
 
    while ( filaprioridade.size() >= 1 ){
 
        top = filaprioridade.top();
 
        agregado = agregado - top.multa;
 
        multa = agregado*top.dia + multa;
 
        filaprioridade.pop();
 
    }
 
    printf("%lld\n", multa);
 
    return 0;
}